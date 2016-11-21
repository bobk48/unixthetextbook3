from Tkinter import *
def menu():
    root = Tk()
    root.title("Menu")
    def hello():
        print "I am here"
    # create a toplevel menu
    menubar = Menu(root)
    menubar.add_command(label="1stMenu", command=hello)
    menubar.add_command(label="2ndMenu", command=root.quit)
    # Show them
    root.config(menu=menubar)
    mainloop()
menu()
