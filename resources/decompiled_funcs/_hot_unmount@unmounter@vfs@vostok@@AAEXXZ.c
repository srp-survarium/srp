void __thiscall vostok::vfs::unmounter::hot_unmount(vostok::vfs::unmounter *this)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v1; // ecx
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *physical_path; // eax
  const char *v3; // eax
  const char *v4; // eax
  char *v5; // eax
  const char *v6; // eax
  signed int v7; // [esp-8h] [ebp-6A4h]
  signed int v8; // [esp-8h] [ebp-6A4h]
  const char *v9; // [esp-4h] [ebp-6A0h]
  vostok::vfs::query_mount_arguments *m_args; // [esp+304h] [ebp-398h]
  char v12; // [esp+41Ch] [ebp-280h]
  vostok::vfs::is_exact_node v13; // [esp+420h] [ebp-27Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+424h] [ebp-278h] BYREF
  vostok::fs_new::native_path_string result; // [esp+444h] [ebp-258h] BYREF
  char v16; // [esp+55Bh] [ebp-141h]
  vostok::vfs::vfs_iterator iterator; // [esp+55Ch] [ebp-140h] BYREF
  unsigned int hash; // [esp+56Ch] [ebp-130h]
  vostok::vfs::base_folder_node<1> *parent_to_traverse; // [esp+570h] [ebp-12Ch]
  vostok::fs_new::virtual_path_string parent_path; // [esp+574h] [ebp-128h] BYREF
  vostok::vfs::is_part_of_mount predicate; // [esp+68Ch] [ebp-10h] BYREF
  unsigned int parent_path_hash; // [esp+690h] [ebp-Ch]
  vostok::vfs::base_node<1> *overlap_of_node_to_unmount; // [esp+694h] [ebp-8h] BYREF
  vostok::vfs::base_node<1> *node_to_unmount; // [esp+698h] [ebp-4h] BYREF

  v12 = 0;
  v16 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "vfs:", info) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v1);
    v12 = 1;
    v9 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->m_args);
    physical_path = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::vfs::query_mount_arguments::get_physical_path(this->m_args, &result);
    v3 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(physical_path);
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\unmount_hot.cpp",
      0x2Eu,
      "void __thiscall vostok::vfs::unmounter::hot_unmount(void)",
      "vfs:",
      info,
      "hot unmount '%s' from '%s'",
      v3,
      v9);
  }
  if ( (v12 & 1) != 0 )
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v1,
      (int *)&log_callback);
  if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&loc_20186 + (unsigned int)this->m_file_system + 2))
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0 )
  {
    vostok::vfs::vfs_iterator::vfs_iterator(
      &iterator,
      this->m_args->submount_node,
      0,
      &this->m_file_system->hashset,
      type_non_recursive);
    boost::function1<void,vostok::ai::sensors::sensed_object const &>::operator()(
      (boost::function1<void,vostok::ai::sensors::sensed_object const &> *)((char *)&loc_20186
                                                                          + (unsigned int)this->m_file_system
                                                                          + 2),
      (const vostok::ai::sensors::sensed_object *)&iterator);
  }
  m_args = this->m_args;
  v7 = vostok::fs_new::path_string_impl::length(&this->m_args->virtual_path);
  v4 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)m_args);
  hash = vostok::fs_new::path_crc32(v4, v7, 0);
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
  vostok::fs_new::virtual_path_string::virtual_path_string(&parent_path);
  v5 = (char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->m_args);
  vostok::fs_new::get_path_without_last_item<vostok::fs_new::virtual_path_string>(&parent_path, v5);
  v8 = vostok::fs_new::path_string_impl::length(&parent_path);
  v6 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&parent_path);
  parent_path_hash = vostok::fs_new::path_crc32(v6, v8, 0);
  parent_to_traverse = node_to_unmount->m_parent.pointer;
  v13.helper_node = node_to_unmount;
  vostok::vfs::unmounter::recursive_traverse_folder<vostok::vfs::is_exact_node>(
    this,
    &parent_path,
    parent_path_hash,
    &v13,
    parent_to_traverse);
}
