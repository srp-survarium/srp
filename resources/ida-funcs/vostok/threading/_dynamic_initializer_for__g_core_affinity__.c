void __thiscall vostok::threading::_dynamic_initializer_for__g_core_affinity__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &vostok::threading::g_core_affinity,
    "core_affinity",
    uri,
    "threading",
    "string mask with 1 and 0",
    uri);
}
