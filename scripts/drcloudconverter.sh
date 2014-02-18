#!/bin/bash
sudo rm -r ./data.json
sudo rm -r ./DoctorCloud.xls
sudo rm -r ./info.js
thisdate=$(date +%s)
first="https://manager.enableiot.com/sensors/servlet/GraphFileDownloadServlet?customerName=DoctorCloud&deviceIds=251561%2C251561%2C&metricNames=lon%2Clat%2Cheartbeat%2Cbodytemp%2C&endDate="
second="&startDate="
two=400
third=$(expr $thisdate - $two)
fourth="&maxPoints=800"
zero=000
echo test1
sudo echo $first$thisdate$zero$second$third$zero$fourth | python ./main.py 
echo test2
echo "test3"
sudo python ./pypypy.py
sudo python ./script.py
exit 0
