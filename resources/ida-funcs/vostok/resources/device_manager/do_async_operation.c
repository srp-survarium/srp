char __userpurge vostok::resources::device_manager::do_async_operation@<al>(
        vostok::resources::query_result *query@<edi>,
        const vostok::fs_new::synchronous_device_interface *device@<eax>,
        vostok::fs_new::device_file_system_proxy_base *a3@<ecx>,
        vostok::resources::device_manager *this,
        void **file,
        vostok::mutable_buffer out_data,
        const unsigned __int64 file_pos,
        bool sector_aligned)
{
  vostok::fs_new::device_file_system_no_watcher_proxy *p_m_device; // esi
  vostok::fs_new::device_file_system_no_watcher_proxy *v9; // ecx
  __int64 v10; // rax

  p_m_device = &device->m_device;
  vostok::fs_new::device_file_system_proxy_base::seek(
    a3,
    &device->m_device.m_device_file_system,
    (void **)&this->__vftable,
    __PAIR64__((unsigned int)out_data.m_data, (unsigned int)file),
    seek_file_begin);
  if ( (query->m_flags & 2) != 0 )
    LODWORD(v10) = vostok::fs_new::device_file_system_proxy_base::read(
                     v9,
                     p_m_device,
                     (void **)&this->__vftable,
                     (void *)out_data.m_size,
                     (unsigned int)file_pos);
  else
    LODWORD(v10) = vostok::fs_new::device_file_system_no_watcher_proxy::write(
                     v9,
                     p_m_device,
                     (void **)&this->__vftable,
                     (const void *)out_data.m_size,
                     (unsigned int)file_pos);
  if ( v10 == (unsigned int)file_pos )
    return 1;
  query->m_error_type = ((query->m_flags & 2) != 2) + 3;
  return 0;
}
