# Desarrollo de un compilador

Este TFG se centra en el desarrollo de un compilador funcional que transforma un código fuente (gramática Alfa) en un código objeto (código máquina).

## Ejecución del compilador
1. **make clean**   Limpia los elementos generados o clonados que pueden hacer fallar el compilador.
2. **make directories** Crea cualquier directorio que no esté creado al clonar el repositorio.
3. **make all** Crea los directorios y ejecuta los comandos necesarios para generar el compilador ejecutable "compiler.exe".
4. **./compiler.exe**   Con este comando ejecutamos el compilador y se nos abrirá una interfaz en la que seleccionaremos un fichero, y podremos compilarlo de forma sencilla e intuitiva.
5. **./compiler.exe path/nombre_fichero** Este comando es otra forma de ejecución más manual que se basa en añadir al comando anterior el fichero y su path de forma directa.

### Otras opciones
1. **make docs** Genera la documentación entera del proyecto (realiza limpieza de los docs generados anteriormente, ejecutar Doxygen y lo abre en el navegador del ordenador que se esté usando[compatibilidad con varios sistemas definidos en open_docs.sh]), pudiendo observar cada clase, diagramas...






chmod +x open_docs.sh