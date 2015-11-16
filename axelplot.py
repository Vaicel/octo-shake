#!/usr/bin/env python2

import numpy as np 
import matplotlib.pyplot as plt 
import csv


Y = []

filename = 'data.csv'

with open(filename, 'rb') as csvfile:
	filereader = csv.reader(csvfile, delimiter=',')
	for row in filereader:
		Y.append(map(float,row))

Y = np.array(Y)
x = np.arange(len(Y))
#print x
#print Y[:,range(3,6)]
plt.plot(x,Y[:,range(3,6)]) # this is for plotting second column
plt.show()