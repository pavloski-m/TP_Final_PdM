# TP_Final_PdM

**-Fecha de entrega: 17/08/2021**

**-Alumno: Morzán, Pablo J.**

**-Plataforma: EDU CIAA v1.1**

## Titulo: Adquisición de datos de celda de carga
---

### Descripción:

El proyecto se resuelve sobre la plataroma **EDU-CIAA v1.1**. Se utilizan 3 periféricos: las entradas y salidas de proposito general para manejar teclas y leds integrados en la placa, el conversor analógico digital y la interfaz UART para comunicación con el terminal serial de la PC.
El contexto de este proyecto se da con el fin de evaluar los conceptos adquiridos en la materia de **Programación de microcontroladores** de la 15va cohorte de la **Especialización en sistemas embebidos**. Se toma provecho de esta instancia para avanzar en una función del uroflujómetro planteado como proyecto final de la materia.

**REQUISITOS:**

- La función principal del programa es informar un valor digital que hace referencia al valor analógico obtenido del acondicionamiento de una celda de carga. Este acondicionamiento es el responsable de establecer offset y ganancia del transductor de peso. Con el fin de emular esta celda de carga, en primera instancia, se puede realizar la prueba con un divisor de tensión resistivo utilizando un potenciometro para tal fin.

- Se debe contemplar un estado de error en la medición cuando se pasa de un valor máximo, lo que puede dañar la celda de carga o en el caso de que el peso relativo tome valores por debajo de cero. Este último se establece así por las condiciones naturales de un estudio de Uroflujometría.

- Además, se debe permitir en cualquier momento realizar un proceso de inicialización estableciendo un nuevo offset.

- Se debe poder reconocer en que modo se encuentra el módulo observando el estado de los LEDs.


**DESCRIPCIÓN DE ESTADOS**

El módulo al inicializar se configura en estado de **No adquisición**, en este estado se enciende solo un LED verde y se envía un mensaje al terminal avisando que se encuentra en este. La condición de salida de este módulo es la presión del botón **TEC1**, lo que hace que se pase al estado de **Inicialización**, en este se toma el valor de "Offset" y se establece como cero al valor medido en ese momento.

* ESTADO: **No adquisición**
  - Condición de entrada: inicio de programa - presión de **TEC2** en estado de adquisición o de error.
  - Condición de salida: presión de tecla **TEC1**.
  - Función: Se enciende LED Verde y se envía mensaje "Estado de no adquisición" por puerto serie.

* ESTADO: **Inicialización**
  - Condición de entrada: Presión de **TEC1** desde cualquier estado.
  - Condición de salida: Lectura y análisis de dato de conversión analógico/digital.
  - Función: Se apagan todos los LEDs y se informa por puerto serie que se está pasando por este estado y se el **Offset** medido.

* ESTADO: **Adquisición**
  - Condición de entrada: Valor válido leído en puerto analógico/digital en el estado de Inicialización.
  - Condición de salida: presión de tecla **TEC1** para ir a estado de Inicialización, **TEC2** para ir a estado de No adquisición o lectura de valor inválido para entrar en estado de Error.
  - Función: Parpadea LED Verde y se envía mensaje con el valor de Peso relativo (Valor leído - Offset) por puerto serie.

* ESTADO: **Error**
  - Condición de entrada: lectura de valor inválido en estado de inicialización o de Adquisición.
  - Condición de salida: presión de tecla **TEC1** para ir a inicialización o **TEC2** para ir a estado de no adquisición..
  - Función: Parpadea LED Rojo y se envía mensaje "Estado de error" por puerto serie.


![alt text](https://github.com/pavloski-m/DocumentosAnexos/blob/main/MEF_TP_Final_PdM_1.png?raw=true)
