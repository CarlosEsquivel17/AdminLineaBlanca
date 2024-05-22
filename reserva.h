void reservar(){
	int idH = 0, idR = 0;
	char idC[7];
	bool bandera = true;
	struct reserva *nuevo;
	struct clientes *auxC = primeroC;
	struct recorridos *auxR = primeroR;
	struct hoteles *auxH = primeroH;
	
	nuevo = (struct reserva*)malloc(sizeof(struct reserva));
	
	while(bandera != false){
		system("cls");
		mostrarClientes();
		cout<<endl;
		
		auxC = primeroC;
		cout<<"Ingrese Id de cliente a seleccionar: ";
		cin>>idC;
		while(auxC != NULL && strcmp(auxC->idC, idC) != 0){
			auxC = auxC->siguiente;
		}
		if(auxC == NULL){
			cout<<"Cliente no existente."<<endl;
			bandera = true;
			cout<<"Presiona cualquier tecla para reintentar...";
			getch();
		}else{
			strcpy(nuevo->idC, auxC->idC);
			bandera = false;
			break;
		}
	}
	
	bandera = true;
	
	while(bandera != false){
		system("cls");
		mostrarR();
		cout<<endl;
		auxR = primeroR;
//		cout<<"Ingrese Id de recorrido a seleccionar: ";
//		cin>>idR;
		idR = validaEntero("Ingrese id de recorrido a seleccionar: ");
		while(auxR != NULL && auxR->idR != idR){
			auxR = auxR->siguiente;
		}
		if(auxR == NULL){
			cout<<"Recorrido no existente."<<endl;
			bandera = true;
			cout<<"Presiona cualquier tecla para reintentar...";
			getch();
		}else{
			nuevo->idR = auxR->idR;
			bandera = false;
			break;
		}
	}
	
	bandera = true;
		
	while(bandera != false){
		system("cls");
		mostrarHoteles();
		cout<<endl;
		auxH = primeroH;
//		cout<<"Ingrese Id del hotel a seleccionar: ";
//		cin>>idH;
		idH = validaEntero("Ingrese id del hotel a seleccionar: ");
		while(auxH != NULL && auxH->idH != idH){
			auxH = auxH->siguiente;
		}
		if(auxH == NULL){
			cout<<"Hotel no existente."<<endl;
			bandera = true;
			cout<<"Presione cualquier tecla para reintentar...";
			getch();
		}else{
			nuevo->idH = auxH->idH;
			bandera = false;
			break;
		}
	}
	
	system("cls");
	nuevo->idReserv = rand()%(99999-10000);
	nuevo->numPer = validaEntero("Número de personas: ");
	nuevo->subTotal = auxR->costo * nuevo->numPer;
	strcpy(nuevo->estado, "ACTIVO");
	validaFecha("Fecha de reservación (dd/mm/aaaa): ", nuevo->fecha);
	
	if(primeroRes == NULL){
		nuevo->siguiente = NULL;
		nuevo->anterior = NULL;
		primeroRes = nuevo;
		ultimoRes = nuevo;
	}else{
		nuevo->anterior = ultimoRes;
		nuevo->siguiente = NULL;
		ultimoRes->siguiente = nuevo;
		ultimoRes = nuevo;
	}
	guardaReservas(nuevo);
	
	system("cls");
	struct reserva *aux = ultimoRes;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
		for(int i = 0; i < 120;i++){
			printf("%c", 22);
		}
		cout<<endl;
		auxC = primeroC;
		auxR = primeroR;
		auxH = primeroH;
		while(auxH != NULL && auxH->idH != aux->idH){
			auxH = auxH->siguiente;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Hotel: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxH->cadena<<"\t"<<auxH->ciudad<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Reservación: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<aux->idReserv<<endl;
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		
		while(auxR != NULL && auxR->idR != aux->idR){
			auxR = auxR->siguiente;
		}
		cout<<"Recorrido: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxR->idR<<"\t"<<auxR->nombreR<<"\t";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Fecha de reserva: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<aux->fecha<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		
		while(auxC != NULL && strcmp(auxC->idC, aux->idC) != 0){
			auxC = auxC->siguiente;
		}
		cout<<"Cliente: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxC->idC<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Datos del cliente "<<endl<<endl;
		cout<<"Nombre: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxC->nombreC<<" "<<auxC->apellido<<"  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Dirección: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxC->direccion<<" ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Ciudad: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxC->ciudad<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Tel: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxC->tel<<"   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Correo: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxC->correo<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Fecha salida: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxR->fechaS<<"   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Hora de salida: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxR->horaS<<":00 hrs  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Hora llegada: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxR->horaL<<":00 hrs  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Lugar de reunión: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxR->lugarR<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Número de personas: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<aux->numPer<<"  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Costo unitario: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<"$"<<auxR->costo<<"  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Total: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<"$"<<aux->subTotal<<endl<<endl;
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
		for(int i = 0; i < 120;i++){
			printf("%c", 22);
		}
		cout<<endl;
	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

void mostrarRes(){
	struct reserva *aux = primeroRes;
	struct clientes *auxC = primeroC;
	struct recorridos *auxR = primeroR;
	struct hoteles *auxH = primeroH;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
	cout<<"Mostrando reservaciones."<<endl<<endl;
	while(aux != NULL && strcmp(aux->estado,"CANCELADO") != 0){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
		for(int i = 0; i < 120;i++){
			printf("%c", 22);
		}
		cout<<endl;
		auxC = primeroC;
		auxR = primeroR;
		auxH = primeroH;
		while(auxH != NULL && auxH->idH != aux->idH){
			auxH = auxH->siguiente;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Hotel: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxH->cadena<<"\t"<<auxH->ciudad<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Reservación: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<aux->idReserv<<endl;
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		
		while(auxR != NULL && auxR->idR != aux->idR){
			auxR = auxR->siguiente;
		}
		cout<<"Recorrido: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxR->idR<<"\t"<<auxR->nombreR<<"\t";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Fecha de reserva: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<aux->fecha<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		
		while(auxC != NULL && strcmp(auxC->idC, aux->idC) != 0){
			auxC = auxC->siguiente;
		}
		cout<<"Cliente: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxC->idC<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Datos del cliente "<<endl<<endl;
		cout<<"Nombre: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxC->nombreC<<" "<<auxC->apellido<<"  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Dirección: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxC->direccion<<" ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Ciudad: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxC->ciudad<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Tel: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxC->tel<<"   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Correo: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxC->correo<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Fecha salida: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxR->fechaS<<"   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Hora de salida: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxR->horaS<<":00 hrs  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Hora llegada: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxR->horaL<<":00 hrs  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Lugar de reunión: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<auxR->lugarR<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Número de personas: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<aux->numPer<<"  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Costo unitario: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<"$"<<auxR->costo<<"  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		cout<<"Total: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<"$"<<aux->subTotal<<endl<<endl;
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
		for(int i = 0; i < 120;i++){
			printf("%c", 22);
		}
		cout<<endl;
		
		aux = aux->siguiente;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

void modificaEst(){
	int id = 0;
	bool bandera = true;
	struct reserva *aux = primeroRes;
	while(bandera != false){
		system("cls");
		aux = primeroRes;
		mostrarRes();
		cout<<endl;
		id = validaEntero("Ingrese Id de reservación a cancelar: ");
		while(aux != NULL && id != aux->idReserv){
			aux = aux->siguiente;
		}
		if(aux == NULL){
			bandera = true;
			cout<<"Reservación no existente."<<endl;
			cout<<"Presione cualquier tecla para reintentar...";
			getch();
		}else{
			strcpy(aux->estado, "CANCELADO");
			bandera = false;
			cout<<"Reservación cancelada.";
			break;
		}
	}
}
