/* include only picoc.h here - should be able to use it with only the external interfaces, no internals from interpreter.h */
#include "picoc.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PICOC_STACK_SIZE (128*1024)              /* space for the the stack */

int picoc(int argc, char **argv)
{
    int ParamCount = 0;
    int DontRunMain = FALSE;
    int StackSize = PICOC_STACK_SIZE;
    
    argc++;

    if (argc < 2)
    {
        printf("Format: picoc <csource1.c>... [- <arg1>...]    : run a program (calls main() to start it)\n"
               "        picoc -s <csource1.c>... [- <arg1>...] : script mode - runs the program without calling main()\n"
               "        picoc -i                               : interactive mode\n");
        return (FALSE);
    }
    
    PicocInitialise(StackSize);
    
    if (strcmp(argv[ParamCount], "-s") == 0 || strcmp(argv[ParamCount], "-m") == 0)
    {
        DontRunMain = TRUE;
        PicocIncludeAllSystemHeaders();
        ParamCount++;
    }
        
    if (argc > ParamCount && strcmp(argv[ParamCount], "-i") == 0)
    {
        PicocIncludeAllSystemHeaders();
        PicocParseInteractive();
    }
    else
    {
        if (PicocPlatformSetExitPoint())
        {
            PicocCleanup();
            return PicocExitValue;
        }
        
        for (; ParamCount < argc && strcmp(argv[ParamCount], "-") != 0; ParamCount++)
            PicocPlatformScanFile(argv[ParamCount]);
        
        if (!DontRunMain)
            PicocCallMain(argc - ParamCount, &argv[ParamCount]);
    }
    
    PicocCleanup();
    return PicocExitValue;
}

