vostok::sound::voice_bridge *__thiscall vostok::sound::voice_factory::new_voice(
        vostok::sound::voice_factory *this,
        vostok::sound::sound_voice *callback_handler,
        unsigned __int8 channels_num,
        unsigned int sample_rate)
{
  vostok::sound::voice_bridge *idle_voice; // [esp+8h] [ebp-4h]

  for ( idle_voice = (vostok::sound::voice_bridge *)*(&this->m_pool_params.mono_voices_count + 4 * channels_num);
        idle_voice->m_handler;
        idle_voice = idle_voice->m_next )
  {
    ;
  }
  vostok::sound::voice_bridge::set_handler(idle_voice, callback_handler);
  vostok::sound::voice_bridge::set_sample_rate(idle_voice, sample_rate);
  return idle_voice;
}
