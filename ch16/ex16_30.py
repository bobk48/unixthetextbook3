#!/usr/local/bin/python
import os
import shutil
target = "/usr/home/bob/USBint/"
i = 1
while i <= 5:
    temp_path = target + str(i) + "/"
    if not os.path.exists( temp_path ):
        try:
            os.makedirs( temp_path )
            print "Created  " + temp_path
        except:
            print " Could not create  " + temp_path
    i = i + 1
print "Deleting the oldest archive"
shutil.rmtree( target + "5" )
print "Recycle the backups"
os.rename( target + "4", target + "5" )
os.rename( target + "3", target + "4" )
os.rename( target + "2", target + "3" )
os.system('cp -a ' + target + "1" + " " + target + "2")
os.system('rsync -av /usr/home/bob/python/' + " " + target + "1")
