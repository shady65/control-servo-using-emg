
EMG Controlled Robotic Hand
Overview
This Arduino sketch is designed for controlling a robotic hand using electromyography (EMG) signals. The system uses five servo motors to mimic hand movements based on EMG readings from muscle contractions.

Components
Arduino Board
EMG Sensors
Servo Motors
Wires
Setup
Connect EMG sensors to analog pins A0 and A1 on the Arduino.
Connect servo motors to digital pins 3, 5, 6, 9, and 10 on the Arduino.
Connect digital pins 2-7 for mode selection switches.
Upload the provided Arduino sketch to the board.
Operation
Calibration Mode: Activate by pressing one of the mode selection switches (2-6). It records and calculates the mean value of the last 10 EMG readings.

Execution Mode: Activate by pressing the mode selection switch 7. It reads current EMG values, compares them with the calibrated means, and moves the robotic hand accordingly.

Test Mode: If no mode switch is pressed, the system enters test mode, displaying raw EMG values for debugging.

Movements
Open (0): Opens all fingers.
Fist (1): Closes all fingers into a fist.
Thumb (2): Closes thumb.
Love (3): Closes pinky and ring fingers.
Three (4): Closes index, middle, and thumb in a 'three' gesture.
Notes
The len constant defines the number of readings used for mean calculation.
Adjust the servo angles (o and c) based on your robotic hand's design.
