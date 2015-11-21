#!/usr/bin/env python2

import numpy as np 
import matplotlib.pyplot as plt 
import csv


Y = []

filename = "DATALOG.TXT"

for line in open(filename):
	line = line.split(',')
	Y.append(map(float,line))

Y = np.array(Y)
x = np.arange(len(Y))
#print x
#print Y[:,range(3,6)]
plt.plot(x,Y[:,range(3,6)]) # this is for plotting second column
plt.show()