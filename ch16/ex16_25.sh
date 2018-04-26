#!/bin/csh
if ( ( $#argv == 0 ) || ( $#argv > 1 ) ) then
    echo "Usage: $0 ordinary_file"
    exit 1
endif
if ( -f $1 ) then
    set filename = $argv[1]
    set fileinfo = `ls -il $filename`
    set inode = $fileinfo[1]
    set size = $fileinfo[6]
    echo "File Name:        $filename"
    echo "Inode Number:     $inode"
    echo "Size (bytes):     $size" 
    exit 0
else
    echo "$0: argument must be an ordinary file" 
    exit 1
endif
