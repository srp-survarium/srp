void __thiscall vostok::core::_dynamic_initializer_for__s_log_to_stdout__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_log_to_stdout,
    "log_to_stdout",
    uri,
    "logging",
    "turns on writing to stdout",
    uri);
}
