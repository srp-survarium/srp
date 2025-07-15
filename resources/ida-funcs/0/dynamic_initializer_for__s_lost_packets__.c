void __thiscall dynamic_initializer_for__s_lost_packets__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_lost_packets,
    "lost_packets",
    uri,
    uri,
    "probability of packets being lost on server side (flow emulator)",
    uri);
}
