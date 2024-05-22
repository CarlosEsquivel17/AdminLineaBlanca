int buscaRec(int x){
	bool bandera;
	struct recorridos *aux = primeroR;
	while(aux != NULL){
		if(x == aux->idR){
			return 1;
		}else{
			aux = aux->siguiente;
			bandera = false;
		}
	}
	if(bandera = false){
		return 0;
	}
}

int buscaPrecio(int x){
	bool bandera;
	struct recorridos *aux = primeroR;
	while(aux != NULL){
		if(x == aux->idR){
			return aux->costo;
		}else{
			aux = aux->siguiente;
			bandera = false;
		}
	}
	if(bandera = false){
		return 0;
	}
}

void mostrarR(){
	struct recorridos *aux = primeroR;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
	cout<<"Id recorrido"<<setw(8)<<"Nombre"<<setw(15)<<"Fecha salida"<<setw(15)<<"Hora salida"<<setw(15)<<"Hora llegada"<<setw(20)<<"Lugar de reunión"<<setw(15)<<"Costo"<<endl;	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	while(aux != NULL){
		cout<<aux->idR<<setw(15);
		cout<<aux->nombreR<<setw(15);
		cout<<aux->fechaS<<setw(5);
		cout<<aux->horaS<<":00 hrs"<<setw(12);
		cout<<aux->horaL<<":00 hrs"<<setw(12);
		cout<<aux->lugarR<<setw(20);
		cout<<"$"<<aux->costo<<endl<<endl;
		aux = aux->siguiente;
	}
}

void agregaR(){
	struct recorridos *nuevo = (struct recorridos*)malloc(sizeof(struct recorridos));
	
	if(nuevo == NULL){
		cout<<"No hay memoria disponible."<<endl;
	}else{
		nuevo->idR = 10000+rand()%90000;
		validaCadena("Nombre de recorrido: ", nuevo->nombreR);
		//validaCadena("Fecha de salida: ", nuevo->fechaS);
		validaFecha("Fecha de salida (dd/mm/aaaa): ",nuevo->fechaS);
		nuevo->horaS = validaEntero("Hora de salida: ");
		nuevo->horaL = validaEntero("Hora de llegada: ");
		validaCadena("Lugar de reuníon: ", nuevo->lugarR);
		nuevo->costo = validaEntero("Costo: $");
		
		if(primeroR == NULL){
			nuevo->siguiente = NULL;
			nuevo->anterior = NULL;
			primeroR = nuevo;
			ultimoR = nuevo;
		}else{
			nuevo->anterior = ultimoR;
			nuevo->siguiente = NULL;
			ultimoR->siguiente = nuevo;
			ultimoR = nuevo;
		}
		guardaRecorrido(nuevo);
	}
}

void modificar(){
	int opc = 0, id = 0, cont = 0;
	bool bandera;
	
	struct recorridos *aux = primeroR;
	mostrarR();
	
	id = validaEntero("Id del recorrido a modificar: ");
	
	while(aux != NULL){
		while(aux != NULL && id != aux->idR){
			aux = aux->siguiente;
		}
		if(aux == NULL){
			cout<<endl<<"Recorrido inexistente."<<endl;
			return;
		}
			do{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
				cout<<"Id recorrido"<<setw(8)<<"Nombre"<<setw(15)<<"Fecha salida"<<setw(15)<<"Hora salida"<<setw(15)<<"Hora llegada"<<setw(20)<<"Lugar de reunión"<<setw(15)<<"Costo"<<endl<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				cout<<aux->idR<<setw(15);
				cout<<aux->nombreR<<setw(15);
				cout<<aux->fechaS<<setw(5);
				cout<<aux->horaS<<":00 hrs"<<setw(12);
				cout<<aux->horaL<<":00 hrs"<<setw(12);
				cout<<aux->lugarR<<setw(20);
				cout<<"$"<<aux->costo<<endl<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
				gotoxy(40,5);
				cout<<"1.Modificar nombre.";
				gotoxy(40,7);
				cout<<"2.Modificar fecha de salida.";
				gotoxy(40,9);
				cout<<"3.Modificar hora de salida.";
				gotoxy(40,11);
				cout<<"4.Modificar hora de llegada.";
				gotoxy(40,13);
				cout<<"5.Modificar lugar de reunión.";
				gotoxy(40,15);
				cout<<"6.Modificar costo.";
				gotoxy(40,17);
				cout<<"7.Regresar."<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
				opc = validaEntero("Opción del menú: ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				switch(opc){
					case 1:
						system("cls");
						validaCadena("Nuevo nombre de recorrido: ", aux->nombreR);
						cout<<endl<<"Presione cualquier tecla para continuar...";
						getch();
						cont++;
						break;
						
					case 2:
						system("cls");
						validaCadena("Nueva fecha de salida: ", aux->fechaS);
						cout<<endl<<"Presione cualquier tecla para continuar...";
						getch();
						cont++;
						break;
						
					case 3: 
						system("cls");
						aux->horaS = validaEntero("Nueva hora de salida: ");
						cout<<endl<<"Presione cualquier tecla para continuar...";
						getch();
						cont++;
						break;
						
					case 4: 
						system("cls");
						aux->horaL = validaEntero("Nueva hora de llegada: ");
						cout<<endl<<"Presione cualquier tecla para continuar...";
						getch();
						cont++;
						break;
						
					case 5: 
						system("cls");
						validaCadena("Nuevo lugar de reunión: ", aux->lugarR);
						cout<<endl<<"Presione cualquier tecla para continuar...";
						getch();
						cont++;
						break;
						
					case 6:
						system("cls");
						aux->costo = validaEntero("Nuevo costo: ");
						cout<<endl<<"Presione cualquier tecla para continuar...";
						getch();
						cont++;
						break;				
				}
			}while(opc != 7);
			bandera = true;
			break;
	}
	if(cont > 0){
		cout<<"Recorrido modificado."<<endl<<endl;
	}
}
