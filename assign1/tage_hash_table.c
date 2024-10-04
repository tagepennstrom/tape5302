#include <stdlib.h>
#include "hash_table.h"
#include <stdbool.h>

typedef struct entry entry_t;

struct entry
{
  int key;       // holds the key
  char *value;   // holds the value
  entry_t *next; // points to the next entry (possibly NULL)
};

struct hash_table
{
  entry_t buckets[17];
};


#define Success(v)      (option_t) { .success = true, .value = v };
#define Failure()       (option_t) { .success = false };
#define Successful(o)   (o.success == true)
#define Unsuccessful(o) (o.success == false)

ioopm_hash_table_t *ioopm_hash_table_create()
{
    /// Allocate space for a ioopm_hash_table_t = 17 pointers to
    /// entry_t's, which will be set to NULL
    ioopm_hash_table_t *result = calloc(1, sizeof(ioopm_hash_table_t));
    return result;
}

void ioopm_hash_table_destroy(ioopm_hash_table_t *ht)
{
    for (int i = 0; i < 17; i++)
    {
        entry_t *entry = ht->buckets[i].next;
        while (entry != NULL)
        {
            entry_t *next_entry = entry->next;
            free(entry);
            entry = next_entry;
        }
    }
    free(ht);
}

static entry_t *entry_create(int key,char *value)
{
    /// Create an object for the new entry
    entry_t *new_entry = calloc(1, sizeof(entry_t));
    /// Set the key and value fields to the key and value
    new_entry->key = key;
    new_entry->value = value;
    /// Make the first entry the next entry of the new entry
    new_entry->next = NULL;
    /// Make the new entry the first entry in the bucket
    return new_entry;
}

static entry_t *find_previous_entry_for_key(entry_t *entry,int key)
{
    entry_t *cursor = entry;
    entry_t *prev_entry = NULL;
    while (cursor != NULL)
    {
        if (cursor->key == key)
        {
            break;
        }
        prev_entry = cursor;
        cursor = cursor->next; /// Step forward to the next entry, and repeat loop
    }
    return prev_entry;
}

void ioopm_hash_table_insert(ioopm_hash_table_t *ht, int key, char *value)
{
  /// Calculate the bucket for this entry
  int bucket = key % 17;
  /// Search for an existing entry for a key
  entry_t *entry = find_previous_entry_for_key(&ht->buckets[bucket], key);

  /// Check if the next entry should be updated or not
  if (entry && entry->value && entry->next->value)
    {
      entry->next->value = value;
    }
  else
    {
      ht->buckets[bucket].next = entry_create(key, value);
    }
}

option_t ioopm_hash_table_lookup(ioopm_hash_table_t *ht, int key)
{
    /// Find the previous entry for key
    entry_t *tmp = find_previous_entry_for_key(&ht->buckets[key % 17], key);

    if (tmp && tmp->next && tmp->next->value)
    {
        return Success(tmp->next->value);
    }
    else
    {
        return Failure();
    }
}