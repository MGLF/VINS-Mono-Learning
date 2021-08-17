import cv2
import numpy as np
# import skimage

depth_filename="realsense.png"
imgOri = cv2.imread(depth_filename, -1)
#depth=cv2.split(imgOri)[0]
#depth[depth>2000]=0
#depth=depth/2000.0000
print(imgOri[240])
cv2.imshow('imgOri',imgOri)
cv2.waitKey(0)

