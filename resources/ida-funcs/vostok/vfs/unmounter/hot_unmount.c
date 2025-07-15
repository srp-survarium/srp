void __usercall vostok::vfs::unmounter::hot_unmount(
        vostok::vfs::unmounter *this@<ecx>,
        vostok::vfs::unmounter *a2@<edi>)
{
  vostok::vfs::virtual_file_system *m_file_system; // eax
  _DWORD *v3; // esi
  vostok::vfs::base_node<1> *submount_node; // ecx
  vostok::vfs::is_part_of_mount *v5; // eax
  vostok::vfs::query_mount_arguments *v6; // eax
  const vostok::vfs::is_exact_node *v7; // eax
  vostok::vfs::query_mount_arguments *m_args; // [esp-14h] [ebp-154h]
  vostok::vfs::base_folder_node<1> *pointer; // [esp-4h] [ebp-144h]
  vostok::fs_new::virtual_path_string out_result; // [esp+8h] [ebp-138h] BYREF
  _DWORD v11[4]; // [esp+124h] [ebp-1Ch] BYREF
  vostok::vfs::mount_root_node_base<1> *m_root_node_to_unmount; // [esp+134h] [ebp-Ch] BYREF
  vostok::vfs::base_node<1> *v13; // [esp+138h] [ebp-8h] BYREF
  vostok::vfs::is_exact_node v14; // [esp+13Ch] [ebp-4h] BYREF

  m_file_system = a2->m_file_system;
  v3 = &m_file_system->mount_history.gap0 + (_DWORD)&loc_20185 + 3;
  if ( (*(_DWORD *)(&m_file_system->mount_history.gap0 + (_DWORD)&loc_20185 + 3) != 0
      ? (unsigned int)vostok::memory::process_allocator::finalize_impl
      : 0) != 0 )
  {
    submount_node = a2->m_args->submount_node;
    v11[0] = &m_file_system->hashset;
    v11[1] = submount_node;
    v11[2] = 0;
    v11[3] = 2;
    if ( submount_node )
      vostok::vfs::vfs_iterator::vfs_iterator((vostok::vfs::vfs_iterator *)submount_node, (int)v11);
    boost::function1<void,vostok::collision::object const &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)submount_node,
      v3,
      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)v11);
  }
  v5 = (vostok::vfs::is_part_of_mount *)vostok::fs_new::path_crc32(
                                          a2->m_args->virtual_path.m_string.m_begin,
                                          a2->m_args->virtual_path.m_string.m_end
                                        - a2->m_args->virtual_path.m_string.m_begin,
                                          0);
  m_root_node_to_unmount = a2->m_root_node_to_unmount;
  m_args = a2->m_args;
  v13 = 0;
  v14.helper_node = 0;
  vostok::vfs::unmounter::recursive_unmount_node<vostok::vfs::is_part_of_mount>(
    (vostok::vfs::unmounter *)&m_root_node_to_unmount,
    a2,
    &m_args->virtual_path,
    v5,
    (vostok::vfs::base_node<1> **)&m_root_node_to_unmount,
    &v13,
    &v14.helper_node);
  out_result.m_string.m_begin = out_result.m_string.m_buffer;
  out_result.m_string.m_end = out_result.m_string.m_buffer;
  out_result.m_string.m_max_end = &out_result.m_separator;
  v6 = a2->m_args;
  out_result.m_string.m_buffer[0] = 0;
  out_result.m_separator = 47;
  vostok::fs_new::get_path_without_last_item<vostok::fs_new::virtual_path_string>(
    &out_result,
    v6->virtual_path.m_string.m_begin);
  v7 = (const vostok::vfs::is_exact_node *)vostok::fs_new::path_crc32(
                                             out_result.m_string.m_begin,
                                             out_result.m_string.m_end - out_result.m_string.m_begin,
                                             0);
  pointer = v13->m_parent.pointer;
  v14.helper_node = v13;
  vostok::vfs::unmounter::recursive_traverse_folder<vostok::vfs::is_exact_node>(
    (vostok::vfs::unmounter *)&v14,
    a2,
    &out_result,
    v7,
    &v14,
    &pointer->m_first_child.pointer);
}
