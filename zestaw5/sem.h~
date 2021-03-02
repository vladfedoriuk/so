#ifndef LIBSEM_H
#define LIBSEM_H
#include <stdio.h>
#include <stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<semaphore.h>
#include"pthread.h"


typedef sem_t* semid;

semid semOpen(const char *name); //Uzyskuje dostęp lub tworzy (jeden) semafor.
void semInit(semid sem, int val);// Przypisuje semaforowi sem wartość val.
void semRm(semid sem, const char* name);// Usuwa semafor.
void semP(semid sem);// Opuszcza semafor: zmniejsza wartość semafora o 1 lub czeka.
void semV(semid sem);// Podnosi semafor: zwiększa wartość semafora o 1 lub wznawia czekający proces.
void semZ(semid sem);// Funkcja czeka na wyzerowanie semafora.
void semInfo(semid sem);

#endif
