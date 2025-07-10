int __cdecl vostok::vfs::try_find_sync(
        char *path_to_find,
        vostok::vfs::vfs_locked_iterator *out_iterator,
        vostok::vfs::find_enum find_flags,
        vostok::vfs::virtual_file_system *file_system,
        vostok::memory::base_allocator *allocator)
{
  survarium::game_camera *v5; // ecx
  const char *v6; // eax
  vostok::vfs::vfs_iterator::type_enum v8; // eax
  unsigned int mount_operation_id; // [esp-4h] [ebp-200h]
  unsigned int v10; // [esp+0h] [ebp-1FCh]
  vostok::vfs::vfs_hashset *hashset; // [esp+Ch] [ebp-1F0h]
  vostok::vfs::vfs_hashset *p_hashset; // [esp+10h] [ebp-1ECh]
  vostok::vfs::result_enum v14; // [esp+2Ch] [ebp-1D0h]
  char *end_src; // [esp+40h] [ebp-1BCh]
  vostok::vfs::result_enum link_result; // [esp+4Ch] [ebp-1B0h]
  vostok::vfs::result_enum result; // [esp+50h] [ebp-1ACh]
  vostok::vfs::base_node<1> *previous_node; // [esp+54h] [ebp-1A8h]
  vostok::fs_new::path_part_iterator it_end; // [esp+5Ch] [ebp-1A0h] BYREF
  vostok::vfs::find_environment env; // [esp+74h] [ebp-188h] BYREF
  vostok::vfs::result_enum pin_tree_result; // [esp+C8h] [ebp-134h]
  vostok::fs_new::virtual_path_string partial_path; // [esp+CCh] [ebp-130h] BYREF
  vostok::fs_new::path_part_iterator it; // [esp+1E4h] [ebp-18h] BYREF

  survarium::weapon_user_dead_state::finalize(v5);
  vostok::fs_new::virtual_path_string::virtual_path_string(&partial_path);
  vostok::vfs::find_environment::find_environment(&env);
  env.out_iterator = out_iterator;
  env.partial_path = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&partial_path);
  env.path_to_find = path_to_find;
  env.find_flags.m_flags = find_flags;
  env.file_system = file_system;
  env.allocator = allocator;
  it.m_include_empty_string_in_iteration = include_empty_string_in_iteration_true;
  it.m_separator = 47;
  it.m_path_str = path_to_find;
  if ( path_to_find )
    v10 = vostok::strings::length(path_to_find);
  else
    v10 = 0;
  it.m_path_end = &path_to_find[v10];
  it.m_cur_str = path_to_find;
  it.m_cur_end = path_to_find;
  vostok::fs_new::path_part_iterator::operator++(&it);
  vostok::fs_new::path_part_iterator::path_part_iterator(&it_end, 0, 0, include_empty_string_in_iteration_false);
  while ( it.m_include_empty_string_in_iteration != it_end.m_include_empty_string_in_iteration
       || it.m_cur_str != it_end.m_cur_str )
  {
    end_src = (char *)it.m_cur_end;
    vostok::fs_new::path_string_impl::clear(&partial_path.m_string);
    vostok::buffer_string::append(&partial_path.m_string, path_to_find, end_src);
    vostok::fs_new::path_string_impl::verify_self(&partial_path);
    previous_node = env.node;
    env.node_parent = env.node;
    p_hashset = &env.file_system->hashset;
    v6 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&partial_path);
    if ( !vostok::vfs::vfs_hashset::find_no_branch_lock(
            p_hashset,
            &env.node,
            v6,
            lock_type_read,
            lock_operation_try_lock) )
    {
      vostok::vfs::unlock_and_decref_branch(env.node, lock_type_read, env.mount_operation_id);
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&env.callback);
      return 4;
    }
    if ( !env.node )
    {
      vostok::vfs::vfs_locked_iterator::clear(out_iterator);
      vostok::vfs::unlock_and_decref_branch(previous_node, lock_type_read, env.mount_operation_id);
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&env.callback);
      return 1;
    }
    vostok::vfs::upgrade_node(env.node_parent, lock_type_read, lock_type_write|lock_type_read);
    result = vostok::vfs::overlapped_chain_is_expanded(env.node, &env);
    vostok::vfs::change_subfat_ref_for_overlapped(1, env.node, &env.mount_operation_id);
    if ( result != result_error )
    {
      vostok::vfs::unlock_and_decref_branch(env.node, lock_type_read, env.mount_operation_id);
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&env.callback);
      return result;
    }
    if ( (env.node->m_flags & 0x300) != 0 )
    {
      link_result = vostok::vfs::try_find_sync_link(&env);
      vostok::vfs::unlock_and_decref_branch(env.node, lock_type_read, env.mount_operation_id);
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&env.callback);
      return link_result;
    }
    vostok::fs_new::path_part_iterator::operator++(&it);
    ++env.path_part_index;
  }
  pin_tree_result = vostok::vfs::try_pin_tree(env.node, &env);
  if ( pin_tree_result == result_error )
  {
    hashset = &env.file_system->hashset;
    mount_operation_id = env.mount_operation_id;
    v8 = vostok::vfs::iterator_type(find_flags);
    vostok::vfs::vfs_locked_iterator::assign(out_iterator, env.node, hashset, v8, mount_operation_id);
  }
  else
  {
    vostok::vfs::unlock_and_decref_branch(env.node, lock_type_read, env.mount_operation_id);
  }
  v14 = pin_tree_result;
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&env.callback);
  return v14;
}
