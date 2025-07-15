void __thiscall vostok::engine::_dynamic_initializer_for__s_no_fs_watch__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_no_fs_watch,
    "no_fs_watch",
    uri,
    "file system",
    "disables file system changes watching",
    uri);
}
