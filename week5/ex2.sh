#!/bin/bash

FILE="numbers.txt"
LOCK="numbers.lock"

function lock {
    while ! ln $FILE $LOCK 2> /dev/null ; do
        sleep 0.01
    done
}

function unlock() {
    rm $LOCK
}

if ! test -e $FILE; then
    echo "1" > $FILE
fi

while :;
do
    lock
    # Critical region starts
    last=$(tail -n1 $FILE)
    next=$(($last + 1))
    echo $next >> $FILE
    # Critical region ends
    unlock
    sleep 1
done
