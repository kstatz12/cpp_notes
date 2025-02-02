#!/usr/bin/env ruby
Vagrant.configure("2") do |config|
  # Define the base box
  config.vm.box = "generic/ubuntu2204"

  # Set up SSH access
  config.vm.network "private_network", type: "dhcp"

  # Sync local directory to VM
  config.vm.synced_folder ".", "/home/vagrant/code"

  # Provisioning: Install C++ Development Tools
  config.vm.provision "shell", inline: <<-SHELL
    sudo apt update
    sudo apt install -y build-essential cmake clang clangd gdb ninja-build valgrind lldb git python3 python3-pip
  SHELL

  # Define settings for VirtualBox
  config.vm.provider "virtualbox" do |vb|
    vb.memory = "4096"
    vb.cpus = 2
    vb.name = "vagrant_cpp_dev_vbox"
  end

  # Define settings for VMware
  config.vm.provider "vmware_desktop" do |vmware|
    vmware.memory = "4096"
    vmware.cpus = 2
  end

  # Define settings for Hyper-V
  config.vm.provider "hyperv" do |hv|
    hv.memory = "4096"
    hv.cpus = 2
    hv.vmname = "vagrant_cpp_dev_hyperv"
  end

  config.vm.provider "qemu" do |qe|
    qe.arch = "x86_64"
    qe.machine = "q35"
    qe.cpu = "max"
    qe.net_device = "virtio-net-pci"
  end

  # Define settings for Libvirt (KVM/QEMU)
  config.vm.provider "libvirt" do |lv|
    lv.arch = "x86_64"
    lv.memory = 4096
    lv.cpus = 2
    lv.driver = "kvm"
  end
end
