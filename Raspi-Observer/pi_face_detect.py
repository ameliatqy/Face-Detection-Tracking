from picamera.array import PiRGBArray
from picamera import PiCamera
import time
import sys
import imutils
import numpy as np
import cv2
import spidev
import io
import RPi.GPIO as GPIO




camera = PiCamera()
camera.resolution = (500,500)
camera.framerate = 2
raw_format = PiRGBArray(camera, size=(500,500))

face_cascade = cv2.CascadeClassifier('/home/pi/opencv/data/haarcascades/haarcascade_frontalface_default.xml')

time.sleep(0.2)
last_time = time.time()*1000

spi = spidev.SpiDev()
spi.open(0, 0)
spi.max_speed_hz = 500000 #7629
spi.mode = 0
spi.bits_per_word = 8

global main_bool
main_bool = True



def pause_program(channel):
    print("PAUSED")
    main_bool = False
    time.sleep(100)
    main_bool = True

GPIO.setmode(GPIO.BCM)
GPIO.setup(24, GPIO.IN)
GPIO.add_event_detect(24, GPIO.RISING, callback=pause_program)
    


def main():
    
    

    for frame in camera.capture_continuous(raw_format, format= "bgr", use_video_port=True):
        

#while(True):
    #stream = io.BytesIO()
    #camera.capture(stream, format= "jpeg")
    #data = np.fromstring(stream.getvalue(), dtype=np.uint8)
    #frame = cv2.imdecode(data, 1)
    
    #spi = spidev.SpiDev()
    #spi.open(0, 0)
    #spi.max_speed_hz = 500000 #7629
    #spi.mode = 0
    #spi.bits_per_word = 8

    #current_img = frame
        
        current_img = frame.array
        gray = cv2.cvtColor(current_img, cv2.COLOR_BGR2GRAY)
        faces = face_cascade.detectMultiScale(gray,
                                                  scaleFactor=1.1,
                                                  minNeighbors=5,
                                                  minSize=(30,30),
                                                  flags = cv2.CASCADE_SCALE_IMAGE)
    
        biggest_face = 0
        big_x = 0
        big_y = 0
        big_w = 0
        big_h = 0
        for (x,y,w,h) in faces:
            if w*h > biggest_face:
                biggest_face = w*h
                big_x = x
                big_y = y
                big_w = w
                big_h = h

        
        print(big_x, big_y)
        
        if big_x > 0 and big_y > 0 and GPIO.input(24) == 0:
            big_x_256 = int(big_x/256)
            big_y_256 = int(big_y/256)
            spi.xfer([big_x_256])
            time.sleep(0.05) #0.8
            spi.xfer([big_x])
            time.sleep(0.05) #0.8
            spi.xfer([big_y_256])
            time.sleep(0.05) #0.8
            spi.xfer([big_y])
            time.sleep(0.2) #1.5
            print("Detect")
        elif GPIO.input(24) == 1:
            time.sleep(1)
            

    #spi.close()
    
    #cv2.rectangle(current_img,(big_x,big_y),(big_x+big_w,big_y+big_h),(255,0,0),2)
    #roi_gray = gray[big_y:big_y+big_h, big_x:big_x+big_w]
    #roi_color = current_img[big_y:big_y+big_h, big_x:big_x+big_w]
    #cv2.imshow('img', current_img)


    
        key = cv2.waitKey(1) & 0xFF

        raw_format.truncate(0)

        if key == ord("q"):
            break

           

if __name__=="__main__":
    main()

#    for (x,y,w,h) in faces:
#        cv2.rectangle(current_img,(x,y),(x+w,y+h),(255,0,0),2)
#        roi_gray = gray[y:y+h, x:x+w]
#        roi_color = current_img[y:y+h, x:x+w]
    
