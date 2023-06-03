Proceso RegistroClubGuitarra
	
    Dimension miembros[10, 9];  // Asumiendo una matriz de 10 filas y 9 columnas
    Definir opcion, codigo, nombre, apellido, anio, facultad, edad, contacto, departamento como Cadena;
    Definir posicion como Entero;  // Agregar la definición de la variable posición
    opcion <- "";
	
	
    Mientras opcion <> "5" Hacer
        Escribir "----- Registro del Club de Guitarra -----";
        Escribir "1. Agregar datos del miembro";
        Escribir "2. Editar datos de los miembros";
        Escribir "3. Eliminar miembro";
        Escribir "4. Visualizar registro de miembros";
        Escribir "5. Salir del programa";
        Escribir "Ingrese el número de opción:";
        Leer opcion;
		
        Segun opcion Hacer 
            Caso "1":
                Escribir "----- Cargar datos del miembro -----";
                Escribir "Ingrese el código:";
                Leer codigo;
                Escribir "Ingrese el nombre:";
                Leer nombre;
                Escribir "Ingrese el apellido:";
                Leer apellido;
                Escribir "Ingrese el año:";
                Leer anio;
                Escribir "Ingrese la facultad:";
                Leer facultad;
                Escribir "Ingrese la edad:";
                Leer edad;
                Escribir "Ingrese el contacto:";
                Leer contacto;
                Escribir "Ingrese el departamento:";
                Leer departamento;
				
                // Lógica para agregar el miembro a la matriz miembros
                // ...
				
                Escribir "Datos del miembro cargados correctamente.";
            Caso "2":
                Escribir "----- Editar datos de los miembros -----";
                Escribir "Ingrese el código del miembro a editar:";
                Leer codigo;
		
				
                Si posicion <> -1 Entonces
                    Escribir "Ingrese el nuevo nombre:";
                    Leer nombre;
                    Escribir "Ingrese el nuevo apellido:";
                    Leer apellido;
                    Escribir "Ingrese el nuevo año:";
                    Leer anio;
                    Escribir "Ingrese la nueva facultad:";
                    Leer facultad;
                    Escribir "Ingrese la nueva edad:";
                    Leer edad;
                    Escribir "Ingrese el nuevo contacto:";
                    Leer contacto;
                    Escribir "Ingrese el nuevo departamento:";
                    Leer departamento;
					
                    // Lógica para editar los datos del miembro en la matriz miembros
                    // ...
                    Escribir "Datos del miembro editados correctamente.";
                Sino
                    Escribir "Miembro no encontrado.";
                FinSi
            Caso "3":
                Escribir "----- Eliminar miembro -----";
                Escribir "Ingrese el código del miembro a eliminar:";
                Leer codigo;
	
				
                Si posicion <> -1 Entonces
                    // Lógica para eliminar el miembro de la matriz miembros
                    // ...
                    Escribir "Miembro eliminado correctamente.";
                Sino
                    Escribir "Miembro no encontrado.";
                FinSi
			Caso "4":
				Escribir "----- Buscar miembro por ID -----";
				Escribir "Ingrese el código del miembro a buscar:";
				Leer codigo;
		
				
				Si posicion <> -1 Entonces
					// Lógica para buscar al miembro en la matriz miembros
					// ...
					
					// Supongamos que encontramos al miembro en la posición deseada
					Escribir "Miembro encontrado:";
					Escribir "Código: " + miembros[posicion, 0];
					Escribir "Nombre: " + miembros[posicion, 1];
					Escribir "Apellido: " + miembros[posicion, 2];
					Escribir "Año: " + miembros[posicion, 3];
					Escribir "Facultad: " + miembros[posicion, 4];
					Escribir "Edad: " + miembros[posicion, 5];
					Escribir "Contacto: " + miembros[posicion, 6];
					Escribir "Departamento: " + miembros[posicion, 7];
				Sino
					Escribir "Miembro no encontrado.";
				FinSi

            Caso "5":
                Escribir "Programa finalizado.";
        FinSegun
    FinMientras


FinProceso
