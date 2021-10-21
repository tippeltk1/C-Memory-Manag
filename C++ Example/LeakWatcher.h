// Courtesy:  Chris Losinger and others
#ifndef IMWATCHINGYOULEAK
#define IMWATCHINGYOULEAK
#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
inline void* operator new(size_t nSize, const char * lpszFileName, int nLine)
{  return ::operator new(nSize, 1, lpszFileName, nLine); }
inline void __cdecl operator delete(void * _P, const char * lpszFileName, int nLine) 
{ ::operator delete(_P, _NORMAL_BLOCK, lpszFileName, nLine); } 
#define DEBUG_NEW new( __FILE__, __LINE__)
#define MALLOC_DBG(x) _malloc_dbg(x, 1, __FILE__, __LINE__);
#define malloc(x) MALLOC_DBG(x)
#define new DEBUG_NEW
#endif // _DEBUG
#endif // #include guard
