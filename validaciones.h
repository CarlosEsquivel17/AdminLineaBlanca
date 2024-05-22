float validaFlotante(const char mensaje[]){
	int continuar=0;
	float flotante=0;
	
	do{
		//system("cls");
		printf("%s",mensaje);
		continuar = scanf("%f", &flotante);	
		fflush(stdin);
	}while (continuar != 1);
	
	return flotante;
}

int validaEntero(const char mensaje[]){
	int continuar=0;
	int entero=0;
	
	do{
		//system("cls");
		printf("%s",mensaje);
		continuar = scanf("%d", &entero);
		fflush(stdin);
	}while (continuar != 1);
	
	return entero;
}

void validaCadena(const char mensaje[], const char cadena[]){
	bool bandera = true;
	while(bandera){
		//system("cls");
		fflush(stdin);
		printf("%s", mensaje);
		scanf("%[^\n]",cadena);
		fflush(stdin);		
		if(strlen(cadena)>29){
			continue;
		}else{
			for(int i = 0; i<strlen(cadena); i++){
				if(isalpha(cadena[i]) || cadena[i]==' ' || cadena[i]=='+' || cadena[i]=='-' || cadena[i]=='#'){
					if (i== (strlen(cadena)-1)){
						bandera=false;
					}
				}else{
					break;
				}
			}
		}				
	}
}

void correo(const char mensaje[],char electronico[]){
	bool bandera= true,bandera1=true;
    fflush(stdin);
    do{ 
        //system("cls");
        bandera= true,bandera1=true;
        printf("%s ",mensaje);
        scanf("%[^\n]",electronico);
        fflush(stdin);
        if(strlen(electronico)>45){
            continue;
        }else{
            if(strchr(electronico,64)!=NULL){
                bandera=false;
            }
            if(strchr(electronico,46)!=NULL){
                bandera1=false;
            }
        }
    }while(bandera || bandera1);
}

void validaNum(const char mensaje[], char cadena[]){
	char num[11] = "";
	while(strlen(num) < 10){
		cout<<mensaje;
		gets(num);
		fflush(stdin);
	}
	strcpy(cadena, num);
	return;
}

void validaFecha(const char mensaje[], char cadena[]){
	bool bandera = true;
	while(bandera != false){
		//system("cls");
		fflush(stdin);
		printf("%s", mensaje);
		scanf("%[^\n]",cadena);
		fflush(stdin);
		for(int i = 0; i < strlen(cadena); i++){
			if(cadena[2] == 47 || cadena[2] == 45){
				if(cadena[5] == 47 || cadena[5] == 45){
					bandera = false;
					return;
				}
			}
			if(isdigit(cadena[i]) == 0){
				bandera = true;
			}
		}
		if(bandera = true){
			cout<<"Fecha invalida."<<endl;
		}
		
	}
}

