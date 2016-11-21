from Tkinter import *
def optionmenu():
    master = Tk()
    master.title("OptionMenu")
    variable = StringVar(master)
    variable.set("one") # default value
    w = OptionMenu(master, variable, "one", "two", "three")
    w.pack()
    mainloop()
optionmenu()
