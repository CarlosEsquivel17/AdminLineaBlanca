#include "libreria.h"

int main(){
	system("mode con lines=80");
	portada();
	datos();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	usuario("Usuario: ");
	contrasenia("Contraseña: ");
	primeroH = NULL;
	ultimoH = NULL;
	primeroR = NULL;
	ultimoR = NULL;
	primeroC = NULL;
	ultimoC = NULL;
	
	leeHoteles();
	leeClientes();
	leeRecorridos();
	leeReserv();
	
	srand(time(NULL));
	menu();
	
	return 0;
}
