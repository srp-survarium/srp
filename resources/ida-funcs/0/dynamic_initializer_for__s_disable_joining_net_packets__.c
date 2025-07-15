void __thiscall dynamic_initializer_for__s_disable_joining_net_packets__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_disable_joining_net_packets,
    "disable_joining_net_packets",
    uri,
    &initiator_raw.filter_stack.gap0,
    "try to merge packets before sending",
    "0 or 1");
}
