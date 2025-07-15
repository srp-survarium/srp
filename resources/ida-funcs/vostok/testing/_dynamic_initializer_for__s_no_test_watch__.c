void __thiscall vostok::testing::_dynamic_initializer_for__s_no_test_watch__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &vostok::testing::s_no_test_watch,
    "no_test_watch",
    uri,
    "testing",
    "disables thread that watches for too long tests",
    uri);
}
