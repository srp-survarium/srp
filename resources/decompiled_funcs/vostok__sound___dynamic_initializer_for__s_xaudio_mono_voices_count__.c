void vostok::sound::_dynamic_initializer_for__s_xaudio_mono_voices_count__()
{
  vostok::command_line::key::key(
    &s_xaudio_mono_voices_count,
    "xaudio_mono_voices_count",
    "xaudio_mono_voices",
    "sound engine",
    "count of mono xaudio voices in voice_factory, default is 64.",
    (const char *)&buf);
}
