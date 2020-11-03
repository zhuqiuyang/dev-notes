ls *.perl | awk -F "." '{print "mv " $1 ".perl " $1".pl"}' | bash
