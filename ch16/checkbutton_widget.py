from Tkinter import *
def checkbutton():
    master = Tk()
    var = IntVar()
    c = Checkbutton(master, text="Checkbutton", variable=var)
    c.pack()
    mainloop()
checkbutton()
