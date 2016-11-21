#!/usr/local/bin/python
import stat, sys, os, string, commands
try:
    #Getting search pattern from user and assigning it to a list
    pattern = raw_input("Enter the file pattern to search for:\n")
    #defining a 'find' string and assigning results to a variable
    commandString = "find " + pattern
    commandOutput = commands.getoutput(commandString)
    findResults = string.split(commandOutput, "\n")
    #output find results, along with permissions
    print "Files:"
    print commandOutput
    print "*******************************"
    for file in findResults:
        mode=stat.S_IMODE(os.lstat(file)[stat.ST_MODE])
        print "\nPermissions for file ", file, ":"
        for level in "USR", "GRP", "OTH":
            for perm in "R", "W", "X":
                if mode & getattr(stat,"S_I"+perm+level):
                    print level, " has ", perm, " permission"
                else:
                    print level, " does NOT have ", perm, "permission"
except:
    print "Error - check your input of file matching pattern"
