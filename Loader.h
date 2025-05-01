#ifndef LOADER_H
#define LOADER_H

#include "Main.h"  // Include the main header to use structures

// Function declarations for loading data
void* load_all_os(const char* filename, size_t* os_count);
void* load_all_software(const char* filename, size_t* sw_count);
void* load_all_hypervisors(const char* filename, size_t* hv_count);
void* load_all_products(const char* filename, size_t* prod_count);

#endif // LOADER_H
