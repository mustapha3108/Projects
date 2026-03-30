import cv2
import matplotlib.pyplot as plt
import numpy as np
import random

# Read the image
img = cv2.imread('cablecar.BMP', 0)
if img is None:
    print("Erreur : Impossible de charger l'image.")
    exit()


height, width = img.shape
if height % 4 != 0 :
    for i in range(height%4 *4):
        img[width:]

w = width//4
h = height//4

filters = [
    [
        [-1,-1,-1],
        [-1,8,-1],
        [-1,-1,-1]
    ],
    [
        [0, -1, 0],
        [-1, 5, -1],
        [0, -1, 0]
    ],
    [
        [-1, 0, 1],
        [-2,0,2],
        [-1,0,1] 
    ],
    [
        [-2,-1,0],
        [-1, 1, 1],
        [0,1,2]    
    ],
    [
        [1/16, 2/16, 1/16],
        [2/16, 4/16, 2/16],
        [1/16, 2/16,1/16]
    ]
]

for row in range(4):
    for col in range(4):

        y1 = row * h
        y2 = (row + 1) * h

        x1 = col * w
        x2 = (col + 1) * w

        n = random.randint(0, 4)
        kernel = np.array(filters[n], dtype=np.float32)

        img[y1:y2, x1:x2] = cv2.filter2D(img[y1:y2, x1:x2],ddepth=-1,kernel=kernel)

figure, plots = plt.subplots(1, 1)
plots.imshow(img, cmap='gray')
plots.axis('off')
plots.set_title('img_conv')

plt.show()