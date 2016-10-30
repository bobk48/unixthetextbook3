from Tkinter import *
def listbox():
    master = Tk()
    master.title("Listbox")
    listbox = Listbox(master)
    listbox.pack()
    for item in ["one", "two", "three", "four"]:
        listbox.insert(END, item)
    mainloop()
listbox()
