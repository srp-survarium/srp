vostok::vfs::result_enum __cdecl vostok::vfs::try_find_sync(
        char *path_to_find,
        vostok::vfs::vfs_locked_iterator *out_iterator,
        unsigned int find_flags,
        vostok::vfs::virtual_file_system *file_system,
        vostok::memory::base_allocator *allocator)
{
  vostok::vfs::base_node<1> *node; // edi
  vostok::vfs::vfs_locked_iterator *v6; // ecx
  vostok::vfs::result_enum is_expanded; // edi
  vostok::fs_new::path_string_impl *v8; // ecx
  vostok::vfs::vfs_locked_iterator *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  vostok::vfs::vfs_locked_iterator *v12; // [esp-4h] [ebp-1ACh]
  unsigned int mount_operation_id; // [esp-4h] [ebp-1ACh]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v14; // [esp-4h] [ebp-1ACh]
  vostok::vfs::lock_operation_enum v15; // [esp+0h] [ebp-1A8h]
  const char *m_cur_end; // [esp+Ch] [ebp-19Ch] BYREF
  vostok::vfs::find_environment env; // [esp+10h] [ebp-198h] BYREF
  vostok::fs_new::path_part_iterator v18; // [esp+60h] [ebp-148h] BYREF
  vostok::fs_new::path_part_iterator v19; // [esp+78h] [ebp-130h] BYREF
  vostok::buffer_string v20; // [esp+90h] [ebp-118h] BYREF
  _BYTE v21[260]; // [esp+9Ch] [ebp-10Ch] BYREF
  char v22; // [esp+1A0h] [ebp-8h] BYREF

  v20.m_begin = v21;
  v20.m_end = v21;
  v20.m_max_end = &v22;
  env.out_iterator = out_iterator;
  env.partial_path = v21;
  env.find_flags.m_flags = find_flags;
  env.file_system = file_system;
  env.allocator = allocator;
  v21[0] = 0;
  v22 = 47;
  env.find_results = 0;
  env.path_part_index = 0;
  env.callback.vtable = 0;
  env.node = 0;
  env.node_parent = 0;
  env.mount_operation_id = 0;
  env.path_to_find = path_to_find;
  vostok::fs_new::path_part_iterator::path_part_iterator(&v18, path_to_find, include_empty_string_in_iteration_true, 47);
  vostok::fs_new::path_part_iterator::path_part_iterator(&v19, 0, include_empty_string_in_iteration_false, 0);
  while ( 1 )
  {
    if ( !vostok::fs_new::path_part_iterator::operator!=(&v18, &v19) )
    {
      is_expanded = vostok::vfs::try_pin_tree(env.node, &env);
      v9 = v12;
      mount_operation_id = env.mount_operation_id;
      if ( is_expanded == result_success )
      {
        vostok::vfs::vfs_locked_iterator::assign(
          env.node,
          v9,
          out_iterator,
          &env.file_system->hashset,
          (vostok::vfs::vfs_iterator::type_enum)(((find_flags & 1) == 0) + 1),
          env.mount_operation_id);
        goto LABEL_14;
      }
      goto LABEL_12;
    }
    m_cur_end = v18.m_cur_end;
    vostok::fs_new::path_string_impl::assign<char const *>(v8, &v20, &path_to_find, &m_cur_end);
    node = env.node;
    env.node_parent = env.node;
    if ( !vostok::vfs::vfs_hashset::find_no_branch_lock(
            (vostok::vfs::vfs_hashset *)&env.node,
            (vostok::vfs::base_node<1> **)&env.file_system->hashset,
            (char *)&env.node,
            v20.m_begin,
            v15) )
    {
      is_expanded = result_cannot_lock;
      goto LABEL_11;
    }
    if ( !env.node )
      break;
    vostok::vfs::upgrade_node(env.node_parent, lock_type_read, (vostok::vfs::lock_operation_enum)3);
    is_expanded = vostok::vfs::overlapped_chain_is_expanded(&env, env.node);
    vostok::vfs::change_subfat_ref_for_overlapped(
      env.node,
      (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>)1,
      &env.mount_operation_id);
    if ( is_expanded != result_success )
      goto LABEL_11;
    if ( (env.node->m_flags & 0x300) != 0 )
    {
      is_expanded = vostok::vfs::try_find_sync_link(&env);
LABEL_11:
      mount_operation_id = env.mount_operation_id;
LABEL_12:
      vostok::vfs::unlock_and_decref_branch(env.node, lock_type_read, mount_operation_id);
      goto LABEL_13;
    }
    vostok::fs_new::path_part_iterator::operator++((vostok::fs_new::path_part_iterator *)env.node, (int)&v18);
    ++env.path_part_index;
  }
  vostok::vfs::vfs_locked_iterator::clear(v6, (int)out_iterator);
  vostok::vfs::unlock_and_decref_branch(node, lock_type_read, env.mount_operation_id);
  is_expanded = result_success;
LABEL_13:
  v10 = v14;
LABEL_14:
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v10,
    (int *)&env.callback);
  return is_expanded;
}
