/* hash_impl.c --- 
 * 
 * 
 * Author: Julianah Adubi
 * Created: Sun Oct 10 15:15:51 2021 (-0400)
 * Version: 
 * 
 * Description: File that implements the functions within the hash.h interface module 
 * 
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "queue.h"
#include "hash.h"

#define TABLESIZE 10  

int hsize;

typedef struct real_hashtable_t {
	struct real_hashtable_t *key;
	void *data;
} real_hashtable_t;

/*
typedef struct real_hashtable_t {
*/

int hashfn(int key) {
	return key % TABLESIZE;
}

hashtable_t *hopen(unit32_t hsize) {
	real_hashtable_t *hp;

	if ()

/*
int main(int argc, char *argv[]){
	person_t *p;


	p = make_person */


	
}

/* hclose -- closes a hash table */                                             
void hclose(hashtable_t *htp);




/* hput -- puts an entry into a hash table under designated key                 
 * returns 0 for success; non-zero otherwise                                    
 */                                                                             
int32_t hput(hashtable_t *htp, void *ep, const char *key, int keylen) {
	
