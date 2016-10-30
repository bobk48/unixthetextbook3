import thread, time
def counter(myId, count):                     # function that will run in each thread
     for i in range(count):
          time.sleep(1)                       # simulate useful code here
          print '[%s] => %s' % (myId, i)
for i in range(5):                            # call start_new_thread 5 times
     thread.start_new_thread(counter, (i, 3)) # loop the newest thread 3 times
time.sleep(5)                                 # prevents exit from parent too early
print 'Main thread exiting.'                  # all threads are destroyed by default
