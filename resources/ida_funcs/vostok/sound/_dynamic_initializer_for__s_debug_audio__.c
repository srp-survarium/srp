void vostok::sound::_dynamic_initializer_for__s_debug_audio__()
{
  vostok::command_line::key::key(
    &s_debug_audio,
    "debug_audio",
    (const char *)&buf,
    "sound engine",
    "running debug XAudio2 engine",
    (const char *)&buf);
}
