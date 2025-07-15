void __thiscall dynamic_initializer_for__s_no_memory_usage_stats__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_no_memory_usage_stats,
    "no_memory_usage_stats",
    uri,
    "memory",
    "disable CRT and GetProcessHeap() memory usage stats detection. Use this option if another program injected thread in"
    "to application, which uses one of these allocators.",
    uri);
}
