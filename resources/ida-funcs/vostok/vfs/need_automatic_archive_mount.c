bool __usercall vostok::vfs::need_automatic_archive_mount@<al>(
        vostok::vfs::base_node<1> *node@<eax>,
        bool *is_out_of_memory,
        vostok::memory::base_allocator *allocator)
{
  unsigned __int16 m_flags; // cx
  vostok::vfs::base_node<1> *v6; // ecx
  vostok::vfs::physical_file_node<1> *v7; // ebx
  volatile signed __int32 *p_m_flags; // edi
  vostok::vfs::physical_folder_mount_root_node<1> *mount_root; // esi
  vostok::vfs::base_node<1> *v10; // ecx
  vostok::fixed_string<260> *p_m_file_flags; // ecx
  bool v12; // bl
  char v13; // al
  vostok::fs_new::asynchronous_device_interface *v14; // [esp-4h] [ebp-13Ch]
  vostok::fs_new::watcher_enabled_bool v15; // [esp+0h] [ebp-138h]
  vostok::fs_new::native_path_string v16; // [esp+10h] [ebp-128h] BYREF
  vostok::fs_new::synchronous_device_interface v17; // [esp+12Ch] [ebp-Ch] BYREF

  m_flags = node->m_flags;
  *is_out_of_memory = 0;
  if ( (m_flags & 0x800) == 0x800 )
    return 0;
  v7 = vostok::vfs::node_cast<vostok::vfs::physical_file_node,vostok::vfs::base_node,1>(node);
  p_m_flags = &v7->m_file_flags.m_flags;
  if ( (v7->m_file_flags.m_flags & 1) != 0 )
    return (*p_m_flags & 2) != 0 && (*p_m_flags & 4) == 0;
  mount_root = vostok::vfs::base_node<1>::get_mount_root(v6, (int)node);
  vostok::vfs::get_node_physical_path<vostok::vfs::physical_file_node,1>(v7, v10, &v16);
  vostok::fs_new::synchronous_device_interface::synchronous_device_interface(
    &v17,
    mount_root->device.pointer,
    v14,
    (vostok::fs_new::asynchronous_device_query_vtbl *)mount_root->async_device.pointer,
    allocator,
    v15);
  if ( v17.m_out_of_memory )
  {
    *is_out_of_memory = 1;
    v12 = 0;
  }
  else
  {
    v13 = vostok::vfs::check_is_archive_file(&v17, p_m_file_flags, v16.m_string.m_begin);
    p_m_file_flags = (vostok::fixed_string<260> *)&v7->m_file_flags;
    _InterlockedOr(p_m_flags, (v13 != 0 ? 2 : 0) | 1);
    v12 = (*p_m_flags & 2) == 2;
  }
  vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(
    (vostok::fs_new::synchronous_device_interface *)p_m_file_flags,
    (int *)&v17);
  return v12;
}
