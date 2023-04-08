# Sistemas de Computación - Trabajo Práctico II: Stack Frame
Facultad de Ciencias Exactas, Física y Naturales, Universidad Nacional de Córdoba.

Año: 2023.

### Autores
* BOTTINI, Franco Nicolás
* LENCINA, Aquiles Benjamín
* ROBLEDO, Valentín

### Grupo: _C Lovers_

### **¿Cómo usar?**
Puede clonar y compilar este repositorio siguiendo estos pasos:

```bash
$ git clone https://github.com/FrancoNB/TP2_SC_2023.git

$ cd TP2_SC_2023

$ cmake .

$ make
```

Finalmente, para ejecutar el programa:

```bash
$ ./bin/TP2
```

### **Resumen del Funcionamiento**
Para el desarrollo de este programa se utilizaron las siguientes APIs:

* [CoinLayer](https://coinlayer.com/)
* [Fixer](https://fixer.io/)

La primera utilizada para obtener la cotización de las criptomonedas Bitcoin (BTC) y Ethereum (ETH) en Dólares Estadounidenses (USD) y en tiempo real, la segunda, para obtener el cambio de valor de divisas, de Dólar Estadounidense (USD) a Pesos Argentinos (ARS) y Euros (EUR).  

Al iniciar el programa, se realiza una consulta a las APIs, las cuales nos devuelven la información en formato JSON, posteriormente, extraemos los datos necesarios y los guardamos en estructuras.  
Luego, realizamos un par de llamadas a una función en assembler, la cual recibe como parámetro la cotización de la criptomoneda en Dólares Estadounidenses (USD) y el factor de conversión a la moneda deseada. Esta función, realiza la conversión de divisas y devuelve el resultado. De esta manera, obtenemos la cotización de Bitcoin (BTC) y Ethereum (ETH) en Pesos Argentinos (ARS) y Euros (EUR).

### **Licencia 🧾**
_GNU General Public License v3.0 Copyright (c) C Lovers 2023_
