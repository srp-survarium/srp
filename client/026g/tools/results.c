// SPDX-License-Identifier: GPL-3.0-or-later
/* Retail 0.26g0 Scaleform ABI; invoked only after a bounded SRP F8 v1 message. */
typedef unsigned int u32;
#ifndef RESULTS_PARSER_ONLY
typedef struct Value {
    void *interface;
    u32 type;
    union { double number; const char *string; void *object; u32 integer; } data;
} Value;
_Static_assert(sizeof(void *) == 4 && sizeof(Value) == 16, "Requires the retail x86 Value ABI");
typedef void (__attribute__((thiscall)) *CreateObject)(void *, Value *, const char *, Value *, u32);
typedef void (__attribute__((thiscall)) *CreateArray)(void *, Value *);
typedef unsigned char (__attribute__((thiscall)) *SetMember)(void *, void *, const char *, const Value *, u32);
typedef unsigned char (__attribute__((thiscall)) *PushBack)(void *, void *, const Value *);
typedef void (__attribute__((thiscall)) *Release)(void *, Value *, void *);
typedef unsigned char (__attribute__((thiscall)) *Invoke)(void *, const char *, Value *, Value *, u32);
static void clear(Value *v) {
    if (v->type & 64) {
        void **table = *(void ***)v->interface;
        ((Release)table[2])(v->interface, v, v->data.object);
    }
    v->interface = 0; v->type = 0; v->data.number = 0;
}
static void member(Value *object, const char *name, const Value *value) {
    void **table = *(void ***)object->interface;
    ((SetMember)table[5])(object->interface, object->data.object, name, value, 0);
}
static void number(Value *object, const char *name, double number) {
    Value v = {0, 5, {.number=number}};
    member(object, name, &v);
}

extern void results_close_native(void *network, void *reader);
extern void results_activate_native(void *game);
extern void results_present_native(void *lobby);
#if WITH_REJOIN
extern void rejoin_completed(void *game);
extern int rejoin_initial_results(void *game);
#endif
#endif
static u32 word(const unsigned char *p) { return p[0] | (u32)p[1] << 8; }
static u32 dword(const unsigned char *p) { return word(p) | word(p+2) << 16; }

int results_valid_payload(const unsigned char *packet, u32 remaining) {
    if (remaining < 104 || remaining > 24 + 80 * 20) return 0;
    u32 count = packet[21], slot = packet[2], mask = dword(packet+12);
    if (packet[0] != 1 || packet[3] != 2 || count == 0 || count > 20 || slot >= count
        || remaining != 24 + count * 80 || packet[20] > 2 || packet[22] > 1
        || packet[23] != 0 || (mask >> count) || !(mask & (1u << slot))
        || packet[1] != (unsigned char)(dword(packet+4)/50)) return 0;
    for (u32 i = 0; i < count; ++i) {
        const unsigned char *row = packet+24+i*80;
        if (row[4] > 1 || row[5] || row[14] > 63 || row[15] || row[16+row[14]]) return 0;
        for (u32 n = 0; n < row[14]; ++n) if (row[16+n] == 0) return 0;
    }
    if (packet[24+slot*80+4] != packet[22]) return 0;
    return 1;
}

#ifndef RESULTS_PARSER_ONLY
/* Reader layout is the native (begin, current, size) bounded byte buffer. */
void results_receive(void *network, unsigned char **reader) {
    unsigned char packet[24 + 80 * 20];
    unsigned char *start = reader[0], *current = reader[1];
    u32 size = (u32)reader[2], consumed = (u32)current - (u32)start;
    if (consumed > size) return;
    u32 remaining = size - consumed;
    reader[1] = start + size;
    if (remaining < 104 || remaining > sizeof(packet)) return;
    for (u32 i = 0; i < remaining; ++i) packet[i] = current[i];
    if (!results_valid_payload(packet, remaining)) return;
    u32 count = packet[21], slot = packet[2], mask = dword(packet+12);
    if (packet[24+slot*80+4] != packet[22]
        || *(unsigned char *)((char *)network+0x1f1c44) != slot
        || !*(void **)((char *)network+0x1f1c40)) return;
    // Results retain their verified historical cutoff. Native own-slot teardown
    // is a current event; the older cutoff can be outside its rollback window.
    void *world = *(void **)((char *)network + 0x1f1c40);
    u32 now = *(u32 *)((char *)world + 0x191b8);
    unsigned char leave[2] = {(unsigned char)(now/50), (unsigned char)slot};
    unsigned char *leave_reader[3] = {leave, leave, (unsigned char *)2};
    results_close_native(network, leave_reader);
    void *game = *(void **)((char *)network + 0x14);
    void *lobby = *(void **)((char *)game + 0x5390);
    if (!lobby) return;
    results_activate_native(game);
    results_present_native(lobby);
    void *stage = *(void **)((char *)lobby + 0x690);
    if (!stage) return;
    void *holder = *(void **)((char *)stage + 0x108);
    if (!holder) return;
    void *movie = *(void **)((char *)holder + 4);
    if (!movie) return;
    Value data = {0}, array = {0}, empty = {0}, players = {0};
    ((CreateObject)0x511700)(movie, &data, 0, 0, 0);
    ((CreateArray)0x511710)(movie, &array);
    member(&data, "score_components", &array);
    ((CreateArray)0x511710)(movie, &players);
    for (u32 i = 0; i < count; ++i) {
        if (!(mask & (1u << i))) continue;
        unsigned char *p = packet+24+i*80;
        Value row = {0};
        ((CreateObject)0x511700)(movie, &row, 0, 0, 0);
        Value name = {0, 6, {.string=(const char *)(p+16)}};
        member(&row, "name", &name);
        number(&row, "id", dword(p));
        number(&row, "team", p[4] == packet[22] ? 1 : 2);
        number(&row, "kills", word(p+8)); number(&row, "deaths", word(p+10));
        number(&row, "score", (short)word(p+12)); number(&row, "rank", word(p+6));
        void **table = *(void ***)players.interface;
        ((PushBack)table[15])(players.interface, players.data.object, &row);
        clear(&row);
    }
    member(&data, "players", &players);
    ((CreateObject)0x511700)(movie, &empty, 0, 0, 0);
    member(&data, "statistics_money", &empty);
    member(&data, "statistics_reputation", &empty);
    member(&data, "statistics_rating", &empty);
    member(&data, "statistics_exp", &empty);
    number(&data, "match_id", dword(packet+8));
    number(&data, "match_result", packet[20] == packet[22] ? 5 : 0);
    number(&data, "game_mode", packet[3]);
    number(&data, "team1_score", word(packet+16+packet[22]*2));
    number(&data, "team2_score", word(packet+16+(1-packet[22])*2));
    Value no = {0, 2, {.integer=0}};
    member(&data, "allow_drop_card", &no);
    member(&data, "is_bonus_match", &no);
    ((Invoke)0x511600)(movie, "root.victory_screen.setData", 0, &data, 1);
    // The initial profile-less lobby creates this overlay once. Direct rejoin
    // does not recreate it; retail close_sync removes its children unconditionally.
#if WITH_REJOIN
    if (rejoin_initial_results(game))
#endif
        ((Invoke)0x511600)(movie, "root.close_sync", 0, 0, 0);
    clear(&players); clear(&empty); clear(&array); clear(&data);
#if WITH_REJOIN
    rejoin_completed(game);
#endif
}

#endif
