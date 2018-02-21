Dependency Injection demo
=========================

This is a demo implementeation of Dependency Injection, a pattern from Inversion of Control family.
This is a naive and simplified reproduction of constructor-based OiC with text file config,
similar to what we can see in Spring framework.

Features supported:
 - Creating bean singletons
 - Bean config file in human readable form
 - Garbage Collection for beans


![Dependency Injection](https://en.wikipedia.org/wiki/File:W3sDesign_Dependency_Injection_Design_Pattern_UML.jpg "Dependency Injection)


Build
-----

```
g++ -std=c++1y -Wall -g -o test *.cpp
```

Run
---

```
./test
```


Configure
---------

Prepare a text file with beans, for example, toyota.config:

```
*bean* GasEngine ge
*bean* FourWheelTransmission fwt
*bean* Car Toyota with ge fwt
```

The keyword *bean* starts the bean declaration. Each bean should be declared on a single line.

Next word is a bean type, one of following:
 - GasEngine
 - DieselEngine
 - FourWheelTransmission
 - SixWheelTransmission
 
Bean constructor parameters should be listed after a keyword *with*.

Note, beans should follow in order in which they are used.
In other words, the pair of beans *ge* and *fwt* must be declared before the bean *Toyota*.


Reference
---------

https://en.wikipedia.org/wiki/Dependency_injection
