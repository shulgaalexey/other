C# practice
===========

Installing Mono
---------------

```
sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 3FA7E0328081BFF6A14DA29AA6A19B38D3D831EF
echo "deb http://download.mono-project.com/repo/debian wheezy main" | sudo tee /etc/apt/sources.list.d/mono-xamarin.list

sudo apt-get update

sudo apt-get install mono-complete
```

### Installing the IDE

```
sudo apt-get install monodevelop
```

Getting started
---------------

http://www.mono-project.com/docs/getting-started/


Compiling
---------

```
mcs -out:hello.exe hello.cs
```

or

```
mcs -out:my-program.exe *.cs
```

or

```
mcs -out:my-gui-program.exe -r:System.Windows.Forms.dll -r:System.Drawing.dll *.cs
```


Running
-------

```
mono hello.exe
```


Debuging
--------

```
https://marketplace.visualstudio.com/items?itemName=ms-vscode.mono-debug
```

Reference
---------

How to build:
 http://www.c-sharpcorner.com/UploadFile/201fc1/guide-for-building-C-Sharp-apps-on-ubuntu-monoproject-introducti/


 C# in VIM:
 https://codeword.xyz/2015/08/26/c-sharp-in-vim/
