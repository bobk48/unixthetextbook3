from Tkinter import *
def message():
    master = Tk()
    master.title("Message")
    w = Message(master, text="the message")
    w.pack()
    mainloop()
message()
