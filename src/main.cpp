/*
 *  Project 20-wifi-scan - main.cpp
 *      Este programa muestra como determinar (scan = barrer) redes
 *      WiFi disponibles
 */

/*
 *  Includes
 */

#ifdef ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif

/*
 *  Constantes defiidas en platformio.ini
 *     NO_ENCR      Constante para NoEncryption
 *     SERIAL_BAUD  Baud rate del port serie
 */

/*
 *  print_network:
 *      Funcion para imprimir los datos de una red, la apuntada por 'i'
 */

static void
print_network( int i )
{
    Serial.print("\t");
    Serial.print(WiFi.RSSI(i));     //  Intensidad de señal
    Serial.print( ": ");
    Serial.print(WiFi.SSID(i));     //  Nombre de la red
    Serial.println((WiFi.encryptionType(i) == NO_ENCR) ? " " : "*");
}


void
setup( void )
{
    Serial.begin(SERIAL_BAUD);
    delay(100);
    Serial.println("Setup done");
}


void
loop( void )
{
    int i, n;

    Serial.println("");
    Serial.println("---- Comienzo de barrido ----");

    if( ( n = WiFi.scanNetworks() ) == 0 )  //  retorna la cantidad de redes descubiertas
        Serial.println("No se encontraron redes disponibles");
    else
    {
        Serial.print(n);
        Serial.println(" redes encontradas");
        Serial.println("---- Barrido terminado ----");
        Serial.println("");

        for( i = 0; i < n; ++i )
            print_network(i);
    }

    delay(3000);
}
