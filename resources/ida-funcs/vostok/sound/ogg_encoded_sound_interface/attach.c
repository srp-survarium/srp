void __thiscall vostok::sound::ogg_encoded_sound_interface::attach(vostok::sound::ogg_encoded_sound_interface *this)
{
  vorbis_info *v2; // esi
  ov_callbacks v3; // [esp-10h] [ebp-2Ch]

  if ( ++this->m_active_count == 1 )
  {
    v3.read_func = (unsigned int (__cdecl *)(void *, unsigned int, unsigned int, void *))vostok::sound::ogg_utils::ov_read_func;
    v3.seek_func = (int (__cdecl *)(void *, __int64, int))vostok::sound::ogg_utils::ov_seek_func;
    v3.close_func = (int (__cdecl *)(void *))survarium::player_respawn_rule::priority;
    this->m_raw_file.pointer = 0;
    v3.tell_func = (int (__cdecl *)(void *))vostok::sound::ogg_utils::ov_tell_func;
    ov_open_callbacks(&this->m_raw_file, &this->m_ovf, 0, 0, v3);
    v2 = ov_info(&this->m_ovf, -1);
    this->m_bytes_per_sample = 2;
    this->m_length_in_pcm = ov_pcm_total(&this->m_ovf, -1);
    this->m_samples_per_sec = v2->rate;
    this->m_channels_num = v2->channels;
  }
}
