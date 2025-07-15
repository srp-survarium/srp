void __thiscall vostok::resources::device_manager::update(vostok::resources::device_manager *this)
{
  vostok::fs_new::asynchronous_device_interface *m_hdd; // esi
  vostok::fs_new::asynchronous_device_interface *m_dvd; // edi
  vostok::fs_new::asynchronous_device_interface *v3; // ecx

  if ( this->m_pre_allocated_size < (signed int)this->m_min_wanted_pre_allocated_size )
    vostok::resources::device_manager::fill_pre_allocated(this, (vostok::resources::query_result *)this);
  m_hdd = s_resources_manager_buffer.m_hdd;
  m_dvd = s_resources_manager_buffer.m_dvd;
  if ( vostok::command_line::key::is_set(
         (vostok::command_line::key *)this,
         (int)&vostok::threading::g_debug_single_thread) )
  {
    if ( m_hdd )
      vostok::fs_new::asynchronous_device_interface::tick(v3, m_hdd, 0);
    if ( m_dvd )
      vostok::fs_new::asynchronous_device_interface::tick(v3, m_dvd, 0);
  }
}
