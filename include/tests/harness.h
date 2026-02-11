#ifndef __ACTIONS_TEST_HARNESS
#define __ACTIONS_TEST_HARNESS
#include <stdio.h>

typedef struct {
    const char* name;
    int (*func)(void);
} TestCase;

extern TestCase test_registry[100];
extern int test_count;


#define TEST(TEST_NAME, BODY) \
    int TEST_NAME##_func(void) { BODY; return 0; } \
    __attribute__((constructor)) \
    void register_##TEST_NAME() { \
        test_registry[test_count++] = (TestCase){ #TEST_NAME, TEST_NAME##_func }; \
    }

#define ASSERT(cond) \
    if (!(cond)) { \
        printf("\n  [!] Assertion Failed: (%s) at %s:%d\n", #cond, __FILE__, __LINE__); \
        return 1; \
    }
#endif