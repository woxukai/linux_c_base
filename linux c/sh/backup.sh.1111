####################################################################
#生成日期: 20170807
#项目说明：backup脚本
#开发人员:cary
#维护日期:20170808
####################################################################

cd ~
. ~/.profile

#判断入参的总数是否小于1
if [ $# -lt 1 ]
then
	echo '输入参数个数不对,脚本格式为:' $0 '交易类型 参数'
	exit -1
fi

#变量赋值
#shlib动态库原目录
echo "HOME目录是:" $HOME 
SHLIB_ORG_DIR=$HOME/shlib
echo $SHLIB_ORG_DIR

#备份动态库目录
SHLIB_BACKUP_DIR=$HOME/backup/shlib
echo $SHLIB_BACKUP_DIR

#备份数据的操作类型
BACKUP_CZLX=$1

#输入参数的总数
g_iCnt=$#
echo "入参总数="$#
echo "g_iCnt="$g_iCnt

#######################################
#交易类型定义
#######################################
arr_backup_czlx=("1")
arr_backup_czlxsm=("shlib备份")

SHLIB_BACKUP_CZLX=1

#######################################
#接口说明:入参数据保存
#开发人员:cary
#开发日期:20170808 1757
#修改日期:20170808
#######################################
iflag=0;

for var in $*;
do
	echo $var
	g_arr_rc[iflag]=${var};
	let iflag++
done

g_arr_rc_len=${#g_arr_rc[@]}
echo "g_arr_rc_len="$g_arr_rc_len
 
####################################################################
#函数名称: Check_RCSJ
#函数说明：判断入参数据个数
#输入:$1 操作类型 $2 输入需要处理参数的数目
#返回值:无
#开发人员:cary
#开发日期:20170807 1805
#维护日期:20170809 1805
#
####################################################################

function Check_RCSJ()
{
    if [ '$BACKUP_CZLX' = '$1' ]
    then
        if [ $2 -lt 1 ]
		then 
			echo "未输入需要备份的数据内容"
		fi
    fi
}


####################################################################
#函数名称: CheckDirIsExist
#函数说明：判断指定目录是否存在,如果不存在，创建指定目录
#入参:BACKUP_CZLX 目录类型：1:shlib类型 
#返回值:无
#开发人员:cary
#开发日期:20170807 1805
#维护日期:20170807 1805
#
####################################################################

function CheckDirIsExist()
{
	if [ $BACKUP_CZLX = '$SHLIB_BACKUP_CZLX' ]
	then
		Check_Shlib_DirIsExist 
	fi
}

####################################################################
#函数名称: Check_Shlib_DirIsExist
#函数说明：判断shlib备份目录是否存在，如果不存在，创建shlib指定目录
#入参:无
#返回值:无
#开发人员:cary
#开发日期:20170808
#维护日期:20170808
#
####################################################################

function Check_Shlib_DirIsExist()
{
	if [ ! -d '$SHLIB_BACKUP_DIR' ]
	then
		mkdir '$SHLIB_BACKUP_DIR'
	fi
}


####################################################################
#函数名称: Shlib_BackUp
#函数说明：shlib 动态库进行备份
#入参:BACKUP_CZLX 需要备份的数据
#返回值:无
#开发人员:cary
#开发日期:20170808
#维护日期:20170808
#
####################################################################
function Shlib_BackUp()
{
	soname=$1
	cp -f $SHLIB_ORG_DIR/$soname $SHLIB_BACKUP_DIR/$soname
}

##################################################################
    #for i in $(seq 2 $g_iCnt)
    #do
    #   if [ -n $i ];then
    #       echo "i=$i"
    #       echo $i
    #       Shlib_BackUp $($i)  #备份操作
    #   fi
    #done
###################################################################



#判断shlib是否存在
CheckDirIsExist $BACKUP_CZLX

let iNum=$#-1; 
echo "需要处理的数据个数:$iNum"
Check_RCSJ $BACKUP_CZLX $iNum

if [ $BACKUP_CZLX = $SHLIB_BACKUP_CZLX ]
then	
	echo "备份动态库开始"
	j=1 
	while [[ j -lt $g_arr_rc_len ]]
	do
		echo "g_arr_rc[$j]="${g_arr_rc[j]}
		Shlib_BackUp ${g_arr_rc[j]}  #备份操作
		let j++
	done
	

#	for var in $*;
#	do
#		echo "XXXXX　varI="$var
#		if [ -n ${var} ]
#		then
#			Shlib_BackUp ${var}  #备份操作
#		else
#			echo "varI="$var
#		fi
#	done
    
#	exit;
#	while [ -n ${i} ]
#	do
#		echo $2
#       	echo "第i个参数值=$i"
#       	Shlib_BackUp ${#i}  #备份操作
#		let i=i+1;
#		break;
#	done
	echo "备份动态库结束"
else
	echo "$BACKUP_CZLX 交易类型暂不支持"
fi
