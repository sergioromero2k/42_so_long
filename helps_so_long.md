## Paso 4: Validación de la Estructura del Mapa
Esta es la parte más compleja de la validación.

* Función	validate_shape(void): Comprueba que todas las filas del map tienen la misma longitud (es rectangular).
  
* Función	validate_walls(void): Recorre la primera y la última fila, y la primera y la última columna para asegurarte de que solo tienen el carácter '1' (Muro).
  
* Función	validate_components(void): Recorre el mapa completo. Verifica que solo haya caracteres válidos ('0', '1', 'C', 'E', 'P'). Cuenta las ocurrencias de 'P', 'E', y 'C'.
Al final, verifica que 'P' y 'E' sean exactamente uno y 'C' sea al menos uno. 