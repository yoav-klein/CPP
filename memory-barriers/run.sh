#!/bin/bash

flag=run
echo "starting..."
declare -i counter=0
while [ $flag = "run" ]; do
    ((counter=counter+1))
    if [ $counter = 50 ]; then
        echo "Running..."
        counter=0
    fi
    res=$(./a.out)
    if [ res = "0" ]; then
        flag="stop"
        echo "FOUND !"
    fi
done     
