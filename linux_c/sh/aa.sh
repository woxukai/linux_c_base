#!/bin/bash
cd ~
. ~/.profile

num=$#
echo num=$num

function aa()
{
	#result=$1 + $2
	aa=11
	bb=22
	#re=$aa+$bb
	echo $re

	let re=$aa+$bb
	echo $re

	re=`expr $aa + $bb`
	echo $re

	return 0
}

#list='$1 $2'
aa 11 22
