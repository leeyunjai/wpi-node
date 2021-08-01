+ nodewpi npm
 - This is temporary package.

+ Environment
  - wiringPi 2.60
  - nodejs12,14 ...

+ Install
  - npm install nodewpi --unsafe-perm

+ Support functions
  - wpi.setup() : only wpi
  - wpi.pinMode(mode): wpi.INPUT|OUTPUT|PWM_OUTPUT
  - wpi.digitalWrite(pin, value): wpi.HIGH|LOW
  - wpi.digitalRead(pin):
  - wpi.pwmSetMode(mode): only wpi.PWM_MODE_MS
  - wpi.pwmSetClock(clock)
  - wpi.pwmSetRange(Range)
  - wpi.pwmWrite(pin, value)
  - wpi.softPwmCreate(pin, minRange, maxRange)
  - wpi.softPwmWrite(pin, value) 
