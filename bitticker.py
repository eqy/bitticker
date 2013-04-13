import serial
import urllib.request
from bs4 import BeautifulSoup
import time

ser = serial.Serial('/dev/ttyACM0', 9600)
        
while True:
        try: 
          page = urllib.request.urlopen('https://mtgox.com')
          break
        except IOError as e:
          if e.args[1].args[0].errno != errno.ECONNRESET:
             raise
        soup = BeautifulSoup(page);
        result = soup.find(id='lastPrice').span.contents[0]
        print(result[1:])

        #Write to Arduino
        ser.write(result[1:].encode('utf-8'))
        time.sleep(30)
        
        
