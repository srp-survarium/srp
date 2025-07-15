void __thiscall dynamic_initializer_for__s_floating_point_control_disabled__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_floating_point_control_disabled,
    "floating_point_control_disabled",
    uri,
    "math",
    "disables floating point control flags setup for each thread",
    uri);
}
