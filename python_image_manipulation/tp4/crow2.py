
import cv2
import numpy as np


image = cv2.imread("Image.bmp", 0)

if image is None:
    print("Error: image not found")
    exit()

_, binary = cv2.threshold(image, 127, 1, cv2.THRESH_BINARY)


fimage = binary.flatten()

print("Vector:")
print(fimage)
rle = []

count = 1
current_value = fimage[0]

for pixel in fimage[1:]:

    if pixel == current_value:
        count += 1

    else:
        rle.append((count, current_value))
        current_value = pixel
        count = 1

rle.append((count, current_value))

print("RLE result:")
print(rle)