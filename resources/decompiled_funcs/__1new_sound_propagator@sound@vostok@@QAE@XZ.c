void __thiscall vostok::sound::new_sound_propagator::~new_sound_propagator(vostok::sound::new_sound_propagator *this)
{
  IXAudio2SubmixVoice **i; // [esp+8h] [ebp-4h]

  if ( this->m_voice )
    vostok::sound::new_sound_propagator::detach_voice(this, this->m_voice);
  for ( i = this->m_submix_voices.m_begin; i != this->m_submix_voices.m_end; ++i )
    ;
  this->m_submix_voices.m_end = this->m_submix_voices.m_begin;
}
