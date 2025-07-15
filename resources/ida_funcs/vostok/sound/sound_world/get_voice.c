vostok::sound::voice_bridge *__thiscall vostok::sound::sound_world::get_voice(
        vostok::sound::sound_world *this,
        vostok::sound::sound_voice *callback_handler,
        IXAudio2SubmixVoice *submix_voice,
        unsigned __int8 channels_num,
        unsigned int sample_rate)
{
  vostok::sound::voice_bridge *voice; // [esp+4h] [ebp-4h]

  voice = vostok::sound::voice_factory::new_voice(this->m_voice_factory, callback_handler, channels_num, sample_rate);
  vostok::sound::voice_bridge::set_output_voice(voice, submix_voice);
  return voice;
}
