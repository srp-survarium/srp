bool __thiscall vostok::memory::monitor::enabled(vostok::command_line::key *this)
{
  if ( (_S5_12 & 1) == 0 )
  {
    _S5_12 |= 1u;
    s_enabled = vostok::command_line::key::is_set(this, (int)&s_memory_monitor_key);
  }
  return s_enabled;
}
