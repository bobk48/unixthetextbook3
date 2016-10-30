from Tkinter import *
def text():
    master = Tk()
    master.title("Text")
    textBox = Text(master,wrap=WORD)
    textBox.grid()
    mainloop()
text()
