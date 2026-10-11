// SPDX-License-Identifier: GPL-3.0-or-later
#include "../command_line.h"
#include <assert.h>
#include <string>

int main()
{
    char line[128] = {0};
    assert(append_argument(line, sizeof(line), "C:\\game dir\\survarium.exe"));
    assert(append_argument(line, sizeof(line), "C:\\data dir\\"));
    assert(append_argument(line, sizeof(line), "say\"hi"));
    assert(append_argument(line, sizeof(line), ""));
    assert(strcmp(line, "\"C:\\game dir\\survarium.exe\" \"C:\\data dir\\\\\" \"say\\\"hi\" \"\"") == 0);
    char boundary[9] = "old";
    assert(!append_argument(boundary, sizeof(boundary), "\"\""));
    assert(strcmp(boundary, "old") == 0);
    char exact[5] = {0};
    assert(append_argument(exact, sizeof(exact), "\""));
    assert(strcmp(exact, "\"\\\"\"") == 0);
    std::string quotes(20000, '"');
    char long_line[32768] = {0};
    assert(!append_argument(long_line, sizeof(long_line), quotes.c_str()));
    assert(long_line[0] == 0);
}
