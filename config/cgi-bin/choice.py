#!\usr\bin\python
#!C:\python27\python.exe

import sys
import MySQLdb as mdb
import serial
from dbconfig import *
con = mdb.connect(host,user,pwd,db_name);

with con:
         cur=con.cursor()
         cur.execute('select gmail from user_info where rid=1')
         USERNAME=cur.fetchone()[0]
         cur.execute('select password from user_info where rid=1')
         PASSWORD=cur.fetchone()[0]
         cur.execute('select fb from user_info where rid=1')
         FACEBOOKFEED=cur.fetchone()[0]
         cur.execute('select NAME from user_info where rid=1')
         NAME=cur.fetchone()[0]
         PROTO="https://"
         SERVER="mail.google.com"
         PATH="/gmail/feed/atom/important"
         i=0
         j=0
         MAX=25
         mySerial= serial.Serial('COM5',9600) #change port to  your setting.
