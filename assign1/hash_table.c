#include <stdlib.h>
#include "hash_table.h"

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

ioopm_hash_table_t *ioopm_hash_table_create()
{
    /// Allocate space for a ioopm_hash_table_t = 17 pointers to
    /// entry_t's, which will be set to NULL
    ioopm_hash_table_t *result = calloc(1, sizeof(ioopm_hash_table_t));
    return result;
}

void ioopm_hash_table_destroy(ioopm_hash_table_t *ht) {
    free(ht);
}

static entry_t *entry_create(int key,char *value, entry_t next)
{
    /// Create an object for the new entry
    entry_t *new_entry = calloc(1, sizeof(entry_t));
    /// Set the key and value fields to the key and value
    new_entry->key = key;
    new_entry->value = value;
    /// Make the first entry the next entry of the new entry
    new_entry->next = &next;
    /// Make the new entry the first entry in the bucket
    return new_entry;
}

static entry_t *find_previous_entry_for_key(entry_t *entry,int key)
{
    entry_t *cursor = entry;
    while (cursor != NULL)
    {
      if (cursor->key == key)
        {
            return cursor;
        }

      cursor = cursor->next; /// Step forward to the next entry, and repeat loop
    }

    return entry_create(0, NULL, *entry);
}

void ioopm_hash_table_insert(ioopm_hash_table_t *ht, int key, char *value)
{
  /// Calculate the bucket for this entry
  int bucket = key % 17;
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
      entry->next = entry_create(key, value, *next);
    }
}

char *ioopm_hash_table_lookup(ioopm_hash_table_t *ht, int key)
{
    return NULL;
}