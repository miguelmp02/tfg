# Usa una imagen base de Ubuntu
FROM ubuntu:20.04

# Establece el directorio de trabajo dentro del contenedor
WORKDIR /usr/src/app

# Configura `tzdata` para que no pida entrada interactiva y actualiza el sistema
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && \
    apt-get install -y tzdata

# Configura la zona horaria
RUN ln -fs /usr/share/zoneinfo/Europe/Madrid /etc/localtime && \
    dpkg-reconfigure --frontend noninteractive tzdata

# Instala las dependencias necesarias
RUN apt-get install -y gcc make flex bison doxygen graphviz libgtk-3-dev

# Copia todos los archivos del proyecto al directorio de trabajo
COPY . .

# Lista los archivos en el directorio de trabajo para diagnóstico
RUN ls -l /usr/src/app


