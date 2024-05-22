#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>//system
#include <string.h>
#include <iomanip>
#include <windows.h>
#include <time.h>
#include <fstream>
#define T 25

using namespace std;

struct hoteles{//Lista de hoteles, lista doblemente enlazada
	int idH;//ID del hotel
	char cadena[T];//Cadena hotelera
	char ciudad[T];//Ciudad del hotel
	char direccion[T];//Direccion del hotel
	char telefonoC[11];//Telefono de contacto
	char correo[T];//Correo de contacto
	struct hoteles *anterior;
	struct hoteles *siguiente;
}*primeroH, *ultimoH;

struct recorridos{//Lista de recorridos, lista doblemente enlazada
	int idR;//id de recorrido
	char nombreR[T];//nombre de recorrido
	char fechaS[10];//fecha de salida
	int horaS;//hora de salida
	int horaL;//hora de llegada
	char lugarR[T];//lugar de reunion
	int costo;//costo de reocorrido
	struct recorridos *anterior;
	struct recorridos *siguiente;
}*primeroR, *ultimoR;

struct clientes{//Lista de clientes, lista simplemente enlazada
	char idC[7];//id del cliente
	char nombreC[T];//nombre del cliente
	char apellido[T];//apellido del cliente
	char direccion[T];
	char ciudad[T];
	char tel[11];
	char correo[T];
	char fecha[10];
	struct clientes *siguiente;
}*primeroC, *ultimoC;

struct reserva{
	int idReserv;
	int idH;
	int idR;//id de recorrido
	char idC[7];
	char fecha[10];
	int numPer;//numero de personas
	int subTotal;
	char estado[10];
	struct reserva *siguiente, *anterior;
}*primeroRes, *ultimoRes;

#include "validaciones.h"
#include "arch.h"
#include "decora.h"
#include "login.h"
#include "funcionesR.h"
#include "clientes.h"
#include "funciones.h"
#include "reserva.h"
#include "menu.h"
