void __thiscall vostok::vfs::archive_mounter::mount_archive_to_parent(
        vostok::vfs::archive_mounter *this,
        void **fat_file,
        vostok::vfs::base_folder_node<1> *parent_of_mount_root,
        vostok::fs_new::synchronous_device_interface *device)
{
  btNullPairCache *v4; // ecx
  unsigned int v5; // esi
  vostok::memory::base_allocator *v6; // eax
  vostok::vfs::vfs_mount *v7; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v8; // ecx
  const char *v9; // eax
  vostok::vfs::virtual_file_system *m_file_system; // [esp-4h] [ebp-64h]
  const char *v11; // [esp-4h] [ebp-64h]
  const char *v12; // [esp+4h] [ebp-5Ch]
  bool v14; // [esp+17h] [ebp-49h]
  char v15; // [esp+1Ch] [ebp-44h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+20h] [ebp-40h] BYREF
  vostok::vfs::fat_header header; // [esp+40h] [ebp-20h] BYREF
  vostok::vfs::archive_folder_mount_root_node<1> *mount_root; // [esp+58h] [ebp-8h]
  const char *mount_type; // [esp+5Ch] [ebp-4h]

  v15 = 0;
  header.num_nodes = 0;
  header.buffer_size = 0;
  vostok::memory::zero<char,14>((char (*)[14])&header);
  vostok::fs_new::device_file_system_proxy_base::read(&device->m_device, fat_file, &header, 0x18u);
  v14 = survarium::player_logic_base_state::is_ready_for_transition(v4) == 0;
  this->m_reverse_byte_order = vostok::vfs::fat_header::is_big_endian(&header) != v14;
  if ( this->m_reverse_byte_order )
    vostok::vfs::fat_header::reverse_bytes(&header);
  v5 = header.buffer_size + 1;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_nodes_buffer = (char *)vostok::memory::malloc_helper<vostok::memory::base_allocator>(v6, v5);
  if ( this->m_nodes_buffer )
  {
    vostok::fs_new::device_file_system_proxy_base::read(
      &device->m_device,
      fat_file,
      this->m_nodes_buffer,
      header.buffer_size);
    mount_root = (vostok::vfs::archive_folder_mount_root_node<1> *)this->m_nodes_buffer;
    mount_root->mount_size = header.buffer_size;
    vostok::vfs::archive_mounter::mount_fat(this, mount_root, parent_of_mount_root);
    m_file_system = this->m_file_system;
    v7 = (vostok::vfs::vfs_mount *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_mount_ptr);
    vostok::vfs::add_to_mount_history(v7, m_file_system);
    if ( this->m_args.submount_node )
      v12 = "auto-archive";
    else
      v12 = "archive";
    v8 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v12;
    mount_type = v12;
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "vfs:", info) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v8);
      v15 = 1;
      v11 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_args);
      v9 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_args.archive_physical_path);
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\mount_archive.cpp",
        0x9Fu,
        "void __thiscall vostok::vfs::archive_mounter::mount_archive_to_parent(void **,class vostok::vfs::base_folder_nod"
        "e<1> *,class vostok::fs_new::synchronous_device_interface &)",
        "vfs:",
        info,
        "mounted %s '%s' on '%s'",
        mount_type,
        v9,
        v11);
    }
    if ( (v15 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v15 & 1),
        (int *)&log_callback);
  }
  else
  {
    this->m_result = result_success;
  }
}
