void usuario(const char mensaje[]){
	setlocale(LC_CTYPE,"Spanish");
	char user[20];
	bool bandera=true;
	while(bandera){
		system("cls");
		printf("\n%s",mensaje);
		fgets(user,6,stdin);//controlar el tamañp de la cadena
		fflush(stdin);
		if(strcmp("admin",user)==0){
			bandera=false;
		}
		else
		{
			printf("Usuario incorrecto: %s \n",user);
			fflush(stdin);
			cout<<"Presione cualquier tecla para reintentar...";
			getchar();
		}
	}
}
void contrasenia(const char mensaje[]){
	setlocale(LC_CTYPE,"Spanish");
	char user[20];
	bool bandera=true;
	char pass[5]="";
	while(bandera){
		system("cls");
		printf("\n%s",mensaje);
		for(int i=0;i<5;i++){
			pass[i]=getch();
			printf("*");
		}
		system("cls");
		if(strcmp("admin",pass)==0){
			system("cls");
			printf("\nBienvenido %s\n\n",user);
			cout<<endl<<"Presione cualquier tecla para continuar...";
			getchar();
			system("cls");
			bandera=false;
		}
		else{
			printf("\nContraseña incorrecta\n");
			system("pause");
		}
	}
}
