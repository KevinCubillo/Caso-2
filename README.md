# Caso 2

Kevin Josué Cubillo Chacón 
carné: 2021123138

## Quicksort logaritmico:
Para demostrar que el quicksort se comporta de forma logaritmica cree 10 arreglos de tamaños:
{50000,100000,150000,200000,250000,300000,350000,400000,450000,500000}, luego los llené con numeros aleatrios del 1 al 100.
 
 Ya que el caso promedio de Quicksort tiene un O(n*log(n)), decidí usar números aleatorios para acercarme a este valor.
 y los resultados fueron los siguntes: 

Arreglo: 0
Cantidad de elementos: 50000
Tiempo de ejecucion: 0.008

Arreglo: 1
Cantidad de elementos: 100000
Tiempo de ejecucion: 0.023
Tasa de cambio de los tiempos: 2.875
Tasa de cambio de la funcion n*log(n): 2.12813

Arreglo: 2
Cantidad de elementos: 150000
Tiempo de ejecucion: 0.044
Tasa de cambio de los tiempos: 1.91304
Tasa de cambio de la funcion n*log(n): 1.55283

Arreglo: 3
Cantidad de elementos: 200000
Tiempo de ejecucion: 0.071
Tasa de cambio de los tiempos: 1.61364
Tasa de cambio de la funcion n*log(n): 1.36552

Arreglo: 4
Cantidad de elementos: 250000
Tiempo de ejecucion: 0.101
Tasa de cambio de los tiempos: 1.42254
Tasa de cambio de la funcion n*log(n): 1.27285

Arreglo: 5
Cantidad de elementos: 300000
Tiempo de ejecucion: 0.138
Tasa de cambio de los tiempos: 1.36634
Tasa de cambio de la funcion n*log(n): 1.2176

Arreglo: 6
Cantidad de elementos: 350000
Tiempo de ejecucion: 0.186
Tasa de cambio de los tiempos: 1.34783
Tasa de cambio de la funcion n*log(n): 1.18093

Arreglo: 7
Cantidad de elementos: 400000
Tiempo de ejecucion: 0.234
Tasa de cambio de los tiempos: 1.25806
Tasa de cambio de la funcion n*log(n): 1.15481

Arreglo: 8
Cantidad de elementos: 450000
Tiempo de ejecucion: 0.3
Tasa de cambio de los tiempos: 1.28205
Tasa de cambio de la funcion n*log(n): 1.13527

Arreglo: 9
Cantidad de elementos: 500000
Tiempo de ejecucion: 0.363
Tasa de cambio de los tiempos: 1.21
Tasa de cambio de la funcion n*log(n): 1.1201

## Quicksort cuadratico:

Luego de hacer pruebas descubrí que el peor caso para quicksort cuando el pivote es el primer elemento, 
es cuando los arreglos estan ordenados de mayor a menor, lo que genera un crecimiento cuadrático.

Por lo que creé 10 arreglos con los siguientes tamaños: {2000,4000,6000,8000,10000,12000,14000,16000,18000,20000}
y los llené con números ordenados de mayor a menor, obteniendo los siguientes resultados:

Arreglo: 0
Cantidad de elementos: 2000
Tiempo de ejecucion: 0.009

Arreglo: 1
Cantidad de elementos: 4000
Tiempo de ejecucion: 0.037
Tasa de cambio de los tiempos: 4.11111
Tasa de cambio de la funcion n^2: 4

Arreglo: 2
Cantidad de elementos: 6000
Tiempo de ejecucion: 0.084
Tasa de cambio de los tiempos: 2.27027
Tasa de cambio de la funcion n^2: 2.25

Arreglo: 3
Cantidad de elementos: 8000
Tiempo de ejecucion: 0.149
Tasa de cambio de los tiempos: 1.77381
Tasa de cambio de la funcion n^2: 1.77778

Arreglo: 4
Cantidad de elementos: 10000
Tiempo de ejecucion: 0.232
Tasa de cambio de los tiempos: 1.55705
Tasa de cambio de la funcion n^2: 1.5625

Arreglo: 5
Cantidad de elementos: 12000
Tiempo de ejecucion: 0.337
Tasa de cambio de los tiempos: 1.45259
Tasa de cambio de la funcion n^2: 1.44

Arreglo: 6
Cantidad de elementos: 14000
Tiempo de ejecucion: 0.47
Tasa de cambio de los tiempos: 1.39466
Tasa de cambio de la funcion n^2: 1.36111

Arreglo: 7
Cantidad de elementos: 16000
Tiempo de ejecucion: 0.597
Tasa de cambio de los tiempos: 1.27021
Tasa de cambio de la funcion n^2: 1.30612

Arreglo: 8
Cantidad de elementos: 18000
Tiempo de ejecucion: 0.753
Tasa de cambio de los tiempos: 1.26131
Tasa de cambio de la funcion n^2: 1.26562

Arreglo: 9
Cantidad de elementos: 20000
Tiempo de ejecucion: 0.935
Tasa de cambio de los tiempos: 1.2417
Tasa de cambio de la funcion n^2: 1.23457

## Influencia del pivote fijo y aleatorio:
Como ya se mencionó anteriormente el usar un pivote fijo puede causar crecienmientos caudráticos en ciertas
circunstancias, usando el ejemplo anterior donde se llenan los arreglos con numeros ordenados de mayor a menor
el algoritmo tiene un creciemnto cuadratico. Sin embargo, si en cada subllamda a quicksort calculamos un nuevo pivote de forma
aleatoria, podemos reducir el tiempo de ejecucion considerablemente.

En los siguientes resultados, se comparó el el crecimiento usando el pivote aleatorio y la funcion n*(log(n))
Se pude ver que en algunos casos se comporta de forma silimilar, mientras que en otros se desvía un poco.

Arreglo: 0
Cantidad de elementos: 2000
Tiempo de ejecucion: 0.004

Arreglo: 1
Cantidad de elementos: 4000
Tiempo de ejecucion: 0.028
Tasa de cambio de los tiempos: 7
Tasa de cambio de la funcion n*log(n): 2.18239

Arreglo: 2
Cantidad de elementos: 6000
Tiempo de ejecucion: 0.034
Tasa de cambio de los tiempos: 1.21429
Tasa de cambio de la funcion n*log(n): 1.57333

Arreglo: 3
Cantidad de elementos: 8000
Tiempo de ejecucion: 0.057
Tasa de cambio de los tiempos: 1.67647
Tasa de cambio de la funcion n*log(n): 1.37742

Arreglo: 4
Cantidad de elementos: 10000
Tiempo de ejecucion: 0.104
Tasa de cambio de los tiempos: 1.82456
Tasa de cambio de la funcion n*log(n): 1.28104

Arreglo: 5
Cantidad de elementos: 12000
Tiempo de ejecucion: 0.152
Tasa de cambio de los tiempos: 1.46154
Tasa de cambio de la funcion n*log(n): 1.22375

Arreglo: 6
Cantidad de elementos: 14000
Tiempo de ejecucion: 0.251
Tasa de cambio de los tiempos: 1.65132
Tasa de cambio de la funcion n*log(n): 1.18581

Arreglo: 7
Cantidad de elementos: 16000
Tiempo de ejecucion: 0.327
Tasa de cambio de los tiempos: 1.30279
Tasa de cambio de la funcion n*log(n): 1.15884

Arreglo: 8
Cantidad de elementos: 18000
Tiempo de ejecucion: 0.459
Tasa de cambio de los tiempos: 1.40367
Tasa de cambio de la funcion n*log(n): 1.13869

Arreglo: 9
Cantidad de elementos: 20000
Tiempo de ejecucion: 0.583
Tasa de cambio de los tiempos: 1.27015
Tasa de cambio de la funcion n*log(n): 1.12306


## Insertionsort lineal: