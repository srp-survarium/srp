void __thiscall vostok::vfs::unmounter::unmount(vostok::vfs::unmounter *this)
{
  const char *v1; // eax
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *physical_path; // eax
  const char *v6; // eax
  unsigned int v7; // [esp-8h] [ebp-2F8h]
  const char *v8; // [esp-4h] [ebp-2F4h]
  vostok::vfs::query_mount_arguments *m_args; // [esp+188h] [ebp-168h]
  char v11; // [esp+18Ch] [ebp-164h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+190h] [ebp-160h] BYREF
  vostok::fs_new::native_path_string result; // [esp+1B4h] [ebp-13Ch] BYREF
  char v14; // [esp+2CAh] [ebp-26h]
  char v15; // [esp+2CBh] [ebp-25h]
  vostok::vfs::physical_file_node<1> *file_node; // [esp+2CCh] [ebp-24h]
  vostok::vfs::base_node<1> *attach_node; // [esp+2D0h] [ebp-20h]
  vostok::vfs::mount_helper_node<1> *mount_root_helper_parent; // [esp+2D4h] [ebp-1Ch]
  unsigned int hash; // [esp+2D8h] [ebp-18h]
  vostok::vfs::base_node<1> *mount_root_node; // [esp+2DCh] [ebp-14h]
  vostok::vfs::is_part_of_mount predicate; // [esp+2E0h] [ebp-10h] BYREF
  const char *mount_log_type; // [esp+2E4h] [ebp-Ch]
  vostok::vfs::base_node<1> *overlap_of_node_to_unmount; // [esp+2E8h] [ebp-8h] BYREF
  vostok::vfs::base_node<1> *node_to_unmount; // [esp+2ECh] [ebp-4h] BYREF

  v11 = 0;
  m_args = this->m_args;
  v7 = vostok::fs_new::path_string_impl::length(&this->m_args->virtual_path);
  v1 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)m_args);
  hash = vostok::fs_new::path_crc32(v1, v7, 0);
  attach_node = vostok::vfs::get_attach_node(this->m_root_node_to_unmount);
  mount_log_type = vostok::vfs::get_mount_log_type(attach_node, this->m_root_node_to_unmount);
  node_to_unmount = 0;
  overlap_of_node_to_unmount = 0;
  predicate.mount_root = this->m_root_node_to_unmount;
  vostok::vfs::unmounter::recursive_unmount_node<vostok::vfs::is_part_of_mount>(
    this,
    &this->m_args->virtual_path,
    hash,
    &predicate,
    &node_to_unmount,
    &overlap_of_node_to_unmount);
  v15 = 0;
  survarium::weapon_user_dead_state::finalize(v2);
  mount_root_node = node_to_unmount;
  mount_root_helper_parent = (vostok::vfs::mount_helper_node<1> *)node_to_unmount->m_mount_root.pointer;
  if ( attach_node )
  {
    vostok::vfs::unmounter::unlink_from_attach_node(
      this,
      mount_root_node,
      hash,
      overlap_of_node_to_unmount,
      attach_node);
    if ( (attach_node->m_flags & 2) == 2 )
    {
      file_node = vostok::vfs::node_cast<vostok::vfs::physical_file_node,vostok::vfs::base_node,1>(attach_node);
      v14 = 0;
      survarium::weapon_user_dead_state::finalize(v3);
      vostok::vfs::physical_file_node<1>::set_is_mounted(file_node, 0);
    }
  }
  else
  {
    vostok::vfs::unmounter::unmount_helper_branch(
      this,
      mount_root_helper_parent,
      mount_root_node,
      overlap_of_node_to_unmount,
      hash);
  }
  vostok::threading::interlocked_increment(&vostok::vfs::s_global_unmounts_counter);
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "vfs:", info) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v4);
    v11 = 1;
    v8 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->m_args);
    physical_path = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::vfs::query_mount_arguments::get_physical_path(this->m_args, &result);
    v6 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(physical_path);
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\unmount.cpp",
      0x85u,
      "void __thiscall vostok::vfs::unmounter::unmount(void)",
      "vfs:",
      info,
      "unmounted %s '%s' on '%s'",
      mount_log_type,
      v6,
      v8);
  }
  if ( (v11 & 1) != 0 )
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v11 & 1),
      (int *)&log_callback);
}
