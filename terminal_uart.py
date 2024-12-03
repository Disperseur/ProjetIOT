import serial

print("*-----------------------Terminal UART Python-----------------------*\n")

num_port = input("Numero de port usb: ")
baudrate = int(input("Baudrate: "))

if(baudrate == 0):
    baudrate = 115200

print("Ouverture du port ...\n*------------------------------------------------------------------*")

try:
    port = serial.Serial(num_port, baudrate)
except:
    print("Erreur d'ouverture")
    while(1): pass

while(1):
    print(port.readline().decode())