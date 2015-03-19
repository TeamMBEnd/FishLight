#ifndef MEMORY_H
#define MEMORY_H

#ifdef _DEBUG{
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <new>
#include <crtdbg.h>

#define new ::new(_NORMAL_BLOCK,__FILE__,__LINE__)

#endif

#endif