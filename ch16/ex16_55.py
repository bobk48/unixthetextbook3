from threading import Thread, Condition                       #Block 1.
import time
import random
buffer = []
MAX_NUM = 10
condition = Condition()

class Producer(Thread):                                       #Block 2.
      def run(self):
            global buffer
            for i in range(10):
                  condition.acquire()
                  if len(buffer) == MAX_NUM:
                        print "Queue full, Producer waiting"
                        condition.wait()
                        print "Queue empty, Producer notified"
                  buffer.append(i)
                  print "Data Produced", i
                  condition.notify()
                  condition.release()
                  time.sleep(random.random())

class Consumer(Thread):                                       #Block 3.
      def run(self):
        global buffer
	for i in range(10):
                   condition.acquire()
                   while not buffer:
                         print "Queue empty, Consumer waiting"
                         condition.wait()
                         print "Data added to queue, Consumer notified"
                   i = buffer.pop(0)
                   print "Data Consumed", i
                   condition.notify()
                   condition.release()
                   time.sleep(random.random())

Producer().start()                                            #Block 4.
Consumer().start()
