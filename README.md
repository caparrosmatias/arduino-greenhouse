# Arduino Greenhouse :seedling:
## Automated Greenhouse with Arduino

![logo](https://raw.githubusercontent.com/caparrosmatias/arduino-greenhouse/master/logo_greenhouse.jpg)

### Greenhouse for the production of crops from stakes, with adjustable temperature range and irrigation timing.

The temperature range must be between Tmin and Tmax. The system through a temperature sensor (LM35), register every 10 minutes the temperature provided by the sensor. With this data the controller can perform 3 tasks depending on the temperature that exists (1):

- If the temperature is within the indicated range, wait 10 minutes and check again.

- If the temperature is LOWER than indicated in the program, turn on the heating cable, and chech again in 10 minutes, returning to 1.

- If the temperature is HIGHER than indicated in the program, turn on the fan, and in 10 minutes check again, returning to 1.

Independently of all this process, the irrigation will be performed, activating an output of the controller that corresponds to the irrigation pump, this will be done every a certain time (Triego), keeping that output on for 15 seconds.

![logo](https://raw.githubusercontent.com/caparrosmatias/arduino-greenhouse/master/greenhouse.jpg)

This project was made from scratch for a client.
