# Vertex coloring problem
Representación del grafo: Listas enlazadas
## Caso backtracking
### ¿Cuales clases puedo tener? (Preliminarmente)
- Clase Nodo: Es el nodo de un grafo, contiene:
	- Id 
	- Color
	- Punteros a los nodos vecinos (inmutable)
	- Punteros a los nodos vecinos coloreados (mutable)
- Clase Grafo:
	- Todos los nodos del grafo (inmutable)
	- Aristas (inmutable)
	- Colores asignados (número) (mutable)
	1) Calcular número cromático
- Clase Estado:
	- Grafo (inmutable)
	- Grafo coloreado (mutable)
	- Grafo no coloreado (mutable)
	1) Resolver BnB
- Clase Leer:
```c
Estado Leer (string nombreArchivo)
```
- Clase Menu:
	- Es el menú

### Estrategia backtracking
1) Usar greedy coloring para calcular el numero cromático propuesto.

2) El método recibe el estado.

Caso base: 
	Si: están todos coloreados
	Entonces: Tenemos el numero de colores actual.
	---------
	Si: El numero de colores actual es menor al numero cromático propuesto
	Entonces: Esta hoja es la nueva propuesta
	Sino: Se pasa al caso recursivo
Caso recursivo:
	Cantidad de colores + 1
	Pregunto al nodo si puedo pintar con cada color
	Actualizo 

Nodo 1: Color 1
Nodo 2: Color 1

Cantidad de colores: n

Tiempo de ejecución: ?