void __userpurge vostok::vfs::unmounter::unmounter(
        vostok::vfs::query_mount_arguments *m_args@<ecx>,
        vostok::vfs::virtual_file_system *file_system@<eax>,
        vostok::vfs::unmounter *this)
{
  vostok::vfs::vfs_hashset *p_hashset; // ecx
  _DWORD *v5; // eax
  int v6; // ecx
  vostok::vfs::unmounter *v7; // ecx
  vostok::vfs::vfs_mount *p_callback; // esi
  vostok::vfs::mount_result *v9; // ecx
  vostok::vfs::vfs_mount *v10; // ecx
  const vostok::vfs::mount_result *v11; // eax
  boost::function1<void,vostok::vfs::mount_result> *v12; // ecx
  vostok::vfs::mount_result v13; // [esp-Ch] [ebp-1Ch] BYREF
  int v14; // [esp-4h] [ebp-14h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v15; // [esp+8h] [ebp-8h] BYREF

  this->m_root_node_to_unmount = 0;
  p_hashset = &file_system->hashset;
  this->m_file_system = file_system;
  v5 = (int *)((char *)&dword_201A8 + (_DWORD)file_system);
  this->m_hashset = p_hashset;
  this->m_args = m_args;
  v6 = -(*v5 != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v6) != 0 )
    boost::function0<void>::operator()((boost::function0<bool> *)v6, v5);
  vostok::vfs::query_mount_arguments::convert_pathes_to_absolute((vostok::vfs::query_mount_arguments *)v6, (int)m_args);
  this->m_root_node_to_unmount = m_args->mount_ptr->m_mount_root;
  if ( m_args->submount_type == submount_type_hot_unmount )
    vostok::vfs::unmounter::hot_unmount(v7, this);
  else
    vostok::vfs::unmounter::unmount(v7, (vostok::fs_new::virtual_path_string *)this);
  if ( m_args->unlock_after_mount )
    vostok::vfs::unlock_branch(m_args->root_write_lock, lock_type_write);
  p_callback = (vostok::vfs::vfs_mount *)&m_args->callback;
  if ( (p_callback->m_reference_count != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    v14 = 1;
    v13.result = result_fail;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v13.result,
      0);
    vostok::vfs::mount_result::mount_result(
      v9,
      &v15,
      (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>)v13.result,
      (vostok::vfs::vfs_mount *)v14);
    v14 = (int)v10;
    v13.result = (vostok::vfs::result_enum)v10;
    vostok::vfs::mount_result::mount_result((vostok::vfs::mount_result *)&v13.result, v11);
    v13.mount.m_object = p_callback;
    boost::function1<void,vostok::vfs::mount_result>::operator()(
      v12,
      v13,
      (boost::function1<void,vostok::vfs::mount_result> *)v14);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v15);
  }
}
