#!/bin/bash
for f in $(ls *.c); do
	echo "$f -> /tmp/${f}.o"
	cc -o /tmp/${f}.o $f ../list.c -Wall -O2
	/tmp/${f}.o
done
