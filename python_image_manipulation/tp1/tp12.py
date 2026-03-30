import numpy as np
import cv2
#...
# Convert from BGR to YCrCb color space: Y is the Luminance component, Cb and Cr chrominance components
img_ycrcb = cv2.cvtColor(resized_img, cv2.COLOR_BGR2YCrCb)
cv2.imwrite("ycrcb_random.png", img_ycrcb)
# Convert from BGR to HSV color space
img_hsv = cv2.cvtColor(resized_img, cv2.COLOR_BGR2HSV)
cv2.imwrite("hsv_random.png", img_hsv)
# Convert an RGB image to grayscale
img_gray = cv2.cvtColor(resized_img, cv2.COLOR_BGR2GRAY)
# concatenate image Horizontally
images = np.concatenate((cv2.cvtColor(img_gray, cv2.COLOR_GRAY2BGR), img_ycrcb, img_hsv), axis=1)
cv2.imshow('Gray, YCrCb and HSV images', images)
cv2.waitKey(0)
cv2.destroyAllWindows()













print(" ")
print(" ")
print(" ")
print(" ")
print(" ")