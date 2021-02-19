# Ball-n-Plate
This is code used to run the Ball n Plate project, built as a part of the Applied physics and electronics section in Mathematical Grammar School (Belgrade, Serbia)

The idea of the project is to have a flat plate (made out of cardboard) ballance the ping pong ball. There are several parts to this process.

First, a web camera is set above the plate to record it at all times. Video from camera is analysed by python code in order to find the position of the ball. Coordinates are sent to the Arduino, which is connected to the PC via serial connection. Arduino is used to move the servo motors in order to prevent the ball from falling. PID controller was used to determine how should the motors be moved based on the position of the ball. The scheme of the setup can be seen in the picture below.


