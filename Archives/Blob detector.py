import cv2
import numpy as np
cap = cv2.VideoCapture(0)
cap.set(3,480)
cap.set(4,320)
kernelOpen = np.ones((5,5))
kernelClose = np.ones((20,20))

params = cv2.SimpleBlobDetector_Params()
params.filterByColor = False
params.filterByArea = True
params.minArea = 1000
params.maxArea = 8000
params.filterByInertia = False
params.filterByConvexity = False
params.filterByCircularity = True
params.minCircularity = 0.5
params.maxCircularity = 1

det = cv2.SimpleBlobDetector_create(params)
lower = np.array([101,174,44])
upper = np.array([147,255,255])

while True:
    ret,frame = cap.read()
    imgHSV = cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
    mask = cv2.inRange(imgHSV,lower,upper)
    maskOpen = cv2.morphologyEx(mask,cv2.MORPH_OPEN,kernelOpen)
    maskClose = cv2.morphologyEx(maskOpen,cv2.MORPH_CLOSE,kernelClose)
    maskFinal = maskClose
    blur = cv2.blur(maskFinal,(10,10))
    res = cv2.bitwise_and(frame,frame,mask=maskFinal)
    keypnts = det.detect(blur)
    cv2.drawKeypoints(frame,keypnts,frame,(0,255,),cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
    cv2.imshow('frame',frame)
    cv2.imshow('mask',maskFinal)
    for k in keypnts:
        Xpoint = int(keypnts[0].pt[0])
        print(Xpoint)
    if cv2.waitKey(1) & 0xff == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()