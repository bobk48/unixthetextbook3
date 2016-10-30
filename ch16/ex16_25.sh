#!/bin/csh
if ( ($#argv == 0) | | ($#argv > 1) ) then
    echo "Usage: $0 ordinary_file"
    exit 1
endif
if ( -f $argv[1] ) then
    set filename = $argv[1]
    set fileinfo = 'ls -il $filename'
    set inode = $fileinfo[1]
    set size = $fileinfo[5]
    echo "Name       Inode      Size"
    echo
    echo "$filename     $inode    $size"
    exit 0
endif
echo "$0: argument must be an ordinary file"
exit 1
