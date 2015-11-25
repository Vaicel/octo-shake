#!/usr/bin/env python2
# -*- coding: utf-8 -*-

# импортируем модули
import webbrowser
import csv
import numpy as np 


# объявляем массив для хранения точек
Y = []

# файл с точками на карте
filename = 'map.csv'

# читаем в файл и складываем в массив
with open(filename, 'rb') as csvfile:
	filereader = csv.reader(csvfile, delimiter=',')
	for row in filereader:
		Y.append(map(float,row))

# делаем из питоновского массива нумпаевский массив
Y = np.array(Y)

# задаем режим открывания страницы в браузере
new = 2 

# начало ссылки
url = "https://static-maps.yandex.ru/1.x/?l=map&pl="

# задаем цвета линий для рисования
colors = ("c:00FF00AA","c:FFFF00AA","c:FF0000AA")

# первый ряд особенный
firstrow = 1

# пробегаем по всем точкам
	# смотрим первый элемент.
	# если 1,2 или 3, начинается новая линия - 
	# добавляем координаты, чтобы закончить старую линию,
	# задаем цвет и добавляем координаты начала новой линии
	# если 0, то линия продолжается - просто добавляем координаты
for row in Y:
	if firstrow:
		url = url + colors[int(row[0])-1] + "," + str(row[1]) + "," + str(row[2]) + ","
		firstrow = 0
	if row[0] > 0:
		url = url + str(row[1]) + "," + str(row[2]) + "~" + colors[int(row[0])-1] \
			+ "," + str(row[1]) + "," + str(row[2]) + ","
	else:
		url += str(row[1]) + "," + str(row[2]) + ","

# удаляем последний символ в ссылке - запятую
url = url[:-1]

# печатаем ссылку в консоль
print url

# открываем ссылку в браузере
webbrowser.open(url,new=new)
