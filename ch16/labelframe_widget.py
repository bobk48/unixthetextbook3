from Tkinter import *
def labelframe():
    master = Tk()
    group = LabelFrame(master, text="LabelFrame", padx=5, pady=5)
    group.pack(padx=10, pady=10)
    w = Entry(group)
    w.pack()
    mainloop()
labelframe()
