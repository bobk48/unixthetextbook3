from Tkinter import *
# These colors are set in several places, but this lets us change in only one.
mainbg = '#8888FF';
activebg = '#AAAAFF';
root = Tk()
root.title('Temp Conversion')
# This grids the widget object where indicated, then returns it.
def mkgrid(r, c, w):
       w.grid(row=r, column=c, sticky='news')
       return w
# This computes the Celsius temperature from the Fahrenheit.
def findcel():
       famt = ftmp.get()
       if famt == '':                      #not double quote, 2 single quotes
             cent.configure(text='')
       else:
             famt = float(famt)
       camt = (famt - 32) / 1.8
       # A method (configure) applied to an object (cent) that is converted to a string (str(camt)).
       cent.configure(text=str(camt))  
# The rest hooks the Fahrenheut and Celsius Temperatures into the grid graphics manager widgets.
flab = mkgrid(0, 0, Label(root, text="Fahrenheit Temperature",
                         anchor='e', bg=mainbg))
clab = mkgrid(1, 0, Label(root, text="Celsius Temperature",
                         anchor='e', bg=mainbg))
ftmp = mkgrid(0, 1, Entry(root, bg=mainbg))
cent = mkgrid(1, 1, Label(root, text="", relief='sunken',
                         anchor='w', bg=mainbg))
elab = mkgrid(0, 2, Label(root, text='', bg=mainbg))
fbut = mkgrid(1, 2, Button(root, text="Compute Celsius",
                           bg=mainbg, activebackground=activebg,
                           command=findcel))
# Starts the root main event loop
root.mainloop()
