#!/usr/local/bin/python
import os
import sys
if len(sys.argv) = = 1 or len(sys.
argv) > 2:    #check for no or too many arg(s)
    print "Usage: ", sys.argv[0], "is not an ordinary file"
    sys.exit(1)
if sys.argv[1].startswith('.'):     #added check for dot files
    print "Usage: ", sys.argv[1], "is a dot file"
    sys.exit(1)
if os.path.isfile(sys.
argv[1]):                      #bingo, get stats
    filename = sys.argv[1]
    fileinfo = os.stat(filename)
    print "Filename   inode    size"
    Print " "
    print filename, fileinfo.st_ino, fileinfo.st_size
    sys.exit(0)
else:                          # argument must be a directory
    print sys.argv[1], " argument must be an ordinary file"
    sys.exit(1)
