import xlrd
from collections import OrderedDict
import simplejson as json
 
# Open the workbook and select the first worksheet
wb = xlrd.open_workbook('DoctorCloud.xls')
sh = wb.sheet_by_index(0)
 
# List to hold dictionaries
cars_list = []
 
# Iterate through each row in worksheet and fetch values into dict
for rownum in range(1, sh.nrows):
    cars = OrderedDict()
    row_values = sh.row_values(rownum)
    cars['Time'] = row_values[0]
    cars['Device'] = row_values[1]
    cars['Measurement'] = row_values[2]
    cars['Value'] = row_values[3]
    cars['Lat'] = row_values[4]
    cars['Long'] = row_values[5]
 
    cars_list.append(cars)
 
# Serialize the list of dicts to JSON
j = json.dumps(cars_list)

# Write to file
with open('data.json', 'w') as f:
    f.write({j})
