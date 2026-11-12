#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char type;
    size_t n;

    printf("Do you want to enter (i)nteger or (f)loat values? ");
    if (scanf(" %c", &type) != 1 || (type != 'i' && type != 'I' && type != 'f' && type != 'F')) {
        fprintf(stderr, "Invalid choice. Exiting.\n");
        return 1;
    }

    printf("How many values do you want to enter? ");
    if (scanf("%zu", &n) != 1) {
        fprintf(stderr, "Invalid number.\n");
        return 1;
    }
    if (n == 0) {
        printf("Nothing to do (n = 0).\n");
        return 0;
    }

    if (type == 'i' || type == 'I') {
        int *arr= calloc(n, sizeof(int));
        if (arr == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return 1;
        }

        for (size_t i = 0; i < n; ++i) {
            do {
            printf("Enter positive integer value %zu (> 0): ", i + 1);
            scanf("%d", &arr[i]);
                if (arr[i] <= 0) {
                    printf( "Please enter a positive value.\n");
                 }
             
            } while (arr[i] <= 0);
                
        }

        printf("Current array : ");
        for (size_t i = 0; i < n; ++i) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        char choice;
        printf("Do you want to modify any values? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            size_t extra;
            printf("How many values do you want to modify? ");
            if (scanf("%zu", &extra) == 1 &&  extra > 0) {
                size_t new_size = n + extra;
                int *temp = realloc(arr, new_size * sizeof(int));
                if (temp == NULL) {
                    fprintf(stderr, "Memory reallocation failed.\n");
                } else { 
                    arr = temp;

                    for (size_t i = n; i < new_size; ++i) {
                        do {
                            printf("Enter positive integer value %zu (> 0): ", i + 1);
                            scanf("%d", &arr[i]);
                            if (arr[i] <= 0) {
                                printf("Please enter a positive value.\n");
                            }
                        } while (arr[i] <= 0);
                    }

                    printf("Updated array : ");
                    for (size_t i = 0; i < new_size; ++i) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");

                    n = new_size;
                }

            }
            
        }
            
            free(arr);

    } else {
        float *arr = calloc(n, sizeof(float));
        if (arr == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return 1;
        }

        for (size_t i = 0; i < n; ++i) {
            do {
                printf("Enter positive value %zu (> 0): ", i + 1);
                scanf("%f", &arr[i]);
                if (arr[i] <= 0) {
                    printf("Please enter a positive value.\n");
                }
            } while (arr[i] <= 0);

        }

        printf("Current array : ");
        for (size_t i = 0; i < n; ++i) {
            printf("%.2f ", arr[i]);
        }
        printf("\n");

        char choice;
        printf("Do you want to modify any values? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            size_t extra;
            printf("How many values do you want to modify? ");
            if (scanf("%zu", &extra) == 1 && extra > 0) {
                size_t new_size = n + extra;

                float *temp = realloc(arr, new_size * sizeof(float));
                if (temp == NULL) {
                    fprintf(stderr, "Memory reallocation failed.\n");
                } else { 
                    arr = temp;

                    for (size_t i = n; i < new_size; ++i) {
                        do {
                            printf("Enter positive value %zu (> 0): ", i + 1);
                            scanf("%f", &arr[i]);
                            if (arr[i] <= 0) {
                                printf("Please enter a positive value.\n");
                            }
                        } while (arr[i] <= 0);
                    }

                    printf("Updated array : ");
                    for (size_t i = 0; i < new_size; ++i) {
                        printf("%.2f ", arr[i]);
                    }
                    printf("\n");

                    n = new_size;
                }

            }
        }

        free(arr);
   
    }


    return 0;
}