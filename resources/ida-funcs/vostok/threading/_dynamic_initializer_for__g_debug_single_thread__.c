void __thiscall vostok::threading::_dynamic_initializer_for__g_debug_single_thread__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &vostok::threading::g_debug_single_thread,
    "debug_single_thread",
    uri,
    "threading",
    "run all in one thread",
    uri);
}
