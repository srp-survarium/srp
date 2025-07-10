char __thiscall vostok::vfs::archive_mounter::read_sub_fat(
        vostok::vfs::archive_mounter *this,
        vostok::fs_new::synchronous_device_interface *device)
{
  unsigned __int64 v2; // rax
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v7; // ecx
  _BYTE *v8; // eax
  survarium::game_camera *v9; // ecx
  char *other; // [esp+24h] [ebp-24Ch] BYREF
  vostok::fs_new::native_path_string physical_path; // [esp+28h] [ebp-248h] BYREF
  char v13; // [esp+13Fh] [ebp-131h]
  unsigned __int64 file_offs; // [esp+140h] [ebp-130h]
  unsigned int sub_fat_size; // [esp+148h] [ebp-128h]
  unsigned int read_bytes; // [esp+14Ch] [ebp-124h]
  vostok::fs_new::native_path_string fat_physical_path; // [esp+150h] [ebp-120h] BYREF
  vostok::fs_new::file_type_pointer fat_file; // [esp+268h] [ebp-8h] BYREF

  LODWORD(v2) = vostok::vfs::get_file_offs<1>(this->m_args.submount_node);
  file_offs = v2;
  v3 = (survarium::game_camera *)(this->m_args.submount_node->m_flags & 0x1000);
  if ( v3 != (survarium::game_camera *)4096 )
  {
    v13 = 0;
    survarium::weapon_user_dead_state::finalize(v3);
  }
  vostok::vfs::query_mount_arguments::get_physical_path(&this->m_args, &fat_physical_path);
  other = (char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&fat_physical_path);
  vostok::fs_new::native_path_string::native_path_string(&physical_path, (const char **)&other);
  survarium::weapon_user_dead_state::finalize(v4);
  fat_file.device = device;
  vostok::fs_new::open_cached_file(
    device,
    &fat_file.file,
    (vostok::fs_new::open_file_cache *)&physical_path,
    open_existing,
    read,
    assert_on_fail_false,
    notify_watcher_true,
    use_buffering_true);
  if ( fat_file.file )
  {
    vostok::fs_new::device_file_system_proxy_base::seek(&device->m_device, fat_file.file, file_offs, seek_file_begin);
    sub_fat_size = vostok::vfs::get_file_size<1>(this->m_args.submount_node);
    read_bytes = vostok::fs_new::device_file_system_proxy_base::read(
                   &device->m_device,
                   fat_file.file,
                   this->m_nodes_buffer,
                   sub_fat_size);
    survarium::weapon_user_dead_state::finalize(v7);
    if ( *v8 )
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)read_bytes);
    vostok::fs_new::file_type_pointer::close(&fat_file);
    survarium::weapon_user_dead_state::finalize(v9);
    return 1;
  }
  else
  {
    vostok::fs_new::file_type_pointer::close(&fat_file);
    survarium::weapon_user_dead_state::finalize(v5);
    return 0;
  }
}
