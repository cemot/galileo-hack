#!/usr/bin/env python


from mechanize import Browser

USER_AGENT = "Mozilla/5.0 (compatible; MSIE 10.0; Windows NT 6.2; Trident/6.0)"

br = Browser()
br.addheaders = [("User-agent", USER_AGENT)]

url = "https://manager.enableiot.com/"
br.open("url")

br.select_form(nr=0)
br['username'] = "donwshin@gmail.com"
br['password'] = "ilovepasswords"
br['account'] = "Doctor Cloud"

response = br.submit()

print response.read()

(filename, headers) = br.retrieve(url, filename)
f = br.retrieve('https://manager.enableiot.com/sensors/servlet/GraphFileDownloadServlet?customerName=DoctorCloud&deviceIds=251561%2C251561%2C&metricNames=bodytemp%2Cheartbeat%2C&endDate=1392577840000&startDate=1392577440000&maxPoints=800')[0]
print f 