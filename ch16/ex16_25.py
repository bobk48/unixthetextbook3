#!/usr/local/bin/python
import os
import sys
if len(sys.argv) == 1 or len(sys.argv) > 2:  #check for no/too many args 
    print "Usage: ", sys.argv[0], " ordinary file"
    sys.exit(1)
if os.path.isfile(sys.argv[1]):      #bingo, get stats
    filename = sys.argv[1]
    fileinfo = os.stat(filename)
    print "Filename   inode    size"
    print " "
    print filename, fileinfo.st_ino, fileinfo.st_size
    sys.exit(0)
else:                                # argument must something else!
    print sys.argv[1], " argument must be an ordinary file"
    sys.exit(1)
