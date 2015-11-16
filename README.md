My awesome npk project
=====

Описание файлов
-----

+ *README.md* - этот файл
+ *octo-shake.ino* - скетч для ардуино, который читает GPS и акселерометр и пишет в файл
+ *DATALOG.TXT* - файл с данными, который генерируется скетчем
+ *data.csv* - то же самое, что и предыдущее
+ *axelplot.py* - строит график ускорений по трем осям
+ *openmap.py* - отрывает браузер с заданной http-ссылкой
+ *stino.settings* - ???

Запуск скриптов
-----

Для работы с массивами и рисования графиков требуются модули питона

    apt-get install python-numpy
    apt-get install python-matplotlib
    
  
Скриптам нужно давать права на исполнение:

    chmod +x %SCRIPT_NAME%

Для запуска написать в консоли:

    ./%SCRIPT_NAME%

Сетевой хэлп
-----

Yandex Maps API: Линии и многоугольники

https://tech.yandex.ru/maps/doc/staticapi/1.x/dg/concepts/polylines-docpage/
