# FourChannelAdapter
The tango server for the custom PNPI controller for four channel of steps motors, using serial port RS485 2Wire.


## Class properties:
#### 1. DevicePath - String type
The path to serial device file (also as /dev/ttyMI[0..7] for Moxa devices)
#### 2. ControllerNumber - int type
Just number (aka address) of controller

## Device properties:
#### 1. Speed - int type
Speed of motor in Hz.
#### 2. Channel - int type 
Channel of motor from 0 to 3 (4 channels).
#### 3. ZeroPosition - double type
Zero position in physical units.
#### 4. CoeffToUnit - double type
coefficient for translate steps to physical units.
#### 5. Stepping
#### 6. Accelerate
Accelerate for start and stop the motor. 

## Commands:
#### 1. StopMove (void)
Turns off power and stops movement.
#### 2. MoveToLeftSteps (int steps_count)
#### 3. MoveToRightSteps (int steps_count)
#### 4. SetCurrentPosAsZero (void)

## Attributes:
#### 1. Position - double type
Current position in the abstract units (depends on CoeffToUnit)
#### 2. ZeroPosition - double type


## Install:
1. git clone https://github.com/tre3k/FourChannelAdapter
2. cd FourChannelAdapter
3. mkdir build && cd build
4. cmake ../ && make
5. TANGO_HOST=tango-host:port ./FourChannelAdapter <instance name>
  
## Regestration in jive:
