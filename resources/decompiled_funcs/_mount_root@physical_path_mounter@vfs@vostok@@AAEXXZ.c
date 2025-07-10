void __usercall vostok::vfs::physical_path_mounter::mount_root(
        vostok::vfs::physical_path_mounter *this@<ecx>,
        unsigned int a2@<ebx>)
{
  BOOL v2; // ecx
  const char *v3; // eax
  void *v4; // esp
  survarium::game_camera *v5; // ecx
  vostok::vfs::mount_helper_node<1> **v6; // eax
  survarium::game_camera *v7; // ecx
  survarium::game_camera *v8; // ecx
  survarium::game_camera *v9; // ecx
  vostok::vfs::base_folder_node<1> *v10; // eax
  BOOL v11; // ecx
  const char *v12; // eax
  const char *v13; // eax
  vostok::vfs::vfs_mount *v14; // eax
  unsigned int v15; // [esp-4h] [ebp-450h]
  const char *v16; // [esp-4h] [ebp-450h]
  const char *v17; // [esp-4h] [ebp-450h]
  vostok::vfs::virtual_file_system *m_file_system; // [esp-4h] [ebp-450h]
  _DWORD v19[2]; // [esp+0h] [ebp-44Ch] BYREF
  unsigned int mount_id; // [esp+8h] [ebp-444h]
  vostok::vfs::physical_path_mounter *thisa; // [esp+Ch] [ebp-440h]
  vostok::vfs::mount_helper_node<1> **i; // [esp+10h] [ebp-43Ch]
  vostok::render::skeleton_model_instance *v23; // [esp+14h] [ebp-438h]
  vostok::platform_pointer_selector<vostok::vfs::vfs_mount,1>::helper *p_mount; // [esp+18h] [ebp-434h]
  vostok::vfs::mount_root_node_base<1> *m_mount_root_base; // [esp+1Ch] [ebp-430h]
  const vostok::variant<32> **v26; // [esp+20h] [ebp-42Ch]
  unsigned __int64 file_size; // [esp+2Ch] [ebp-420h]
  char v28; // [esp+37h] [ebp-415h]
  vostok::vfs::mount_helper_node<1> **j; // [esp+38h] [ebp-414h]
  bool v30; // [esp+3Fh] [ebp-40Dh]
  vostok::vfs::mount_helper_node<1> **k; // [esp+40h] [ebp-40Ch]
  vostok::vfs::mount_helper_node<1> **v32; // [esp+44h] [ebp-408h]
  char v33; // [esp+4Ah] [ebp-402h]
  char v34; // [esp+4Bh] [ebp-401h]
  vostok::fs_new::device_file_system_proxy_base *p_m_device; // [esp+4Ch] [ebp-400h]
  int v36; // [esp+50h] [ebp-3FCh]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v37; // [esp+54h] [ebp-3F8h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v38; // [esp+74h] [ebp-3D8h] BYREF
  char v39; // [esp+9Bh] [ebp-3B1h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+9Ch] [ebp-3B0h] BYREF
  vostok::fs_new::native_path_string absolute_path; // [esp+BCh] [ebp-390h] BYREF
  vostok::vfs::physical_folder_mount_root_node<1> *node; // [esp+1D8h] [ebp-274h]
  vostok::fs_new::virtual_path_string folder_path; // [esp+1DCh] [ebp-270h] BYREF
  vostok::vfs::physical_file_mount_root_node<1> *mount_root; // [esp+2F8h] [ebp-154h]
  unsigned int hash; // [esp+2FCh] [ebp-150h] BYREF
  vostok::vfs::base_node<1> *branch_node; // [esp+300h] [ebp-14Ch] BYREF
  unsigned int max_helper_nodes; // [esp+304h] [ebp-148h]
  vostok::vfs::mount_root_node_base<1> *root_node; // [esp+308h] [ebp-144h]
  vostok::fs_new::physical_path_info path_info; // [esp+30Ch] [ebp-140h] BYREF
  vostok::buffer_vector<vostok::vfs::mount_helper_node<1> *> helper_nodes; // [esp+444h] [ebp-8h] BYREF

  thisa = this;
  v36 = 0;
  if ( this->m_args.mount_id )
    mount_id = thisa->m_args.mount_id;
  else
    mount_id = vostok::vfs::next_mount_id();
  thisa->m_mount_id = mount_id;
  p_m_device = &thisa->m_device->m_device;
  vostok::fs_new::device_file_system_proxy_base::get_physical_path_info(
    p_m_device,
    &path_info,
    &thisa->m_args.physical_path);
  v2 = path_info.data.type != type_error_no_path;
  if ( path_info.data.type )
  {
    v34 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v2);
    max_helper_nodes = vostok::strings::count_of(thisa->m_args.virtual_path.m_string.m_begin, 47) + 1;
    v4 = alloca(4 * max_helper_nodes);
    v19[1] = v19;
    survarium::weapon_user_dead_state::finalize(v5);
    v32 = v6;
    helper_nodes.m_begin = v6;
    helper_nodes.m_end = v6;
    v33 = 0;
    survarium::weapon_user_dead_state::finalize(v7);
    if ( vostok::vfs::mounter::allocate_mount_branch(thisa, &helper_nodes) )
    {
      v30 = path_info.data.type == type_folder;
      root_node = vostok::vfs::mounter::create_mount_root(
                    thisa,
                    path_info.data.type == type_folder,
                    (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&thisa->m_args);
      if ( root_node )
      {
        branch_node = 0;
        hash = 0;
        vostok::vfs::mounter::add_mount_branch(
          thisa,
          &helper_nodes,
          &branch_node,
          &thisa->m_args.root_write_lock,
          &hash);
        vostok::vfs::mounter::add_mount_root(
          thisa,
          root_node,
          &thisa->m_args.virtual_path,
          &hash,
          &branch_node,
          &thisa->m_args.root_write_lock);
        thisa->m_mount_root_base = root_node;
        if ( path_info.data.type == type_file )
        {
          mount_root = vostok::vfs::node_cast<vostok::vfs::physical_file_mount_root_node,vostok::vfs::mount_root_node_base,1>(thisa->m_mount_root_base);
          v39 = 0;
          survarium::weapon_user_dead_state::finalize(v8);
          v28 = 0;
          survarium::weapon_user_dead_state::finalize(v9);
          file_size = path_info.data.file_size;
          mount_root->file.m_size = path_info.data.file_size;
          mount_root->watcher_enabled = watcher_enabled_false;
        }
        else if ( thisa->m_args.recursive == recursive_true )
        {
          node = vostok::vfs::node_cast<vostok::vfs::physical_folder_mount_root_node,vostok::vfs::mount_root_node_base,1>(thisa->m_mount_root_base);
          vostok::fs_new::native_path_string::native_path_string(&absolute_path, &thisa->m_args.physical_path);
          vostok::fs_new::virtual_path_string::virtual_path_string(&folder_path, &thisa->m_args.virtual_path);
          v15 = hash;
          v10 = (vostok::vfs::base_folder_node<1> *)vostok::vfs::node_cast<vostok::vfs::physical_folder_node,vostok::vfs::physical_folder_mount_root_node,1>(node);
          vostok::vfs::physical_path_mounter::mount_physical_folder(thisa, a2, &folder_path, v10, &absolute_path, v15);
        }
        v11 = path_info.data.type == type_file;
        if ( path_info.data.type == type_file )
        {
          if ( !vostok::core::g_log_filter_tree
            || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "vfs:", info) )
          {
            boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v11);
            v36 |= 2u;
            v16 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&thisa->m_args);
            v12 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&thisa->m_args.physical_path);
            vostok::logging::append(
              &v38,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              ".\\mount_physical_path.cpp",
              0x8Eu,
              "void __thiscall vostok::vfs::physical_path_mounter::mount_root(void)",
              "vfs:",
              info,
              "mounting file '%s' on '%s'",
              v12,
              v16);
          }
          if ( (v36 & 2) != 0 )
          {
            v36 &= ~2u;
            boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
              (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v11,
              (int *)&v38);
          }
        }
        else
        {
          if ( !vostok::core::g_log_filter_tree
            || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "vfs:", info) )
          {
            boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v11);
            v36 |= 4u;
            v17 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&thisa->m_args);
            v13 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&thisa->m_args.physical_path);
            vostok::logging::append(
              &v37,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              ".\\mount_physical_path.cpp",
              0x90u,
              "void __thiscall vostok::vfs::physical_path_mounter::mount_root(void)",
              "vfs:",
              info,
              "mounted folder '%s' on '%s'",
              v13,
              v17);
          }
          if ( (v36 & 4) != 0 )
          {
            v36 &= ~4u;
            boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
              (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v11,
              (int *)&v37);
          }
        }
        m_mount_root_base = thisa->m_mount_root_base;
        v26 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)m_mount_root_base,
                (int)&thisa->m_mount_ptr);
        v26[13] = (const vostok::variant<32> *)m_mount_root_base;
        v23 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&thisa->m_mount_ptr);
        p_mount = &thisa->m_mount_root_base->mount;
        p_mount->pointer = (vostok::vfs::vfs_mount *)v23;
        m_file_system = thisa->m_file_system;
        v14 = (vostok::vfs::vfs_mount *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&thisa->m_mount_ptr);
        vostok::vfs::add_to_mount_history(v14, m_file_system);
        for ( i = helper_nodes.m_begin; i != helper_nodes.m_end; ++i )
          ;
      }
      else
      {
        vostok::vfs::mounter::free_mount_branch(thisa, (survarium::game_camera *)&helper_nodes);
        vostok::vfs::mounter::finish_with_out_of_memory(thisa);
        for ( j = helper_nodes.m_begin; j != helper_nodes.m_end; ++j )
          ;
        helper_nodes.m_end = helper_nodes.m_begin;
      }
    }
    else
    {
      vostok::vfs::mounter::finish_with_out_of_memory(thisa);
      for ( k = helper_nodes.m_begin; k != helper_nodes.m_end; ++k )
        ;
      helper_nodes.m_end = helper_nodes.m_begin;
    }
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "vfs:", error) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v2);
      v36 |= 1u;
      v3 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&thisa->m_args.physical_path);
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\mount_physical_path.cpp",
        0x59u,
        "void __thiscall vostok::vfs::physical_path_mounter::mount_root(void)",
        "vfs:",
        error,
        "mount physical path doesnt exist : '%s'",
        v3);
    }
    if ( (v36 & 1) != 0 )
    {
      v36 &= ~1u;
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v2,
        (int *)&log_callback);
    }
    thisa->m_result = result_undefined;
  }
}
