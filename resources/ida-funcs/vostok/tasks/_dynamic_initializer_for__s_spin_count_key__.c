void __thiscall vostok::tasks::_dynamic_initializer_for__s_spin_count_key__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_spin_count_key,
    "spin_count",
    uri,
    "task system",
    "number of trylocks before task system is notified about long lock",
    uri);
}
