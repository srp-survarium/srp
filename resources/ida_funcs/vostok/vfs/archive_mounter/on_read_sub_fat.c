void __thiscall vostok::vfs::archive_mounter::on_read_sub_fat(vostok::vfs::archive_mounter *this, bool read_result)
{
  _BYTE *v2; // eax
  vostok::vfs::vfs_mount *v3; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v4; // ecx
  int v5; // edx
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *physical_path; // eax
  const char *v7; // eax
  vostok::vfs::mount_result *v8; // eax
  vostok::vfs::virtual_file_system *m_file_system; // [esp-4h] [ebp-17Ch]
  const char *v10; // [esp-4h] [ebp-17Ch]
  const char *v11; // [esp+4h] [ebp-174h]
  char v13; // [esp+2Ch] [ebp-14Ch]
  vostok::vfs::mount_result v14; // [esp+30h] [ebp-148h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+38h] [ebp-140h] BYREF
  vostok::fs_new::native_path_string result; // [esp+58h] [ebp-120h] BYREF
  char v17; // [esp+16Fh] [ebp-9h]
  vostok::vfs::archive_folder_mount_root_node<1> *mount_root; // [esp+170h] [ebp-8h]
  vostok::vfs::base_folder_node<1> *root_parent; // [esp+174h] [ebp-4h]

  v13 = 0;
  v17 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v2 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)read_result);
  mount_root = (vostok::vfs::archive_folder_mount_root_node<1> *)(this->m_nodes_buffer + 24);
  root_parent = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(this->m_args.parent_of_submount_node);
  mount_root->mount_size = vostok::vfs::get_file_size<1>(this->m_args.submount_node);
  vostok::vfs::archive_mounter::mount_fat(this, mount_root, root_parent);
  m_file_system = this->m_file_system;
  v3 = (vostok::vfs::vfs_mount *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_mount_ptr);
  vostok::vfs::add_to_mount_history(v3, m_file_system);
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "vfs:", info) )
  {
    v5 = this->m_args.submount_node->m_flags & 0x1000;
    if ( v5 == 4096 )
      v11 = "external ";
    else
      v11 = (const char *)&buf;
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)(v5 == 4096));
    v13 = 1;
    v10 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_args);
    physical_path = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::vfs::query_mount_arguments::get_physical_path(&this->m_args, &result);
    v7 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(physical_path);
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\mount_subfat.cpp",
      0x60u,
      "void __thiscall vostok::vfs::archive_mounter::on_read_sub_fat(bool)",
      "vfs:",
      info,
      "mounted %ssub_fat '%s' on '%s'",
      v11,
      v7,
      v10);
  }
  if ( (v13 & 1) != 0 )
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v4,
      (int *)&log_callback);
  v8 = vostok::vfs::mounter::get_result(this, &v14);
  vostok::vfs::mounter::finish(this, v8, 0);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v14.mount);
  vostok::vfs::mounter::destroy_this_if_needed(this);
}
