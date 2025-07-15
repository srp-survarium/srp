void __thiscall vostok::resources::_dynamic_initializer_for__s_skip_file_not_found__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_skip_file_not_found,
    "skip_file_not_found",
    uri,
    (const char *)&stru_7FD250.lock.m_readers_writers_counter.whole + 4,
    "doesn't debug break if file is not found",
    uri);
}
