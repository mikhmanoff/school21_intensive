#include <curses.h>
#include <math.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

const int MAX_SCORE = 21;
const int NON_BLOCK_DISABLE = 0;
const int NON_BLOCK_ENABLE = 1;
const int PLAYGROUND_HEIGHT = 25;
const int PLAYGROUND_WIDTH = 80;
const int RACKET_SIZE = 3;
const int SLEEP_TIME = 300000;

int score_gamer_left = 0;
int score_gamer_right = 0;

int check_gameover(int x_ball);
void draw_ball(int shift);
void draw_edge();
void draw_left_racket();
void draw_net(int x_init);
void draw_playground(int y_gamer_left, int y_gamer_right, int x_ball, int y_ball);
void draw_right_racket(int x_init);
double get_abs(double number);
double get_x_intersection(double velocity_x, double velocity_y, int x_1, int y_1, int y_2);
double get_y_intersection(double velocity_x, double velocity_y, int x_1, int y_1, int x_2);
int is_y_in_racket(int y_center_of_racket, int y);
int kbhit();
void nonblock(int state);
int play_game(int first_move, int angle);

int main() {
    const int ANGLE_SHIFT = 10;
    int first_move = 1;
    int angle = 15;
    nonblock(NON_BLOCK_ENABLE);
    while (1) {
        if (score_gamer_left >= MAX_SCORE) {
            printf("PLAYER 1 WON");
            return 0;
        } else if (score_gamer_right >= MAX_SCORE) {
            printf("PLAYER 2 WON");
            return 0;
        }

        play_game(first_move, angle);
        if (first_move == 1) {
            first_move = 2;
        } else {
            first_move = 1;
        }
        angle += ANGLE_SHIFT;
    }
    nonblock(NON_BLOCK_DISABLE);
    return 0;
}

int check_gameover(int x_ball) {
    int winner = 0;
    if (x_ball < 0) {
        score_gamer_right += 1;
        winner = 1;
    } else if (x_ball >= PLAYGROUND_WIDTH) {
        score_gamer_left += 1;
        winner = 2;
    }
    return winner;
}

void draw_ball(int shift_along_x) {
    for (int x = 0; x < shift_along_x; x++) {
        printf(" ");
    }
    printf("o");
}

void draw_edge() {
    for (int x = 0; x < PLAYGROUND_WIDTH; x++) {
        printf("-");
    }
    printf("\n");
}

void draw_left_racket() { printf("|"); }

void draw_net(int x_init) {
    for (int x = x_init; x < PLAYGROUND_WIDTH / 2 - 1; x++) {
        printf(" ");
    }
    printf("|");
}

void draw_playground(int y_gamer_left, int y_gamer_right, int x_ball, int y_ball) {
    // To clear all screen
    // https://stackoverflow.com/questions/3646240/how-to-clear-the-screen-with-x1b2j
    printf("\x1B[2J\x1B[H");
    for (int i = 0; i < PLAYGROUND_WIDTH / 2 - 3; i++) {
        printf(" ");
    }
    printf("%02d - %02d\n", score_gamer_left, score_gamer_right);
    for (int y = -1; y <= PLAYGROUND_HEIGHT; y++) {
        if (y == -1 || y == PLAYGROUND_HEIGHT) {
            draw_edge();
            continue;
        }
        int x = -1;
        if (is_y_in_racket(y_gamer_left, y)) {
            draw_left_racket();
            x = 0;
        }
        if (x_ball <= PLAYGROUND_WIDTH / 2 && y == y_ball) {
            draw_ball(x_ball - x - 1);
            x = x_ball;
        }
        if (y != y_ball || x_ball != PLAYGROUND_WIDTH / 2) {
            draw_net(x);
        }
        x = PLAYGROUND_WIDTH / 2;
        if (x_ball > PLAYGROUND_WIDTH / 2 && y == y_ball) {
            draw_ball(x_ball - x - 1);
            x = x_ball;
        }
        if (is_y_in_racket(y_gamer_right, y)) {
            draw_right_racket(x);
        }
        printf("\n");
    }
}

void draw_right_racket(int x_init) {
    for (int x = x_init; x < PLAYGROUND_WIDTH - 2; x++) {
        printf(" ");
    }
    printf("|");
}

double get_abs(double number) {
    return number > 0 ? number : -number;
}

double get_x_intersection(double velocity_x, double velocity_y, int x_1, int y_1, int y_2) {
    return x_1 + velocity_x / velocity_y * (y_2 - y_1);
}

double get_y_intersection(double velocity_x, double velocity_y, int x_1, int y_1, int x_2) {
    return y_1 + velocity_y / velocity_x * (x_2 - x_1);
}

int is_y_in_racket(int y_center_of_racket, int y) {
    if (y_center_of_racket - RACKET_SIZE / 2 <= y && y <= y_center_of_racket + RACKET_SIZE / 2) {
        return 1;
    }
    return 0;
}

// http://cc.byexamples.com/2007/04/08/non-blocking-user-input-in-loop-without-ncurses/
int kbhit() {
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);  // STDIN_FILENO is 0
    select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}

// http://cc.byexamples.com/2007/04/08/non-blocking-user-input-in-loop-without-ncurses/
void nonblock(int state) {
    struct termios ttystate;
    // Get the terminal state
    tcgetattr(STDIN_FILENO, &ttystate);
    if (state == NON_BLOCK_ENABLE) {
        // Turn off canonical mode
        ttystate.c_lflag &= ~ICANON;
        // Minimum of number input read
        ttystate.c_cc[VMIN] = 1;
    } else if (state == NON_BLOCK_DISABLE) {
        // Turn on canonical mode
        ttystate.c_lflag |= ICANON;
    }
    // Set the terminal attributes.
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

int play_game(int first_move, int angle) {
    int y_gamer_left = PLAYGROUND_HEIGHT / 2;
    int y_gamer_right = PLAYGROUND_HEIGHT / 2;
    int x_ball = PLAYGROUND_WIDTH / 2;
    int y_ball = PLAYGROUND_HEIGHT / 2;
    char command;
    double velocity = 3.0;
    double velocity_x = velocity * cos(M_PI * angle / 180.0);
    if (0 <= velocity_x && velocity_x < 1) {
        velocity_x = 1;
    } else if (-1 < velocity_x && velocity_x < 0) {
        velocity_x = -1;
    }
    double velocity_y = velocity * sin(M_PI * angle / 180.0);
    if (0 <= velocity_y && velocity_y < 1) {
        velocity_y = 1;
    } else if (-1 < velocity_y && velocity_y < 0) {
        velocity_y = -1;
    }
    if (first_move == 1) {
        velocity_x = get_abs(velocity_x);
    } else {
        velocity_x = -get_abs(velocity_x);
    }
    while (1) {
        usleep(SLEEP_TIME);
        // Check that ball is inside playground
        if (check_gameover(x_ball)) {
            return 0;
        }

        // Draw playground with rackets and ball
        draw_playground(y_gamer_left, y_gamer_right, x_ball, y_ball);

        // Read command from left or right player
        command = '0';
        int command_for_left = 0;
        int command_for_right = 0;
        while (kbhit() != 0) {
            command = fgetc(stdin);
            // Move left racket
            if (command_for_left == 0 && (command == 'a' || command == 'A') && y_gamer_left > 1) {
                y_gamer_left -= 1;
                command_for_left = 1;
            } else if (command_for_left == 0 && (command == 'z' || command == 'Z') &&
                       y_gamer_left < PLAYGROUND_HEIGHT - 2) {
                y_gamer_left += 1;
                command_for_left = 1;
            }
            // Move right racket
            if (command_for_right == 0 && (command == 'k' || command == 'K') && y_gamer_right > 1) {
                y_gamer_right -= 1;
                command_for_right = 1;
            } else if (command_for_right == 0 && (command == 'm' || command == 'M') &&
                       y_gamer_right < PLAYGROUND_HEIGHT - 2) {
                y_gamer_right += 1;
                command_for_right = 1;
            }
        }

        // Calculate ball's coordinates
        x_ball += velocity_x;
        y_ball += velocity_y;

        double x_intersection_with_edge = -100.0;
        if (velocity_y < 0 && y_ball < 0) {
            x_intersection_with_edge = get_x_intersection(velocity_x, velocity_y, x_ball, y_ball, 0);
        } else if (velocity_y > 0 && y_ball >= PLAYGROUND_HEIGHT) {
            x_intersection_with_edge = get_x_intersection(velocity_x, velocity_y, x_ball, y_ball,
                                                          PLAYGROUND_HEIGHT);
        }

        double y_intersection_with_racket = -100.0;
        if (velocity_x < 0) {
            y_intersection_with_racket = get_y_intersection(velocity_x, velocity_y, x_ball, y_ball, 0);
        } else if (velocity_x > 0) {
            y_intersection_with_racket = get_y_intersection(velocity_x, velocity_y, x_ball, y_ball,
                                                            PLAYGROUND_WIDTH - 1);
        }

        if (0 <= x_intersection_with_edge && x_intersection_with_edge < PLAYGROUND_WIDTH) {
            if (velocity_y < 0) {
                y_ball = -y_ball;
            } else {
                y_ball = PLAYGROUND_HEIGHT - 1 - (y_ball - PLAYGROUND_HEIGHT + 1);
            }
            velocity_y = -velocity_y;
        }

        if (velocity_x < 0 && is_y_in_racket(y_gamer_left, y_intersection_with_racket) && x_ball < 1) {
            x_ball = 1 + (1 - x_ball);
            velocity_x = -velocity_x;
        } else if (velocity_x > 0 && is_y_in_racket(y_gamer_right, y_intersection_with_racket) &&
                   x_ball >= PLAYGROUND_WIDTH - 2) {
            x_ball = PLAYGROUND_WIDTH - 2 - (x_ball - PLAYGROUND_WIDTH + 2);
            velocity_x = -velocity_x;
        }
    }
}


