from Tkinter import *
from tkMessageBox import showinfo
def reply(name):
    showinfo(title='Callback', message='Greetings %s!' % name)
top = Tk( )
top.title('Event')
Label(top, text="Enter your first name:").pack(side=TOP)
ent = Entry(top)
ent.pack(side=TOP)
btn = Button(top, text="Call", command=(lambda: reply(ent.get())))
btn.pack(side=LEFT)
top.mainloop( )
