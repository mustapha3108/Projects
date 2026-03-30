import cv2
import numpy as np
import matplotlib.pyplot as plt
import sys

image = cv2.imread("Image.bmp", 0)
if image is None:
    print("Error: image not found")
    exit()

height, width = image.shape

_, binary = cv2.threshold(image, 127, 1, cv2.THRESH_BINARY)
fimage = binary.flatten()

data = []
for v in fimage:
    if data and v == data[-1][1]:
        data[-1][0] += 1
    else:
        data.append([1, v])
print(data)

f = []
for x in data:
    if x[0] < 3:
        for i in range(x[0]):
            f.append(x[1] + 128)
    else:
        f.append(x[0])
        f.append(x[1])

print("coded", f)

bs =""
for i in f:
    bs = bs + bin(i)[2:].zfill(8)
print(bs)

#decoding

decoded = []

i = 0
while i < len(bs):

    n = int(bs[i:i+8], 2)
    i += 8

    if n >= 128:
        decoded.append(n)
    else:
        value = int(bs[i:i+8], 2)
        decoded.extend([value] * n)
        i += 8
print(decoded)
fdec = []

for i in decoded:
    if i >= 128:
        fdec.append((i-128) * 255)
    else:
        fdec.append(i * 255)

print(fdec)

print(len(bs))
print(len(fimage) * 8)

print((len(bs)/ (len(fimage) * 8)) *100)

arr = np.array(fdec, dtype=np.uint8)

image2d = arr.reshape((height, width))


figure, plots = plt.subplots(1, 1)

plots.imshow(image2d, cmap='gray')
plots.axis('off')
plots.set_title('img_conv')
plt.show()

    







