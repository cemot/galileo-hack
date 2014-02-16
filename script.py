import json
json_data=open('data.json')

readings = json.load(json_data)
json_data.close()

BODY_TEMP_LOW = 97.5
BODY_TEMP_HIGH = 98.9
HEART_RATE_LOW = 60
HEART_RATE_HIGH = 100

body_temps, heart_rates, lat_readings, lon_readings = [], [], [], []

for reading in readings:
	if reading["Measurement"] == "bodytemp":
		body_temps.append(reading["Value"])
	elif reading["Measurement"] == "heartbeat":
		heart_rates.append(reading["Value"])
	elif reading["Measurement"] == "lat":
		lat_readings.append(reading["Value"])
	else:
		lon_readings.append(reading["Value"])

if len(body_temps) > 0:
	avg_body_temp = sum(body_temps) / len(body_temps)
else:
	avg_body_temp = -1

if len(heart_rates) > 0:
	avg_heart_rate = sum(heart_rates) / len(heart_rates) * 60
else:
	avg_heart_rate = -1;

if len(lat_readings) > 0:
	avg_lat = sum(lat_readings) / len(lat_readings)
else:
	avg_lat = -1

if len(lon_readings) > 0:
	avg_lon = sum(lon_readings) / len(lon_readings)
else:
	avg_lon = -1


# 0 is unhealthy, 1 is healthy
is_healthy = 0;
if avg_body_temp >= BODY_TEMP_LOW and avg_body_temp <= BODY_TEMP_HIGH and avg_heart_rate >= HEART_RATE_LOW and avg_heart_rate <= HEART_RATE_HIGH:
	is_healthy = 1;

f = open('info.js','w')
f.write('[{0} {1} {2} {3} {4}]'.format(avg_lat, avg_lon, avg_body_temp, avg_heart_rate, is_healthy))
f.close()

