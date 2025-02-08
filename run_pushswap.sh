#!/bin/zsh
make fclean
if make  # Regular build without DEBUG=1
then
    ./push_swap "$@"  # Run without ASAN_OPTIONS
else
    echo "Make failed"
    exit 1
fi