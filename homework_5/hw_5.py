import numpy as np
import cv2
from PIL import Image
import matplotlib.pyplot as plt
import sys

def bilinear_interpolation(img, target_size):
    return cv2.resize(img, dsize=target_size, interpolation=cv2.INTER_LINEAR)

image_path = '/Users/mac/Desktop/3-2/수치해석/homework_5/sample_image.jpg'
img = cv2.imread(image_path)

original_resolution = img.shape[:2][::-1]

width = int(input("Enter the target width: "))
height = int(input("Enter the target height: "))
target_resolution = (width, height)

resampled_image = bilinear_interpolation(img, target_resolution)

plt.subplot(1, 2, 1)
plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
plt.title(f"Original Image\nResolution: {original_resolution}")

plt.subplot(1, 2, 2)
plt.imshow(cv2.cvtColor(resampled_image, cv2.COLOR_BGR2RGB))
plt.title(f"Resampled Image\nResolution: {target_resolution}")

plt.show()
