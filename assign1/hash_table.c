#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define No_Buckets 17
typedef struct entry entry_t;

struct entry {
  int key;       // holds the key
  char *value;   // holds the value
  entry_t *next; // points to the next entry (possibly NULL)
};

struct hash_table {
  entry_t buckets[No_Buckets];
};

struct option
{
  bool success;
  char *value;
};


static entry_t *entry_create(int key, char* value, entry_t *next) {
  entry_t *new_entry = calloc(1, sizeof(entry_t));

  new_entry->key = key;
  new_entry->value = value;
  new_entry->next = next;

  return new_entry;
}

static entry_t *find_previous_entry_for_key(entry_t *entry, int key) {
  entry_t *current_entry = entry;
  entry_t *next_entry = entry->next;
    
  while (next_entry != NULL) {
    if (next_entry->key >= key) {
      break;
    }
    current_entry = next_entry;
    next_entry = next_entry->next;
  }

  return current_entry;
}

ioopm_hash_table_t *ioopm_hash_table_create() {
  /// Allocate space for a ioopm_hash_table_t = No_Buckets pointers to
  /// entry_t's, which will be set to NULL 
  ioopm_hash_table_t *result = calloc(1, sizeof(ioopm_hash_table_t));
  return result;
}

void ioopm_hash_table_destroy(ioopm_hash_table_t *ht) {
  for(int i = 0; i < No_Buckets; i++) {
    entry_t *current = ht->buckets[i].next;

    while(current != NULL) {
    entry_t *next_entry = current->next;
    free(current);
    current = next_entry;
    }

  }
  free(ht); 
}

void ioopm_hash_table_insert(ioopm_hash_table_t *ht, int key, char *value) {
  /// Calculate the bucket for this entry
  int bucket = key % No_Buckets;
  /// Search for an existing entry for a key
  entry_t *entry = find_previous_entry_for_key(&ht->buckets[bucket], key);
  entry_t *next = entry->next;

  /// Check if the next entry should be updated or not
  if (next != NULL && next->key == key)
    {
      next->value = value;
    }
  else
    {
      entry->next = entry_create(key, value, next);
    }
}

ioopm_option_t ioopm_hash_table_lookup(ioopm_hash_table_t *ht, int key) {
  /// Find the previous entry for key
  entry_t *tmp = find_previous_entry_for_key(&ht->buckets[key % No_Buckets], key);
  entry_t *next = tmp->next;

  if (next && next->value) {
    ioopm_option_t result = { .success = true, .value = next->value };
    return result;
  } else {
    ioopm_option_t result = { .success = false };
    return result;
  }
}

char *ioopm_hash_table_remove(ioopm_hash_table_t *ht, int key) {

  entry_t *prev_entry = find_previous_entry_for_key(&ht->buckets[key % No_Buckets], key);
  entry_t *entry = prev_entry->next;
  
  ioopm_option_t result = ioopm_hash_table_lookup(ht, key);

  if (result.success == false) {

    return "";

  } else {

    char *removed_value = entry->value; 
    prev_entry->next = entry->next; // The previous entry linked to the entry's next entry
    free(entry);               
 
    return removed_value;
  }
}