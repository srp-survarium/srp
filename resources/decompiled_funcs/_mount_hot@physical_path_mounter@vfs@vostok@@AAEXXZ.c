void __usercall vostok::vfs::physical_path_mounter::mount_hot(
        vostok::vfs::physical_path_mounter *this@<ecx>,
        unsigned int a2@<ebx>)
{
  survarium::game_camera *v2; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v3; // ecx
  const char *v4; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // ecx
  const char *v6; // eax
  const char *v7; // [esp-4h] [ebp-68h]
  char v9; // [esp+10h] [ebp-54h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v10; // [esp+14h] [ebp-50h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+34h] [ebp-30h] BYREF
  char v12; // [esp+5Ah] [ebp-Ah]
  char v13; // [esp+5Bh] [ebp-9h]
  vostok::vfs::base_node<1> *overlapper; // [esp+60h] [ebp-4h] BYREF

  v9 = 0;
  v13 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v12 = 0;
  survarium::weapon_user_dead_state::finalize(v2);
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "vfs:", info) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v3);
    v9 = 1;
    v7 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_args);
    v4 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_args.physical_path);
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\mount_hot.cpp",
      0x50u,
      "void __thiscall vostok::vfs::physical_path_mounter::mount_hot(void)",
      "vfs:",
      info,
      "hot mounting of '%s' on '%s'",
      v4,
      v7);
  }
  if ( (v9 & 1) != 0 )
  {
    v9 &= ~1u;
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v3,
      (int *)&log_callback);
  }
  this->m_mount_root_base = vostok::vfs::node_cast<vostok::vfs::mount_root_node_base,vostok::vfs::base_node,1>(this->m_args.submount_node);
  this->m_mount_id = this->m_mount_root_base->mount_id;
  overlapper = 0;
  if ( vostok::vfs::physical_path_mounter::find_node_on_virtual_path(this, &overlapper) )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "vfs:", info) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v5);
      v9 |= 2u;
      v6 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_args);
      vostok::logging::append(
        &v10,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\mount_hot.cpp",
        0x5Bu,
        "void __thiscall vostok::vfs::physical_path_mounter::mount_hot(void)",
        "vfs:",
        info,
        "boo, node '%s' already exists...",
        v6);
    }
    if ( (v9 & 2) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v5,
        (int *)&v10);
  }
  else
  {
    vostok::vfs::physical_path_mounter::mount_hot_branch(this, a2);
  }
}
