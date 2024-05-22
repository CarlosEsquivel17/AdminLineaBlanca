void guardaHotel(struct hoteles *aux){
	FILE *arch;
	
	if(!(arch = fopen("hoteles.xls", "a+"))){
		cout<<"Error al intentar crear el archivo";
		exit(1);
	}
	fprintf(arch, "%d\t", aux->idH);
	fprintf(arch, "%s\t", aux->cadena);
	fprintf(arch, "%s\t", aux->ciudad);
	fprintf(arch, "%s\t", aux->direccion);
	fprintf(arch, "%s\t", aux->telefonoC);
	fprintf(arch, "%s\n", aux->correo);
	
	fclose(arch);
}

void leeHoteles(){
	char cadena[T], ciudad[T], direccion[T], tel[11], correo[T];
	int id;
	struct hoteles *aux;
	FILE *arch;
	
	if(!(arch = fopen("hoteles.xls", "r"))){
		cout<<"Error al intentar leer el arcivo.";
		exit(1);
	}
	
	while(!feof(arch)){
		fscanf(arch, "%d\t", &id);
		fscanf(arch, "%[^\t]\n", cadena);
		fscanf(arch, "%[^\t]\n", ciudad);
		fscanf(arch, "%[^\t]\n", direccion);
		fscanf(arch, "%[^\t]\n", tel);
		fscanf(arch, "%[^\n]\n", correo);
		
		aux = (struct hoteles*)malloc(sizeof(struct hoteles));
		
		aux->idH = id;
		strcpy(aux->cadena, cadena);
		strcpy(aux->ciudad, ciudad);
		strcpy(aux->direccion, direccion);
		strcpy(aux->telefonoC, tel);
		strcpy(aux->correo, correo);
			
		if(primeroH == NULL){
			aux->anterior = NULL;
			primeroH = aux;
			ultimoH = aux;
		}else{
			aux->anterior = ultimoH;
			ultimoH->siguiente = aux;
			ultimoH = aux;
		}
	}
	//free(aux);
	fclose(arch);
}

void modificaHotel(){
	struct hoteles *aux = primeroH;
	FILE *arch, *f;
	
	if(!(f = fopen("hoteles.xls", "r"))){
		cout<<"Error al intentar leer el archivo.";
		exit(1);
	}
	
	if(!(arch = fopen("copia.xls", "a+"))){
		cout<<"Error al intentar crear el archivo.";
		exit(1);
	}
	while(aux != NULL){
		fprintf(arch, "%d\t", aux->idH);
		fprintf(arch, "%s\t", aux->cadena);
		fprintf(arch, "%s\t", aux->ciudad);
		fprintf(arch, "%s\t", aux->direccion);
		fprintf(arch, "%s\t", aux->telefonoC);
		fprintf(arch, "%s\n", aux->correo);
		
		aux = aux->siguiente;
	}
	fclose(arch);
	fclose(f);
	remove("hoteles.xls");
	rename("copia.xls", "hoteles.xls");
}

void guardaRecorrido(struct recorridos *aux){
	FILE *arch;
	
	if(!(arch = fopen("recorridos.xls", "a+"))){
		cout<<"Error al intentar crear el archivo";
		exit(1);
	}
	fprintf(arch, "%d\t", aux->idR);
	fprintf(arch, "%s\t", aux->nombreR);
	fprintf(arch, "%s\t", aux->fechaS);
	fprintf(arch, "%d\t", aux->horaS);
	fprintf(arch, "%d\t", aux->horaL);
	fprintf(arch, "%s\t", aux->lugarR);
	fprintf(arch, "%d\n", aux->costo);
	
	fclose(arch);
	
}

void leeRecorridos(){
	char nombre[T], fecha[10], lugar[T];
	int id, hS, hL, costo;
	struct recorridos *aux;
	FILE *arch;
	
	if(!(arch = fopen("recorridos.xls", "r"))){
		cout<<"Error al intentar leer el arcivo.";
		exit(1);
	}
	
	while(!feof(arch)){
		fscanf(arch, "%d\t", &id);
		fscanf(arch, "%[^\t]\n", nombre);
		fscanf(arch, "%[^\t]\n", fecha);
		fscanf(arch, "%d\t", &hS);
		fscanf(arch, "%d\t", &hL);
		fscanf(arch, "%[^\t]\n", lugar);
		fscanf(arch, "%d\n", &costo);
		
		aux = (struct recorridos*)malloc(sizeof(struct recorridos));
		
		aux->idR = id;
		aux->horaL = hL;
		aux->horaS = hS;
		aux->costo = costo;
		strcpy(aux->nombreR, nombre);
		strcpy(aux->fechaS, fecha);
		strcpy(aux->lugarR, lugar);
			
		if(primeroR == NULL){
			aux->anterior = NULL;
			aux->siguiente = NULL;
			primeroR = aux;
			ultimoR = aux;
		}else{
			aux->anterior = ultimoR;
			ultimoR->siguiente = aux;
			aux->siguiente = NULL;
			ultimoR = aux;
		}
	}
	fclose(arch);
}

void modificaRec(){
	struct recorridos *aux = primeroR;
	FILE *arch, *f;
	
	if(!(f = fopen("recorridos.xls", "r"))){
		cout<<"Error al intentar leer el archivo.";
		exit(1);
	}
	
	if(!(arch = fopen("copia.xls", "a+"))){
		cout<<"Error al intentar crear el archivo.";
		exit(1);
	}
	while(aux != NULL){
		fprintf(arch, "%d\t", aux->idR);
		fprintf(arch, "%s\t", aux->nombreR);
		fprintf(arch, "%s\t", aux->fechaS);
		fprintf(arch, "%d\t", aux->horaS);
		fprintf(arch, "%d\t", aux->horaL);
		fprintf(arch, "%s\t", aux->lugarR);
		fprintf(arch, "%d\n", aux->costo);
		
		aux = aux->siguiente;
	}
	fclose(arch);
	fclose(f);
	remove("recorridos.xls");
	rename("copia.xls", "recorridos.xls");
}

void guardaReservas(struct reserva *aux){
	FILE *arch;
	
	if(!(arch = fopen("reserva.xls", "a+"))){
		cout<<"Error al intentar crear el archivo";
		exit(1);
	}
	
	fprintf(arch, "%d\t", aux->idReserv);
	fprintf(arch, "%d\t", aux->idH);
	fprintf(arch, "%d\t", aux->idR);
	fprintf(arch, "%s\t", aux->idC);
	fprintf(arch, "%s\t", aux->fecha);
	fprintf(arch, "%d\t", aux->numPer);
	fprintf(arch, "%d\t", aux->subTotal);
	fprintf(arch, "%s\n", aux->estado);
}

void leeReserv(){
	FILE *arch;
	int idRe, idH, idR, total, numP;
	char idC[7], fecha[10], estado[10];
	struct reserva *aux;
	
	if(!(arch = fopen("reserva.xls", "r"))){
		cout<<"Error al intentar leer el archivo.";
		exit(1);
	}
	
	while(!feof(arch)){
		fscanf(arch, "%d\t", &idRe);
		fscanf(arch, "%d\t", &idH);
		fscanf(arch, "%d\t", &idR);
		fscanf(arch, "%[^\t]\n", idC);
		fscanf(arch, "%[^\t]\n", fecha);
		fscanf(arch, "%d\t", &numP);
		fscanf(arch, "%d\t", &total);
		fscanf(arch, "%[^\n]\n", estado);
		
		aux = (struct reserva*)malloc(sizeof(struct reserva));
		
		aux->idH = idH;
		aux->idR = idR;
		aux->idReserv = idRe;
		aux->numPer = numP;
		aux->subTotal = total;
		strcpy(aux->estado, estado);
		strcpy(aux->fecha, fecha);
		strcpy(aux->idC, idC);
		
		if(primeroRes == NULL){
			aux->anterior = NULL;
			aux->siguiente = NULL;
			primeroRes = aux;
			ultimoRes = aux;
		}else{
			aux->anterior = ultimoRes;
			aux->siguiente = NULL;
			ultimoRes->siguiente = aux;
			ultimoRes = aux;
		}
	}
	fclose(arch);
}

void modificaReserv(){
	struct reserva *aux = primeroRes;
	FILE *arch, *f;
	
	if(!(f = fopen("reserva.xls", "r"))){
		cout<<"Error al intentar leer el archivo.";
		exit(1);
	}
	
	if(!(arch = fopen("copia.xls", "a+"))){
		cout<<"Error al intentar crear el archivo.";
		exit(1);
	}
	
	while(aux != NULL){
		fprintf(arch, "%d\t", aux->idReserv);
		fprintf(arch, "%d\t", aux->idH);
		fprintf(arch, "%d\t", aux->idR);
		fprintf(arch, "%s\t", aux->idC);
		fprintf(arch, "%s\t", aux->fecha);
		fprintf(arch, "%d\t", aux->numPer);
		fprintf(arch, "%d\t", aux->subTotal);
		fprintf(arch, "%s\n", aux->estado);
		
		aux = aux->siguiente;
	}
	fclose(arch);
	fclose(f);
	remove("reserva.xls");
	rename("copia.xls", "reserva.xls");
}
