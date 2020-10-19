# MBSN
AI Project - WIP Guide

Il progetto è stato configurato su una Docker image, di cui è stato effettuato l'upload su GitHub al seguente link: (WIP)


Configurazione Distro Linux (in Windows tramite WSL2):
- Distro: Linux Ubuntu 64bit LTS 20.04


Configurazione cronologica:
- sudo apt install software-properties-common apt-transport-https wget

- for deb in deb deb-src; do echo "$deb http://build.openmodelica.org/apt `lsb_release -cs` stable"; done | sudo tee /etc/apt/sources.list.d/openmodelica.list

- wget -q http://build.openmodelica.org/apt/openmodelica.asc -O- | sudo apt-key add - 


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
- sudo cpan install XML::LibXML

- creata una cartella vcpkg nel progetto, fatto git clone del pacchetto omonimo e installato da bash
- sudo apt install libxml2
- installare libxml++ ds http://ftp.gnome.org/pub/GNOME/sources/libxml++/4.9/
- verifica installazione glib e glibmm: pkg-config glib-2.0 --modversion && pkg-config glibmm-2.4 --modversion
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
