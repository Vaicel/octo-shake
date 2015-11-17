#!/usr/bin/env python2
# -*- coding: utf-8 -*-



import numpy as np 
import csv
import webbrowser

# объявляем массивы для хранения данных
Y = []
Z = []

# исходный файл с данными по GPS и акселерометру
filename = 'data.csv'

# читаем в файл и склазываем в массив
with open(filename, 'rb') as csvfile:
	filereader = csv.reader(csvfile, delimiter=',')
	for row in filereader:
		Y.append(map(float,row))

# делаем из питоновского массива нумпаевский массив
Y = np.array(Y)

# значения во втором и третьем столбце делим на 100 
# и как раз получаем координаты в формате, который
# понимает Yandex.maps
Y[:,range(1,3)] /= 100

# географические координаты складываем в отдельный массив
for line in range(1,len(Y)):
	if Y[line][0] != Y[line-1][0]:
		Z.append(Y[line][1])
		Z.append(Y[line][2])


# задаем режим открывания страницы в браузере
new = 2 

# начало ссылки
url = "https://static-maps.yandex.ru/1.x/?l=map&pl="

# добавляем по очереди координаты в конец ссылки
for coord in Z:
	url = url + str(coord) + ','  

# удаляем последний символ в ссылке - запятую
url = url[:-1]

# печатаем ссылку в консоль
print url

# открываем ссылку в браузере
webbrowser.open(url,new=new)
