void __thiscall dynamic_initializer_for__s_max_unacknowledged_packets_count__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_max_unacknowledged_packets_count,
    "max_unacknowledged_packets_count",
    uri,
    &initiator_raw.filter_stack.gap0,
    "set maximum unkacknowledged packets count before it is considered connection is be broken",
    "32 - 1024");
}
