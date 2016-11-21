from threading import Thread                  #Block 1.
from random import randint
import time

class Threader(Thread):                       #Block 2.
     def __init__(self, val):
           ''' Constructor. '''
           Thread.__init__(self)
           self.val = val
     def run(self):                           #Block 3.
           for i in range(1, self.val):
                print('Value %d in thread %s' % (i, self.getName()))
                # Sleep for random time
                GoToSleep = randint(1, 5)
                print('%s sleeping fo %d seconds...' % (self.getName(), GoToSleep))
                time.sleep(GoToSleep)
 
if __name__ == '__main__':                    #Block 4.
     # Declare Threader class
     Threader_Object1 = Threader(4)
     Threader_Object1.setName('Thread 1')
 
     Threader_Object2 = Threader(4)
     Threader_Object2.setName('Thread 2')
 
     Threader_Object3 = Threader(4)
     Threader_Object3.setName('Thread 3')

     # Run the threads!
     Threader_Object1.start()
     Threader_Object2.start()
     Threader_Object3.start()
     
# Wait ...
     Threader_Object1.join()
     Threader_Object2.join()
     Threader_Object3.join()

#Exuent …
     print('Main Terminating...')
