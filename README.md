# utn-circuitplc

Proyecto para el laboratorio de OpenPLC de Tecnologías para la Automatización, asignatura cursada en 2024 en la UTN FRRe. Equipo Rompecircuitos.

El circuito consiste en una **Raspberry Pi Pico W** conectada a un **fotosensor LDR Ky-018** que detecta la iluminación de la zona, y si supera un límite aceptable de funcionamiento, se activa de color azul un **foco LED RGB Ky-016**, indicando que hay suficiente luz para operar el candado inteligente del laboratorio de microcontroladores anterior.

Este repositorio es el proyecto de **OpenPLC** que contiene la lógica de control del circuito, programada en un *Ladder Diagram*.
