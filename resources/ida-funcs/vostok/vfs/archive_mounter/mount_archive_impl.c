void __userpurge vostok::vfs::archive_mounter::mount_archive_impl(
        vostok::vfs::archive_mounter *this@<ecx>,
        int a2@<edi>,
        vostok::fs_new::synchronous_device_interface *device)
{
  vostok::vfs::archive_mounter *v3; // ecx
  vostok::vfs::base_node<1> *v4; // eax
  vostok::vfs::base_folder_node<1> *v5; // eax
  _BYTE *v6; // eax
  int v7; // edx
  int v8; // esi
  void *v9; // esp
  vostok::vfs::mounter *v10; // ecx
  vostok::vfs::archive_mounter *v11; // ecx
  vostok::vfs::base_folder_node<1> *v12; // eax
  _BYTE v13[8]; // [esp+0h] [ebp-13Ch] BYREF
  vostok::fs_new::native_path_string v14; // [esp+8h] [ebp-134h] BYREF
  vostok::buffer_vector<vostok::vfs::mount_helper_node<1> *> out_helper_nodes; // [esp+11Ch] [ebp-20h] BYREF
  unsigned int v16; // [esp+128h] [ebp-14h] BYREF
  vostok::vfs::base_node<1> *in_out_lock; // [esp+12Ch] [ebp-10h] BYREF
  vostok::fs_new::synchronous_device_interface *v18; // [esp+130h] [ebp-Ch] BYREF
  vostok::vfs::base_folder_node<1> *parent_of_mount_root; // [esp+134h] [ebp-8h] BYREF

  vostok::fixed_string<260>::fixed_string<260>((vostok::fixed_string<260> *)this, &v14.m_string, *(char **)(a2 + 900));
  v14.m_separator = 92;
  v18 = device;
  vostok::fs_new::open_cached_file(
    device,
    (void ***)&parent_of_mount_root,
    &v14,
    open_existing,
    read,
    assert_on_fail_false,
    notify_watcher_true);
  if ( parent_of_mount_root )
  {
    if ( *(_DWORD *)(a2 + 1288) )
    {
      v4 = *(vostok::vfs::base_node<1> **)(a2 + 1292);
      if ( v4 )
        v5 = vostok::vfs::cast_folder<1>(v4);
      else
        v5 = 0;
      vostok::vfs::archive_mounter::mount_archive_to_parent(v3, (void **)a2, parent_of_mount_root, v5, (int)device);
      if ( *(_DWORD *)(a2 + 68) != 3 )
        _InterlockedOr(
          &vostok::vfs::node_cast<vostok::vfs::physical_file_node,vostok::vfs::base_node,1>(*(vostok::vfs::base_node<1> **)(a2 + 1288))->m_file_flags.m_flags,
          4u);
    }
    else
    {
      v6 = *(_BYTE **)(a2 + 72);
      v7 = 0;
      while ( *v6 )
      {
        if ( *v6 == 47 )
          ++v7;
        ++v6;
      }
      v8 = 4 * ((*(_DWORD *)(a2 + 76) != *(_DWORD *)(a2 + 72)) + v7 + 1);
      v9 = alloca(v8);
      out_helper_nodes.m_begin = (vostok::vfs::mount_helper_node<1> **)v13;
      out_helper_nodes.m_end = (vostok::vfs::mount_helper_node<1> **)v13;
      out_helper_nodes.m_max_end = (vostok::vfs::mount_helper_node<1> **)&v13[v8];
      if ( vostok::vfs::mounter::allocate_mount_branch(0, (vostok::vfs::mounter *)a2, &out_helper_nodes) )
      {
        in_out_lock = 0;
        v16 = 0;
        vostok::vfs::mounter::add_mount_branch(
          v10,
          (vostok::vfs::mounter *)a2,
          (vostok::vfs::base_node<1> **)&out_helper_nodes,
          &in_out_lock,
          (vostok::vfs::base_node<1> **)(a2 + 1284),
          &v16);
        if ( in_out_lock )
          v12 = vostok::vfs::cast_folder<1>(in_out_lock);
        else
          v12 = 0;
        vostok::vfs::archive_mounter::mount_archive_to_parent(v11, (void **)a2, parent_of_mount_root, v12, (int)device);
      }
      else
      {
        vostok::vfs::mounter::finish_with_out_of_memory(v10, a2);
      }
    }
  }
  else
  {
    *(_DWORD *)(a2 + 68) = 0;
  }
  vostok::fs_new::file_type_pointer::close((vostok::fs_new::file_type_pointer *)v3, &v18);
}
