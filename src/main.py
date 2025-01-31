import cv2
import numpy as np

# Load the track image (Fixing path issue)
image_path = r"C:\Users\Bhagya Prabhashwara\OneDrive\Pictures\Download\maze-clipart-square-13.png"
image = cv2.imread(image_path)

# Check if the image is loaded properly
if image is None:
    print("Error: Image not found! Check the file path.")
    exit()

# Convert to grayscale
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Apply thresholding to detect the line
_, thresh = cv2.threshold(gray, 100, 255, cv2.THRESH_BINARY_INV)

# Show the processed image
cv2.imshow('Line Detection', thresh)
cv2.waitKey(0)
cv2.destroyAllWindows()

