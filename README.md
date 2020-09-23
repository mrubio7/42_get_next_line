42Madrid Cursus - get_next_line

![gnl](./114:100.png)

## Uso

Llamar a su función get_next_line en bucle le permitirá leer linea a linea todo el texto de un descriptor de archivo hasta el EOF.

Debería funcionar correctamente cuando lee desde un archivo y cuando lee desde la entrada estándar.

El programa debe compilarse con el flag "**-D BUFFER_SIZE=xx**". Siendo "xx" un numero que será usado como tamaño de buffer para ir leyendo en get_next_line y la funcion "read()"
debe usar BUFFER_SIZE para leer desde un archivo o desde "stdin".

**Para la parte bonus:**

Debe hacerse con una unica variable estatica y debe poder abrir varios descriptores de archivos y sacar las lineas de texto de cada uno que se le pida sin perderse.
