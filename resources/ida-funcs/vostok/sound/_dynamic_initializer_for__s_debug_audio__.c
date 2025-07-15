void __thiscall vostok::sound::_dynamic_initializer_for__s_debug_audio__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_debug_audio,
    "debug_audio",
    uri,
    "sound engine",
    "running debug XAudio2 engine",
    uri);
}
