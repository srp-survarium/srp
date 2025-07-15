void __thiscall dynamic_initializer_for__s_max_ping__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_max_ping,
    "max_ping",
    uri,
    uri,
    "set maximum ping time in milliseconds (flow emulator)",
    uri);
}
