# MBSN
AI Project - WIP Guide

Il progetto è stato configurato su una Docker image, di cui è stato effettuato l'upload su Docker Hub al seguente link: (WIP)


Configurazione Distro Linux (in Windows tramite WSL2):
- Distro: Linux Ubuntu 64bit LTS 20.04


Configurazione cronologica & requisiti:
- sudo apt install software-properties-common apt-transport-https wget
- sudo apt update
- sudo apt install gcc make cmake git curl unzip tar zlib1g-dev libxml2-dev python3-pip pkg-config meson 
- sudo apt update && sudo apt full-upgrade
- for deb in deb deb-src; do echo "$deb http://build.openmodelica.org/apt `lsb_release -cs` stable"; done | sudo tee /etc/apt/sources.list.d/openmodelica.list
- wget -q http://build.openmodelica.org/apt/openmodelica.asc -O- | sudo apt-key add - 
- sudo apt install openmodelica
- for PKG in `apt-cache search "omlib-.*" | cut -d" " -f1`; do sudo apt-get install -y "$PKG"; done # Installs optional Modelica libraries (most have not been tested with OpenModelica)
- pip3 install xmltodict


PER LIBXML++ 4.9.1
- wget https://download.gnome.org/sources/libxml++/4.9/libxml++-4.9.1.tar.xz
- tar -xvf libxml++-4.9.1.tar.xz
- cd libxml++-4.9.1
- sudo ./configure
- sudo ./configure --prefix=/usr
- sudo make
- sudo make install
- cd ..
- sudo rm -r libxml++-4.9.1
- sudo rm -r libxml++-4.9.1.tar.xz


PER GLIB
- wget http://ftp.gnome.org/pub/gnome/sources/glib/2.66/glib-2.66.1.tar.xz
- tar -xvf glib-2.66.1.tar.xz
- cd glib-2.66.1
- meson _build
- ninja -C _build
- sudo ninja -C _build install
- cd ..
- sudo rm -r glib-2.66.1
- sudo rm -r glib-2.66.1.tar.xz


PER SIGC++
- wget http://ftp.gnome.org/pub/gnome/sources/libsigc++/2.10/libsigc++-2.10.4.tar.xz
- tar -xvf libsigc++-2.10.4.tar.xz
- cd libsigc++-2.10.4
- meson _build
- ninja -C _build
- sudo ninja -C _build install
- cd ..
- sudo rm -r libsigc++-2.10.4
- sudo rm -r libsigc++-2.10.4.tar.xz


PER GLIBMM
- wget http://ftp.gnome.org/pub/gnome/sources/glibmm/2.64/glibmm-2.64.2.tar.xz
- tar -xvf glibmm-2.64.2.tar.xz
- cd glibmm-2.64.2
- sudo ./configure
- sudo ./configure --prefix=/usr
- sudo make
- sudo make install
- cd ..
- sudo rm -r glibmm-2.64.2
- sudo rm -r glibmm-2.64.2.tar.xz


PER SBML (LIBSBML)
- wget https://sourceforge.net/projects/sbml/files/libsbml/5.18.0/stable/R%20interface/libSBML_5.18.0.tar.gz/download
- tar -xvf libSBML_5.18.0.tar.gz
- cd libSBML_5.18.0/usr/lib64
- sudo cp -R ./ /usr/lib
- cd ..
- sudo rm -r libSBML-5.18.0-Linux-x64-binaries-ubuntu
- sudo rm -r libSBML-5.18.0-Linux-x64-binaries-ubuntu.tar.gz


Verifica installazioni:
- pkg-config glib-2.0 --modversion
- pkg-config libxml++-5.0 --modversion
- pkg-config glibmm-2.4 --modversion
- pkg-config libsbml --modversion


Installazione di visual studio code (VSC)
- installate estensioni di VSC:
- Cmake Tools
- C/C++ Intellisense
- ninja-build
- Remote-Container (Docker)
- copiata la repository tramite git


TO DO LIST:
– Usare GPUOde

NOTE:
- Agli script Python va passato come argomento il path del modello .mo ma va dato il package o il modello
