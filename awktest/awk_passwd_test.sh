#在 Awk 中，当 print 命令单独出现时，将打印当前行的全部内容。
awk '{print $0}' /etc/passwd

#在 Awk 中，变量 $0 表示整个当前行，因此 print 和 print $0 的作用完全相同。
awk '{print}' /etc/passwd

awk '{ print "xukai,nihao" }' /etc/passwd
