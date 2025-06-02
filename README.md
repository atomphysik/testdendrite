testDendrite
=====

Fork "testDendrite" to create a new MOOSE-based application.

For more information see: [https://mooseframework.inl.gov/getting_started/new_users.html#create-an-app](https://mooseframework.inl.gov/getting_started/new_users.html#create-an-app)

# How to simulate

## Create a new application

Create your own application to simulate
```console
cd {your moose project directory}
./moose/scripts/stork.sh {aplication name}
```
This will avoid the issues of collision with the existing apps.

## Clone this repository

Clone this repository in any folders that is suitable for saving files.

```console
git clone https://github.com/atomphysik/testdendrite.git
```

## copy and paste these files to the new app

What you need to copy is the following
- ./include
-  ./src
- ./Makefile
- ./input.i

paste these to the directory of new application that you created

## Build and launch

Build the app and launch it by the following commands

```console 
make -j{number of cpu thread you want to use}
./{app name}-opt -i input.i
```
