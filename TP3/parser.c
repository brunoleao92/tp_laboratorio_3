#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return Retorna int [1] si se pudo cargar los correctamente los datos del texto.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char id[120];
    char nombre[120];
    char horasTrabajadas[120];
    char salario[120];

    Employee* pEmployee;
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,salario);
    while (!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,salario);
        pEmployee=employee_newParametros(id,nombre,horasTrabajadas,salario);
        ll_add(pArrayListEmployee,pEmployee);
    }
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return Retorna int [1] si se pudo cargar los correctamente los datos del texto en binario.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    Employee auxEmployee;
    int Cantidad;
    while(!feof(pFile))
    {
       pEmployee=employee_new();
       Cantidad=fread(&auxEmployee,sizeof(Employee),1,pFile);
       if(Cantidad==1&&pEmployee!=NULL)
       {
           pEmployee->id=auxEmployee.id;
           strcpy(pEmployee->nombre,auxEmployee.nombre);
           pEmployee->horasTrabajadas=auxEmployee.horasTrabajadas;
           pEmployee->sueldo=auxEmployee.sueldo;
           ll_add(pArrayListEmployee,pEmployee);
       }
       else if(Cantidad!=1)
       {
           if(!feof(pFile))
           {
               printf("\nError al cargar el archivo\n");
               break;
           }
       }

    }

    return 1;
}
