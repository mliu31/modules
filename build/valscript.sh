#!/bin/bash

for testfile in *.test; do
		valgrind "${testfile}"  &> valtest.txt
		
		grep -q "no leaks are possible" "./valtest.txt"
		
		if [ $? -eq "0" ] ; then
				echo "${testfile} has no leaks!"
		else
				echo "${testfile} has leaks!"
		fi

		grep -q "0 errors" valtest.txt "./valtest.txt"
		
		if [ $? -eq "0" ] ; then
				echo "${testfile} has no errors!"
		else
				echo "${testfile} has errors!"
		fi

		rm valtest.txt
done
