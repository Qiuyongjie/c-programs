#!/bin/bash 

# ./init.sh [opt]
# opt -no
#
#


IFND=#ifndef
DEF=#define
ENDIF=#endif 

INCL=#include 
_TH=__TYPE_H__
TH=\"type.h\"
_COMMONH=__COMMON_H__
COMMON=\"common.h\"
GH="<stdio.h>"

OBJTH=type.h
OBJCH=common.h
OBJCF=function.c
OBJCS=main.c

#options
	if [ $1 = "-n" ]; then
		echo "quiet"
	elif [ $1 = "-t" ]; then 
		echo "type head file $2"
		OBJTH=$2;
	elif [ $1 = "clean" ]; then
		rm ./
	else 
		echo "usage: "
	fi


#create type.h
	echo $IFND " " $_TH > $OBJTH
	echo $DEF  " " $_TH >> $OBJTH
	echo $INCL " " $GH  >> $OBJTH
	echo $ENDIF "" >> $OBJTH

#create common.h
	echo $IFND " " $_COMMONH > $OBJCH
	echo $DEF  " " $_COMMONH >> $OBJCH
	echo $INCL " " $GH >> $OBJCH
	echo $INCL " " $TH >> $OBJCH
	echo $ENDIF " " >> $OBJCH
#create function.c
	echo $INCL " " $COMMON > $OBJCF
	
#create main.c 
	echo $INCL " " $GH  > $OBJCS
	echo $INCL " " $COMMON >> $OBJCS
	echo "int main() { printf(\"lalala\n\"); return 0;}" >> $OBJCS
	indent -kr -i8 $OBJCS


