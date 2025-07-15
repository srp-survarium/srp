void __thiscall dynamic_initializer_for__s_enable_crt_memory_allocator__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_enable_crt_memory_allocator,
    "enable_crt_memory_allocator",
    uri,
    "memory",
    "enables crt memory allocator usage",
    uri);
}
