bool __thiscall vostok::vfs::mounter::try_mount_from_history(vostok::vfs::mounter *this)
{
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *physical_path; // eax
  const vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v3; // esi
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v4; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // ecx
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v6; // eax
  const char *v7; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v8; // ecx
  const char *v9; // [esp-4h] [ebp-4BCh]
  vostok::vfs::result_enum m_result; // [esp+14h] [ebp-4A4h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v12; // [esp+18h] [ebp-4A0h] BYREF
  int v13; // [esp+28h] [ebp-490h]
  vostok::vfs::mount_result v14; // [esp+30h] [ebp-488h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+38h] [ebp-480h] BYREF
  vostok::fs_new::native_path_string v16; // [esp+5Ch] [ebp-45Ch] BYREF
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v17; // [esp+170h] [ebp-348h] BYREF
  char *src; // [esp+174h] [ebp-344h] BYREF
  vostok::fs_new::path_string_impl v19; // [esp+178h] [ebp-340h] BYREF
  vostok::fs_new::native_path_string result; // [esp+28Ch] [ebp-22Ch] BYREF
  char *other; // [esp+3A0h] [ebp-118h] BYREF
  vostok::fs_new::native_path_string fat_physical_path; // [esp+3A4h] [ebp-114h] BYREF

  v13 = 0;
  if ( this->m_args.submount_node )
    return 0;
  physical_path = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::vfs::query_mount_arguments::get_physical_path(&this->m_args, &result);
  other = (char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(physical_path);
  vostok::fs_new::native_path_string::native_path_string(&fat_physical_path, (const char **)&other);
  src = (char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_args);
  vostok::fs_new::path_string_impl::path_string_impl(&v19, 47, (const char **)&src);
  v3 = vostok::vfs::find_in_mount_history(
         &v17,
         (const vostok::fs_new::virtual_path_string *)&v19,
         &fat_physical_path,
         &this->m_file_system->mount_history);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
    &this->m_mount_ptr,
    v3);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v17);
  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator survarium::inventory_item * (__thiscall vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::*)(void)const(
         v4,
         &this->m_mount_ptr.m_object) )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "vfs:", info) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v5);
      v13 |= 1u;
      v9 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_args);
      v6 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::vfs::query_mount_arguments::get_physical_path(&this->m_args, &v16);
      v7 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v6);
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\mounter.cpp",
        0x27u,
        "bool __thiscall vostok::vfs::mounter::try_mount_from_history(void)",
        "vfs:",
        info,
        "mounted from history: '%s' on '%s'",
        v7,
        v9);
    }
    v8 = (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v13 & 1);
    if ( (v13 & 1) != 0 )
    {
      v13 &= ~1u;
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        v8,
        (int *)&log_callback);
    }
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &v12,
      &this->m_mount_ptr);
    m_result = this->m_result;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &v14.mount,
      &v12);
    v14.result = m_result;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v12);
    vostok::vfs::mounter::finish(this, &v14, 1);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v14.mount);
  }
  return vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator!=(
           &this->m_mount_ptr,
           0);
}
