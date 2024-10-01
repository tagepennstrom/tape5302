#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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

void ioopm_hash_table_clear(ioopm_hash_table_t *ht) {
    for(int i = 0; i < No_Buckets; i++)
    {
        entry_t *current = ht->buckets[i].next;
        while(current != NULL) 
        {
            entry_t *next_entry = current->next;
            free(current);
            current = next_entry;
        }
    ht->buckets[i].next = NULL;
    }
}

void ioopm_hash_table_destroy(ioopm_hash_table_t *ht) {
    ioopm_hash_table_clear(ht);
    free(ht);
}

void ioopm_hash_table_insert(ioopm_hash_table_t *ht, int key, char *value) {
    /// Calculate the bucket for this entry
    int bucket = abs(key) % No_Buckets;
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
  entry_t *tmp = find_previous_entry_for_key(&ht->buckets[abs(key) % No_Buckets], key);
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

  entry_t *prev_entry = find_previous_entry_for_key(&ht->buckets[abs(key) % No_Buckets], key);
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
int ioopm_hash_table_size(ioopm_hash_table_t *ht) {
  int counter = 0;
  for(int i = 0; i < No_Buckets; i++) {
    entry_t *current = ht->buckets[i].next;
    while(current != NULL) {
    entry_t *next_entry = current->next;
    counter += 1;
    current = next_entry;
    }

  }
  return counter;
}



bool ioopm_hash_table_is_empty(ioopm_hash_table_t *ht)
{
  return ioopm_hash_table_size(ht) == 0;
}

int *ioopm_hash_table_keys(ioopm_hash_table_t *ht) {
  int size = ioopm_hash_table_size(ht);
  int *keys = calloc(size , sizeof(int));
  int keyindex = 0;

  for(int i = 0; i < No_Buckets; i++) {
    entry_t *current = ht->buckets[i].next;
    while(current != NULL) {

      if (keyindex < size) {
        keys[keyindex] = current->key;
        keyindex++;
      }
      if (keyindex == size - 1) {
        break;
      }
      entry_t *next_entry = current->next;
      current = next_entry;
    }
  }
  return keys;
}

char **ioopm_hash_table_values(ioopm_hash_table_t *ht) {
    char **values = calloc(ioopm_hash_table_size(ht), sizeof(char *));

    int valueindex = 0;

    for(int i = 0; i < No_Buckets; i++) {
        entry_t *current = ht->buckets[i].next;
        while(current != NULL) {
            entry_t *next_entry = current->next;
            values[valueindex] = current->value;
            valueindex++;
            current = next_entry;
        }
    }
    return values;
}

bool ioopm_hash_table_has_value(ioopm_hash_table_t *ht, char *value) {

  for(int i = 0; i < No_Buckets; i++) {
      entry_t *current = ht->buckets[i].next;
      while(current != NULL) {
        entry_t *next_entry = current->next;
        char *str = current->value;
        if (!strcmp(value, str)) {

          return true;
        }
        current = next_entry;
      }
  }
  return false;
}

bool ioopm_hash_table_has_key(ioopm_hash_table_t *ht, int key) {
  ioopm_option_t result = ioopm_hash_table_lookup(ht, key);
  return result.success == true;
}