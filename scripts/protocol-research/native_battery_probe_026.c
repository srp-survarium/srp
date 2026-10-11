// SPDX-License-Identifier: GPL-3.0-or-later
/* Diagnostic only: invoke ten native team-0 deposit events after 30 seconds.
 * This exercises the completion/results pipeline, not physical delivery.
 * Called before engine history capture (0x2d2570), within simulation updates.
 * Core rule vector: 0x23aa10; native event handler: 0x313a50.
 * Does not modify uploaded snapshots or grant account rewards.
 */
typedef unsigned int u32;
typedef void (__attribute__((thiscall)) *Event)(void *, int, int *, u32);
typedef void (__attribute__((stdcall)) *Debug)(const char *);
void battery_probe(unsigned char *core) {
    u32 time = *(u32 *)(core+0x18fc0);
    if (time < 30000) return;
    unsigned char **begin = *(unsigned char ***)(core+0x18824);
    unsigned char **end = *(unsigned char ***)(core+0x18828);
    if (end < begin || end-begin > 16) return;
    for (; begin != end; ++begin) {
        unsigned char *rule = *begin;
        // Client-derived gather rule; exercise its core event handler directly.
        if (*(u32 *)rule != 0xa06ab4 || *(u32 *)(rule+0x10c) != 1
            || *(unsigned char **)(rule+0x158) != core) continue;
        if (*(u32 *)(rule+0x15c) != 0xffffffff || rule[0x144] || rule[0x145]) return;
        if ((*(u32 *)(rule+0x114)-*(u32 *)(rule+0x110))/4 != 10) return;
        int event[2] = {0,0};
        for (u32 n=0; n<10; ++n) ((Event)0x313a50)(rule,2,event,time);
        (*(Debug *)0x870198)("SRP_BATTERY_PROBE: invoked ten native deposit events for team 0");
        return;
    }
}
