void __thiscall dynamic_initializer_for__s_render_allocator_memory__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_render_allocator_memory,
    "render_allocator",
    uri,
    "memory",
    "set minimum memory for render allocator, Mb",
    uri);
}
