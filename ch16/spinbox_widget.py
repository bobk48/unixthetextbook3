from Tkinter import *
def spinbox():
    master = Tk()
    master.title("Spinbox")
    w = Spinbox(master, from_=0, to=10)
    w.pack()
    mainloop()
spinbox()
