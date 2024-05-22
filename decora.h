void gotoxy(int x, int y){
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void portada(){
	int aux;
	FILE *arch = fopen("portada.txt", "r");
	
	for(int i = 0; i < 48; i++){
		for(int j = 0; j < 30; j++){
			fscanf(arch, "%d\t", &aux);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), aux);
			printf("%c", 219);
		}
		printf("\n");
	}
	fclose(arch);
}

void datos(){
	setlocale(LC_CTYPE,"Spanish");
	gotoxy(50,10);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
	printf("UNIVERSIDAD POLITECNICA DE SAN LUIS POTOSÍ");
	gotoxy(50,12);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
	printf("PROGRAMACIÓN 2; Proyecto Final");
	gotoxy(50,14);
	cout<<"Maestra: MTI. Guadalupe Ledesma Ramos.";
	gotoxy(50,16);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
	printf("Carlos Emiliano Esquivel Badillo-176841");
	gotoxy(50,18);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
	printf("Presione cualquier tecla para iniciar...");
	getch();
}
