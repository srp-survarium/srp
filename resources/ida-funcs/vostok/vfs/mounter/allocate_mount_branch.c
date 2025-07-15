char __thiscall vostok::vfs::mounter::allocate_mount_branch(
        vostok::vfs::mounter *this,
        vostok::buffer_vector<vostok::vfs::mount_helper_node<1> *> *out_helper_nodes)
{
  survarium::game_camera *v2; // ecx
  vostok::memory::base_allocator *v3; // eax
  vostok::fs_new::virtual_path_string path_part; // [esp+24h] [ebp-158h] BYREF
  unsigned int helper_node_size; // [esp+140h] [ebp-3Ch]
  vostok::vfs::mount_helper_node<1> *new_node; // [esp+144h] [ebp-38h] BYREF
  vostok::fs_new::path_part_iterator it_end; // [esp+148h] [ebp-34h] BYREF
  vostok::fs_new::path_part_iterator it; // [esp+160h] [ebp-1Ch] BYREF
  bool out_of_memory; // [esp+17Bh] [ebp-1h]

  out_of_memory = 0;
  vostok::fs_new::path_string_impl::begin_part(&this->m_args.virtual_path, &it, include_empty_string_in_iteration_true);
  vostok::fs_new::path_part_iterator::end(&it_end);
  while ( it.m_include_empty_string_in_iteration != it_end.m_include_empty_string_in_iteration
       || it.m_cur_str != it_end.m_cur_str )
  {
    vostok::fs_new::virtual_path_string::virtual_path_string(&path_part);
    vostok::fs_new::path_string_impl::clear(&path_part.m_string);
    vostok::fs_new::path_part_iterator::append_to_string<vostok::fs_new::virtual_path_string>(&it, &path_part);
    vostok::fs_new::path_part_iterator::operator++(&it);
    if ( it.m_include_empty_string_in_iteration == it_end.m_include_empty_string_in_iteration
      && it.m_cur_str == it_end.m_cur_str )
    {
      break;
    }
    helper_node_size = vostok::fs_new::path_string_impl::length(&path_part) + 81;
    survarium::weapon_user_dead_state::finalize(v2);
    new_node = (vostok::vfs::mount_helper_node<1> *)vostok::memory::malloc_helper<vostok::memory::base_allocator>(
                                                      v3,
                                                      helper_node_size);
    if ( !new_node )
    {
      out_of_memory = 1;
      break;
    }
    vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
      (vostok::buffer_vector<void const *> *)out_helper_nodes,
      (const void **)&new_node);
  }
  if ( !out_of_memory )
    return 1;
  vostok::vfs::mounter::free_mount_branch(this, (survarium::game_camera *)out_helper_nodes);
  return 0;
}
