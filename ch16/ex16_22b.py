#!/usr/local/bin/python
import os
if os.path.isdir("/usr/bin"):
    print "/usr/bin is a directory"
else:
    print "/usr/bin is not a directory"
