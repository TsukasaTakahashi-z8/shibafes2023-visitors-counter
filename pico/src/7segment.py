from machine import Pin, I2C, UART
import time

def main():
    uart = UART(0, 2400);

    while True:
        buffer = uart.read(1)

        display(buffer)

def display(num):
    bits = [
        0x3f,
        0x06,
        0x5b,
        0x4f,
        0x66,
        0x6d,
        0x7d,
        0x07,
        0x7f,
        0x67  
    ]
    
    

if __name__ == "__main__":
    main()
