void __thiscall dynamic_initializer_for__s_max_video_memory__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_max_video_memory,
    "max_video_memory",
    uri,
    "memory",
    "set maximum video memory limit, Mb",
    uri);
}
