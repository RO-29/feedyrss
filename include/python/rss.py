#!C:\python27\python
#!\usr\bin\python
#delete any of the above line depending on your system...


import feedparser,serial,sys
from settings import *
g=0
f=0
maxd=MAX
while MAX:
        gmail = feedparser.parse(PROTO + USERNAME + ":" + PASSWORD + "@" + SERVER + PATH)
        total_g = len(gmail.entries)
        facebook = feedparser.parse(FACEBOOKFEED)                here feedparser does the hard work of loasding the rss feed
        total_f = len(facebook.entries)
        g_n=("(""mail {"+ str(i+1) + "/"+ str(maxd)+ "}"")")
        f_n=("(""fb{"+ str(i+1) + "/"+ str(maxd)+ "}"")")
        if total_g>0:
                gmail_latest = gmail.entries[i]
                g_title = gmail_latest.title
                g_author = gmail_latest.author
                print (g_n)
                print (g_title)        
                print (g_author)
                print("")
                i+=1
                mySeiral.write('<')
                mySerial.write("[{0}]{1} {2} ".format(g_n,g_author,g_title))
                time.sleep(30)

        elif (total_g ==0 and g==0) or total_f==0:
                   print("hey no mail! sorry :p")
                   mySerial.write('0')
				   g=1
        if total_f>0:
               mySerial.write('>')
               noti = facebook['items'][j].title
               print(f_n)
               print(noti) 
               print("") 
               j+=1
               mySerial.write(f_n)
               mySerial.write(noti)         
               time.sleep(30) 
       
        i+=1
		MAX=MAX-1
