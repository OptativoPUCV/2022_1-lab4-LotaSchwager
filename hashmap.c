#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"


typedef struct HashMap HashMap;
int enlarge_called=0;

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}


void insertMap(HashMap * map, char * key, void * value) {
  long hach = hash(key, map->capacity);

  if (map->buckets[hach]->key == NULL){
    strcpy(map->buckets[hach]->key,key);
    map->buckets[hach]->value = value;
    map->current = hach;
    map->size++;
  }

  while (map->buckets[hach] != NULL){

    if (strcmp(key, map->buckets[hach]->key) == 0) return exit(1);

    if (map->buckets[hach] == NULL){
       strcpy(map->buckets[hach]->key,key);
       map->buckets[hach]->value = value;
       map->size++;
       map->current = hach;
    }

    hach++;
    if (hach >= map->capacity) hach = 0;
  }
}

void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)


}


HashMap * createMap(long capacity) {

  HashMap* table = malloc (sizeof(HashMap));
  if (table == NULL) return NULL;

  table->current = -1;
  table->capacity = capacity;
  table->size = 0;
  table->buckets = calloc(table->capacity, sizeof(Pair));
  if (table->buckets == NULL){

    free(table);
    return NULL;
  }
  return table;
}

void eraseMap(HashMap * map,  char * key) {    


}

Pair * searchMap(HashMap * map,  char * key) {   


    return NULL;
}

Pair * firstMap(HashMap * map) {

    return NULL;
}

Pair * nextMap(HashMap * map) {

    return NULL;
}
