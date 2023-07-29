from machine import Pin
import machine
import utime
from ssd1306 import SSD1306_I2C
from mpu6050 import accel

#初始化I2C0，服务于OLED屏幕
sda=Pin(25)
scl=Pin(26)
i2c=machine.I2C(0,sda=sda,scl=scl,freq=400000)
oled=SSD1306_I2C(128,64,i2c)

#初始化I2C1，服务于MPU6050
sda=Pin(27)
scl=Pin(14)
i2c1=machine.I2C(1,sda=sda,scl=scl,freq=40000)

#第二个参数为加速度最大量程
#0 ±2G   1  ±4G
#2 ±8G   3  ±16G
cgq=accel(i2c1,0)

BLOCK_SIZE=6
AREA_SIZE=48
AREA_X=80
AREA_Y=8
MOVE_SPAN=AREA_SIZE-BLOCK_SIZE

while True:
    v=cgq.get_values()
    acX=v['AcX']/16384.0
    acY=v['AcY']/16384.0
    acZ=v['AcZ']/16384.0
    coorY=int((acX+1)*0.5*MOVE_SPAN)
    coorX=int((acY+1)*0.5*MOVE_SPAN)
    #清空屏幕
    oled.fill(0)
    oled.text("acX:"+str(acX)[0:4]+"g",0,5)
    oled.text("acY:"+str(acY)[0:4]+"g",0,20)
    oled.text("acZ:"+str(acZ)[0:4]+"g",0,35)
    oled.rect(80,8,48,48,1)
    oled.fill_rect(AREA_X+coorX,AREA_Y+coorY,BLOCK_SIZE,BLOCK_SIZE,1)
    oled.show()
    utime.sleep(0.05)
