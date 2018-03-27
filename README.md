# midpoint-filter


This function will filter the image by the nonlinear midpoint filter method. This function works only for monochrome images, 8 bit per bixel and 24 bit per pixel. The midpoint filter is typically used to filter images containing short tail noises such as Gaussian noise and uniform type. The midpoint filter output is the average of the maximum and minimum gray level values ​​within a local region of the image determined by a specified mask.