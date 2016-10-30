#!/usr/local/bin/python
import sys
s = raw_input("Enter input:")
print "You entered:", s
r = raw_input("Enter another line:")
words = r.split(' ')
print "The first word is:", words[0]
print "The second word is:", words[1]
rest = (' '.join(words[2:]))
print "The rest of the line is:", rest
sys.exit() #normal exit status
