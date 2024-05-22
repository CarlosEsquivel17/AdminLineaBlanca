void buscarC(char id[7]){
	bool bandera;
	//char id[7];
	struct clientes *aux = primeroC;
	while(bandera){
		fflush(stdin);
		cout<<"Id del cliente: ";
		scanf("%[^\n]", id);
		getch();
		while(aux != NULL){
			if(strcmp(id, aux->idC) == 0){
				bandera = false;
				return;
			}else{
				aux = aux->siguiente;
			}
		}
	}
}

void listaClientes(struct clientes *aux){
	if(primeroC == NULL){
		//aux->siguiente = NULL;
		primeroC = aux;
		primeroC->siguiente = NULL;
		ultimoC = aux;
	}else{
		ultimoC->siguiente = aux;
		aux->siguiente = NULL;
		ultimoC = aux;
	}
}

void leeClientes(){
	struct clientes *aux;
	char mat[7], nom[T], ap[T], dire[T], cd[T], tel[11], mail[T];
//	aux = (struct clientes*)malloc(sizeof(struct clientes));
	FILE *arch;
	
	if(!(arch = fopen("Clientes.xls", "r"))){
		cout<<"Error al intentar leer el arcivo.";
		exit(1);
	}
	while(!feof(arch)){
		fscanf(arch, "%[^\t]\n", mat);
		fscanf(arch, "%[^\t]\n", nom);
		fscanf(arch, "%[^\t]\n", ap);
		fscanf(arch, "%[^\t]\n", dire);
		fscanf(arch, "%[^\t]\n", cd);
		fscanf(arch, "%[^\t]\n", tel);
		fscanf(arch, "%[^\n]\n", mail);
		
		aux = (struct clientes*)malloc(sizeof(struct clientes));
		
		strcpy(aux->idC, mat);
		strcpy(aux->nombreC, nom);
		strcpy(aux->apellido, ap);
		strcpy(aux->direccion, dire);
		strcpy(aux->ciudad, cd);
		strcpy(aux->tel, tel);
		strcpy(aux->correo, mail);
		listaClientes(aux);
		
		if(primeroC == NULL){
			primeroC = aux;
			primeroC->siguiente = NULL;
			ultimoC = primeroC;
		}else{
			ultimoC->siguiente = aux;
			aux->siguiente = NULL;
			ultimoC = aux;
		}
	}
	//free(aux);
	fclose(arch);
}

void mostrarClientes(){
	struct clientes *aux = primeroC;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
	cout<<"Mostrando clientes."<<endl;
	cout<<"Id\tNombre\tApellido\tDirección\tCiudad\tTelefono\tCorreo\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	while(aux != NULL){
		cout<<aux->idC<<"\t";
		cout<<aux->nombreC<<"\t";
		cout<<aux->apellido<<"\t";
		cout<<aux->direccion<<"\t";
		cout<<aux->ciudad<<"\t";
		cout<<aux->tel<<"\t";
		cout<<aux->correo<<endl;
		aux = aux->siguiente;
	}
	cout<<endl;
}
