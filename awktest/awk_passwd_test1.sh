#多个字段

awk -F ":" '{print $1 $3}' /etc/passwd


awk -F ":" '{print "username="$1 "\t\t\tuid="$3}' /etc/passwd

#两种方法的区别在于如何设置字段分隔符。在该脚本中，（通过设置 FS 变量）在代码中指定字段分隔符，而前一示例通过在命令行向 awk 传递 -F":" 选项来设置 FS。一般而言，最好在脚本内部设置字段分隔符，因为这样可以少输入一个命令行参数。本文稍后将深入讲解 FS 变量。

# BEGIN { FS ":" } { print $1 }

#/foo/ {print}

#/[0-9]+\.[0-9]*/ { print }

#$5 ~ /root/ { print $3 }
