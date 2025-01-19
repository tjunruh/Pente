```
__/\\\\\\\\\\\\\_______________________________________________________________________         
 _\/\\\/////////\\\_____________________________________________________________________        
  _\/\\\_______\/\\\__________________________________/\\\_______________________________       
   _\/\\\\\\\\\\\\\/______/\\\\\\\\___/\\/\\\\\\____/\\\\\\\\\\\_____/\\\\\\\\____________      
    _\/\\\/////////______/\\\/////\\\_\/\\\////\\\__\////\\\////____/\\\/////\\\___________     
     _\/\\\______________/\\\\\\\\\\\__\/\\\__\//\\\____\/\\\_______/\\\\\\\\\\\____________    
      _\/\\\_____________\//\\///////___\/\\\___\/\\\____\/\\\_/\\__\//\\///////_____________   
       _\/\\\______________\//\\\\\\\\\\_\/\\\___\/\\\____\//\\\\\____\//\\\\\\\\\\___________  
        _\///________________\//////////__\///____\///______\/////______\//////////____________
```
<a href="https://github.com/tjunruh/Pente/actions/workflows/pipeline.yml"><img src="https://img.shields.io/github/actions/workflow/status/tjunruh/Pente/pipeline.yml?label=build&branch=main"></a>

Console application of Pente. It features multiplayer for two to four people.

# Windows

Clone this repository and run the following command (Note that MSbuild.exe from Visual Studio 2022 must be in the System Environment Path variable):

```shell
.\windows_make.bat
```

Then enter the newly created build directory and execute the script.

```shell
cd build
.\Pente.bat
```


# Linux

You will need to install the ncurses library if you do not already have it. Run the command below to install it.

```shell
sudo apt-get install libncurses5-dev libncursesw5-dev
```

Simply clone this repository and run the following command:

```shell
make all
```

Then enter the newly created build directory and execute the script.

```shell
cd build
./Pente.sh
```
