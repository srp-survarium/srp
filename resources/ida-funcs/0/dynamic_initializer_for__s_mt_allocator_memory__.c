void __thiscall dynamic_initializer_for__s_mt_allocator_memory__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_mt_allocator_memory,
    "mt_allocator",
    uri,
    "memory",
    "set maximum memory for global mt allocator, Mb",
    uri);
}
