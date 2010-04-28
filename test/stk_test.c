
#include "../stk.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

static void stk_test001(void);
static void stk_test002(void);
static void stk_test003(void);

static void stk_test001(void) {
    stk_t *vec = stk_create(0, sizeof(int));
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int siz = sizeof(arr) / sizeof(*arr);
    for (int i=0;i<siz;++i) {
        stk_push(vec, &arr[i]);
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
        stk_push(vec, &arr[i]);
    }
    CU_ASSERT(STK_SIZ(vec) == 9);
    for (int i=0;i<siz;++i) {
        CU_ASSERT(STK_IDX(vec, i) == arr[i]);
    }
    stk_destroy(vec);
}

static void stk_test003(void) {
    typedef struct test_s {
        int n;
        char c;
    } test_t;
    stk_t *vec = stk_create(5, sizeof(test_t));
    test_t arr[10];
    int siz = sizeof(arr) / sizeof(arr[0]);
    for (int i=0;i<siz;++i) {
        arr[i].n = i + 1;
        arr[i].c = 'a' + i;
        stk_push(vec, &arr[i]);
    }
    CU_ASSERT(STK_SIZ(vec) == 10);
    for (int i=0;i<siz;++i) {
        test_t *t = (test_t *)STK_IDXP(vec, i);
        CU_ASSERT(t->n == i + 1);
        CU_ASSERT(t->c == 'a' + i);
    }
    stk_destroy(vec);
    
}


int main (int argc, char *argv[]) {
    CU_pSuite suite_stk;
    CU_initialize_registry();
    suite_stk = CU_add_suite("stk", NULL, NULL);
    CU_add_test(suite_stk, "stk_test001", stk_test001);
    CU_add_test(suite_stk, "stk_test002", stk_test002);
    CU_add_test(suite_stk, "stk_test003", stk_test003);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
