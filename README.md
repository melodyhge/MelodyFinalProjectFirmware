[Uploading FinalProject_MelodyElHage_report.pdf…]()
________________________________________
Floor Elevator Controller System
Overview
This project involves the design and implementation of a 4-floor elevator controller system that demonstrates seamless integration of hardware and firmware for a reliable, efficient, and user-friendly solution. The system is designed to handle key operations, including floor selection, elevator movement, and real-time display of information such as temperature, time, and date.
This repository includes all the code, flowcharts, and block diagrams necessary for implementation and testing, as well as detailed documentation outlining the project methodology, challenges, and possible expansions.
________________________________________
Features
•	Floor Indication: Real-time floor display on 7-segment displays located on each floor and inside the cabin.
•	User Input: Buttons for UP/DOWN floor calls on each floor and dedicated floor selection buttons inside the cabin.
•	Direction Indicators: LED arrows indicate the elevator's movement direction (UP or DOWN).
•	Real-Time Data: Displays temperature (via LM35 sensor), time, and date (via I2C RTC module) inside the cabin.
•	Motor Control: Dual-speed and dual-direction motor operation for smooth and efficient elevator movement.
•	Safety Features: Error detection for invalid inputs, sensor failures, or motor malfunctions, with built-in safety protocols.
________________________________________
System Components
Hardware
1.	Microcontroller: PIC18F67K22 for managing inputs, outputs, and task scheduling.
2.	Sensors: 
o	LM35 Temperature Sensor for cabin temperature monitoring.
o	I2C-based Real-Time Clock (RTC) for time and date data.
3.	Motor: Dual-speed motor with PWM control for precision.
4.	Displays: 
o	7-Segment Displays for floor indication.
o	Cabin displays for real-time environmental data.
5.	Limit Switches: For precise floor alignment and position feedback.
6.	LED Indicators: Visual direction cues for elevator movement.
Firmware
The firmware is modular, ensuring efficient operation and scalability. Key modules include:
•	Input Handling: Processes user inputs and validates requests.
•	Motor Control: Handles motor direction and speed using PWM.
•	Data Management: Fetches and processes time, date, and temperature.
•	Output Management: Updates displays and indicators.
•	Error Handling: Detects faults and triggers safety mechanisms.
________________________________________
Project Structure
├── src/
│   ├── main.c               # Main code
│   ├── input_handling.c     # Input processing logic
│   ├── motor_control.c      # Motor control logic
│   ├── real_time_data.c     # RTC and LM35 data handling
│   ├── error_handling.c     # Error detection and safety protocols
│   └── utils.h              # Shared utilities and definitions
├── docs/
│   ├── abstract.md          # Project abstract
│   ├── block_diagrams/      # System architecture and workflows
│   ├── flowcharts/          # Input, motor, data, and error flowcharts
│   └── report.pdf           # Full project report
├── README.md                # Project documentation (this file)
________________________________________
Setup and Usage
Hardware Requirements
•	PIC18F67K22 Microcontroller
•	LM35 Temperature Sensor
•	DS1307 RTC Module
•	Dual-speed motor with driver circuit
•	7-Segment Displays and LEDs
•	Buttons and limit switches
Software Requirements
•	MPLAB X IDE for firmware development.
•	Proteus for simulation (optional).
•	Git for version control.
Steps to Run
1.	Clone this repository: 
2.	git clone https://github.com/melodyhge/MelodyFinalProjectFirmware.git
3.	Open the project in MPLAB X IDE.
4.	Connect the hardware components as per the block diagrams.
5.	Upload the firmware to the microcontroller.
6.	Test the system using the procedures outlined in the documentation.
________________________________________
Challenges Faced
•	Synchronization Issues: Optimized task scheduling for improved responsiveness.
•	Inconsistent Displays: Adjusted firmware timing for precise updates.
•	Limit Switch Calibration: Enhanced sensitivity for accurate floor alignment.
•	Temperature Sensor Noise: Implemented filtering for stable readings.
•	Motor Transitions: Fine-tuned PWM signals for smooth operation.
________________________________________
Future Expansions
1.	Support for More Floors: Scale for high-rise applications.
2.	Voice Announcements: Improve accessibility with audio cues.
3.	Advanced Emergency Features: Add battery backup, alarms, and emergency stops.
4.	Modern User Interface: Introduce touchscreen controls and dynamic displays.
5.	Load Monitoring: Incorporate weight sensors for enhanced safety.
________________________________________
Authors
•	Melody El Hage 
o	Email: melody.hage@net.usj.edu.lb
________________________________________

