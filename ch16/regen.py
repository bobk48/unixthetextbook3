from __future__ import generators # This line is optional

def abc():
	a = deff()
	for i in a:
		yield i
	yield 'abc'

def deff():
	a = ijk()
	for i in a:
		yield i
	yield 'deff'

def ijk():
	for i in (1,2,3):
		yield i
	yield 'ijk'
