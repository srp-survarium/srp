void __thiscall vostok::vfs::archive_mounter::mount_archive_impl(
        vostok::vfs::archive_mounter *this,
        vostok::fs_new::synchronous_device_interface *device)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  void *v6; // esp
  vostok::vfs::mount_helper_node<1> **v7; // eax
  survarium::game_camera *v8; // ecx
  survarium::game_camera *v9; // ecx
  survarium::game_camera *v10; // ecx
  int v11; // [esp+0h] [ebp-1A8h] BYREF
  vostok::vfs::base_folder_node<1> *parent_of_mount_root; // [esp+4h] [ebp-1A4h]
  int *v13; // [esp+8h] [ebp-1A0h]
  vostok::vfs::archive_mounter *thisa; // [esp+Ch] [ebp-19Ch]
  vostok::vfs::mount_helper_node<1> **i; // [esp+1Ch] [ebp-18Ch]
  void **v16; // [esp+20h] [ebp-188h]
  vostok::vfs::mount_helper_node<1> **j; // [esp+30h] [ebp-178h]
  vostok::vfs::mount_helper_node<1> **v18; // [esp+34h] [ebp-174h]
  char v19; // [esp+3Bh] [ebp-16Dh]
  unsigned int v20; // [esp+3Ch] [ebp-16Ch]
  char v21; // [esp+43h] [ebp-165h]
  void **file; // [esp+64h] [ebp-144h]
  char v23; // [esp+69h] [ebp-13Fh]
  char v24; // [esp+6Ah] [ebp-13Eh]
  char v25; // [esp+6Bh] [ebp-13Dh]
  char *other; // [esp+6Ch] [ebp-13Ch] BYREF
  vostok::fs_new::native_path_string physical_path; // [esp+70h] [ebp-138h] BYREF
  unsigned int hash; // [esp+184h] [ebp-24h] BYREF
  vostok::vfs::base_node<1> *branch_node; // [esp+188h] [ebp-20h] BYREF
  unsigned int max_helper_nodes; // [esp+18Ch] [ebp-1Ch]
  vostok::buffer_vector<vostok::vfs::mount_helper_node<1> *> helper_nodes; // [esp+190h] [ebp-18h] BYREF
  vostok::vfs::physical_file_node<1> *file_node; // [esp+198h] [ebp-10h]
  vostok::vfs::base_folder_node<1> *root_parent; // [esp+19Ch] [ebp-Ch]
  vostok::fs_new::file_type_pointer fat_file; // [esp+1A0h] [ebp-8h] BYREF

  thisa = this;
  other = (char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_args.fat_physical_path);
  vostok::fs_new::native_path_string::native_path_string(&physical_path, (const char **)&other);
  survarium::weapon_user_dead_state::finalize(v2);
  fat_file.device = device;
  v23 = vostok::fs_new::open_cached_file(
          device,
          &fat_file.file,
          (vostok::fs_new::open_file_cache *)&physical_path,
          open_existing,
          read,
          assert_on_fail_false,
          notify_watcher_true,
          use_buffering_true);
  if ( !fat_file.file )
  {
    thisa->m_result = result_undefined;
    vostok::fs_new::file_type_pointer::close(&fat_file);
    survarium::weapon_user_dead_state::finalize(v3);
    return;
  }
  if ( thisa->m_args.submount_node )
  {
    root_parent = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(thisa->m_args.parent_of_submount_node);
    v25 = 0;
    survarium::weapon_user_dead_state::finalize(v4);
    file = fat_file.file;
    vostok::vfs::archive_mounter::mount_archive_to_parent(thisa, fat_file.file, root_parent, device);
    if ( thisa->m_result != result_success )
    {
      file_node = vostok::vfs::node_cast<vostok::vfs::physical_file_node,vostok::vfs::base_node,1>(thisa->m_args.submount_node);
      v24 = 0;
      survarium::weapon_user_dead_state::finalize(v5);
      vostok::vfs::physical_file_node<1>::set_is_mounted(file_node, 1);
    }
LABEL_19:
    vostok::fs_new::file_type_pointer::close(&fat_file);
    survarium::weapon_user_dead_state::finalize(v10);
    return;
  }
  v21 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)thisa);
  v20 = vostok::strings::count_of(thisa->m_args.virtual_path.m_string.m_begin, 47);
  max_helper_nodes = v20 + (vostok::fs_new::path_string_impl::length(&thisa->m_args.virtual_path) != 0) + 1;
  v6 = alloca(4 * max_helper_nodes);
  v13 = &v11;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)max_helper_nodes);
  v18 = v7;
  helper_nodes.m_begin = v7;
  helper_nodes.m_end = v7;
  v19 = 0;
  survarium::weapon_user_dead_state::finalize(v8);
  if ( vostok::vfs::mounter::allocate_mount_branch(thisa, &helper_nodes) )
  {
    branch_node = 0;
    hash = 0;
    vostok::vfs::mounter::add_mount_branch(thisa, &helper_nodes, &branch_node, &thisa->m_args.root_write_lock, &hash);
    if ( branch_node )
      parent_of_mount_root = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(branch_node);
    else
      parent_of_mount_root = 0;
    v16 = fat_file.file;
    vostok::vfs::archive_mounter::mount_archive_to_parent(thisa, fat_file.file, parent_of_mount_root, device);
    for ( i = helper_nodes.m_begin; i != helper_nodes.m_end; ++i )
      ;
    helper_nodes.m_end = helper_nodes.m_begin;
    goto LABEL_19;
  }
  vostok::vfs::mounter::finish_with_out_of_memory(thisa);
  for ( j = helper_nodes.m_begin; j != helper_nodes.m_end; ++j )
    ;
  helper_nodes.m_end = helper_nodes.m_begin;
  vostok::fs_new::file_type_pointer::close(&fat_file);
  survarium::weapon_user_dead_state::finalize(v9);
}
