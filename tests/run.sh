#!/bin/bash
for f in $(ls *.c); do
	echo "$f -> /tmp/${f}.exe"
	cc -o /tmp/${f}.exe $f ../list.c -Wall -O2
	/tmp/${f}.exe
done
