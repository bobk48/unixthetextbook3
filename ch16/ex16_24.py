#!/usr/local/bin/python
import sys
x = (sys.argv)
print "The command name is: ", sys.argv[0]
print "The number of command line arguments passed as
parameters is: ", len(sys.argv[1: ])
print "The value of the command line arguments are: ", x[1: ]
print "Another way to display values of all the arguments: ",
sys.argv[1: ]
print "Yet another way is: ", sys.argv[slice(1,9)]
sys.exit ( )
