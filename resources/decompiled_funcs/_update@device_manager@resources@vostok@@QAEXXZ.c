void __thiscall vostok::resources::device_manager::update(vostok::resources::device_manager *this)
{
  vostok::fs_new::asynchronous_device_interface *v1; // esi
  vostok::fs_new::asynchronous_device_interface *v2; // edi

  if ( this->m_pre_allocated_size < (signed int)this->m_min_wanted_pre_allocated_size )
    vostok::resources::device_manager::fill_pre_allocated(this, this);
  v1 = *(vostok::fs_new::asynchronous_device_interface **)((char *)&loc_205F8
                                                         + (unsigned int)vostok::resources::g_resources_manager.m_variable);
  v2 = *(vostok::fs_new::asynchronous_device_interface **)((char *)&loc_205FB
                                                         + (unsigned int)vostok::resources::g_resources_manager.m_variable
                                                         + 1);
  if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
  {
    vostok::threading::g_debug_single_thread.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( vostok::threading::g_debug_single_thread.m_type != type_recursive )
  {
    if ( v1 )
      vostok::fs_new::asynchronous_device_interface::tick(v1, 0);
    if ( v2 )
      vostok::fs_new::asynchronous_device_interface::tick(v2, 0);
  }
}
