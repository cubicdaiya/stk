
#include "../stk.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

static void stk_test001(void);
static void stk_test002(void);

static void stk_test001(void) {
  stk_t *vec = stk_create(0, sizeof(int));
  int arr[] = {1,2,3,4,5,6,7,8,9,10};
  int siz = sizeof(arr) / sizeof(*arr);
  for (int i=0;i<siz;++i) {
    stk_push_back(vec, &arr[i]);
  }
  CU_ASSERT(STK_SIZ(vec) == 10);
  for (int i=0;i<siz;++i) {
    CU_ASSERT(STK_IDX(vec, i) == i+1);
  }
  stk_destroy(vec);
}

static void stk_test002(void) {
  stk_t *vec = stk_create(5, sizeof(char));
  char arr[] = "abcdefghi";
  int siz = sizeof(arr) / sizeof(*arr) - 1;
  for (int i=0;i<siz;++i) {
    stk_push_back(vec, &arr[i]);
  }
  CU_ASSERT(STK_SIZ(vec) == 9);
  for (int i=0;i<siz;++i) {
    CU_ASSERT(STK_IDX(vec, i) == arr[i]);
  }
  stk_destroy(vec);
  
}


int main (int argc, char *argv[]) {
  CU_pSuite suite_stk;
  CU_initialize_registry();
  suite_stk = CU_add_suite("stk", NULL, NULL);
  CU_add_test(suite_stk, "stk_test001", stk_test001);
  CU_add_test(suite_stk, "stk_test002", stk_test002);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return 0;
}
