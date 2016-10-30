from Tkinter import *
def frame():
    master = Tk()
    master.title("Frame")
    Label(text="above Frame separator").pack()
    separator = Frame(height=2, bd=1, relief=SUNKEN)
    separator.pack(fill=X, padx=5, pady=5)
    Label(text="below Frame separator").pack()
    mainloop()
frame()
