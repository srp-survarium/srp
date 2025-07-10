char __cdecl vostok::vfs::need_automatic_archive_mount(
        bool *is_out_of_memory,
        vostok::vfs::base_node<1> *node,
        vostok::memory::base_allocator *allocator)
{
  const char *v4; // eax
  vostok::vfs::mount_root_node_base<1> *pointer; // [esp+0h] [ebp-1B8h]
  unsigned int v7; // [esp+24h] [ebp-194h] BYREF
  unsigned int v8; // [esp+28h] [ebp-190h]
  unsigned int *v9; // [esp+2Ch] [ebp-18Ch]
  bool m_out_of_memory; // [esp+37h] [ebp-181h]
  vostok::flags_type<enum vostok::vfs::physical_file_node<1>::flags_enum,vostok::threading::multi_threading_policy> *p_m_file_flags; // [esp+6Ch] [ebp-14Ch]
  _DWORD v12[4]; // [esp+70h] [ebp-148h] BYREF
  bool v13; // [esp+82h] [ebp-136h]
  char v14; // [esp+83h] [ebp-135h]
  vostok::vfs::mount_root_node_base<1> *mount_root; // [esp+84h] [ebp-134h]
  vostok::fs_new::native_path_string file_path; // [esp+88h] [ebp-130h] BYREF
  vostok::fs_new::synchronous_device_interface sync_device; // [esp+1A4h] [ebp-14h] BYREF
  vostok::vfs::physical_file_node<1> *file_node; // [esp+1B0h] [ebp-8h]
  bool is_archive_file; // [esp+1B7h] [ebp-1h]

  *is_out_of_memory = 0;
  if ( (node->m_flags & 0x800) == 0x800 )
    return 0;
  file_node = vostok::vfs::node_cast<vostok::vfs::physical_file_node,vostok::vfs::base_node,1>(node);
  v12[2] = v12;
  v12[0] = 1;
  p_m_file_flags = &file_node->m_file_flags;
  v12[1] = 1;
  if ( (file_node->m_file_flags.m_flags & 1) == 1 )
  {
    return vostok::vfs::physical_file_node<1>::is_archive_file(file_node)
        && !vostok::vfs::physical_file_node<1>::is_mounted_archive(file_node);
  }
  else
  {
    if ( (node->m_flags & 8) == 8 )
      pointer = vostok::vfs::node_cast<vostok::vfs::mount_root_node_base,vostok::vfs::base_node,1>(node);
    else
      pointer = node->m_mount_root.pointer;
    mount_root = pointer;
    vostok::vfs::get_node_physical_path<vostok::vfs::physical_file_node,1>(&file_path, file_node);
    vostok::fs_new::synchronous_device_interface::synchronous_device_interface(
      &sync_device,
      mount_root->async_device.pointer,
      allocator,
      mount_root->device.pointer,
      mount_root->watcher_enabled);
    m_out_of_memory = sync_device.m_out_of_memory;
    if ( sync_device.m_out_of_memory )
    {
      *is_out_of_memory = 1;
      v14 = 0;
      vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(&sync_device);
      return v14;
    }
    else
    {
      v4 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&file_path);
      is_archive_file = vostok::vfs::check_is_archive_file(v4, &sync_device);
      v9 = &v7;
      v8 = (is_archive_file ? 2 : 0) | 1;
      v7 = v8;
      _InterlockedOr(&file_node->m_file_flags.m_flags, v8);
      v13 = vostok::vfs::physical_file_node<1>::is_archive_file(file_node);
      vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(&sync_device);
      return v13;
    }
  }
}
