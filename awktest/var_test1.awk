awk 'BEGIN {test="hello";print test}'
#awk -F: '{print "%s\n",$1 }' /etc/fstab

#多行注释
<< 'COMMENT'
N : 显示宽度
- : 左对齐（默认为右对齐）
+ : 显示数值符号
COMMENT

awk -F: '{printf "username=%s,uid=%d\n",$1,$3 }' /etc/passwd
awk '/^UUID/{print $1}' /etc/fstab
awk '{print NR}' /etc/fstab
awk 'END {print NR}' /etc/fstab
