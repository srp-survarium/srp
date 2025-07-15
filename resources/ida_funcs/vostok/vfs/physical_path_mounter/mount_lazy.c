void __usercall vostok::vfs::physical_path_mounter::mount_lazy(
        vostok::vfs::physical_path_mounter *this@<ecx>,
        unsigned int a2@<ebx>)
{
  survarium::game_camera *v2; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v3; // ecx
  const char *v4; // eax
  bool is_scanned; // al
  const char *v6; // eax
  const char *v7; // [esp-8h] [ebp-2B4h]
  signed int v8; // [esp-8h] [ebp-2B4h]
  vostok::vfs::mount_root_node_base<1> *pointer; // [esp+4h] [ebp-2A8h]
  const char *v10; // [esp+8h] [ebp-2A4h]
  vostok::vfs::base_node<1> *node; // [esp+40h] [ebp-26Ch]
  char v13; // [esp+48h] [ebp-264h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+4Ch] [ebp-260h] BYREF
  char v15; // [esp+6Eh] [ebp-23Eh]
  char v16; // [esp+6Fh] [ebp-23Dh]
  unsigned int hash; // [esp+70h] [ebp-23Ch]
  vostok::fs_new::virtual_path_string virtual_path; // [esp+74h] [ebp-238h] BYREF
  vostok::fs_new::native_path_string physical_path; // [esp+18Ch] [ebp-120h] BYREF
  bool is_already_scanned; // [esp+2A7h] [ebp-5h]
  vostok::vfs::physical_folder_node<1> *folder; // [esp+2A8h] [ebp-4h]

  v13 = 0;
  v16 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v15 = 0;
  survarium::weapon_user_dead_state::finalize(v2);
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "vfs:", info) )
  {
    if ( this->m_args.recursive )
      v10 = "(recursive)";
    else
      v10 = (const char *)&buf;
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this);
    v13 = 1;
    v7 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_args);
    v4 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_args.physical_path);
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\mount_lazy.cpp",
      0x17u,
      "void __thiscall vostok::vfs::physical_path_mounter::mount_lazy(void)",
      "vfs:",
      info,
      "lazy mount of '%s' on '%s' %s",
      v4,
      v7,
      v10);
  }
  if ( (v13 & 1) != 0 )
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v3,
      (int *)&log_callback);
  folder = vostok::vfs::node_cast<vostok::vfs::physical_folder_node,vostok::vfs::base_node,1>(this->m_args.submount_node);
  node = this->m_args.submount_node;
  if ( (node->m_flags & 8) == 8 )
    pointer = vostok::vfs::node_cast<vostok::vfs::mount_root_node_base,vostok::vfs::base_node,1>(node);
  else
    pointer = node->m_mount_root.pointer;
  this->m_mount_root_base = pointer;
  is_scanned = vostok::vfs::physical_folder_node<1>::set_is_scanned(folder, this->m_args.recursive == recursive_true);
  is_already_scanned = !is_scanned;
  if ( is_scanned )
  {
    vostok::fs_new::virtual_path_string::virtual_path_string(&virtual_path, &this->m_args.virtual_path);
    vostok::vfs::get_node_physical_path<vostok::vfs::base_node,1>(&physical_path, this->m_args.submount_node);
    v8 = vostok::fs_new::path_string_impl::length(&this->m_args.virtual_path);
    v6 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_args);
    hash = vostok::fs_new::path_crc32(v6, v8, 0);
    vostok::vfs::physical_path_mounter::mount_physical_folder(
      this,
      a2,
      &this->m_args.virtual_path,
      (vostok::vfs::base_folder_node<1> *)folder,
      &physical_path,
      hash);
  }
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
    &this->m_mount_ptr,
    this->m_mount_root_base->mount.pointer,
    (vostok::vfs::vfs_mount *)this);
}
