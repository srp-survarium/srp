void __thiscall dynamic_initializer_for__s_min_ping__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_min_ping,
    "min_ping",
    uri,
    uri,
    "set minimum ping time in milliseconds (flow emulator)",
    uri);
}
