#include "os_simulation.h"
#include <stdio.h>   // Include for printf
#include <string.h>  // Include for memset

// Global variable declaration
extern Process processes[MAX_PROCESSES]; // Declare the global variable

int main(void) {
    // Initialize memory and processes
    init_memory();
    memset(processes, 0, sizeof(processes));

    // Simulate process management
    create_process(1, "Process1");
    create_process(2, "Process2");
    
    // Allocate memory for a process
    void* mem_block = allocate_memory(100);
    if (mem_block) {
        printf("Allocated 100 bytes of memory.\n");
    } else {
        printf("Failed to allocate memory.\n");
    }

    // Schedule processes
    schedule_process(1);
    schedule_process(2);

    // Terminate a process
    terminate_process(1);

    // Deallocate memory
    deallocate_memory(mem_block, 100);
    printf("Deallocated 100 bytes of memory.\n");

    return 0;
}