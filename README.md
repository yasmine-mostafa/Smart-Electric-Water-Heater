# Smart-Electric-Water-Heater
## Objectives:
Control the temperature of water with reference to a set temperature which the user enters, using Atmega32.
## Features:
### Heating Elements:
- Heating Element is turned ON, if current water temperature is less than the set temperature by 5 degrees.
- Heating Element is turned OFF, if current water temperature is greater than the set temperature by 5 degrees.
- Cooling Element is turned ON, if current water temperature is greater than the set temperature by 5 degrees.
- Cooling Element is turned OFF, if current water temperature is less than the set temperature by 5 degrees.
### Seven Segment:
- Seven Segment by default shows the current water temperature.
- If the water heater is in the temperature setting mode, the 2 seven segments should blink every 1 second and show the set temperature.
### Buttons:
- Up and Down buttons should increase/decrease the set temperature by 5 degrees.
### EEPROM:
- An external EEPROM should save the set temperature once set.
- if the electric water heater is turned off then on, then the stored set temperature should be retrieved from the external EEPROM.
### Temperature Sensor:
- The temperature sensor measures the water temperature every 100 ms.
- The decision to turn ON or OFF the heating elements is based on the average of the last 10 temperatures.
