void __thiscall vostok::memory::monitor::_dynamic_initializer_for__s_memory_monitor_key__(
        vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_memory_monitor_key,
    "memory_monitor",
    uri,
    "memory",
    "turns on monitoring all the memory oprations and dumping them to file",
    uri);
}
