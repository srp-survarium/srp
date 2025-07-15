char __userpurge vostok::resources::device_manager::do_async_operation@<al>(
        void **file@<ecx>,
        vostok::fs_new::synchronous_device_interface *device@<eax>,
        vostok::resources::device_manager *this,
        vostok::resources::query_result *query,
        unsigned __int64 out_data,
        vostok::mutable_buffer file_pos,
        bool sector_aligned)
{
  vostok::animation::mixing::animation_interval *v9; // eax
  vostok::fs_new::device_file_system_proxy_base *v10; // eax
  void *v11; // ebx
  vostok::animation::mixing::animation_interval *v12; // eax
  vostok::fs_new::device_file_system_proxy_base *v13; // eax
  vostok::vfs::base_node<1> *v14; // eax
  int v15; // edx
  vostok::animation::mixing::animation_interval *v16; // eax
  vostok::fs_new::device_file_system_no_watcher_proxy *v17; // eax
  int v18; // edi
  unsigned __int64 v21; // [esp-8h] [ebp-18h]
  unsigned __int64 v22; // [esp-8h] [ebp-18h]

  v9 = (vostok::animation::mixing::animation_interval *)vostok::fs_new::synchronous_device_interface::operator->(device);
  v10 = (vostok::fs_new::device_file_system_proxy_base *)vostok::animation::mixing::animation_interval::animation(v9);
  vostok::fs_new::device_file_system_proxy_base::seek(
    v10,
    file,
    __PAIR64__(out_data, (unsigned int)query),
    seek_file_begin);
  v11 = (void *)HIDWORD(out_data);
  if ( (*(_DWORD *)&this->m_sector_data_first[556] & 2) != 0 )
  {
    v21 = (unsigned int)vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)((char *)&out_data + 4));
    v12 = (vostok::animation::mixing::animation_interval *)vostok::fs_new::synchronous_device_interface::operator->(device);
    v13 = (vostok::fs_new::device_file_system_proxy_base *)vostok::animation::mixing::animation_interval::animation(v12);
    v14 = (vostok::vfs::base_node<1> *)vostok::fs_new::device_file_system_proxy_base::read(v13, file, v11, v21);
  }
  else
  {
    v22 = (unsigned int)vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)((char *)&out_data + 4));
    v16 = (vostok::animation::mixing::animation_interval *)vostok::fs_new::synchronous_device_interface::operator->(device);
    v17 = (vostok::fs_new::device_file_system_no_watcher_proxy *)vostok::animation::mixing::animation_interval::animation(v16);
    v14 = (vostok::vfs::base_node<1> *)vostok::fs_new::device_file_system_no_watcher_proxy::write(v17, file, v11, v22);
  }
  v18 = v15;
  if ( v14 == vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)((char *)&out_data + 4)) && !v18 )
    return 1;
  *(_DWORD *)&this->m_sector_data_first[124] = ((*(_DWORD *)&this->m_sector_data_first[556] & 2) != 2) + 3;
  return 0;
}
