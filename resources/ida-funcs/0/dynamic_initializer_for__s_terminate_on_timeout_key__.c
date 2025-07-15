void __thiscall dynamic_initializer_for__s_terminate_on_timeout_key__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_terminate_on_timeout_key,
    "terminate_on_timeout",
    uri,
    "tests",
    "application will be terminated after timeout",
    "specify time limit (in seconds) as a first argument");
}
