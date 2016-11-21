from Tkinter import *
def scale():
    master = Tk()
    master.title("Scale")
    w = Scale(master, from_=0, to=100)
    w.pack()
    w = Scale(master, from_=0, to=200, orient=HORIZONTAL)
    w.pack()
    mainloop()
scale()
