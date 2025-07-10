void __cdecl vostok::vfs::try_find_async(
        char *path_to_find,
        boost::function<void __cdecl(vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum)> callback,
        vostok::vfs::find_enum find_flags,
        vostok::vfs::virtual_file_system *file_system,
        vostok::memory::base_allocator *allocator,
        unsigned int start_mount_operation_id,
        unsigned int start_path_part_index)
{
  boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *v7; // eax
  const char *v8; // eax
  survarium::game_camera *v9; // ecx
  const char *v10; // eax
  unsigned int v11; // [esp+0h] [ebp-57Ch]
  vostok::vfs::vfs_hashset *p_hashset; // [esp+360h] [ebp-21Ch]
  vostok::vfs::vfs_hashset *v13; // [esp+364h] [ebp-218h]
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v14; // [esp+370h] [ebp-20Ch] BYREF
  vostok::vfs::vfs_locked_iterator v15; // [esp+394h] [ebp-1E8h] BYREF
  vostok::vfs::vfs_locked_iterator v16; // [esp+3A8h] [ebp-1D4h] BYREF
  char v17; // [esp+3BFh] [ebp-1BDh]
  char *end_src; // [esp+3C0h] [ebp-1BCh]
  vostok::vfs::find_enum v19; // [esp+3C4h] [ebp-1B8h]
  vostok::vfs::vfs_locked_iterator out_iterator; // [esp+3C8h] [ebp-1B4h] BYREF
  vostok::vfs::base_node<1> *previous_node; // [esp+3DCh] [ebp-1A0h]
  vostok::fs_new::path_part_iterator it_end; // [esp+3E4h] [ebp-198h] BYREF
  vostok::vfs::find_environment env; // [esp+3FCh] [ebp-180h] BYREF
  vostok::fs_new::virtual_path_string partial_path; // [esp+44Ch] [ebp-130h] BYREF
  vostok::fs_new::path_part_iterator it; // [esp+564h] [ebp-18h] BYREF

  vostok::vfs::find_environment::find_environment(&env);
  vostok::fs_new::virtual_path_string::virtual_path_string(&partial_path);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
    &v14,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&callback);
  boost::function1<unsigned int,char const *>::swap(
    v7,
    (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&env.callback);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v14);
  env.partial_path = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&partial_path);
  env.path_to_find = path_to_find;
  v19 = find_flags;
  env.find_flags.m_flags = find_flags;
  env.file_system = file_system;
  env.allocator = allocator;
  env.mount_operation_id = start_mount_operation_id;
  it.m_include_empty_string_in_iteration = include_empty_string_in_iteration_true;
  it.m_separator = 47;
  it.m_path_str = path_to_find;
  if ( path_to_find )
    v11 = vostok::strings::length(path_to_find);
  else
    v11 = 0;
  it.m_path_end = &path_to_find[v11];
  it.m_cur_str = path_to_find;
  it.m_cur_end = path_to_find;
  vostok::fs_new::path_part_iterator::operator++(&it);
  vostok::fs_new::path_part_iterator::path_part_iterator(&it_end, 0, 0, include_empty_string_in_iteration_false);
  while ( !vostok::fs_new::path_part_iterator::operator==(&it, &it_end) )
  {
    end_src = (char *)it.m_cur_end;
    vostok::fs_new::path_string_impl::clear(&partial_path.m_string);
    vostok::buffer_string::append(&partial_path.m_string, path_to_find, end_src);
    vostok::fs_new::path_string_impl::verify_self(&partial_path);
    if ( start_path_part_index == -1 )
      goto LABEL_11;
    if ( env.path_part_index < start_path_part_index )
      goto LABEL_5;
    if ( env.path_part_index != start_path_part_index )
    {
LABEL_11:
      previous_node = env.node;
      env.node_parent = env.node;
      p_hashset = &env.file_system->hashset;
      v10 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&partial_path);
      if ( !vostok::vfs::vfs_hashset::find_no_branch_lock(
              p_hashset,
              &env.node,
              v10,
              lock_type_read,
              lock_operation_try_lock) )
      {
        vostok::vfs::vfs_iterator::vfs_iterator(&v16);
        v16.mount_operation_id = 0;
        boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
          (boost::function2<void,char const *,vostok::network_core::udp_match_packet const *> *)&callback,
          (const char *)&v16,
          (const vostok::network_core::udp_match_packet *)4);
        vostok::vfs::vfs_locked_iterator::~vfs_locked_iterator(&v16);
        vostok::vfs::unlock_and_decref_branch(env.node, lock_type_read, env.mount_operation_id);
        boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&env.callback);
        boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&callback);
        return;
      }
      if ( !env.node )
      {
        vostok::vfs::vfs_iterator::vfs_iterator(&v15);
        v15.mount_operation_id = 0;
        boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
          (boost::function2<void,char const *,vostok::network_core::udp_match_packet const *> *)&callback,
          (const char *)&v15,
          (const vostok::network_core::udp_match_packet *)1);
        vostok::vfs::vfs_locked_iterator::~vfs_locked_iterator(&v15);
        vostok::vfs::unlock_and_decref_branch(previous_node, lock_type_read, env.mount_operation_id);
        boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&env.callback);
        boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&callback);
        return;
      }
      vostok::vfs::upgrade_node(env.node_parent, lock_type_read, lock_type_write|lock_type_read);
      vostok::vfs::change_subfat_ref_for_overlapped(1, env.node, &env.mount_operation_id);
      if ( (env.node->m_flags & 0x300) != 0 )
      {
        vostok::vfs::find_async_across_link(&env);
        boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&env.callback);
        boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&callback);
        return;
      }
      if ( vostok::vfs::mount_overlapped_if_needed((boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&env) )
        goto LABEL_18;
    }
    else
    {
      v13 = &env.file_system->hashset;
      v8 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&partial_path);
      env.node = vostok::vfs::vfs_hashset::find_no_lock(v13, v8, check_locks_true);
      v17 = 0;
      survarium::weapon_user_dead_state::finalize(v9);
    }
LABEL_5:
    vostok::fs_new::path_part_iterator::operator++(&it);
    ++env.path_part_index;
  }
  if ( (env.node->m_flags & 1) == 1 )
  {
    vostok::vfs::try_find_tree(&env);
  }
  else
  {
    vostok::vfs::vfs_iterator::vfs_iterator(&out_iterator);
    out_iterator.mount_operation_id = 0;
    vostok::vfs::make_iterator(&out_iterator, &env);
    boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
      (boost::function2<void,char const *,vostok::network_core::udp_match_packet const *> *)&env.callback,
      (const char *)&out_iterator,
      (const vostok::network_core::udp_match_packet *)1);
    vostok::vfs::vfs_locked_iterator::~vfs_locked_iterator(&out_iterator);
  }
LABEL_18:
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&env.callback);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&callback);
}
