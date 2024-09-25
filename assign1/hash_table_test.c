
#include "hash_table.h"
#include <stdbool.h>
#include <CUnit/Basic.h>

typedef struct entry entry_t;

struct entry {
  int key;       // holds the key
  char *value;   // holds the value
  entry_t *next; // points to the next entry (possibly NULL)
};

struct hash_table {
  entry_t buckets[17];
};

struct option
{
  bool success;
  char *value;
};

int init_suite(void) {
  // Change this function if you want to do something *before* you
  // run a test suite
  return 0;
}

int clean_suite(void) {
  // Change this function if you want to do something *after* you
  // run a test suite
  return 0;
}

void test_create_destroy()
{
   ioopm_hash_table_t *ht = ioopm_hash_table_create();
   CU_ASSERT_PTR_NOT_NULL(ht);
   ioopm_hash_table_destroy(ht);

}

void test_insert_once() {
  ioopm_hash_table_t *ht = ioopm_hash_table_create();
  int key = 31495;
  char *value = "10";

  ioopm_option_t result = ioopm_hash_table_lookup(ht, key);
  CU_ASSERT_FALSE(result.success);

  ioopm_hash_table_insert(ht, key, value);
  result = ioopm_hash_table_lookup(ht, key);
  CU_ASSERT_TRUE(result.success);

  CU_ASSERT_STRING_EQUAL(result.value, value);

  ioopm_hash_table_destroy(ht);
}

void test_remove() {
  ioopm_hash_table_t *ht = ioopm_hash_table_create();
  int key = 2313;
  char *value = "10";

  ioopm_hash_table_remove(ht, key);
  ioopm_option_t result = ioopm_hash_table_lookup(ht, key);
  CU_ASSERT_FALSE(result.success);
  
  ioopm_hash_table_insert(ht, key, value);
  result = ioopm_hash_table_lookup(ht, key);
  CU_ASSERT_TRUE(result.success);

  char* removed_string = ioopm_hash_table_remove(ht, key);
  result = ioopm_hash_table_lookup(ht, key);
  CU_ASSERT_FALSE(result.success);
  CU_ASSERT_STRING_EQUAL(removed_string, value);

  ioopm_hash_table_destroy(ht);
}

void test_ioopm_hash_table_size(){
    ioopm_hash_table_t *ht = ioopm_hash_table_create();
    ioopm_hash_table_insert(ht, 1, "Apa");
    ioopm_hash_table_insert(ht, 2, "Giraff");
    ioopm_hash_table_insert(ht, 3, "Lejon");
    CU_ASSERT_TRUE(ioopm_hash_table_size(ht) == 3);
    ioopm_hash_table_destroy(ht);
}

void test_is_empty() {
    int key1 = 0;
    char *value1 = "Hej";
    ioopm_hash_table_t *ht = ioopm_hash_table_create();
    bool result = ioopm_hash_table_is_empty(ht);
    CU_ASSERT_TRUE(result);

    ioopm_hash_table_insert(ht, key1, value1);

    result = ioopm_hash_table_is_empty(ht);
    CU_ASSERT_FALSE(result);

    ioopm_hash_table_destroy(ht);
}

void test_clear_ht() {
    int key1 = 1;
    char *value1 = "176";
    ioopm_hash_table_t *ht = ioopm_hash_table_create();  
    ioopm_hash_table_insert(ht, key1, value1);
    bool result = ioopm_hash_table_is_empty(ht);
    CU_ASSERT_FALSE(result);

    ioopm_hash_table_clear(ht);
    result = ioopm_hash_table_is_empty(ht);
    CU_ASSERT_TRUE(result);

    ioopm_hash_table_destroy(ht);
}

int main() {
  // First we try to set up CUnit, and exit if we fail
  if (CU_initialize_registry() != CUE_SUCCESS)
    return CU_get_error();

  // We then create an empty test suite and specify the name and
  // the init and cleanup functions
  CU_pSuite my_test_suite = CU_add_suite("My awesome test suite", init_suite, clean_suite);
  if (my_test_suite == NULL) {
      // If the test suite could not be added, tear down CUnit and exit
      CU_cleanup_registry();
      return CU_get_error();
  }

  // This is where we add the test functions to our test suite.
  // For each call to CU_add_test we specify the test suite, the
  // name or description of the test, and the function that runs
  // the test in question. If you want to add another test, just
  // copy a line below and change the information
  if (
    (CU_add_test(my_test_suite, "Create Destroy", test_create_destroy) == NULL) ||
    (CU_add_test(my_test_suite, "insert", test_insert_once) == NULL) ||
    (CU_add_test(my_test_suite, "remove", test_remove) == NULL) ||
    (CU_add_test(my_test_suite, "Hashtable Size", test_ioopm_hash_table_size) == NULL) ||
    (CU_add_test(my_test_suite, "Is empty", test_is_empty) == NULL) ||
    (CU_add_test(my_test_suite, "Clear HT", test_clear_ht) == NULL) ||


    0
  )
    {
      // If adding any of the tests fails, we tear down CUnit and exit
      CU_cleanup_registry();
      return CU_get_error();
    }

  // Set the running mode. Use CU_BRM_VERBOSE for maximum output.
  // Use CU_BRM_NORMAL to only print errors and a summary
  CU_basic_set_mode(CU_BRM_VERBOSE);

  // This is where the tests are actually run!
  CU_basic_run_tests();

  // Tear down CUnit before exiting
  CU_cleanup_registry();
  return CU_get_error();
} 

