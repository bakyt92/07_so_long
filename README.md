# 07_so_long

Проект состоит из нескольких частей

1. Сделать парсинг карты (сделать проверки и запихнуть все в двумерный массив): 
Квадратный, 5 символов, 1 выход, 1 стартовая позиция. 
Есть штука, что может быть несколько стартовых позиций, может 
3. работа с графикой - с библиотекой МЛХ, вывести окно, привязать к воидовским указателем, работаем с воидовским указателем. 
4. работа с кнопками, чтобы игра шла. 


Что почитать
1. https://github.com/luta-wolf/so_long
2. https://harm-smits.github.io/42docs/libs/minilibx
3. На каждую ошибку должно быть объяснение. 
4. 

Перечень keycode for MAC
https://gist.github.com/rickyzhang82/8581a762c9f9fc6ddb8390872552c250


MAKEFILE
https://www.youtube.com/watch?v=99ZrYs_ATH8   
https://youtu.be/cIUKfGuPIu8  
https://youtu.be/lPIH7JqfmSI  
https://21-school-by-students.notion.site/makefile-38308edf82454e43923cc316a15022b3
https://www.notion.so/Makefile-25e9e4c6b0a24784bcf3abe642c21130
https://makefiletutorial.com/  
https://www.gnu.org/software/make/manual/

Краткая структура (прошелся по коду пиров)
1. Парсинг 
   - проверки внутри парсинга (проверка на чтение fd, файл - карта т.е. длина после слэша не пять символов а больше, 
   наличие .ber в названии файла, проверка что не папка)
   - дальше мы читаем содержимое карты (по идее проверка на fd должна быть тут)
   - 
