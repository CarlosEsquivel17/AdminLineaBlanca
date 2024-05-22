void menu(){
	setlocale(LC_CTYPE, "Spanish");
	int opc = 0;//VARIABLE DEL MENU GENERAL
	int opcH = 0;//VARIABLE DEL MENU DE HOTELES
	int opcR = 0;//VARIABLE DEL MENU DE RECORRIDO
	int opcRR = 0;//VARIABLE PARA RESERVAR RECORRIDO
	do{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		gotoxy(40,0);
		cout<<"MENÚ PRINCIPAL DEL PROGRAMA."<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
		gotoxy(40,2);
		cout<<"1. Hoteles.";
		gotoxy(40,4);
		cout<<"2. Recorridos.";
		gotoxy(40,6);
		cout<<"3. Reservaciones.";
		gotoxy(40,8);
		cout<<"4. Salir."<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
//		cout<<"Opción a elegir: ";
//		fflush(stdin);
//		scanf("%d", &opc);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		opc = validaEntero("Opción a elegir: ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<"Presione cualquier tecla para continuar."<<endl;
		getch();
		switch(opc){
			case 1://OPCINES PARA HOTEL
				do{
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
					gotoxy(40,0);
					cout<<"1. Agregar hotel.";
					gotoxy(40,2);
					cout<<"2. Modificar hotel.";
					gotoxy(40,4);
					cout<<"3. Eliminar hotel.";
					gotoxy(40,6);
					cout<<"4. Consultar hotel.";
					gotoxy(40,8);
					cout<<"5. Regresar al menú principal."<<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
					opcH = validaEntero("Opción a elegir: ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
					switch(opcH){
						case 1:
							system("cls");
							agregarHoteles();
							cout<<endl;
							cout<<endl<<"Presione cualquier tecla para continuar."<<endl;
							getch();
							break;
							
						case 2:
							system("cls");
							modificarHotel();//Modifica la lista
							modificaHotel();//escribe la lista en el archivo
							cout<<"Presione cualquier tecla para continuar."<<endl;
							getch();
							break;
							
						case 3:
							system("cls");
							eliminarIdHotel();
							modificaHotel();//Actuliza el archivo
							cout<<"Presione cualquier tecla para continuar."<<endl;
							getch();
							break;
							
						case 4:
							system("cls");
							mostrarHoteles();
							cout<<"Presione cualquier tecla para continuar."<<endl;
							getch();
							break;	
					}
				}while(opcH != 5);
				//opc = 0;
				break;
				
			case 2://AGREGAR Y MODIFICAR DATOS DEL REOCORRIDO
				do{
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
					gotoxy(40,0);
					cout<<"1. Agregar recorrido.";
					gotoxy(40,2);
					cout<<"2. Modificar los datos del recorrido.";
					gotoxy(40,4);
					cout<<"3. Regresar."<<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
					opcR = validaEntero("Opción a elegir: ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
					switch(opcR){
						case 1: 
							system("cls");
							agregaR();
							cout<<"Presione cualquier tecla para continuar."<<endl;
							getch();
							break;	
							
						case 2:
							system("cls");
							modificar();//Modifica la lista
							modificaRec();//Se escribe la lista modificada en el archivo
							cout<<"Presione cualquier tecla para continuar."<<endl;
							getch();
							break;		
					}
				}while(opcR != 3);
				//opc = 0;
				break;
				
			case 3://MENU PARA RESERVAR RECORRIDO 
				do{
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
					gotoxy(40,0);
					cout<<"1. Hacer reservación.";
					gotoxy(40,2);
					cout<<"2. Modificar estado.";
					gotoxy(40,4);
					cout<<"3. Regresar."<<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
					opcRR = validaEntero("Opción a elegir: ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
					switch(opcRR){
						case 1:
							reservar();
							cout<<endl<<"Presione cualquier tecla para continuar."<<endl;
							getch();
							break;	
						
						case 2:
							//Modificar
							//mostrarRes();
							modificaEst();
							modificaReserv();//Modifica el archivo
							cout<<"Presione cualquier tecla para continuar."<<endl;
							getch();
							break;	
								
					}
				}while(opcRR != 3);
				break;
		}
		if(opc == 4){
			exit(1);
		}
		opc = 0;
	}while(opc != 4);
}
