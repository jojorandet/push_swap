#!/bin/bash
make fclean
if make
then 
	./push_swap $@
else
	echo "Error: Make failed - cannot execute pushswap"
	exit 1
fi 