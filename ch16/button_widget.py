from Tkinter import *
import sys
def quit():
    print "Out of Here"
    sys.exit()
def button():
    master = Tk()
    b = Button(master, text="Button", command=quit)
    b.pack()
    mainloop()
button()
