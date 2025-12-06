# 42_ft_so_long

## Guía Paso a Paso Mejorada — so_long (sin código)
### Paso 1 — Configuración Inicial y Manejo de Argumentos
#### 1. Crea el archivo main.c

Debe contener:
* La función `main(argc, argv)`
* Un sistema básico de detección de errores
* Llamadas ordenadas a tus funciones principales

#### 2. Comprueba los argumentos

Tu programa debe recibir exactamente 1 argumento: un archivo `.ber.`
Validaciones:

* Si argc != 2 → error.
* Si el archivo no termina en .ber → error.

#### 3. Crear el Makefile
Debe incluir como mínimo:
* `NAME`
* `all`
* `clean`
* `fclean`
* `re`

Consejos:
* Añade los directorios `src/` y `include/.`
* Más adelante agregarás MiniLibX al Makefile.

#### Paso 2 — Diseño de la Estructura del Juego (Modelo)
1. Crea `so_long.h`

Aquí defines:
* Tu estructura principal del juego
* Prototipos de funciones
* Includes básicos

2. Define la estructura `t_game`
Debe contener toda la información de estado del juego, para no tener mil parámetros en cada función.

Incluye:

Datos del mapa:
* `map` → matriz de chars (char **)
* `width` → ancho
* `height` → alto

Datos del jugador:
* **player_x**, **player_y**
* `moves` → contador de movimientos

Objetos:
* **collectibles** → total de 'C'
* **collected** → recogidos

#### MiniLibX (se añaden después):
* puntero a mlx
* puntero a la ventana
* punteros a las imágenes
**Consejo**: inicializa la estructura siempre a cero.

#### Paso 3 — Lectura del Mapa
##### Objetivo:
Leer el archivo `.ber` y construir el char `**map.`
La función de lectura debe:

* Abrir el archivo con `open().`
* Leer línea por línea (ideal con `get_next_line`).
* Guardar cada línea en un array dinámico.
* Guardar la matriz en `game->map.`

Determinar:
* **game->height** → número de líneas
* **game->width**→ longitud de la primera línea

Recomendación:
* Quita el salto de línea final si existe.

Asegúrate de que el mapa no está vacío.

#### Paso 4 — Validación Completa del Mapa
Aquí se cometen el 90% de los errores, así que tómate tu tiempo.
Debes crear varias funciones de validación:

##### 1. Validación de forma (validate_shape)
Comprueba:
* Todas las filas deben tener la misma longitud.
* No se aceptan mapas irregulares.

Errores comunes:
* Líneas con espacios al final.
* Líneas creadas en Windows que incluyen \r.

##### 2. Validación de muros (validate_walls)
Condiciones:
* Primera fila → todo '1'
* Última fila → todo '1'
* Primera columna de cada fila → '1'
* Última columna de cada fila → '1'
* Si alguno falla → `error`.

##### 3. Validación de componentes (validate_components)
Recorre el mapa entero y comprueba:

Caracteres permitidos:
* `'0'` → espacio vacío
* `'1'` → muro
* `'C'` → collectible
* `'E'` → salida
* `'P'` → jugador
Si aparece cualquier otro → error.

Cantidad Obligatoria:
* Debe haber exactamente 1 `P`
* Debe haber exactamente 1 `E`
* Debe haber al menos 1 `C`

Al mismo tiempo debes:
* Guardar la posición del jugador en el struct.
* Contar C y guardarlo en game->collectibles.

#### Paso 5 — Validación de la Ruta (Accesibilidad)
Este paso es obligatorio:
Deben ser accesibles:
* Todos los `'C'`
* La salida `'E'`
Método recomendado: **Flood Fill**

1.  Copia el mapa.
2. Desde la posición del jugador:
* Marca todas las casillas que pueda atravesar.
* Permite avanzar por '0', 'C', 'E'.
3. Tras el recorrido:
* Si queda algún 'C' sin marcar → mapa inválido.
* Si queda 'E' sin marcar → mapa inválido.
Este paso garantiza que **es posible ganar el juego.**

#### Secuencia Final del main (Resumen)
Tu main debe seguir este orden:

1. `check_args(argc, argv)`
2. Inicializar estructura del juego
3. `game.map = read_map(argv[1])`
4. `validate_map_logic(&game)`
5. `check_path(&game)`
6. (Fase gráfica) `start_mlx(&game)`

#### Consejos extra para evitar errores
##### ✔ Prueba tus validaciones con mapas incorrectos:

* Sin muros
* Múltiples P
* Múltiples E
* Ningún C
* Mapa no rectangular
* Collectibles inaccesibles
* Salida encerrada por muros

##### ✔ Mantén tus archivos bien organizados:
* `read_map.c`
* `validate_shape.c`
* `validate_walls.c`
* `validate_components.c`
* `path_check.c`
* `utils.c`

##### ✔ No uses números mágicos
Usa constantes o comentarios claros.






































## Holy Graph M-03
---
### Análisis de Dificultad de los Proyectos

| Proyecto    | Resumen                                                                                          | Dificultad (1-10) | Habilidades Principales                                      |
|-------------|--------------------------------------------------------------------------------------------------|-------------------|-------------------------------------------------------------|
| **fdf**     | Crea una representación 3D básica de un mapa de elevación con líneas (wireframe).               | 7                 | Gráficos, Geometría, manejo de ventanas (minilibx).        |
| **fract'ol**| Genera y explora conjuntos fractales (como Mandelbrot o Julia).                                 | 8                 | Gráficos, Matemáticas complejas, optimización.              |
| **so_long** | Desarrolla un pequeño juego 2D usando la librería de gráficos (minilibx).                      | 5                 | Gráficos básicos, manejo de eventos, lógica de juego.      |
| **pipex**   | Implementa una versión simplificada de la funcionalidad de tuberías (``) de la shell de Unix.| 6                 | Manejo de procesos, comunicación entre procesos.            |
| **minitalk**| Crea un programa de comunicación simple entre dos procesos utilizando señales de Unix.           | 7                 | Comunicación Inter-Procesos (IPC), manejo de señales.      |
| **push_swap**| Ordena una pila de números usando solo dos pilas y un conjunto limitado de operaciones.        | 9                 | Algoritmos, Estructuras de datos (listas enlazadas), Optimización. |
