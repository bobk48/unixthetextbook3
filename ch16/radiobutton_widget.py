from Tkinter import *
def radiobutton():
    master = Tk()
    master.title("RadioButton")
    v = IntVar()
    Radiobutton(master, text="One", variable=v, value=1).pack(anchor=W)
    Radiobutton(master, text="Two", variable=v, value=2).pack(anchor=W)
    mainloop()
radiobutton()
