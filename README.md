# MBSN
AI Project

WIP


Configurazione progetto IA.

Configurazione VM in Virtualbox:
Distro: Linux Ubuntu 64bit LTS 20.04
User:   vbox
Pw:     2020

Configurazione cronologica:
applicati tutti gli aggiornamenti da GUI e da riga di comando

sudo apt install software-properties-common apt-transport-https wget

for deb in deb deb-src; do echo "$deb http://build.openmodelica.org/apt `lsb_release -cs` stable"; done | sudo tee /etc/apt/sources.list.d/openmodelica.list

wget -q http://build.openmodelica.org/apt/openmodelica.asc -O- | sudo apt-key add - 

sudo apt update
sudo apt install
                  gcc
                  make
                  cmake
                  git
                  openmodelica
                  zlib1g-dev libxml2-dev
                  
pip3 install xmltodict
sudo cpan install XML::LibXML

sudo apt install
                  libxml++
                  glibmm
                  glib
                  libsbml
                  python3-pip

installazione di visual studio code (VSC)
installate estensioni di VSC:
Cmake Tools
C/C++ Intellisense
ninja-build
copiata la repository tramite git



Agli script Python va passato come argomento il path del modello mo
ma va dato il package o il modello!

1 – creare dizionario in c++ da json
2 – Usare GPUOde
