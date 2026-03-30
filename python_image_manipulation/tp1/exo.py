import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread("cablecar.BMP")

if img is None:
    print("Error: image not loaded")
    exit()

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

ycbcr = cv2.cvtColor(img, cv2.COLOR_BGR2YCrCb)

hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)


def add_borders(image, is_gray=False):
    top = 20
    left = 20
    right = 20

    if is_gray:
        image = cv2.copyMakeBorder(
            image,
            top, 0, left, right,
            cv2.BORDER_CONSTANT,
            value=0
        )

        image[0:top, :] = 200      
        image[:, 0:left] = 150     
        image[:, -right:] = 0      

    else:
        image = cv2.copyMakeBorder(
            image,
            top, 0, left, right,
            cv2.BORDER_CONSTANT,
            value=[0, 0, 0]
        )

        image[0:top, :] = [0, 255, 0]   
        image[:, 0:left] = [0, 0, 255]  
        image[:, -right:] = [0, 0, 0]   

    return image


gray_b = add_borders(gray, is_gray=True)
ycbcr_b = add_borders(ycbcr)
hsv_b = add_borders(hsv)

ycbcr_rgb = cv2.cvtColor(ycbcr_b, cv2.COLOR_YCrCb2RGB)
hsv_rgb = cv2.cvtColor(hsv_b, cv2.COLOR_HSV2RGB)



fig, ax = plt.subplots(1, 3, figsize=(15,5))

ax[0].imshow(gray_b, cmap='gray')
ax[0].set_title("Grayscale")
ax[0].axis("off")

ax[1].imshow(ycbcr_rgb)
ax[1].set_title("YCbCr")
ax[1].axis("off")

ax[2].imshow(hsv_rgb)
ax[2].set_title("HSV")
ax[2].axis("off")

plt.show()