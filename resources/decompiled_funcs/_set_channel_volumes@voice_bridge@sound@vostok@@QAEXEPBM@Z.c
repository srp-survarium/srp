void __thiscall vostok::sound::voice_bridge::set_channel_volumes(
        vostok::sound::voice_bridge *this,
        unsigned __int8 channels_num,
        const float *level_matrix)
{
  this->m_source_voice->SetChannelVolumes(this->m_source_voice, channels_num, level_matrix, 0);
}
