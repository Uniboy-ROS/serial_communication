import serial
from time import sleep
import sys

COM_PORT = '/dev/ttyUSB0'  # 請自行修改序列埠名稱
BAUD_RATES = 115200
ser = serial.Serial(COM_PORT, BAUD_RATES)

try:
    while True:
        # 接收用戶的輸入值並轉成小寫
        choice = input('按1.2加減綠、按4.5加減藍、3綠開、6藍開、7綠關、8藍關、e=close  ').lower()

        if choice == '1':
            print('傳送綠燈指令')
            ser.write(b'GLED_UP\n')  # 訊息必須是位元組類型
            sleep(0.5)              # 暫停0.5秒，再執行底下接收回應訊息的迴圈
        elif choice == '2':
            print('傳送綠燈指令')
            ser.write(b'GLED_DOWN\n')
            sleep(0.5)
        elif choice == '4':
            print('傳送藍燈指令')
            ser.write(b'BLED_UP\n')
            sleep(0.5)
        elif choice == '5':
            print('傳送藍燈指令')
            ser.write(b'BLED_DOWN\n')
            sleep(0.5)
        elif choice == '3':
            print('傳送綠燈指令')
            ser.write(b'GLED_ON\n')
            sleep(0.5)
        elif choice == '6':
            print('傳送藍燈指令')
            ser.write(b'BLED_ON\n')
            sleep(0.5) 
        elif choice == '7':
            print('傳送綠燈指令')
            ser.write(b'GLED_OFF\n')
            sleep(0.5)
        elif choice == '8':
            print('傳送藍燈指令')
            ser.write(b'BLED_OFF\n')
            sleep(0.5)    
        elif choice == 'f':
            print('閃爍一次')
            ser.write(b'flicker\n')
            sleep(1.7) 
        elif choice == 'e':
            ser.close()
            print('再見！')
            sys.exit()
        else:
            print('指令錯誤…')

        while ser.in_waiting:
            mcu_feedback = ser.readline().decode()  # 接收回應訊息並解碼
            print('控制板回應：', mcu_feedback)
            
except KeyboardInterrupt:
    ser.close()
    print('再見！')