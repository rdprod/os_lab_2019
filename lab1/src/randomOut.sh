#!/bin/bash

file_name=numbers1.txt
while read -r number
do
  echo $number
done < $file_name