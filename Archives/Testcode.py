# ROBOKEN 2021 PYTHON CODE
import serial
import time
import cv2
import numpy as np
import RPi.GPIO as GPIO

ser = serial.Serial("/dev/ttyACM0", 9600, timeout=1)
cap = cv2.VideoCapture(0)
cap.set(3, 480)
cap.set(4, 320)
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
trig = 20
echo = 21
GPIO.setup(trig, GPIO.OUT)
GPIO.setup(echo, GPIO.IN)
lower_red = [101, 49, 121]
upper_red = [12, 255, 255]
lower_blue = [101, 174, 41]
upper_blue = [147, 255, 255]
kernelOpen = np.ones((5, 5))
kernelClose = np.ones((20, 20))

d = 0  # variable to control the sequence of the tasks

def blob_detector(Lower, Upper):
    params = cv2.SimpleBlobDetector_Params()
    params.filterByColor = False
    params.filterByArea = True
    params.minArea = 2000
    params.maxArea = 10000
    params.filterByInertia = False
    params.filterByConvexity = False
    params.filterByCircularity = True
    params.minCircularity = 0.5
    params.maxCircularity = 1
    det = cv2.SimpleBlobDetector_create(params)
    lower = np.array(Lower)
    upper = np.array(Upper)
    ret, frame = cap.read()
    imgHSV = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    mask = cv2.inRange(imgHSV, lower, upper)
    maskOpen = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernelOpen)
    maskClose = cv2.morphologyEx(maskOpen, cv2.MORPH_CLOSE, kernelClose)
    maskFinal = maskClose
    blur = cv2.blur(maskFinal, (10, 10))
    res = cv2.bitwise_and(frame, frame, mask=maskFinal)
    keypnts = det.detect(blur)
    cv2.drawKeypoints(frame, keypnts, frame, (0, 255, 0), cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
    #cv2.imshow('frame',frame)
    position = 0
    setpoint = 252
    for k in keypnts:
        position = int(keypnts[0].pt[0]) # x axis position of the object
    error = setpoint-position
    if error > -5 and error < 5:
        error = 0
    print(error)
    """valList = str(error), str(error)
    sendStr = ',' .join(valList)
    ser.write(sendStr.encode('utf-8'))"""

def distance_sonic():
    GPIO.output(trig, True)
    time.sleep(0.0001)
    GPIO.output(trig, False)
    while GPIO.input(echo) == 0:
        pulse_start = time.time()
    while GPIO.input(echo) == 1:
        pulse_end = time.time()
    pulse_duration = pulse_end - pulse_start
    distance = pulse_duration*17150
    distance = round(distance, 2)
    return distance

def send_data(x, y, z):  # function tested and working
    a = x
    b = y
    c = z
    valList = str(a), str(b), str(c)
    sendStr = ',' .join(valList)
    print(sendStr)
    ser.write(sendStr.encode('utf-8'))
    time.sleep(0.1)

def armcontrol(angle1, angle2, angle3, time):
    servol1 = angle1
    servol2 = angle2
    servol3 = angle3
    wait_time = time
    time.sleep(wait_time)  # wait for the arm to move to the new position
    valList = [str(servol1), str(servol2), str(servol3)]
    sendStr = ',' .join(valList)
    ser.write(sendStr.encode('utf-8'))

def Send_Data(x):  # Send single data stream
    a = x
    valList = str(a), str(a)
    sendStr = ',' .join(valList)
    ser.write(sendStr.encode('utf-8'))


def receive_data():  # receive three data from arduino and return the sum
    a = 0
    b = 0
    c = 0      # function tested and working
    val = ser.readline().decode('utf-8')
    # time.sleep(0.5)
    parsed = val.split(',')
    parsed = [x.rstrip() for x in parsed]
    if(len(parsed) > 2):
        # print(parsed)
        a = int(parsed[0]+'0')/10
        b = int(parsed[1]+'0')/10
        c = int(parsed[2]+'0')/10
    return (a+b+c)   # return the sum of the three data

def Camera(Lower, Upper):  # function to accept two lists arguments lower and upper values of color
    _, frame = cap.read()  # function tested works well with a usb web cam
    hsv_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    lower = np.array(Lower)
    upper = np.array(Upper)
    # cv2.imshow('frame',frame)
    mask = cv2.inRange(hsv_frame, lower, upper)
    contours, hierarchy = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    countours = sorted(contours, key = lambda x:cv2 .contourArea(x),reverse = True)
    position = 0
    for cnt in contours:
        (x, y, w, h) = cv2.boundingRect(cnt)
        position = int((x+x+w)/2)
        break
    set_point = 285  # Find suitable set point
    error = set_point-position
    if error > -5 and error < 5:
        error = 0
    power = (kp*error)
    if power > 255:
        power = 255
    if power <- 255:
        power = -255
    print(power)
    return power


while True:
  # send_data(4,4,4)
  # time.sleep(5)
  # d = receive_data()
  # time.sleep(2)
  # send_data(5,5,5)
  # time.sleep(5)
  # p=Camera(lower_red,upper_red)
  # ser.flush()
  # blob_detector(lower_blue, upper_blue)

  """ if d == 0: # wait for data from arduino
        d = receive_data()
  elif d == 3:
      power = 23
      print(power)
      time.sleep(1)
       # search for blue container
      d = 0
  """
