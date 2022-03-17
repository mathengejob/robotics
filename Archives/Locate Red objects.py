import cv2
import numpy as np
 
x = 0 # variable to store the x-coordinate of the object
set_point = 300 # variable to store set_point
totalError=0
kp=1
ki=0
kd=0
 
cap = cv2.VideoCapture(0)
 # setup detector and paramaters
params = cv2.SimpleBlobDetector_Params()
 
params.filterByColor = False
params.filterByArea = False # set it to True to use minArea & maxArea
params.minArea = 500 # choose suitable values of minArea & maxArea 
params.maxArea = 2000
params.filterByInertia = False
params.filterByConvexity = False
params.filterByCircularity = True
params.minCircularity =0.5
params.maxCircularity =1
 
det = cv2.SimpleBlobDetector_create(params)
 
lower_red = np.array([149,169,143])
upper_red = np.array([179,255,255])
 
while True:
    ret,frame = cap.read()
    imgHSV = cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
    redMask = cv2.inRange(imgHSV,lower_red,upper_red)
    blur= cv2.blur(redMask,(10,10))
     
    res = cv2.bitwise_and(frame,frame, mask=redMask)
     # get and draw keypoint
    keypnts= det.detect(blur)
    cv2.drawKeypoints(frame,keypnts,frame,(0,255,0),cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
    cv2.imshow('frame',frame)
    #cv2.imshow('mask',blur)
     
    for k in keypnts:
        x = (int (k.pt[0]))
        #print(x)
    z= x-set_point
    
    if z>=-20 and z<=20: # condition to set the marging of error at zero plus or minus 2
        error = 0
        previousError = error
        totalError = totalError + error
        
    else:
       error = z 
       previousError = error
       totalError = totalError + error
    
    power = int(kp*error + kd*(error-previousError) + ki*totalError)
    print(power)
    if cv2.waitKey(1) & 0xff == ord('q'):
       break
    
cap.release()
cv2.destroyAllWindows
     