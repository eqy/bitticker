import urllib.request
from bs4 import BeautifulSoup

page = urllib.request.urlopen('https://mtgox.com')
soup = BeautifulSoup(page);
result = soup.find(id='lastPrice').span.contents[0]
print(result[1:])
