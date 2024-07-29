#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "os_simulation.h"

// Global variables
Process processes[MAX_PROCESSES];
Memory mem;

// Initialize memory
void init_memory() {
    memset(mem.memory, 0, MEMORY_SIZE);
    memset(mem.allocated, 0, MEMORY_SIZE * sizeof(int));
}

// Allocate memory
void* allocate_memory(int size) {
    for (int i = 0; i < MEMORY_SIZE - size; i++) {
        int j;
        for (j = 0; j < size; j++) {
            if (mem.allocated[i + j]) {
                break;
            }
        }
        if (j == size) {
            for (j = 0; j < size; j++) {
                mem.allocated[i + j] = 1;
            }
            return &mem.memory[i];
        }
    }
    return NULL; // Not enough memory
}

// Deallocate memory
void deallocate_memory(void* ptr, int size) {
    int start = (char*)ptr - mem.memory;
    for (int i = start; i < start + size; i++) {
        mem.allocated[i] = 0;
    }
}

// Create a process
void create_process(int id, const char* name) {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (processes[i].state == 0) { // Inactive process slot
            processes[i].id = id;
            strncpy(processes[i].name, name, sizeof(processes[i].name) - 1);
            processes[i].state = 1;
            printf("Process created: ID = %d, Name = %s\n", id, name);
            return;
        }
    }
    printf("No more slots for new processes.\n");
}

// Schedule a process (for demonstration, just prints the process state)
void schedule_process(int id) {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (processes[i].id == id && processes[i].state == 1) {
            printf("Scheduling process: ID = %d, Name = %s\n", id, processes[i].name);
            return;
        }
    }
    printf("Process not found or inactive.\n");
}

// Terminate a process
void terminate_process(int id) {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (processes[i].id == id && processes[i].state == 1) {
            processes[i].state = 0;
            printf("Process terminated: ID = %d\n", id);
            return;
        }
    }
    printf("Process not found or inactive.\n");
}