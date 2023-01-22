/**
 * Version.h
 *
 * For more information about "Semantic Versioning" see: https://semver.org/
 */

#ifndef VERSION_H
#define VERSION_H

#define MAJOR_VERSION 0
#define MINOR_VERSION 0
#define PATCH_VERSION 1

#define XSTR(x) #x
#define STR(x) XSTR(x)
#define VERSION_STRING STR(MAJOR_VERSION) "." STR(MINOR_VERSION) "." STR(PATCH_VERSION)

#endif //VERSION_H