#include <curses.h>
#include <stdio.h>
#include <unistd.h>
#define HEIGHT 25
#define WIDTH 80
#define STEP 2000
#define TIME 100000

void print_state(int mtx[HEIGHT][WIDTH]);
void cell_st(int cur_state[HEIGHT][WIDTH], int next_state[HEIGHT][WIDTH],
             int row, int col);
void state_calc(int cur_state[HEIGHT][WIDTH], int next_state[HEIGHT][WIDTH]);
int input(int cur_state[HEIGHT][WIDTH]);
void rules();

int main() {
  int cur_state[HEIGHT][WIDTH] = {0};
  initscr();
  cbreak();
  nodelay(stdscr, true);
  noecho();
    if (input(cur_state) == 0) {
    int next_state[HEIGHT][WIDTH] = {0};
    char c;
    int k = TIME;
    (void)freopen("/dev/tty", "r", stdin);
     while ((c = getch()) != 'q') {
      if (c == 'a') {
          if (k - STEP >= 0) {
          k = k - STEP;
      }
      }
        if (c == 'd') {
          k = k + STEP;
      }
    usleep(k);
    clear();
    print_state(cur_state);
    state_calc(cur_state, next_state);
    refresh();
  }
  endwin();
  printf("\33[0d\33[2J");
    } else {
        printf("n/a");
    }
  return 0;
}
int input(int cur_state[HEIGHT][WIDTH]) {
    int flag = 0;
    for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
          if (scanf("%d", &cur_state[i][j])!= 1) {
              flag = 1;
          }
      }
    }
    return flag;
}
void print_state(int mtx[HEIGHT][WIDTH]) {
  for (int y = 0; y <= HEIGHT; y++) {
    for (int x = 0; x <= WIDTH; x++) {
      if ((y == 0 && x != 0 && x != WIDTH) ||
          (y == HEIGHT && x != 0 && x != WIDTH)) {
        printw("-");
      } else if ((x == 0 && y != 0 && y != HEIGHT) ||
                 (x == WIDTH && y != 0 && y != HEIGHT)) {
        printw("|");
      } else if ((y == 0 && x == 0) || (y == HEIGHT && x == 0) ||
                 (y == HEIGHT && x == WIDTH) || (y == 0 && x == WIDTH)) {
        printw(" ");
      } else {
        if (mtx[y][x] == 1) {
          printw("@");
        } else {
          printw(" ");
        }
      }
    }
    printw("\n");
  }
  rules();
}
void cell_st(int cur_state[HEIGHT][WIDTH], int next_state[HEIGHT][WIDTH],
             int row, int col) {
  int sum = -cur_state[row][col];
  int r = row - 1;
  for (int i = ((r + HEIGHT) % HEIGHT); r < row + 2;
       i = (++r + HEIGHT) % HEIGHT) {
    int c = col - 1;
    for (int j = ((c + WIDTH) % WIDTH); c < col + 2;
         j = (++c + WIDTH) % WIDTH) {
      sum += cur_state[i][j];
    }
  }
  if (cur_state[row][col] == 0 && sum == 3) {
    next_state[row][col] = 1;
  }
  if (cur_state[row][col] == 1 && (sum < 2 || sum > 3)) {
    next_state[row][col] = 0;
  } else if (cur_state[row][col] == 1 && (sum == 2 || sum == 3)) {
    next_state[row][col] = 1;
  }
}
void state_calc(int cur_state[HEIGHT][WIDTH], int next_state[HEIGHT][WIDTH]) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      cell_st(cur_state, next_state, i, j);
    }
  }
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      cur_state[i][j] = next_state[i][j];
    }
  }
}
void rules() {
    printw("Press buttons below to control the speed\n-a increase | -d decrease | q-quit\n> ");
}

