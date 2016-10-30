import thread
def child(tid):
     print 'Started thread', tid
def parent():
     i = 0
     while 1:
        i += 1
        thread.start_new_thread(child, (i,))
        if raw_input() == 'x': break
parent()
