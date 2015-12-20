#!/usr/bin/env python2
# -*- coding: utf-8 -*-

# подключение модулей
import numpy as np 
import matplotlib.pyplot as plt 
import csv

# массив для хранения данных
Y = []

# файл из которого читаются данные
filename = 'data.csv'

# чтение файла построчно, разделение строк на float значения из столбцов 3, 4, 5
with open(filename, 'rb') as csvfile:
	filereader = csv.reader(csvfile, delimiter=',')
	for row in filereader:
		Y.append(map(float,row[3:6]))

# преобразование python массива в numpy массив
Y = np.array(Y)

# генерация натурального ряда для оси Х графиков
x = np.arange(1000)

# зеленый, желтый и красный предел
greenLine = 0.02
yellowLine = 0.1
redLine = 1.0

# построение графиков ускорений по трем осям для части массива
plt.plot(x,Y[9000:10000,0])
plt.plot([0, 1000], [1.0 - greenLine, 1.0 - greenLine], color='g', linestyle='-', linewidth=2)
plt.plot([0, 1000], [1.0 - yellowLine, 1.0 - yellowLine], color='y', linestyle='-', linewidth=2)
plt.plot([0, 1000], [1.0 - redLine, 1.0 - redLine], color='r', linestyle='-', linewidth=2)
#сохранение графика в файл
plt.savefig('axel1-lines.png')
# отображение графика 
#plt.show()
