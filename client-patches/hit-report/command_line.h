// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef SRP_HIT_REPORT_COMMAND_LINE_H
#define SRP_HIT_REPORT_COMMAND_LINE_H
#include <stddef.h>
#include <string.h>

// Quote one argument using the Windows CRT backslash/quote rules. Count the
// escaped output first, so rejection leaves the existing command line intact.
inline bool append_argument(char* output, size_t capacity, char const* argument)
{
    size_t const used = strlen(output);
    if (!capacity || used >= capacity)
        return false;
    size_t required = used + (used ? 1 : 0) + 2;
    for (char const* p = argument; ; ) {
        size_t slashes = 0;
        while (*p == '\\') { ++slashes; ++p; }
        required += (*p == '"' || !*p) ? 2 * slashes : slashes;
        if (*p == '"') ++required;
        if (*p) { ++required; ++p; }
        else break;
        if (required >= capacity) return false;
    }
    if (required >= capacity)
        return false;

    char* dest = output + used;
    if (used) *dest++ = ' ';
    *dest++ = '"';
    for (char const* p = argument; ; ) {
        size_t slashes = 0;
        while (*p == '\\') { ++slashes; ++p; }
        size_t count = (*p == '"' || !*p) ? 2 * slashes : slashes;
        while (count--) *dest++ = '\\';
        if (!*p) break;
        if (*p == '"') *dest++ = '\\';
        *dest++ = *p++;
    }
    *dest++ = '"';
    *dest = 0;
    return true;
}
#endif
