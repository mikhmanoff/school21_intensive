#!/bin/bash

#condition to check file exist
read -p "Введите путь файла, который вы хотите изменить: " source
if [ -f "$source" ]; then
    read -p "Введите строчку, которую вы хотите изменить: " editing
else
    echo "Файла или директории не существует"
    pkill edit.sh
fi

#condition to check string exist
if grep -q "$editing" "$source"; then
    read -p "Введите строчку, на которую вы хотите изменить: " edited
else
    echo "Такой строки не существует"
    pkill edit.sh
fi

#some activity
sed -i '' "s/${editing}/${edited}/g" ${source}
f=$(basename "$source")
fsize=$(stat -f%z "$source")
fdate=$(date '+%Y-%m-%d %H:%M')
fsha=$(openssl dgst -sha256 "$source"  | awk '{print $2}')

#outtput
echo "$f - $fsize - $fdate - $fsha - sha256" >> files.log
echo "Изменение строчки прошло успешно"