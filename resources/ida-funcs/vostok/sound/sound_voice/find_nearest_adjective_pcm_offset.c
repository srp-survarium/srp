unsigned int __thiscall vostok::sound::sound_voice::find_nearest_adjective_pcm_offset(vostok::sound::sound_voice *this)
{
  return vostok::sound::time_in_msec_to_pcm(&this->m_current_sound_quality, this->m_playing_offset)
       / (0xAC44
        / this->m_current_sound_quality.m_object->m_bytes_per_sample)
       * (0xAC44
        / this->m_current_sound_quality.m_object->m_bytes_per_sample);
}
