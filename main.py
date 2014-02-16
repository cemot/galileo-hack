#!/usr/bin/env python


from mechanize import Browser

USER_AGENT = "Mozilla/5.0 (compatible; MSIE 10.0; Windows NT 6.2; Trident/6.0)"

br = Browser()
br.addheaders = [("User-agent", USER_AGENT)]

url = "https://manager.enableiot.com/sensors/login/loginPage.html"
br.open(url)

br.select_form(nr=0)
br['j_username'] = "donwshin@gmail.com"
br['j_password'] = "ilovepasswords"
br['company'] = "DoctorCloud"

response = br.submit()

print response.read()


f = br.retrieve(raw_input(), 'DoctorCloud.xls')[0]
print f