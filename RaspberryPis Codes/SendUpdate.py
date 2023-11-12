import serial
from time import sleep

with open("/home/michael/FOTA/Flag.txt","r") as file:
       flagValue=file.read()
ser = serial.Serial('/dev/ttyS0', baudrate=9600,
                    parity=serial.PARITY_NONE,
                    stopbits=serial.STOPBITS_ONE,
                    bytesize=serial.EIGHTBITS
                    )
    
f=0
if flagValue=="1":
    print("start Send Update")
    
    while f==0:
        print(flagValue)
        ser.write(flagValue.encode("utf-8"))
        received_data = ser.read()              #read serial port
        sleep(0.03)
        data_left = ser.inWaiting()             #check for remaining byte
        received_data += ser.read(data_left)
        received_data=received_data.decode("utf-8")
        print(received_data)
        if received_data=='ok':
            f=1

    text_file=open("/home/michael/FOTA/Updatefile/weird.hex","r")
    lines =text_file.readlines()

    x=0
    while x<len(lines):
        print(lines[x])
        ser.write(lines[x].encode("utf-8"))
        received_data = ser.read()              #read serial port
        sleep(0.03)
        data_left = ser.inWaiting()             #check for remaining byte
        received_data += ser.read(data_left)
        received_data=received_data.decode("utf-8")
        print(received_data)
        if received_data=='ok':
            x+=1
    text_file.close() 
elif flagValue=='0':
    print('no updates')
    while f==0:
        print(flagValue)
        ser.write(flagValue.encode("utf-8"))
        received_data = ser.read()              #read serial port
        sleep(0.03)
        data_left = ser.inWaiting()             #check for remaining byte
        received_data += ser.read(data_left)
        received_data=received_data.decode("utf-8")
        print(received_data)
        if received_data=='ok':
            f=1
                    
   
