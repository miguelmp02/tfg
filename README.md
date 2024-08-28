# Desarrollo de un compilador

Este TFG se centra en el desarrollo de un compilador funcional que transforma un código fuente (gramática Alfa) en un código objeto (código máquina).

## Ejecución del compilador
1. **make clean**   Limpia los elementos generados o clonados que pueden hacer fallar el compilador.
2. **make directories** Crea cualquier directorio que no esté creado al clonar el repositorio.
3. **make all** Crea los directorios y ejecuta los comandos necesarios para generar el compilador ejecutable "compiler.exe".
4. **./compiler.exe**   Con este comando ejecutamos el compilador y se nos abrirá una interfaz en la que seleccionaremos un fichero, y podremos compilarlo de forma sencilla e intuitiva.
5. **./compiler.exe path/nombre_fichero** Este comando es otra forma de ejecución más manual que se basa en añadir al comando anterior el fichero y su path de forma directa.

### Documentación proyecto
1. **chmod +x open_docs.sh** Para dar permisos al fichero open_docs.sh que se encarga de la compatibilidad con varios sistemas definidos a la hora de abrir el index.html en el navegador del sistema.
2. **make docs** Genera la documentación entera del proyecto (realiza limpieza de los docs generados anteriormente, ejecutar Doxygen y lo abre en el navegador del ordenador que se esté usando), pudiendo observar cada clase, diagramas...

#### Requisitos
- El requisito más importante es el del sistema que utiliza el dispositivo. Este proyecto es compatible con Windows (mediante el uso de MSYS2, máquina virtual...) y Linux
- Herramientas: make (para ejecutar el Makefile), Flex, Bison, Gtk (para la interfaz), Doxygen y Graphviz (para la documentación)

##### Instalación previa
Tenemos tres opciones para la instalación:
1. Utilizar Windows con una Máquina Virtual: Descargar Oracle VM VirtualBox y descargar un disco como Ubuntu. Una vez descargado, creamos una nueva máquina virtual con el Ubuntu. Desde Ubuntu clonar el repositorio. Una vez clonado, tenemos dos opciones:
- Descargar las herramientas una a una con el apt install, o
- Utilizar el Dockerfile: Descargar Docker Desktop **docker login** para logearse en la cuenta de Docker Desktop **docker build -t tfg .** para crear la imagen **docker run -it ubuntu:20.04 /bin/bash** para ejecutarla
2. Utilizar Windows con MSYS2 (Usada y probada): Esta instalación está descrita paso a paso en la memoria del TFG
3. Utilizar Linux: Procedimiento igual al primero