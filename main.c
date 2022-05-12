//
//  Mini-Proyecto 2 - Programación Avanzada
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *ptrFile;
FILE *ptrFile2;
char line[300];

struct _empleado
{
	int id;
	char nombre[50];
	char apellidos[100];
	int idDept;
	char fechaNacim[11];
	char fechaContrat[11];
	char ciudad[50];
	int proyActuales;
	double salario;
};

struct _departamento
{
	int idDept;
	char nombre[80];
	char descripcion[150];
	int piso;
	double presupuesto;
};

struct _usuario
{
	char usuario[50];
	char password[50];
};

int lecturaTabla1(struct _empleado *empleados)
{
	int contEmp = 0;

	ptrFile = fopen("table_1.txt", "r");

	if (ptrFile != NULL)
	{
		// printf("table_1.txt open\n");

		while (!feof(ptrFile))
		{
			while (fgets(line, sizeof(line), ptrFile))
			{
				int state = 0;
				int finished = 0;

				// Que no sea la primera línea y que no haya terminado de leer la línea
				while (contEmp != 0 && state < 5)
				{
					char elem[150] = {NULL};

					// Obtener primera palabra antes del ;
					char *token = strtok(line, ";");
					strcpy(elem, token);

					while (token != NULL && finished == 0)
					{
						switch (state)
						{
						case 0:
							empleados[contEmp - 1].id = atoi(elem);
							break;
						case 1:
							strcpy(empleados[contEmp - 1].nombre, elem);
							break;
						case 2:
							strcpy(empleados[contEmp - 1].apellidos, elem);
							break;
						case 3:
							empleados[contEmp - 1].idDept = atoi(elem);
							break;
						case 4:
							strcpy(empleados[contEmp - 1].fechaNacim, elem);
							break;
						case 5:
							strcpy(empleados[contEmp - 1].fechaContrat, elem);
							break;
						case 6:
							strcpy(empleados[contEmp - 1].ciudad, elem);
							break;
						case 7:
							empleados[contEmp - 1].proyActuales = atoi(elem);
							break;
						case 8:
							empleados[contEmp - 1].salario = atof(elem);
							finished = 1;
							break;
						default:
							printf("done");
						}
						state++;

						if (finished != 1)
						{
							// Obtener palabra antes del ;
							token = strtok(NULL, ";");
							strcpy(elem, token);
						}
					}
				}

				// Cambiar de línea de registros
				contEmp++;
			}
		}

		if (fclose(ptrFile) == 0)
		{
			// printf("table_1.txt closed\n");
		}
		else
		{
			printf("Error in fclose for table_1.txt\n");
		}
	}
	else
	{
		printf("Error in fopen for table_1.txt\n");
	}

	return contEmp;
};

int lecturaTabla2(struct _departamento *departamentos)
{
	int contDept = 0;

	ptrFile = fopen("table_2.txt", "r");

	if (ptrFile != NULL)
	{
		// printf("table_2.txt open\n");

		while (!feof(ptrFile))
		{
			while (fgets(line, sizeof(line), ptrFile))
			{
				int state = 0;
				int finished = 0;

				// Que no sea la primera línea y que no haya terminado de leer la línea
				while (contDept != 0 && state < 5)
				{
					char elem[150] = {NULL};

					// Obtener primera palabra antes del ;
					char *token = strtok(line, ";");
					strcpy(elem, token);

					while (token != NULL && finished == 0)
					{
						switch (state)
						{
						case 0:
							departamentos[contDept - 1].idDept = atoi(elem);
							break;
						case 1:
							strcpy(departamentos[contDept - 1].nombre, elem);
							break;
						case 2:
							strcpy(departamentos[contDept - 1].descripcion, elem);
							break;
						case 3:
							departamentos[contDept - 1].piso = atoi(elem);
							break;
						case 4:
							departamentos[contDept - 1].presupuesto = atof(elem);
							finished = 1;
							break;
						default:
							printf("done");
						}
						state++;

						if (finished != 1)
						{
							// Obtener palabra antes del ;
							token = strtok(NULL, ";");
							strcpy(elem, token);
						}
					}
				}

				// Cambiar de línea de registros
				contDept++;
			}
		}

		if (fclose(ptrFile) == 0)
		{
			// printf("table_2.txtclosed\n");
		}
		else
		{
			printf("Error in fclose for table_2.txt\n");
		}
	}
	else
	{
		printf("Error in fopen for table_2.txt\n");
	}

	return contDept;
};

void printColumnasTabla1()
{
	printf("1. id\n");
	printf("2. Nombre\n");
	printf("3. apellidos\n");
	printf("4. idDepartamento\n");
	printf("5. Fecha de Nacimiento\n");
	printf("6. Fecha de Contratacion\n");
	printf("7. Ciudad\n");
	printf("8. # de Proyectos act\n");
	printf("9. Salario\n");
}

void printColumnasTabla2()
{
	printf("1. idDept\n");
	printf("2. Nombre\n");
	printf("3. Descripcion\n");
	printf("4. Piso\n");
	printf("5. Presupuesto\n");
}

void selectTabla1(struct _empleado *empleados, int contEmp, int columnas[9], int opp, int col, int valNum, char valStr[150])
{
	for (int i = 0; i < contEmp; i++)
	{
		switch (col)
		{
		case 1: // id
			if (opp == 1)
			{
				if (empleados[i].id != valNum)
					continue;
			}
			else if (opp == 2)
			{
				if (empleados[i].id == valNum)
					continue;
			}
			else if (opp == 3)
			{
				if (empleados[i].id > valNum)
					continue;
			}
			else if (opp == 4)
			{
				if (empleados[i].id < valNum)
					continue;
			}
			break;
		case 2: // nombre
			if (opp == 1)
			{
				if (strcasecmp(empleados[i].nombre, valStr) != 0)
					continue;
			}
			else if (opp == 2)
			{
				if (strcasecmp(empleados[i].nombre, valStr) == 0)
					continue;
			}
			break;
		case 3: // apellidos
			if (opp == 1)
			{
				if (strcasecmp(empleados[i].apellidos, valStr) != 0)
					continue;
			}
			else if (opp == 2)
			{
				if (strcasecmp(empleados[i].apellidos, valStr) == 0)
					continue;
			}
			break;
		case 4: // idDept
			if (opp == 1)
			{
				if (empleados[i].idDept != valNum)
					continue;
			}
			else if (opp == 2)
			{
				if (empleados[i].idDept == valNum)
					continue;
			}
			else if (opp == 3)
			{
				if (empleados[i].idDept > valNum)
					continue;
			}
			else if (opp == 4)
			{
				if (empleados[i].idDept < valNum)
					continue;
			}
			break;
		case 5: // fechaNacimiento
			if (opp == 1)
			{
				if (strcasecmp(empleados[i].fechaNacim, valStr) != 0)
					continue;
			}
			else if (opp == 2)
			{
				if (strcasecmp(empleados[i].fechaNacim, valStr) == 0)
					continue;
			}
			break;
		case 6: // fechaContra
			if (opp == 1)
			{
				if (strcasecmp(empleados[i].fechaContrat, valStr) != 0)
					continue;
			}
			else if (opp == 2)
			{
				if (strcasecmp(empleados[i].fechaContrat, valStr) == 0)
					continue;
			}
			break;
		case 7: // ciudad
			if (opp == 1)
			{
				if (strcasecmp(empleados[i].ciudad, valStr) != 0)
					continue;
			}
			else if (opp == 2)
			{
				if (strcasecmp(empleados[i].ciudad, valStr) == 0)
					continue;
			}
			break;
		case 8: // proyecto actuales
			if (opp == 1)
			{
				if (empleados[i].proyActuales != valNum)
					continue;
			}
			else if (opp == 2)
			{
				if (empleados[i].proyActuales == valNum)
					continue;
			}
			else if (opp == 3)
			{
				if (empleados[i].proyActuales > valNum)
					continue;
			}
			else if (opp == 4)
			{
				if (empleados[i].proyActuales < valNum)
					continue;
			}
			break;
		case 9: // salario
			if (opp == 1)
			{
				if (empleados[i].salario != valNum)
					continue;
			}
			else if (opp == 2)
			{
				if (empleados[i].salario == valNum)
					continue;
			}
			else if (opp == 3)
			{
				if (empleados[i].salario > valNum)
					continue;
			}
			else if (opp == 4)
			{
				if (empleados[i].salario < valNum)
					continue;
			}
			break;

		default:
			break;
		}
		if (columnas[0] == 1)
		{
			printf("%d;", empleados[i].id);
		}
		if (columnas[1] == 1)
		{
			printf("%s;", empleados[i].nombre);
		}
		if (columnas[2] == 1)
		{
			printf("%s;", empleados[i].apellidos);
		}
		if (columnas[3] == 1)
		{
			printf("%d;", empleados[i].idDept);
		}
		if (columnas[4] == 1)
		{
			printf("%s;", empleados[i].fechaNacim);
		}
		if (columnas[5] == 1)
		{
			printf("%s;", empleados[i].fechaContrat);
		}
		if (columnas[6] == 1)
		{
			printf("%s;", empleados[i].ciudad);
		}
		if (columnas[7] == 1)
		{
			printf("%d;", empleados[i].proyActuales);
		}
		if (columnas[8] == 1)
		{
			printf("%0.f;", empleados[i].salario);
		}
		printf("\n");
	}
};

void selectTabla2(struct _departamento *departamentos, int contDept, int columnas[9], int opp, int col, int valNum, char valStr[150])
{
	for (int i = 0; i < contDept; i++)
	{
		switch (col)
		{
		case 1: // idDept
			if (opp == 1)
			{
				if (departamentos[i].idDept != valNum)
					continue;
			}
			else if (opp == 2)
			{
				if (departamentos[i].idDept == valNum)
					continue;
			}
			else if (opp == 3)
			{
				if (departamentos[i].idDept > valNum)
					continue;
			}
			else if (opp == 4)
			{
				if (departamentos[i].idDept < valNum)
					continue;
			}
			break;
		case 2: // nombre
			if (opp == 1)
			{
				if (strcasecmp(departamentos[i].nombre, valStr) != 0)
					continue;
			}
			else if (opp == 2)
			{
				if (strcasecmp(departamentos[i].nombre, valStr) == 0)
					continue;
			}
			break;
		case 3: // descripcion
			if (opp == 1)
			{
				if (strcasecmp(departamentos[i].descripcion, valStr) != 0)
					continue;
			}
			else if (opp == 2)
			{
				if (strcasecmp(departamentos[i].descripcion, valStr) == 0)
					continue;
			}
			break;
		case 4: // piso
			if (opp == 1)
			{
				if (departamentos[i].piso != valNum)
					continue;
			}
			else if (opp == 2)
			{
				if (departamentos[i].piso == valNum)
					continue;
			}
			else if (opp == 3)
			{
				if (departamentos[i].piso > valNum)
					continue;
			}
			else if (opp == 4)
			{
				if (departamentos[i].piso < valNum)
					continue;
			}
			break;
		case 5: // presupuesto
			if (opp == 1)
			{
				if (departamentos[i].presupuesto != valNum)
					continue;
			}
			else if (opp == 2)
			{
				if (departamentos[i].presupuesto == valNum)
					continue;
			}
			else if (opp == 3)
			{
				if (departamentos[i].presupuesto > valNum)
					continue;
			}
			else if (opp == 4)
			{
				if (departamentos[i].presupuesto < valNum)
					continue;
			}
			break;
		default:
			break;
		}
		if (columnas[0] == 1)
		{
			printf("%d;", departamentos[i].idDept);
		}
		if (columnas[1] == 1)
		{
			printf("%s;", departamentos[i].nombre);
		}
		if (columnas[2] == 1)
		{
			printf("%s;", departamentos[i].descripcion);
		}
		if (columnas[3] == 1)
		{
			printf("%d;", departamentos[i].piso);
		}
		if (columnas[4] == 1)
		{
			printf("%0.f;", departamentos[i].presupuesto);
		}
		printf("\n");
	}
};

void impresionTabla1(struct _empleado *empleados, int contEmp)
{
	for (int i = 0; i < contEmp; i++)
	{
		printf("%d; %s; %s; %d; %s; %s; %s; %d; %0.f;\n", empleados[i].id, empleados[i].nombre, empleados[i].apellidos, empleados[i].idDept, empleados[i].fechaNacim, empleados[i].fechaContrat, empleados[i].ciudad, empleados[i].proyActuales, empleados[i].salario);
	}
};

void impresionTabla2(struct _departamento *departamentos, int contDept)
{
	for (int i = 0; i < contDept; i++)
	{
		printf("%d; %s; %s; %d; %.0f;\n", departamentos[i].idDept, departamentos[i].nombre, departamentos[i].descripcion, departamentos[i].piso, departamentos[i].presupuesto);
	}
}

int joinCondition(struct _empleado emp, int col1, struct _departamento dep, int col2)
{
	switch (col1)
	{
	case 1:			   // id
		if (col2 == 1) // idDept
		{
			return (emp.id == dep.idDept);
		}
		else if (col2 == 4) // piso
		{
			return (emp.id == dep.piso);
		}
		break;
	case 2:			   // nombre
		if (col2 == 2) // nombre
		{
			if (strcasecmp(emp.nombre, dep.nombre) == 0)
				return 1;
		}
		else if (col2 == 3) // descripcion
		{
			if (strcasecmp(emp.nombre, dep.descripcion) == 0)
				return 1;
		}
		break;
	case 3:			   // apellidos
		if (col2 == 2) // nombre
		{
			if (strcasecmp(emp.apellidos, dep.nombre) == 0)
				return 1;
		}
		else if (col2 == 3) // descripcion
		{
			if (strcasecmp(emp.apellidos, dep.descripcion) == 0)
				return 1;
		}
		break;
	case 4:			   // idDept
		if (col2 == 1) // idDept
		{
			return (emp.idDept == dep.idDept);
		}
		else if (col2 == 4) // piso
		{
			return (emp.idDept == dep.piso);
		}
		break;
	case 5:			   // fechaNacim
		if (col2 == 2) // nombre
		{
			if (strcasecmp(emp.fechaNacim, dep.nombre) == 0)
				return 1;
		}
		else if (col2 == 3) // descripcion
		{
			if (strcasecmp(emp.fechaContrat, dep.descripcion) == 0)
				return 1;
		}
		break;
	case 6:			   // fechaContrat
		if (col2 == 2) // nombre
		{
			if (strcasecmp(emp.fechaContrat, dep.nombre) == 0)
				return 1;
		}
		else if (col2 == 3) // descripcion
		{
			if (strcasecmp(emp.fechaContrat, dep.descripcion) == 0)
				return 1;
		}
		break;
	case 7:			   // Ciudad
		if (col2 == 2) // nombre
		{
			if (strcasecmp(emp.ciudad, dep.nombre) == 0)
				return 1;
		}
		else if (col2 == 3) // descripcion
		{
			if (strcasecmp(emp.ciudad, dep.descripcion) == 0)
				return 1;
		}
		break;
	default:
		return 0;
		break;
	}

	return 0;
}

void joinTable(struct _empleado *empleados, int contEmp, int columnas1[9], struct _departamento *departamentos, int contDept, int columnas2[5], int col1, int col2)
{
	for (int i = 0; i < contEmp; i++)
	{
		for (int j = 0; j < contDept; j++)
		{
			if (joinCondition(empleados[i], col1, departamentos[j], col2) == 1)
			{
				if (columnas1[0] == 1)
				{
					printf("%d;", empleados[i].id);
				}
				if (columnas1[1] == 1)
				{
					printf("%s;", empleados[i].nombre);
				}
				if (columnas1[2] == 1)
				{
					printf("%s;", empleados[i].apellidos);
				}
				if (columnas1[3] == 1)
				{
					printf("%d;", empleados[i].idDept);
				}
				if (columnas1[4] == 1)
				{
					printf("%s;", empleados[i].fechaNacim);
				}
				if (columnas1[5] == 1)
				{
					printf("%s;", empleados[i].fechaContrat);
				}
				if (columnas1[6] == 1)
				{
					printf("%s;", empleados[i].ciudad);
				}
				if (columnas1[7] == 1)
				{
					printf("%d;", empleados[i].proyActuales);
				}
				if (columnas1[8] == 1)
				{
					printf("%0.f;", empleados[i].salario);
				}
				if (columnas2[0] == 1)
				{
					printf("%d;", departamentos[j].idDept);
				}
				if (columnas2[1] == 1)
				{
					printf("%s;", departamentos[j].nombre);
				}
				if (columnas2[2] == 1)
				{
					printf("%s;", departamentos[j].descripcion);
				}
				if (columnas2[3] == 1)
				{
					printf("%d;", departamentos[j].piso);
				}
				if (columnas2[4] == 1)
				{
					printf("%0.f;", departamentos[j].presupuesto);
				}
				break;
				printf("\n");
			}
		}
	}
}

int main(int argc, const char *argv[])
{
	struct _empleado empleados[50] = {NULL, "", "", NULL, "", "", " ", NULL, 0};
	struct _departamento departamentos[20] = {NULL, "", "", NULL, 0};
	int opcion = 0;

	// Cantidad de registros
	int contEmp = lecturaTabla1(empleados) - 1;
	int contDept = lecturaTabla2(departamentos) - 1;

	// Menú
	printf("Base de Datos de Empleados y Departamentos\n");
	printf("Opciones:\n");
	printf("1. Ver tabla 1 - Empleados.\n");
	printf("2. Ver tabla 2 - Departamentos.\n");
	printf("3. Hacer query SELECT.\n");
	printf("4. Hacer query JOIN.\n");
	printf("5. Hacer query INSERT.\n");
	printf("0. Salir.\n");
	printf("Teclee la opción deseada: ");
	scanf("%d", &opcion);
	do
	{
		switch (opcion)
		{
		case 0:
			printf("Proceso terminado. Vuelva pronto.\n");
			break;
		case 1:
			printf("Tabla 1\n");
			impresionTabla1(empleados, contEmp);
			break;
		case 2:
			printf("Tabla 2\n");
			impresionTabla2(departamentos, contDept);
			break;
		case 3:
			printf("Query SELECT\n");
			printf("1. SELECT a Tabla 1 - Empleados\n");
			printf("2. SELECT a Tabla 2 - Departamentos\n");
			printf("Teclee la opción deseada: ");
			int selectOption = 0;
			scanf("%d", &selectOption);
			if (selectOption == 1)
			{
				int columnas[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
				printColumnasTabla1();
				printf("0. TERMINAR SELECCION\n");
				int sel = 0;
				do
				{
					printf("Teclee la columna deseada: ");
					scanf("%d", &sel);
					if (sel > 0)
					{
						columnas[sel - 1] = 1;
					}

				} while (sel != 0);

				int opp = 5;
				int col = 0;
				int valNum = 0;
				char valStr[150];
				printf("1. igual (=) \n");
				printf("2. no igual (!=) \n");
				printf("3. menor que (<)\n");
				printf("4. mayor que (>)\n");
				printf("0. NINGUNA\n");
				printf("Selecciona operacion para WHERE: ");
				scanf("%d", &opp);

				if (opp != 0)
				{
					printColumnasTabla1();
					printf("Selecciona la columna: ");
					scanf("%d", &col);
					printf("Escibra el valor: ");
					if (col == 1 || col == 4 || col == 8 || col == 9)
					{
						scanf("%d", &valNum);
					}
					else
					{
						scanf("%s", &valStr);
					}
				}
				selectTabla1(empleados, contEmp, columnas, opp, col, valNum, valStr);
			}
			else if (selectOption == 2)
			{
				int columnas[9] = {0, 0, 0, 0, 0};
				printColumnasTabla2();
				printf("0. TERMINAR SELECCION\n");
				int sel = 0;
				do
				{
					printf("Teclee la columna deseada: ");
					scanf("%d", &sel);
					if (sel > 0)
					{
						columnas[sel - 1] = 1;
					}

				} while (sel != 0);

				int opp = 5;
				int col = 0;
				int valNum = 0;
				char valStr[150];
				printf("1. igual (=) \n");
				printf("2. no igual (!=) \n");
				printf("3. menor que (<) (numerico)\n");
				printf("4. mayor que (>) (numerico)\n");
				printf("0. NINGUNA\n");
				printf("Selecciona operacion para WHERE: ");
				scanf("%d", &opp);
				if (opp != 0)
				{
					printColumnasTabla2();
					printf("Selecciona la columna: ");
					scanf("%d", &col);

					printf("Escibra el valor: ");
					if (col == 1 || col == 4 || col == 5)
					{
						scanf("%d", &valNum);
					}
					else
					{
						scanf("%s", &valStr);
					}
				}
				selectTabla2(departamentos, contDept, columnas, opp, col, valNum, valStr);
			}

			break;
		case 4:
			printf("Query JOIN\n");
			int col1 = 0;
			int col2 = 0;
			int sel = 0;

			printf("TABLA 1\n");
			int columnas1[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
			printColumnasTabla1();
			printf("0. TERMINAR SELECCION\n");
			do
			{
				printf("Teclee la columna deseada: ");
				scanf("%d", &sel);
				if (sel > 0)
				{
					columnas1[sel - 1] = 1;
				}

			} while (sel != 0);
			printf("Selecciona la columna para union: ");
			scanf("%d", &col1);

			printf("TABLA 2\n");
			int columnas2[5] = {0, 0, 0, 0, 0};
			printColumnasTabla2();
			printf("0. TERMINAR SELECCION\n");
			do
			{
				printf("Teclee la columna deseada: ");
				scanf("%d", &sel);
				if (sel > 0)
				{
					columnas2[sel - 1] = 1;
				}

			} while (sel != 0);
			printf("Selecciona la columna para union: ");
			scanf("%d", &col2);

			joinTable(empleados, contEmp, columnas1, departamentos, contDept, columnas2, col1, col2);

			break;
		case 5:
			printf("\nQuery INSERT\n");
			printf("1. INSERT a Tabla 1 - Empleados\n");
			printf("2. INSERT a Tabla 2 - Departamentos\n");
			printf("0. Regresar al menú\n");
			printf("Teclee la opción deseada: ");
			int insertOpcion = 0;
			scanf("%d", &insertOpcion);
			if (insertOpcion == 1)
			{
				ptrFile2 = fopen("table_1.txt", "a");
				if (ptrFile2 != NULL)
				{
					// printf("table_1.txt open\n");
					int id, idDept, proyActuales;
					double salario;
					char temp, nombre[50], apellidos[100], fechaNacim[11], fechaContrat[11], ciudad[50];
					printf("Id (entero): ");
					scanf("%d", &id);
					empleados[contEmp].id = id;
					printf("Nombre (string): ");
					scanf("%c", &temp); // Limpiar buffer
					scanf("%[^\n]", nombre);
					strcpy(empleados[contEmp].nombre, nombre);
					printf("Apellidos (string): ");
					scanf("%c", &temp);
					scanf("%[^\n]", apellidos);
					strcpy(empleados[contEmp].apellidos, apellidos);
					printf("Id de Departamento (entero): ");
					scanf("%d", &idDept);
					empleados[contEmp].idDept = idDept;
					printf("Fecha de Nacimiento (Día/Mes/Año): ");
					scanf("%c", &temp);
					scanf("%s", fechaNacim);
					strcpy(empleados[contEmp].fechaNacim, fechaNacim);
					printf("Fecha de Contratación (Día/Mes/Año): ");
					scanf("%s", fechaContrat);
					strcpy(empleados[contEmp].fechaContrat, fechaContrat);
					printf("Ciudad (string): ");
					scanf("%c", &temp);
					scanf("%[^\n]", ciudad);
					strcpy(empleados[contEmp].ciudad, ciudad);
					printf("Proyectos Actuales (entero): ");
					scanf("%d", &proyActuales);
					empleados[contEmp].proyActuales = proyActuales;
					printf("Salario (double): ");
					scanf("%lf", &salario);
					empleados[contEmp].salario = salario;
					fprintf(ptrFile, "\n%d;%s;%s;%d;%s;%s;%s;%d;%.0f;", id, nombre, apellidos, idDept, fechaNacim, fechaContrat, ciudad, proyActuales, salario);
					contEmp++;

					if (fclose(ptrFile2) == 0)
					{
						printf("table_1.txt closed\n");
					}
					else
					{
						printf("Error in fclose for table_1.txt\n");
					}
				}
				else
				{
					printf("Error in fopen for table_1.txt\n");
				}
			}
			else if (insertOpcion == 2)
			{
				ptrFile2 = fopen("table_2.txt", "a");
				if (ptrFile2 != NULL)
				{
					// printf("table_2.txt open\n");
					int idDept, piso;
					char temp, nombre[80], descripcion[150];
					double presupuesto;
					printf("Id (entero): ");
					scanf("%d", &idDept);
					departamentos[contDept].idDept = idDept;
					printf("Nombre (string): ");
					scanf("%c", &temp); // Limpiar buffer
					scanf("%[^\n]", nombre);
					strcpy(departamentos[contDept].nombre, nombre);
					printf("Descripción (string): ");
					scanf("%c", &temp);
					scanf("%[^\n]", descripcion);
					strcpy(departamentos[contDept].descripcion, descripcion);
					printf("Piso (entero): ");
					scanf("%d", &piso);
					departamentos[contDept].piso = piso;
					printf("Presupuesto (double): ");
					scanf("%lf", &presupuesto);
					departamentos[contDept].presupuesto = presupuesto;
					fprintf(ptrFile, "\n%d;%s;%s;%d;%.0f;", idDept, nombre, descripcion, piso, presupuesto);
					contDept++;

					if (fclose(ptrFile2) == 0)
					{
						printf("File closed\n");
					}
					else
					{
						printf("Error in fclose for table_2.txt\n");
					}
				}
				else
				{
					printf("Error in fopen for table_2.txt\n");
				}
			}
			break;
		default:
			printf("Opción inválida, intente de nuevo.\n");
		}
		printf("\nBase de Datos de Empleados y Departamentos\n");
		printf("Opciones:\n");
		printf("1. Ver tabla 1 - Empleados.\n");
		printf("2. Ver tabla 2 - Departamentos.\n");
		printf("3. Hacer query SELECT.\n");
		printf("4. Hacer query JOIN.\n");
		printf("5. Hacer query INSERT.\n");
		printf("0. Salir.\n");
		printf("Teclee la opción deseada: ");
		scanf("%d", &opcion);
	} while (opcion != 0);

	return 0;
}
