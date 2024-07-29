#ifndef OS_SIMULATION_H
#define OS_SIMULATION_H

// Constants
#define MAX_PROCESSES 10
#define MEMORY_SIZE 1024 // 1 KB of simulated memory

// Process structure
typedef struct {
    int id;
    char name[20];
    int state; // 0 = inactive, 1 = active
} Process;

// Memory structure
typedef struct {
    char memory[MEMORY_SIZE];
    int allocated[MEMORY_SIZE];
} Memory;

// Global variables
extern Process processes[MAX_PROCESSES]; // Declare global variable

// Function prototypes
void init_memory(void);
void* allocate_memory(int size);
void deallocate_memory(void* ptr, int size);
void create_process(int id, const char* name);
void schedule_process(int id);
void terminate_process(int id);

#endif // OS_SIMULATION_H