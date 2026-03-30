import cv2
import matplotlib.pyplot as plt
import numpy as np

# Read the image
img = cv2.imread('cablecar.BMP') #you can add a secnd paraneter as 0 to read it as gray
if img is None:
    print("Erreur : Impossible de charger l'image.")
    exit()

height, width, _ = img.shape


gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

threshold = 127

_, img_bw = cv2.threshold(gray_img, threshold, 255, cv2.THRESH_BINARY)

threshold, img_bw_otsu = cv2.threshold(gray_img, threshold, 255, cv2.THRESH_OTSU)

print (f"Otsu threshold {threshold}")

figure, plots = plt.subplots(1, 3)

plots[0].imshow(img_bw, cmap='gray')
plots[0].axis('off')
plots[0].set_title('Binarized Image')

plots[1].imshow(img_bw_otsu, cmap='gray')
plots[1].axis('off')
plots[1].set_title('Otsu Binarized Image')

plots[2].imshow(gray_img, cmap='gray')
plots[2].axis('off')
plots[2].set_title('Gray Image')
plt.show()


# part 1   
#else:
## Get the image height and width
#    height, width, _ = img.shape
#    for y in range(height):
#        for x in range(width):
#            pixel = img[y, x]
#            B, G, R = pixel
#            if 100 < x < 200 and 100 < y < 150 :
#                img[y, x] = (255,0,0)
#
#    img[150:200, 200:300] = (0,255,0)

#part 2
#block_size = int(width/2)
## Parcourir l'image bloc par bloc
#for y in range(0, height, block_size):
#    for x in range(0, width, block_size):
#        # Définir les limites du bloc
#        y_end = min(y + block_size, height)
#        x_end = min(x + block_size, width)
#        # Extraire le bloc
#        block = img[y:y_end, x:x_end]
#        # Afficher les coordonnées du bloc
#        print(f"Bloc ({x}, {y}) → ({x_end}, {y_end})")
#
#        block = cv2.cvtColor(block, cv2.COLOR_BGR2RGB)
#
#        fig, ax = plt.subplots(1, 1, figsize=(15,5))
#        ax.imshow(block)
#        ax.set_title("red stuff")
#        ax.axis("off")
#        plt.show()