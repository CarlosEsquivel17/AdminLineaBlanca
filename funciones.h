int buscarH(){
	bool bandera = true;
	int x = 0;
	struct hoteles *aux = primeroH;
	while(bandera == true){
		cout<<"Id de hotel: ";
		fflush(stdin);
		scanf("%d", &x);
		while(aux != NULL){
			if(x == aux->idH){
				bandera = false;
				break;
			}else{
				aux = aux->siguiente;
				bandera = true;
			}
		}
	}
	return x;
}

void mostrarHoteles(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
	cout<<"Id hotel"<<setw(8)<<"Cadena"<<setw(15)<<"Ciudad"<<setw(15)<<"Dirección"<<setw(12)<<"Teléfono"<<setw(15)<<"Correo"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	struct hoteles *aux = primeroH;
	while(aux != NULL){
		cout<<aux->idH<<setw(13);
		cout<<aux->cadena<<setw(13);
		cout<<aux->ciudad<<setw(15);
		cout<<aux->direccion<<setw(15);
		cout<<aux->telefonoC<<setw(25);
		cout<<aux->correo<<endl<<endl;
		aux = aux->siguiente;
	}
}

void agregarHoteles(){//Se insertan al final

	setlocale(LC_CTYPE, "Spanish");
	struct hoteles *nuevo = (struct hoteles*)malloc(sizeof(struct hoteles));
	
	if(nuevo == NULL){
		cout<<"No hay memoria disponible."<<endl;
	}else{
		nuevo->idH = 1000+rand()%9000;//Numero de 5 digitos
		validaCadena("Cadena: ", nuevo->cadena);
		validaCadena("Ciudad: ", nuevo->ciudad);
		validaCadena("Dirección: ", nuevo->direccion);
		validaNum("Número de contacto: ", nuevo->telefonoC);
		correo("E-mail de contacto: ", nuevo->correo);
		
		if(primeroH == NULL){
			nuevo->anterior = NULL;
			primeroH = nuevo;
			ultimoH = nuevo;
		}else{
			nuevo->anterior = ultimoH;
			ultimoH->siguiente = nuevo;
			ultimoH = nuevo;
		}
		cout<<endl<<"Hotel agregado."<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Id hotel"<<setw(8)<<"Cadena"<<setw(15)<<"Ciudad"<<setw(15)<<"Dirección"<<setw(12)<<"Teléfono"<<setw(15)<<"Correo"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<nuevo->idH<<setw(13);
		cout<<nuevo->cadena<<setw(13);
		cout<<nuevo->ciudad<<setw(15);
		cout<<nuevo->direccion<<setw(15);
		cout<<nuevo->telefonoC<<setw(25);
		cout<<nuevo->correo<<endl<<endl;
		
		guardaHotel(nuevo);
	}
}

void borrarInicioHotel(){
	struct hoteles *auxiliar = primeroH;
	if(primeroH == NULL){
		cout<<"No hay elementos en la lista";
	}else{
		primeroH = primeroH->siguiente;
		primeroH->anterior = ultimoH;
		ultimoH->siguiente = primeroH;
		free(auxiliar);
		cout<<"Primer hotel eliminado."<<endl;
	}
}

void borrarFinalHotel(){
	struct hoteles *auxiliar = ultimoH;
	if(primeroH == NULL){
		cout<<"No hay elementos en la lista";
	}else{
		ultimoH = ultimoH->anterior;
		ultimoH->siguiente = primeroH;
		primeroH->anterior = ultimoH;
		free(auxiliar);
		cout<<"Último hotel eliminado."<<endl;
	}
}

void eliminarIdHotel(){
	struct hoteles *previo, *actual, *aux;
	
	bool bandera;
	int id = 0, i = 0;
	actual = primeroH;
	previo = actual;
	
	mostrarHoteles();
	cout<<"Ingrese ID del hotel a borrar: ";
	cin>>id;
	
	/*if(id == idP){
		borrarInicio();
		return;
	}
	
	if(id == idU){
		borrarFinal();
		return;
	}*/
	
	while(actual != NULL){
		if(id == actual->idH){
			aux = actual->siguiente;
			previo = actual->anterior;
			previo->siguiente = aux;
			aux->anterior = previo;
			free(actual);
			bandera = true;
			break;
		}else{
			previo = actual;
			actual = actual->siguiente;
			bandera = false;
		}
	}
	if(bandera == true){
		cout<<endl<<"Hotel eliminado."<<endl;
	}
	
	if(bandera == false){
		cout<<endl<<"No se eliminó el hotel."<<endl;
	}
}

void modificarHotel(){
	struct hoteles *aux = primeroH, *previo;
	int id = 0, opc = 0, cont = 0;
	bool bandera;
	
	mostrarHoteles();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	id = validaEntero("Ingrese ID del hotel a modificar: ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	while(aux != NULL){
		if(id == aux->idH){
			
			do{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
				cout<<"Id hotel"<<setw(8)<<"Cadena"<<setw(15)<<"Ciudad"<<setw(15)<<"Dirección"<<setw(12)<<"Teléfono"<<setw(15)<<"Correo"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				cout<<endl<<aux->idH<<setw(13)<<aux->cadena<<setw(13)<<aux->ciudad<<setw(15)<<aux->direccion<<setw(15)<<aux->telefonoC<<setw(25)<<aux->correo<<endl<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
				gotoxy(40,5);
				cout<<"1.Modidicar cadena";
				gotoxy(40,7);
				cout<<"2.Modificar ciudad";
				gotoxy(40,9);
				cout<<"3.Modificar dirección";
				gotoxy(40,11);
				cout<<"4.Modificar telefono";
				gotoxy(40,13);
				cout<<"5.Modificar correo";
				gotoxy(40,15);
				cout<<"6.Regresar"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
				opc = validaEntero("Opción: ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				switch(opc){
					
					case 1:
						system("cls");
						validaCadena("Nueva cadena: ", aux->cadena);
						cout<<"Presione cualquier tecla para continuar..."<<endl;
						getch();
						cont++;
						break;	
					
					case 2:
						system("cls");
						validaCadena("Nueva ciudad: ", aux->ciudad);
						cout<<"Presione cualquier tecla para continuar..."<<endl;
						getch();
						cont++;
						break;	
						
					case 3:
						system("cls");
						validaCadena("Nueva direccion: ", aux->direccion);
						cout<<"Presione cualquier tecla para continuar..."<<endl;
						getch();
						cont++;
						break;
						
					case 4:
						system("cls");
						fflush(stdin);
						validaNum("Nuevo telefono: ", aux->telefonoC);
						cout<<"Presione cualquier tecla para continuar..."<<endl;
						getch();
						cont++;
						break;	
						
					case 5:
						system("cls");
						correo("Nuevo correo: ", aux->correo);
						cout<<"Presione cualquier tecla para continuar..."<<endl;
						getch();
						cont++;
						break;			
				}
			}while(opc != 6);
			
			//bandera = true;
			break;
		}else{
			previo = aux;
			aux = aux->siguiente;
			bandera = false;
			if(aux == primeroH){
				aux = NULL;
			}
		}
	}
	if(cont > 0){
		cout<<endl<<"Hotel modificado."<<endl;
	}
	
	if(bandera == false){
	//	cout<<endl<<"No existe el hotel."<<endl;
	}
}

void consultaHotel(){
	struct hoteles *aux = primeroH;
	bool bandera;
	int id = validaEntero("Ingrese el ID del hotel a buscar: ");
	if(aux == NULL){
		cout<<"No hay hoteles registrados"<<endl;
	}else{
		while(aux != NULL){
			if(aux->idH == id){
				cout<<endl<<aux->idH<<setw(15)<<aux->cadena<<setw(15)<<aux->ciudad<<setw(15)<<aux->direccion<<setw(15)<<aux->telefonoC<<setw(15)<<aux->correo<<endl;
				bandera = true;
				return;
			}else{
				aux = aux->siguiente;
				if(aux == primeroH){
					aux = NULL;
				}
				bandera = false;
			}
		}
	}
	if(bandera == false){
		cout<<"No se encontró el hotel...";
	}
}
