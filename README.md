# Bank-Door
This system constitutes a security solution for a bank door. When an individual wants to enter, the external ultrasonic sensor detects their presence and automatically opens the door. Then, the door closes, and a LED illuminates. If another individual attempts entry while someone is already inside, the system prevents access, maintaining the interior's security. To exit, the person inside must press a button; the door will open automatically. Following the person's exit, the LED indicator and the door will automatically close.

The system includes:
  - 2 Ultrasonic Senser - one external to detect the presence outside
                         - one inside to detect the presence inside
  - 1 Servo Motor - to open the door
  - 1 LED - to illuminate when someone is inside


The system was create using Node-RED Application and MQTT Protocol. Node-RED was utilized for developing the logic and workflow of the system, while MQTT protocol facilitated communication and data exchange between different components.
