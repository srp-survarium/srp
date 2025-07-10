void __thiscall vostok::sound::sound_voice::set_output_matrix(
        vostok::sound::sound_voice *this,
        const float *level_matrix)
{
  if ( this->m_channels_num == 1 )
  {
    vostok::sound::voice_bridge::set_output_matrix(this->m_voice, level_matrix);
  }
  else if ( this->m_channels_num == 2 )
  {
    vostok::sound::voice_bridge::set_channel_volumes(this->m_voice, this->m_channels_num, level_matrix);
  }
}
