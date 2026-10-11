// SPDX-License-Identifier: GPL-3.0-or-later
/* Diagnostic UI payload only; not a live match-results implementation. */
typedef unsigned int u32;
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
void results_probe(void *lobby) {
    void *stage = *(void **)((char *)lobby + 0x690);
    void *holder = *(void **)((char *)stage + 0x108);
    void *movie = *(void **)((char *)holder + 4);
    Value data = {0}, array = {0}, empty = {0};
    ((CreateObject)0x511700)(movie, &data, 0, 0, 0);
    ((CreateArray)0x511710)(movie, &array);
    member(&data, "score_components", &array);
    Value players = {0}, row = {0};
    ((CreateArray)0x511710)(movie, &players);
    ((CreateObject)0x511700)(movie, &row, 0, 0, 0);
    Value name = {0, 6, {.string="UI diagnostic"}};
    member(&row, "name", &name);
    number(&row, "id", 1); number(&row, "team", 1);
    number(&row, "kills", 0); number(&row, "deaths", 0);
    number(&row, "score", 0); number(&row, "rank", 1);
    void **table = *(void ***)players.interface;
    ((PushBack)table[15])(players.interface, players.data.object, &row);
    member(&data, "players", &players);
    ((CreateObject)0x511700)(movie, &empty, 0, 0, 0);
    member(&data, "statistics_money", &empty);
    member(&data, "statistics_reputation", &empty);
    member(&data, "statistics_rating", &empty);
    member(&data, "statistics_exp", &empty);
    number(&data, "match_id", 1);
    number(&data, "match_result", 0);
    number(&data, "game_mode", 2);
    number(&data, "team1_score", 0);
    number(&data, "team2_score", 0);
    Value no = {0, 2, {.integer=0}};
    member(&data, "allow_drop_card", &no);
    member(&data, "is_bonus_match", &no);
    ((Invoke)0x511600)(movie, "root.victory_screen.setData", 0, &data, 1);
    ((Invoke)0x511600)(movie, "root.close_sync", 0, 0, 0);
    clear(&row); clear(&players); clear(&empty); clear(&array); clear(&data);
}
