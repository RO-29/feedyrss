#!\usr\bin\python
#!C:\python27\python

# Import modules for CGI handling 
import cgi, cgitb,serial,sys

import MySQLdb as mdb

from dbconfig import *

#mySerial= serial.Serial('COM5',9600) #change port to  your setting.

# Create instance of FieldStorage 
form = cgi.FieldStorage() 

# Get data from fields
Name = form.getvalue('fname')
USERNAME=form.getvalue('email')
PASSWORD=form.getvalue('passwd')
FACEBOOKFEED=form.getvalue('fb')
gender="default"
con = None

con = mdb.connect(host,user,pwd,db_name);

with con:
			cur = con.cursor()
			sql= ("""INSERT INTO user_info(name,gender,gmail,fb,password) VALUES (%s,%s,%s,%s,%s)""", (Name,gender,USERNAME,FACEBOOKFEED,PASSWORD)) 
			cur.execute(*sql)
#confirmation 
print "Content-type:text/html\r\n\r\n"
print "<html>"
print "<head>"
print "<title>Confirm settings</title>"
print '<link rel=stylesheet href="//localhost/arduino/css/style.css">'
print "</head>"
print "<body>"
print "<h2>Hello %s</h2>" % (Name)
print "<h3>Gmail ID -<u>%s</u></h3>" % (USERNAME)
print "<h3>facebook_stream -<u>%s</u></h3>" % (FACEBOOKFEED)
print "<h3>Password-- <u>%s</u></h3> " % (PASSWORD)
#print "gender <u>%s</u>" % (gender)
print '<a href="//localhost/arduino/" class="edit">Proceed</a>' 
print "</body>"
print "</html>"
