sudo apt install software-properties-common apt-transport-https wget
for deb in deb deb-src; do echo "$deb http://build.openmodelica.org/apt lsb_release -cs stable"; done | sudo tee /etc/apt/sources.list.d/openmodelica.list
wget -q http://build.openmodelica.org/apt/openmodelica.asc -O- | sudo apt-key add -
sudo apt update
sudo apt install gcc make cmake git curl unzip tar zlib1g-dev libxml2-dev python3-pip pkg-config meson
sudo apt update && sudo apt full-upgrade
sudo apt install openmodelica
pip3 install xmltodict
wget https://download.gnome.org/sources/libxml++/4.9/libxml++-4.9.1.tar.xz
tar -xvf libxml++-4.9.1.tar.xz
cd libxml++-4.9.1
sudo ./configure
sudo ./configure --prefix=/usr
sudo make
sudo make install
cd ..
sudo rm -r libxml++-4.9.1
sudo rm -r libxml++-4.9.1.tar.xz
wget http://ftp.gnome.org/pub/gnome/sources/glib/2.66/glib-2.66.1.tar.xz
tar -xvf glib-2.66.1.tar.xz
cd glib-2.66.1
meson _build
ninja -C _build
sudo ninja -C _build install
cd ..
sudo rm -r glib-2.66.1
sudo rm -r glib-2.66.1.tar.xz
wget http://ftp.gnome.org/pub/gnome/sources/libsigc++/2.10/libsigc++-2.10.4.tar.xz
tar -xvf libsigc++-2.10.4.tar.xz
cd libsigc++-2.10.4
meson _build
ninja -C _build
sudo ninja -C _build install
cd ..
sudo rm -r libsigc++-2.10.4
sudo rm -r libsigc++-2.10.4.tar.xz
wget http://ftp.gnome.org/pub/gnome/sources/glibmm/2.64/glibmm-2.64.2.tar.xz
tar -xvf glibmm-2.64.2.tar.xz
cd glibmm-2.64.2
sudo ./configure
sudo ./configure --prefix=/usr
sudo make
sudo make install
cd ..
sudo rm -r glibmm-2.64.2
sudo rm -r glibmm-2.64.2.tar.xz
wget https://sourceforge.net/projects/sbml/files/libsbml/5.18.0/stable/R%20interface/libSBML_5.18.0.tar.gz/download
tar -xvf libSBML_5.18.0.tar.gz
cd libSBML_5.18.0/usr/lib64
sudo cp -R ./ /usr/lib
cd ..
sudo rm -r libSBML-5.18.0-Linux-x64-binaries-ubuntu
sudo rm -r libSBML-5.18.0-Linux-x64-binaries-ubuntu.tar.gz