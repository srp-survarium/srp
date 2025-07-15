void __thiscall dynamic_initializer_for__s_rh_allocator_memory__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_rh_allocator_memory,
    "rh_allocator",
    uri,
    "memory",
    "set maximum memory for resources helper allocator, Mb",
    uri);
}
