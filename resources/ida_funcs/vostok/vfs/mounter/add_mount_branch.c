void __thiscall vostok::vfs::mounter::add_mount_branch(
        vostok::vfs::mounter *this,
        vostok::buffer_vector<vostok::vfs::mount_helper_node<1> *> *helper_nodes,
        vostok::vfs::base_node<1> **out_branch,
        vostok::vfs::base_node<1> **in_out_lock,
        unsigned int *out_node_hash)
{
  const char *v5; // eax
  const char *v6; // eax
  BOOL v7; // ecx
  unsigned int v8; // [esp-8h] [ebp-4C0h]
  unsigned int v9; // [esp-8h] [ebp-4C0h]
  unsigned int v10; // [esp-4h] [ebp-4BCh]
  bool v12; // [esp+6h] [ebp-4B2h]
  vostok::fs_new::path_string_impl v14; // [esp+138h] [ebp-380h] BYREF
  char v15; // [esp+24Fh] [ebp-269h]
  vostok::fs_new::virtual_path_string path_part; // [esp+250h] [ebp-268h] BYREF
  vostok::fs_new::path_part_iterator it_end; // [esp+368h] [ebp-150h] BYREF
  vostok::fs_new::path_part_iterator it; // [esp+380h] [ebp-138h] BYREF
  unsigned int partial_path_hash; // [esp+398h] [ebp-120h]
  int index; // [esp+39Ch] [ebp-11Ch]
  vostok::fs_new::virtual_path_string partial_path; // [esp+3A0h] [ebp-118h] BYREF

  v15 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::fs_new::virtual_path_string::virtual_path_string(&partial_path);
  vostok::fs_new::path_string_impl::path_string_impl(&v14, 47, (const char (*)[1])&buf);
  v8 = vostok::fs_new::path_string_impl::length(&v14);
  v5 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v14);
  partial_path_hash = vostok::fs_new::path_crc32(v5, v8, 0);
  index = 0;
  vostok::fs_new::path_string_impl::begin_part(&this->m_args.virtual_path, &it, include_empty_string_in_iteration_true);
  vostok::fs_new::path_part_iterator::end(&it_end);
  while ( it.m_include_empty_string_in_iteration != it_end.m_include_empty_string_in_iteration
       || it.m_cur_str != it_end.m_cur_str )
  {
    vostok::fs_new::virtual_path_string::virtual_path_string(&path_part);
    vostok::fs_new::path_string_impl::clear(&path_part.m_string);
    vostok::fs_new::path_part_iterator::append_to_string<vostok::fs_new::virtual_path_string>(&it, &path_part);
    vostok::fs_new::path_string_impl::append_path<vostok::fixed_string<260>>(&partial_path, &path_part.m_string);
    v10 = partial_path_hash;
    v9 = vostok::fs_new::path_string_impl::length(&path_part);
    v6 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&path_part);
    partial_path_hash = vostok::fs_new::path_crc32(v6, v9, v10);
    vostok::fs_new::path_part_iterator::operator++(&it);
    if ( it.m_include_empty_string_in_iteration == it_end.m_include_empty_string_in_iteration )
    {
      v7 = it.m_cur_str == it_end.m_cur_str;
      v12 = it.m_cur_str == it_end.m_cur_str;
    }
    else
    {
      v12 = 0;
    }
    if ( !v12 )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v7);
      vostok::vfs::mounter::add_mount_helper_node(
        this,
        helper_nodes->m_begin[index],
        &partial_path,
        partial_path_hash,
        out_branch,
        in_out_lock);
    }
    ++index;
  }
  if ( out_node_hash )
    *out_node_hash = partial_path_hash;
}
