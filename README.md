# MBSN
AI Project - WIP Guide

Il progetto è stato configurato su una Docker image, di cui è stato effettuato l'upload su GitHub al seguente link: (WIP)


Configurazione Distro Linux (in Windows tramite WSL2):
- Distro: Linux Ubuntu 64bit LTS 20.04



Configurazione cronologica & requisiti:
- sudo apt install software-properties-common apt-transport-https wget

- for deb in deb deb-src; do echo "$deb http://build.openmodelica.org/apt `lsb_release -cs` stable"; done | sudo tee /etc/apt/sources.list.d/openmodelica.list

- wget -q http://build.openmodelica.org/apt/openmodelica.asc -O- | sudo apt-key add - 

- sudo apt update

- sudo apt install
                  gcc
                  make
                  cmake
                  git
                  curl
                  unzip
                  tar
                  zlib1g-dev libxml2-dev
                  python3-pip
                  

- applicati tutti gli aggiornamenti (update && upgrade && install)

- sudo apt install openmodelica

- pip3 install xmltodict

- DA QUESTO PUNTO IN POI WIP

- PER LIBXML++ 4.9.1
- wget https://download.gnome.org/sources/libxml++/4.9/libxml++-4.9.1.tar.xz
- tar -xvf libxml++-4.9.1.tar.xz
- cd libxml++-4.9.1
- sudo ./configure --prefix=/usr
- sudo make
- sudo make install

- PER GLIB
- wget https://download.gnome.org/sources/libxml++/4.9/libxml++-4.9.1.tar.xz
- tar -xvf libxml++-4.9.1.tar.xz
- cd libxml++-4.9.1
- sudo ./configure --prefix=/usr
- sudo make
- sudo make install

- PER GLIBMM
- wget https://download.gnome.org/sources/libxml++/4.9/libxml++-4.9.1.tar.xz
- tar -xvf libxml++-4.9.1.tar.xz
- cd libxml++-4.9.1
- sudo ./configure --prefix=/usr
- sudo make
- sudo make install

- PER SBML (LIBSBML)
- wget https://download.gnome.org/sources/libxml++/4.9/libxml++-4.9.1.tar.xz
- tar -xvf libxml++-4.9.1.tar.xz
- cd libxml++-4.9.1
- sudo ./configure --prefix=/usr
- sudo make
- sudo make install


- verifica installazione glib e glibmm:
- pkg-config glib-2.0 --modversion
- pkg-config libxml++-5.0 --modversion
- pkg-config glibmm-2.4 --modversion
- pkg-config glibmm-2.4 --modversion

- echo 'deb http://download.opensuse.org/repositories/home:/fbergman:/libsbml/xUbuntu_18.10/ /' | sudo tee /etc/apt/sources.list.d/home:fbergman:libsbml.list

- curl -fsSL https://download.opensuse.org/repositories/home:fbergman:libsbml/xUbuntu_18.10/Release.key | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/home:fbergman:libsbml.gpg > /dev/null

- sudo apt update

- sudo apt install libsbml5


WIP MA CANDIDATA A RELEASE
- installare via vcpkg tutti i 4 package


Installazione di visual studio code (VSC)
- installate estensioni di VSC:
- Cmake Tools
- C/C++ Intellisense
- ninja-build
- Remote-Container (Docker)
- copiata la repository tramite git



- Agli script Python va passato come argomento il path del modello .mo ma va dato il package o il modello!

1 – creare dizionario in c++ da json
2 – Usare GPUOde
