feedyrss
========
An python web app + arduino project micro 

<a href="http://youtu.be/hri3XFPpZcE" target=_blank>See the feedy in action!</a>
Contact
=======
<a href="//www.facebook.com/rohit.jain.1993" target=_blank>Facebook</a>
Email-rj.2929@yahoo.com 

Description
========

Lcd will show rss feeds from facebook + gmail  + blink led(s) (different leds for different streams ) + play sound 

you have to first burn the arduino code located in arduino sketch directory (for geting started on arduino <a href="http://arduino.cc/en/Guide/HomePage" target=_blank>
see</a> )

Circuit diagram and more refer (<a href="http://www.aungthiha.me/2012/04/physical-priority-gmail-notifier-and.html target=_blank">here </a>)

I have also taken the arduino code (and made my changes located in arduino sketch) and circuit diagram  from above site!!
 
I have also tried to make a simple web app for configuring the user info ...!!
just paste the contents of cgi bin folder located in config folder into you cgi-bin folder and remaining files in your public_html folder...
and rest you can figure it out ....

Change some setttngs in settings.py -(com port or dev device(linux)) 
Open rss.py to make neccesary changes located in python folder 
Change neccessary database settings in dbconfig.py located in config folder
Also make sure to install the neccesary dependencies in dependencies folder
Software required -- arduino + python + its dependencies
Hardware required -Arduino uno board + leds + pizo speaker +lcd +wires 
  
