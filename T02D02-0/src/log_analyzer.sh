#!/bin/bash

if [ -f "files.log" ];
then
    #just for smth
    logf=$(<files.log)
else
    echo "Лог файла не существует"
    pkill log_analyzer.sh
fi

string_num=$(wc -l < files.log)
uniq_num=$(awk < files.log '{print $1}' | sort -u | uniq | wc -l)
uniq_ch=$(awk < files.log '{print $8}' | sort -ud | uniq | wc -l)

echo "$string_num $uniq_num $uniq_ch"