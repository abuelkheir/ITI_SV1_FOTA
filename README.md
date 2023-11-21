# ITI_SV1_FOTA
This project was a graduation project for ITI's Embedded Systems Intensive track Intake 3.
The main foucs was on developing a vehicle firmware update system(FOTA), including a custom STM32 microcontroller bootloader, a secure web-based server for updates, and enhanced vehicle features of parking assistance and auto parking.
Product Features: 
Bootloader:
1. Develop a customized bootloader for STM32 microcontrollers to facilitate firmware updates in vehicles.
2. Modify the linker script to accommodate the updated application code.

Web Application & FTP Server:
3. Create a user-friendly web-based server using HTML, CSS, and Javascript as an interface for uploading firmware updates to the vehicle.
4. Employ Hybrid encryption technique (AES & RSA) to ensure the security and integrity of update files during transmission.

Application (Vehicle):
5. Design and build a vehicle system based on the STM32 microcontroller, focusing on primary obstacle avoidance using ultrasonic sensors.
6. Develop a Bluetooth driver to enable remote control of the vehicle via a mobile phone.
7. After firmware updates, introduce additional features:
   - A) Implement a configurable speed limit for the vehicle to enhance safety.
   - B) Enable parking assistance using a combination of ultrasonic and IR sensors, accompanied by a buzzer for audio feedback.

