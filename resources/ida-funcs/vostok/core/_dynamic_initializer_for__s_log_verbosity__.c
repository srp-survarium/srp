void __thiscall vostok::core::_dynamic_initializer_for__s_log_verbosity__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_log_verbosity,
    "log_verbosity",
    uri,
    "logging",
    "one of: [trace|debug|info|warning|error|silent]",
    uri);
}
