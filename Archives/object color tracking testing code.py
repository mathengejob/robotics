import cv2
import numpy as np
cap = cv2.VideoCapture(0)

while True:
    _,frame = cap.read()
    hsv_frame = cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
    lower = np.array([0,202,33])
    upper= np.array([120,255,255])
    mask = cv2.inRange(hsv_frame,lower,upper)
    contours,hierarchy = cv2.findContours(mask,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
    countours = sorted(contours,key = lambda x:cv2 .contourArea(x),reverse = True)
    position = 0
    for cnt in contours:
        (x,y,w,h) = cv2.boundingRect(cnt)
        cv2.rectangle(frame,(x,y),(x+w,y+h),(0,255,0),2)
        position = int((x+x+w)/2)
        break
    cv2.imshow('frame',frame)
    cv2.imshow('mask', mask)
    key = cv2.waitKey(1)

    if key == 27:
        break
cap.realease()
cv2.destroyAllWindows()