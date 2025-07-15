void __thiscall vostok::core::_dynamic_initializer_for__s_suppress_debug_window_on_crash__(
        vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_suppress_debug_window_on_crash,
    "suppress_debug_window_on_crash",
    uri,
    "tests",
    "application will not show debug window on crash",
    "boolean");
}
