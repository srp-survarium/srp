char __thiscall vostok::logging::log_file::read_next_char(vostok::logging::log_file *this)
{
  int cache_offs; // [esp+8h] [ebp-4h]

  cache_offs = this->m_current_pos - this->m_cache_start;
  ++this->m_current_pos;
  if ( this->m_cache_start != -1 && cache_offs >= 0 && cache_offs < this->m_cache_size )
    return this->m_cache[cache_offs];
  this->m_cache_start = this->m_current_pos - 1;
  vostok::fs_new::device_file_system_proxy_base::seek(
    &this->m_device.m_device,
    this->m_file,
    this->m_cache_start,
    seek_file_begin);
  this->m_cache_size = vostok::fs_new::device_file_system_proxy_base::read(
                         &this->m_device.m_device,
                         this->m_file,
                         this,
                         0x400u);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return this->m_cache[0];
}
