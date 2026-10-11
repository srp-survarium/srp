// SPDX-License-Identifier: GPL-3.0-or-later
// Run with tests/run_bridge_smoke.py and its header-checking HTTP fixture.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "../dll/menu_http.h"
static char reply[32832];
#define CHECK(test) do { if (!(test)) { fprintf(stderr,"FAIL line %d: %s\n",__LINE__,#test); return 1; } } while (0)
int main(void)
{
    CHECK(srp_http_initialize());
    CHECK(!srp_http_command("stock_command", reply, sizeof(reply)));
    CHECK(srp_http_command("srp_attach/first", reply, sizeof(reply)));
    srp_http_command("srp_request/first/0/v=1&id=first-0&player=transport&op=list", reply, sizeof(reply));
    CHECK(strstr(reply, "0\n401\nSign in"));
    srp_http_set_identity(1, 0);
    srp_http_command("srp_request/first/0/v=1&id=first-0&player=transport&op=list", reply, sizeof(reply));
    CHECK(strstr(reply, "0\n401\nThe lobby session changed"));
    CHECK(srp_http_command("srp_request/first/1/v=1&id=first-1&player=transport&op=capabilities", reply, sizeof(reply)));
    CHECK(!reply[0]);
    srp_http_command("srp_poll/wrong", reply, sizeof(reply)); CHECK(!reply[0]);
    for (unsigned i=0;i<500;i++) {
        srp_http_command("srp_poll/first", reply, sizeof(reply));
        if (reply[0]) break;
        Sleep(10);
    }
    CHECK(!strncmp(reply,"1\n200\n",6));
    CHECK(strstr(reply,"\"fixture\": true"));
    srp_http_command("srp_request/first/2/v=1&id=first-2&player=transport&op=list", reply, sizeof(reply));
    CHECK(!reply[0]);
    srp_http_command("srp_request/first/3/v=1&id=first-3&player=transport&op=list", reply, sizeof(reply));
    CHECK(strstr(reply,"3\n0\nAnother request"));
    srp_http_command("srp_attach/second", reply, sizeof(reply));
    Sleep(500);
    srp_http_command("srp_poll/second", reply, sizeof(reply)); CHECK(!reply[0]);
    srp_http_command("srp_poll/first", reply, sizeof(reply)); CHECK(!reply[0]);
    srp_http_command("srp_request/second/4/v=1&id=second-4&player=transport&op=list", reply, sizeof(reply));
    CHECK(!reply[0]);
    for (unsigned i=0;i<500;i++) {
        srp_http_command("srp_poll/second", reply, sizeof(reply));
        if (reply[0]) break;
        Sleep(10);
    }
    CHECK(!strncmp(reply,"4\n200\n",6));
    srp_http_set_identity(0, 0x12345678); // synthetic test credential
    srp_http_command("srp_request/second/5/op=native", reply, sizeof(reply));
    CHECK(strstr(reply, "5\n401\n")); // old screen must refresh its identity
    srp_http_command("srp_request/second/6/op=native", reply, sizeof(reply));
    CHECK(!reply[0]);
    for (unsigned i=0;i<500;i++) {
        srp_http_command("srp_poll/second", reply, sizeof(reply));
        if (reply[0]) break;
        Sleep(10);
    }
    CHECK(!strncmp(reply,"6\n200\n",6)); // fixture checks Authorization header
    srp_http_command("srp_request/second/7/op=native", reply, sizeof(reply));
    CHECK(!reply[0]);
    srp_http_set_identity(0, 0); // sign out while HTTP is pending
    srp_http_set_identity(0, 0x12345678); // even same token must not revive old result
    srp_http_command("srp_poll/second", reply, sizeof(reply));
    CHECK(strstr(reply,"7\n401\n"));
    Sleep(500);
    srp_http_command("srp_poll/second", reply, sizeof(reply)); CHECK(!reply[0]);
    srp_http_command("srp_request/second/8/op=native", reply, sizeof(reply));
    CHECK(!reply[0]);
    for (unsigned i=0;i<500;i++) {
        srp_http_command("srp_poll/second", reply, sizeof(reply));
        if (reply[0]) break;
        Sleep(10);
    }
    CHECK(!strncmp(reply,"8\n200\n",6));
    srp_http_enable_match_protocol();
    srp_http_command("srp_request/second/9/op=native-enabled", reply, sizeof(reply));
    CHECK(!reply[0]);
    for (unsigned i=0;i<500;i++) {
        srp_http_command("srp_poll/second", reply, sizeof(reply));
        if (reply[0]) break;
        Sleep(10);
    }
    CHECK(!strncmp(reply,"9\n200\n",6)); // actual DLL capability header
    srp_http_enable_match_recovery();
    srp_http_command("srp_request/second/10/op=native-recovery", reply, sizeof(reply));
    CHECK(!reply[0]);
    for (unsigned i=0;i<500;i++) {
        srp_http_command("srp_poll/second", reply, sizeof(reply));
        if (reply[0]) break;
        Sleep(10);
    }
    CHECK(!strncmp(reply,"10\n200\n",7));
    puts("PASS: HTTP, busy, generations, native auth/capability headers, identity invalidation/recovery");
    return 0;
}
