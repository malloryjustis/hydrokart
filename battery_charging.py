#import things need to import

#use crontab?

#run through this every _____ minutes

#define maximum battery limit
max_battery_limit = 

battery_1_signal = #import signal from battery1

if battery_1_signal >= max_battery_limit:
  #close circuit to battery 1
  print('battery 1 charge completed')
  
  if battery_2_signal < max_battery_limit:
  #open circuit to battery 2
  
else return

if battery_2_signal >= max_battery_limit:
    #close circuit to battery 2
    print('battery 2 charge completed')
    
    if battery_3_signal < max_battery_limit:
    #open circuit to battery 3
    
else #keep running current to battery 2

if battery_3_signal >= max_battery_limit:
  # close circuit to battery 3
  print('battery 3 charge completed')
  
  if battery_4_signal < max_battery_limit:
  #open circuit to battery 4
  
if battery_4_signal >= max_battery_limit:
  #close circuit to battery 4
  print('battery 4 charge completed')
  

