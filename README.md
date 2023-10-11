# temperature_module_test01

Utilizar sensor ds18b20 para hacer leer temperatura.

guardar en un la memoria EEPROM dos parámetros (tiempo y temperatura)

el tiempo debe ser el delay que se le aplique a la lectura de temp.

Cada vez que se realize una lectura se debe guardar en una variable dentro de la memoria eeprom.

Deben comparar la temperatura anterior con la nueva registrada.

Si hay una diferencia mayor a 2 grados, deben enviar una alerta en el display que diga "Cambio Significativo"

MATERIALES:
Led RGB (se debe prender cada vez que se hace una lectura).
DISPLAY I2C LCD (debe decir "Data Cleared cada vez que se borra la base de datos)
SENSOR DS18B20

LIBRERIAS:
One Wire
LiquidCrystal_I2C
DallasTemperature
EEPROM
(de usar otras agregarlo por comentario)
