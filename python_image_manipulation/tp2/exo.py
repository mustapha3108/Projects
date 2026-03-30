import cv2
import matplotlib.pyplot as plt
import numpy as np

# Read the image
img = cv2.imread('cablecar.BMP') #you can add a secnd paraneter as 0 to read it as gray
if img is None:
    print("Erreur : Impossible de charger l'image.")
    exit()

height, width, _ = img.shape
bloc  = (width)//3
end = bloc + bloc

gg = img[:, bloc:end ]

gg = cv2.cvtColor(gg, cv2.COLOR_BGR2GRAY)

threshold = 127

_,bg = cv2.threshold(gg, threshold, 255, cv2.THRESH_BINARY)
bg = cv2.cvtColor(bg, cv2.COLOR_GRAY2BGR)

img[:, bloc:end] = bg

img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

figure, plots = plt.subplots(1, 1)

plots.imshow(img)
plots.axis('off')
plots.set_title('bobs your uncle')

plt.show()

