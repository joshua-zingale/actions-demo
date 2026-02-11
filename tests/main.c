#include <tests/harness.h>

TestCase test_registry[100];
int test_count = 0;

int main() {
    printf("--- Starting Test Suite ---\n");
    int failed_count = 0;

    for (int i = 0; i < test_count; i++) {
        printf("Running %-25s ", test_registry[i].name);
        
        int result = test_registry[i].func();
        
        if (result == 0) {
            printf("[ PASS ]\n");
        } else {
            printf("[ FAIL ] (Code: %d)\n", result);
            failed_count++;
        }
    }

    printf("\nSummary: %d passed, %d failed\n", (test_count - failed_count), failed_count);
    return (failed_count == 0) ? 0 : 1;
}