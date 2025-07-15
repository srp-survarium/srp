void __thiscall vostok::core::_dynamic_initializer_for__s_dont_check_multithreaded_safety__(
        vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_dont_check_multithreaded_safety,
    "dont_check_multithreaded_safety",
    uri,
    "threading",
    "turn off checks of parallel use of code that is not multithreaded",
    uri);
}
