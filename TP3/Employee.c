#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Employee.h"


/** \brief Compara los elementos por Id
 *
 * \param empl1 void*
 * \param empl2 void*
 * \return int retorna (1) si el primer elemento es mayor-(-1) si el elemento es menor -(0) si son iguales
 *
 */
int employee_compareById(void* emp1, void* emp2)
{
    int status=0;
    int id1;
    int id2;
    employee_getId((Employee*)emp1, &id1);
    employee_getId((Employee*)emp2, &id2);
    if(emp1 != NULL && emp2 !=NULL)
    {


        if(id1 > id2)
        {
            status=1;
        }

        else if(id1 < id2)
        {
            status=-1;
        }

    }

    return status;
}


/** \brief Compara los elementos por Horas Trabajdas
 *
 * \param empl1 void*
 * \param empl2 void*
 * \return int retorna (1) si el primer elemento es mayor-(-1) si el elemento es menor -(0) si son iguales
 *
 */
int employee_compareByHorasTrabajadas(void* emp1, void* emp2)
{
    int status=0;
    Employee* e1;
    Employee* e2;

    if(emp1 != NULL && emp2 !=NULL)
    {
        e1=(Employee*)emp1;
        e2=(Employee*)emp2;

        if((e1->horasTrabajadas)>(e2->horasTrabajadas))
        {
            status=1;
        }

        if((e1->horasTrabajadas)<(e2->horasTrabajadas))
        {
            status=-1;
        }

        if((e1->horasTrabajadas)==(e2->horasTrabajadas))
        {
            status=0;
        }

    }

    return status;
}

/** \brief Compara los elementos por Sueldo
 *
 * \param empl1 void*
 * \param empl2 void*
 * \return int retorna (1) si el primer elemento es mayor-(-1) si el elemento es menor -(0) si son iguales
 *
 */
int employee_compareBySueldo(void* emp1, void* emp2)
{
    int status=0;
    Employee* e1;
    Employee* e2;

    if(emp1 != NULL && emp2 !=NULL)
    {
        e1=(Employee*)emp1;
        e2=(Employee*)emp2;


        if((e1->sueldo)>(e2->sueldo))
        {
            status=1;
        }

        if((e1->sueldo)<(e2->sueldo))
        {
            status=-1;
        }

        if((e1->sueldo)==(e2->sueldo))
        {
            status=0;
        }

    }

    return status;
}

/** \brief Compara los elementos por Nombre
 *
 * \param empl1 void*
 * \param empl2 void*
 * \return int retorna (1) si el primer elemento es mayor-(-1) si el elemento es menor -(0) si son iguales
 *
 */
int employee_compareByNombre(void* emp1, void* emp2)
{
    int status=0;
    Employee* e1;
    Employee* e2;

    if(emp1 != NULL && emp2 !=NULL)
    {
        e1=(Employee*)emp1;
        e2=(Employee*)emp2;

        if((e1->nombre)>(e2->nombre))
        {
            status=1;
        }

        if((e1->nombre)<(e2->nombre))
        {
            status=-1;
        }

        if((e1->nombre)==(e2->nombre))
        {
            status=0;
        }
    }

    return status;
}

/** \brief Establece el tamanio del nuevo empleado
 *
 * \return Puntero con el tamanio del empleado
 *
 */
Employee* employee_new()
{
    Employee* empleado;
    empleado = malloc(sizeof(Employee));
    return empleado;
}

/** \brief Toma las horas trabajadas del empleado
 *
 * \param Employee* this
 * \param int* horasTrabajadas
 * \return Retorna int [1] si se pudo tomar correcatamente los datos y [0] si no se pudo
 *
 */

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int status=-1;

    if(this!=NULL && horasTrabajadas > 0)
    {
        *horasTrabajadas=this->horasTrabajadas;
        status = 0;
    }
    return status;
}

/** \brief Asigna el valor de horas trabajadas del empleado
 *
 * \param Employee* this
 * \param int horasTrabajadas
 * \return Retorna  int [1] si se pudo asignar correctamente las horas trabajadas y [0] si no se pudo
 *
 */

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int status = -1;
    if (this !=  NULL && horasTrabajadas> 0)
    {
        this->horasTrabajadas=horasTrabajadas;
        status=0;
    }
    return status;
}

/** \brief Toma el ID del empleado
 *
 * \param Employee* this
 * \param int* id
 * \return Retorna int [1] si se pudo tomar correcatamente los datos y [0] si no se pudo
 *
 */

int employee_getId(Employee* this, int* id)
{
    int status = -1;

    if( this != NULL && id>0)
    {
        *id =this->id;
        status = 0;
    }
    return status;
}

/** \brief Asigna el valor de id del empleado
 *
 * \param Employee* this
 * \param int id
 * \return Retorna  int [1] si se pudo asignar correctamente el id y [0] si no se pudo
 *
 */

int employee_setId(Employee* this, int id)
{
    int status = -1;

    if(this != NULL && id>0)
    {
        this->id=id;
        status=0;
    }
    return status;
}

/** \brief Toma el nombre del empleado
 *
 * \param Employee* this
 * \param char* nombre
 * \return Retorna int [1] si se pudo tomar correcatamente los datos y [0] si no se pudo
 *
 */

int employee_getNombre(Employee* this, char* nombre)
{
    int status = -1;

    if(this != NULL)
    {
        strcpy(nombre, this->nombre);
        status=0;
    }
    return status;
}

/** \brief Asigna el nombre del empleado
 *
 * \param Employee* this
 * \param char* nombre
 * \return Retorna  int [1] si se pudo asignar correctamente el nombre del empleado y [0] si no se pudo
 *
 */

int employee_setNombre(Employee* this, char* nombre)
{
    int status= -1;

    if( this != NULL)
    {
        strcpy(this->nombre,nombre);
        status=0;

    }
    return status;
}

/** \brief Toma el sueldo del empleado
 *
 * \param Employee* this
 * \param int* sueldo
 * \return Retorna int [1] si se pudo tomar correcatamente los datos y [0] si no se pudo
 *
 */

int employee_getSueldo(Employee* this, int* sueldo)
{
    int status=-1;
    if( this !=NULL && sueldo>0)
    {
        *sueldo=this->sueldo;
        status=0;
    }
    return status;
}

/** \brief Asigna el sueldo del empleado
 *
 * \param Employee* this
 * \param int sueldo
 * \return Retorna  int [1] si se pudo asignar correctamente el sueldo y [0] si no se pudo
 *
 */

int employee_setSueldo(Employee* this, int sueldo)
{
    int status = -1;

    if( this != NULL && sueldo > 0)
    {
        this->sueldo=sueldo;
        status =0;
    }
    return status;
}

/** \brief Asigna el todos los datos del empleado
 *
 * \param char* idStr
 * \param char* nombreStr
 * \param char* horasTrabajdasStr
 * \param char* sueldoStr
 * \return Retorna puntero empleado con todos los datos ya asignados y NULL si no se pudo asignar correctamente
 *
 */


Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    int id;

    int horasTrabajadas;
    int sueldo;

    id= atoi(idStr);
    horasTrabajadas= atoi(horasTrabajadasStr);
    sueldo= atoi(sueldoStr);

    Employee* empleado = employee_new();
    if(empleado!=NULL)
    {
        employee_setId(empleado,id);
        employee_setNombre(empleado, nombreStr);
        employee_setHorasTrabajadas(empleado, horasTrabajadas);
        employee_setSueldo(empleado,sueldo);

    }

    return empleado;
}
