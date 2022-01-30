#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct contacto
    {
        char id[10];
        char nombre[20];
        char apellido[20];
        char apellido2[20];
        char email[80];
        char telefono[20];
    };

typedef struct contacto Contacto;
FILE *fichero;
FILE *fich;
int opcion;

void Menu() {
  system("cls");
  printf ("-----AGENDA DE CONTACTOS-----\n");
  printf("1 ... Nuevo contacto\n");
  printf("2 ... Consultar contacto\n");
  printf("3 ... Eliminar contacto\n");
  printf("4 ... Modificar contacto\n");
  printf("5 ... Salir\n");
  scanf ("%d", &opcion);
  getchar();
}
void Eleminarinto(char cadena[200]) {
  cadena[strlen(cadena)-1]='\0';
}

/////////////////////////////////////
int valor;
int numeroedi;

void Nuevo(){

    Contacto primero;
    int sup=0;
    printf ("Nombre: \n");
    fgets(primero.nombre, 20, stdin);Eleminarinto(primero.nombre);
    printf ("Prime Apellido: \n");
    fgets(primero.apellido, 20, stdin);Eleminarinto(primero.apellido);
    printf ("Segundo Apellido: \n");
    fgets(primero.apellido2, 20, stdin);Eleminarinto(primero.apellido2);
    printf ("Telefono: \n");
    fgets(primero.telefono, 20, stdin);Eleminarinto(primero.telefono);
    printf ("Correo Electronico: \n");
    fgets(primero.email, 80, stdin);


    printf ("\nEl nuevo contacto es:\n");
    printf ("[ID]: %s | [Nombre] %s %s, %s | [Telefono]: %s | [Correo]: %s", primero.id, primero.apellido, primero.apellido2, primero.nombre, primero.telefono, primero.email);

    printf ("\n\nEstos datos se han almacenado.");



    fichero=fopen ("contactos.dat", "wb+");
    fwrite(&primero,sizeof(primero),1,fichero);
    //fprintf (fichero, "\n%s %s %s %d %s", primero.nombre, primero.apellido, primero.apellido2, primero.telefono, primero.email);


    fclose(fichero);
    printf("\nPulsa cualquier tecla para volver al menu\n");
    scanf ("%d", &sup);
    getchar();
    if (sup!=0) {
      opcion=0;
      Menu();
      sup=0;
    }
    }
void AddContacto(){
        Contacto primero;
        int sup=0;
        fich=fopen("id.dat","rb+");
        while (fread(&valor,sizeof(int),1,fich)) {
          if (valor>0) {
            numeroedi=valor+1;
            fseek(fich,-1*sizeof(valor),SEEK_CUR);
            fwrite(&numeroedi,sizeof(int),1,fich);
            fseek(fich,+1*sizeof(valor),SEEK_CUR);
          }

        }
        fclose(fichero);
        char cid[10];
        fich=fopen("id.dat","rb");
        while (fread(&valor,sizeof(int),1,fich)) {
          itoa(valor, cid, 10);
          strcpy(primero.id, cid);
        }
        fclose(fich);

        printf ("Nombre: \n");
        fgets(primero.nombre, 20, stdin);Eleminarinto(primero.nombre);
        printf ("Prime Apellido: \n");
        fgets(primero.apellido, 20, stdin);Eleminarinto(primero.apellido);
        printf ("Segundo Apellido: \n");
        fgets(primero.apellido2, 20, stdin);Eleminarinto(primero.apellido2);
        printf ("Telefono: \n");
        fgets(primero.telefono, 20, stdin);Eleminarinto(primero.telefono);
        printf ("Correo Electronico: \n");
        fgets(primero.email, 80, stdin);

    printf ("\nEl nuevo contacto es:\n");
    printf ("[ID]: %s | [Nombre] %s %s, %s | [Telefono]: %s | [Correo]: %s", primero.id, primero.apellido, primero.apellido2, primero.nombre, primero.telefono, primero.email);

    printf ("\n\nEstos datos se han almacenado.");


    fichero=fopen ("contactos.dat", "rb+");

    fseek (fichero, 0, SEEK_END);
    fwrite(&primero,sizeof(primero),1,fichero);
    //fprintf (fichero, "\n%s %s %s %d %s", primero.nombre, primero.apellido, primero.apellido2, primero.telefono, primero.email);
    fclose(fichero);

    printf("\nPulsa cualquier tecla para volver al menu\n");
    scanf ("%d", &sup);
    getchar();
    if (sup!=0) {
      opcion=0;
      Menu();
      sup=0;
    }
    }
void leerContactos(){

        char c;
        Contacto primero;
        fichero=fopen ("contactos.dat", "rb");
        while (fread(&primero,sizeof(primero),1,fichero)) {
          printf ("[ID]: %s | [Nombre] %s %s, %s | [Telefono]: %s | [Correo]: %s", primero.id, primero.apellido, primero.apellido2, primero.nombre, primero.telefono, primero.email);
          //printf("%s ", nombre);
        }
        fclose(fichero);
        int sup=0;
        printf("\nPulsa cualquier tecla para volver al menu\n");
        scanf ("%d", &sup);
        getchar();
        if (sup!=0) {
          opcion=0;
          Menu();
          sup=0;
        }
}
void leerContactosOtros(){

        char c;
        Contacto primero;
        fichero=fopen ("contactos.dat", "rb");
        while (fread(&primero,sizeof(primero),1,fichero)) {
          printf ("[ID]: %s | [Nombre] %s %s, %s | [Telefono]: %s | [Correo]: %s", primero.id, primero.apellido, primero.apellido2, primero.nombre, primero.telefono, primero.email);
          //printf("%s ", nombre);
        }
        fclose(fichero);
}
void borrarContacto (){
        int eliminarID;
        FILE *eliminar;
        Contacto primero;
        char supeli[10];
        printf ("\nLista de contactos: \n");
        leerContactosOtros();

        printf ("Introduce el ID que quieres borrar: ");
        scanf("%d", &eliminarID);getchar();
        //fgets(supeli, 10, stdin);Eleminarinto(supeli);

        eliminar=fopen("copia.dat","wb");
        fichero=fopen("contactos.dat","rb");
        while (fread(&primero,sizeof(primero),1,fichero)) {
            int x = atoi(primero.id);
            if (x != eliminarID) {
            fwrite(&primero,sizeof(primero),1,eliminar);
          }
        }
        fclose(fichero);
        fclose(eliminar);
        remove("contactos.dat");
        rename("copia.dat","contactos.dat");

        int sup=0;
        printf("\nPulsa cualquier tecla para volver al menu\n");
        scanf ("%d", &sup);
        getchar();
        if (sup!=0) {
          opcion=0;
          Menu();
          sup=0;
        }
    }

void Modificar() {
      int modificarID;
      Contacto primero;
      printf ("\nLista de contactos: \n");
      leerContactosOtros();

      printf ("Introduce el ID que quieres modificar: ");
      scanf("%d", &modificar);getchar();


      printf("\nVolver a modificar:");scanf("%d", &numeroedi);
      fichero=fopen("numeroej.dat","rb+");
      while (fread(&valor,sizeof(int),1,fichero)) {
        if (valor==numeroeli) {
          fseek(fichero,-1*sizeof(valor),SEEK_CUR);
          fwrite(&numeroedi,sizeof(int),1,fichero);
          fseek(fichero,+1*sizeof(valor),SEEK_CUR);
        }

      }
      fclose(fichero);



      int sup=0;
      printf("\nPulsa cualquier tecla para volver al menu\n");
      scanf ("%d", &sup);
      getchar();
      if (sup!=0) {
        opcion=0;
        Menu();
        sup=0;
      }
    }

void Selector() {

      if ((fichero=fopen("contactos.dat","rb"))==NULL) {
        fichero=fopen ("contactos.dat", "wb+");
        fclose(fichero);
        fich=fopen ("id.dat", "wb+");
        valor=1;
        fwrite(&valor,sizeof(int),1,fichero);
        fclose(fich);
        }else{

      switch (opcion){
          case 1:
              {if (fichero==NULL)
              {
              fclose(fichero);
              printf ("\nIntroducir un contacto.\n");
              Nuevo();}
              else
              {
              fclose(fichero);
              system("cls");
              printf("\nIntroducir un contacto.\n");
              AddContacto();}}
          break;

          case 2:
              {if (fichero==NULL)
              {
              fclose(fichero);
              system("cls");
              printf ("\nLista vacia.\n");
              }
              else
              {
              fclose(fichero);
              system("cls");
              leerContactos();}
              }
          break;

          case 3:
              {if (fichero==NULL)
              {
               fclose(fichero);
              printf ("\nLista vacia.\n");
              }
              else
              {
              fclose(fichero);
              system("cls");
              borrarContacto();
              }
              }
          break;

          case 4:
              {if (fichero==NULL)
              {
               fclose(fichero);
              printf ("\nLista vacia.\n");
              }
              else
              {
              fclose(fichero);
              system("cls");
              Modificar();
              }
              }
          break;

          case 5:
              system("cls");
          break;

          default:
          {fclose(fichero);
              printf ("\nLa opcion seleccionada no es valida\n.");}
      }
      }
    }

int main (){

        Menu();
        while (opcion!=5) {
          Selector();

        }


        return 0;
    }
