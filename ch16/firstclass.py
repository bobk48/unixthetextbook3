#!/usr/local/bin/python
class Structure:
   'Common base class for all Python Structures'
   StrucCount = 0

   def __init__(s, name, number):
      s.name = name
      s.number= number
      Structure.StrucCount += 1
   
   def displayCount(s):
     print "Total Structures %d" % Structure.StrucCount

   def displayStructure(s):
      print "Name : ", s.name,  ", Number : ", s.number
