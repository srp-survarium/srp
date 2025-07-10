void __thiscall vostok::sound::voice_factory::set_frequency_ratio(vostok::sound::voice_factory *this, float ratio)
{
  vostok::sound::voice_bridge *current_voice; // [esp+Ch] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-4h]

  for ( i = 0; i < 2; ++i )
  {
    for ( current_voice = this->m_voices_pool.elems[i].m_first; current_voice; current_voice = current_voice->m_next )
      vostok::sound::voice_bridge::set_frequency_ratio(current_voice, ratio);
  }
}
