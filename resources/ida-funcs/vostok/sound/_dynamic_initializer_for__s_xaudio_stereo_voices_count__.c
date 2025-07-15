void vostok::sound::_dynamic_initializer_for__s_xaudio_stereo_voices_count__()
{
  vostok::command_line::key::key(
    &s_xaudio_stereo_voices_count,
    "xaudio_stereo_voices_count",
    "xaudio_stereo_voices",
    "sound engine",
    "count of stereo xaudio voices in voice_factory, default is 64.",
    (const char *)&buf);
}
