from Tkinter import *
def scrollbar():
    master = Tk()
    master.title("Scrollbar")
    scrollbar = Scrollbar(master)
    scrollbar.pack(side=RIGHT, fill=Y)
    listbox = Listbox(master, yscrollcommand=scrollbar.set)
    listbox.insert(END, "Listbox")
    for i in range(1000):
        listbox.insert(END, str(i))
    listbox.pack(side=LEFT, fill=BOTH)
    scrollbar.config(command=listbox.yview)
    mainloop()
scrollbar()
