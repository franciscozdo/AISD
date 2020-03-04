#!/bin/bash

for ((i = 0; i < $1; i++)); do
  ./Arand > in 2> /dev/null
  ./A < in > out
  cat in out | ./Acheck  2> /dev/null
  if [ "$?" -eq 0 ]; then
    echo $i OK
  else
    echo NOT OK
    exit 1
  fi
done
