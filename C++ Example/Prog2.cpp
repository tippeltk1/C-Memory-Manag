//---------------------------------------------------------------------
// Name:    
// Project: Maintain and Manipulate a directory of companies.
// Purpose: Run Directory, with Memory Leak detection.
//---------------------------------------------------------------------
#include "Directory.h"
#include "LeakWatcher.h"
#include <iostream>
using namespace std;

int main()
{
   _CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_FILE ); 
   _CrtSetReportFile( _CRT_WARN, _CRTDBG_FILE_STDOUT ); 
   _CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_FILE ); 
   _CrtSetReportFile( _CRT_ERROR, _CRTDBG_FILE_STDOUT ); 
   _CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_FILE ); 
   _CrtSetReportFile( _CRT_ASSERT, _CRTDBG_FILE_STDOUT ); 

   try
   {
      Directory().Run();
   }
   catch ( ... )
   {
      cout << "Uncaught Exception" << endl;
   }

   _CrtDumpMemoryLeaks();

   return 0;
}
