import cv2
import matplotlib.pyplot as plt
import numpy as np

# Read the image
img = cv2.imread('cablecar.BMP', 0)
if img is None:
    print("Erreur : Impossible de charger l'image.")
    exit()




kernel1 = np.ones((5, 5))/30
kernel= np.array([[-1,-1,-1],[-1,8,-1],[-1,-1,-1]])
#part 1
#img_conv = cv2.filter2D(src=img, ddepth=cv2.CV_64F, kernel=kernel)

#part 2
gray_img = img

def convolution(pad_img, kernel):
    p = int(kernel.shape[0]/2)
    pheight, pwidth = pad_img.shape
    img_conv = np.zeros(pad_img.shape)
    for i in range(p, pheight-p):
        for j in range(p, pwidth-p):
            roi = pad_img[i-p:i+p+1, j-p:j+p+1]
            img_conv[i, j] = np.sum(kernel * roi)
    img_conv = img_conv[p:-p, p:-p]
    return img_conv

p = int(kernel.shape[0]/2)
pad_img = np.zeros((gray_img.shape[0]+2*p, gray_img.shape[1]+2*p))
pad_img[p:-p, p:-p] = gray_img

gray_img = convolution(pad_img, kernel)

figure, plots = plt.subplots(1, 1)

plots.imshow(gray_img, cmap='gray')
plots.axis('off')
plots.set_title('img_conv')

plt.show()

