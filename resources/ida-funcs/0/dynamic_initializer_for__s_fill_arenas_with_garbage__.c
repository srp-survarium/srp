void __thiscall dynamic_initializer_for__s_fill_arenas_with_garbage__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_fill_arenas_with_garbage,
    "fill_arenas_with_garbage",
    uri,
    "memory",
    "fills all the memory in all the arenas with garbage; could slowdown startup significantly!",
    uri);
}
