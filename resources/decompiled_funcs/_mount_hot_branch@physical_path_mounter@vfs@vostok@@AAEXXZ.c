void __usercall vostok::vfs::physical_path_mounter::mount_hot_branch(
        vostok::vfs::physical_path_mounter *this@<ecx>,
        unsigned int a2@<ebx>)
{
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  const char *v7; // eax
  int v8; // [esp-Ch] [ebp-748h]
  signed int v9; // [esp-8h] [ebp-744h]
  char m_separator; // [esp-8h] [ebp-744h]
  signed int v11; // [esp-8h] [ebp-744h]
  unsigned int v12; // [esp-4h] [ebp-740h]
  _DWORD v14[75]; // [esp+1Ch] [ebp-720h] BYREF
  vostok::platform_pointer_selector<char,1>::helper *src; // [esp+14Ch] [ebp-5F0h]
  int v17; // [esp+150h] [ebp-5ECh]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+154h] [ebp-5E8h] BYREF
  char v19; // [esp+17Bh] [ebp-5C1h]
  vostok::vfs::physical_folder_node<1> *folder; // [esp+17Ch] [ebp-5C0h]
  vostok::vfs::base_node<1> *node; // [esp+180h] [ebp-5BCh]
  vostok::fs_new::virtual_path_string path_part; // [esp+184h] [ebp-5B8h] BYREF
  vostok::fs_new::path_part_iterator it_end; // [esp+29Ch] [ebp-4A0h] BYREF
  vostok::fs_new::path_part_iterator it; // [esp+2B4h] [ebp-488h] BYREF
  vostok::fs_new::virtual_path_string base_path; // [esp+2CCh] [ebp-470h] BYREF
  unsigned int virtual_path_hash; // [esp+3E8h] [ebp-354h]
  vostok::fs_new::native_path_string it_physical_path; // [esp+3ECh] [ebp-350h] BYREF
  vostok::vfs::base_node<1> *parent; // [esp+508h] [ebp-234h]
  vostok::fs_new::virtual_path_string it_virtual_path; // [esp+50Ch] [ebp-230h] BYREF
  vostok::fs_new::virtual_path_string relative_path; // [esp+624h] [ebp-118h] BYREF

  v17 = 0;
  v19 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::fs_new::virtual_path_string::virtual_path_string(&base_path);
  vostok::vfs::base_node<1>::get_full_path(this->m_args.submount_node, (vostok::fs_new::native_path_string *)&base_path);
  vostok::fs_new::virtual_path_string::virtual_path_string(&relative_path);
  vostok::fs_new::convert_to_relative_path<vostok::fs_new::virtual_path_string,vostok::fs_new::virtual_path_string>(
    &relative_path,
    (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_args,
    (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&base_path);
  v9 = vostok::fs_new::path_string_impl::length(&base_path);
  v2 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&base_path);
  virtual_path_hash = vostok::fs_new::path_crc32(v2, v9, 0);
  vostok::fs_new::virtual_path_string::virtual_path_string(&it_virtual_path, &base_path);
  src = (vostok::platform_pointer_selector<char,1>::helper *)&this->m_mount_root_base->physical_path;
  vostok::fs_new::path_string_impl::path_string_impl(&it_physical_path, 92, src);
  parent = 0;
  m_separator = relative_path.m_separator;
  v8 = vostok::fs_new::path_string_impl::length(&relative_path);
  v3 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&relative_path);
  vostok::fs_new::path_part_iterator::path_part_iterator(
    &it,
    v3,
    v8,
    m_separator,
    include_empty_string_in_iteration_true);
  vostok::fs_new::path_part_iterator::path_part_iterator(&it_end, 0, 0, include_empty_string_in_iteration_false);
  while ( 1 )
  {
    if ( it.m_include_empty_string_in_iteration == it_end.m_include_empty_string_in_iteration
      && it.m_cur_str == it_end.m_cur_str )
    {
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
        &this->m_mount_ptr,
        this->m_mount_root_base->mount.pointer,
        (vostok::vfs::vfs_mount *)this);
      return;
    }
    vostok::fs_new::virtual_path_string::virtual_path_string(&path_part);
    vostok::fs_new::path_string_impl::clear(&path_part.m_string);
    vostok::fs_new::path_part_iterator::append_to_string<vostok::fs_new::virtual_path_string>(&it, &path_part);
    vostok::fs_new::path_string_impl::append_path<vostok::fixed_string<260>>(&it_virtual_path, &path_part.m_string);
    if ( vostok::fs_new::path_string_impl::length(&path_part) )
    {
      v4 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&path_part);
      vostok::fs_new::path_string_impl::appendf(&it_physical_path, "%c%s", 92, v4);
    }
    v12 = virtual_path_hash;
    v11 = vostok::fs_new::path_string_impl::length(&path_part);
    v5 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&path_part);
    virtual_path_hash = vostok::fs_new::path_crc32(v5, v11, v12);
    node = vostok::vfs::find_node_of_mount(
             &this->m_file_system->hashset,
             (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&it_virtual_path,
             virtual_path_hash,
             this->m_mount_id);
    if ( !node )
      node = vostok::vfs::physical_path_mounter::add_physical_node(
               this,
               (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&path_part,
               (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&it_virtual_path,
               virtual_path_hash,
               &it_physical_path,
               parent);
    if ( this->m_result == result_success )
      return;
    if ( !node )
      break;
    if ( (node->m_flags & 2) == 2 && (node->m_flags & 1) == 1 )
    {
      folder = vostok::vfs::node_cast<vostok::vfs::physical_folder_node,vostok::vfs::base_node,1>(node);
      v14[4] = v14;
      v14[0] = 1;
      v14[1] = 1;
      v14[2] = &folder->m_folder_flags;
      v14[3] = 1;
      if ( (folder->m_folder_flags.m_flags & 1) != 1 )
        vostok::vfs::physical_path_mounter::mount_physical_folder(
          this,
          a2,
          &it_virtual_path,
          (vostok::vfs::base_folder_node<1> *)folder,
          &it_physical_path,
          virtual_path_hash);
      if ( this->m_result == result_success )
        return;
    }
    parent = node;
    vostok::fs_new::path_part_iterator::operator++(&it);
  }
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "watcher:", info) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v6);
    v17 |= 1u;
    v7 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&it_physical_path);
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\mount_hot.cpp",
      0x84u,
      "void __thiscall vostok::vfs::physical_path_mounter::mount_hot_branch(void)",
      "watcher:",
      info,
      "hot mount of '%s' failed: nothing on such path",
      v7);
  }
  if ( (v17 & 1) != 0 )
  {
    v17 &= ~1u;
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v6,
      (int *)&log_callback);
  }
}
