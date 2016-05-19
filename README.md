# OpenMP3
# Вывод об эффективности OpenMP по сравнению с последовательным вариантом и по сравнению с различным количеством потоков. 

Исходя из наблюдений, OpenMP хорош для использования в задачах, где необходима обработка большого количества потока данных. Чем больше объем вычислений, тем количество slave потоков, которые генерирует главный (main) поток, играет большую роль в скорости выполнения поставленной задачи. Однако при маленьком объеме данных (например умножение матриц размерами 50х50) использование OpenMP не является целесообразным, потому что 1 поток справляется с задачей намного быстрее, чем требуется (на сколько я понял) на инициализацию slave потоков. Но при увеличении количества элементов в матрицах, наблюдается такая тенденция - распараллеливание вычислений способствует значимому ускорению работы. Наблюдаемым минусом стало ограничение вычислительной мощности самой системы. При инициализации 8 и 16 потоков для вычисления произведения двух матриц размером 10000х10000 процесс занимал очень много ресурсов, что приводило к полному зависанию системы. В противовес - малое количество потоков для этой задачи справлялись довольно медленно и не укладывались в 10 минут ожидания результата (хотя процесс показывал 39% загрузки CPU и 1500 МБ занятой Hauptspeicher :) ) 
