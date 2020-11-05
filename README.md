# NewtonMethod
Решение системы нелинейных уравнений методом Ньютона с заданной точностью

## Постановка задачи
Решить систему нелинейных уравнений

<p align="center"><img src="http://latex.codecogs.com/svg.latex?\left.\begin{matrix}F(x,y)&space;=&space;0&space;\\G(x,y)&space;=&space;0\end{matrix}\right\}"/></p>

методом Ньютона с заданной точностью ε. Определить необходимое для этого число итераций.  
Исходные данные:  
F(x,y) = tg(xy)-x^2  
G(x,y) = x+ln(y/15)  
ε = 10E-6

## Блок-схема работы программы
<p align="center"><img src="https://github.com/NNGU52/NewtonMethod/blob/main/screenshots/NewtonScheme.png"/></p>

## Рассчёты
Построение соответствующих графиков и нахождение приближённых значений решения представлены на рисунке ниже

<p align="center"><img src="https://github.com/NNGU52/NewtonMethod/blob/main/screenshots/Wolfram.png"/></p>

## Результат работы программы
На вход подаются значение x0 и y0 - точки, находящиеся рядом с решением.  
На выходе получаем уточнённое значение решения и количество итерацй, потребовавшихся для его нахождения.

<p align="center"><img src="https://github.com/NNGU52/NewtonMethod/blob/main/screenshots/console.png"/></p>
