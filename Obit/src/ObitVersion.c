
// This file generated by getVersion.py
// Obit version (svn revision) at build time

#include <ObitVersion.h>

const char *const version = "308:309M";

char *ObitVersion (void)
{
    char *ver;
    ver = strdup( version );
    return ver;
}
