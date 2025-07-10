void __thiscall vostok::sound::effect_cross_fader::effect_cross_fader(
        vostok::sound::effect_cross_fader *this,
        vostok::sound::sound_scene *scene,
        unsigned int fade_time_in_ms,
        IXAudio2SubmixVoice *first_submix,
        IXAudio2SubmixVoice *second_submix)
{
  this->m_scene = scene;
  this->m_fade_time = fade_time_in_ms;
  this->m_fade_in_value = FLOAT_1_0;
  this->m_fade_in_submix = first_submix;
  this->m_fade_out_submix = second_submix;
  this->m_fade_in_environment = vostok::sound::sound_scene::get_current_environment(this->m_scene);
  this->m_fade_out_environment = vostok::sound::sound_scene::get_current_environment(this->m_scene);
}
