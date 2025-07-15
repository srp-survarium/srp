vostok::vfs::result_enum __cdecl vostok::vfs::try_pin_tree(
        vostok::vfs::base_node<1> *node,
        vostok::vfs::find_environment *env)
{
  vostok::vfs::result_enum result; // eax
  unsigned int m_flags; // eax
  vostok::vfs::result_enum sync; // eax
  vostok::vfs::result_enum v6; // edi
  vostok::vfs::vfs_locked_iterator *v7; // ecx
  vostok::vfs::base_folder_node<1> *v8; // esi
  vostok::vfs::base_node<1> *i; // ebx
  vostok::vfs::base_node<1> *j; // esi
  vostok::vfs::virtual_file_system *file_system; // [esp-8h] [ebp-148h]
  vostok::memory::base_allocator *allocator; // [esp-4h] [ebp-144h]
  vostok::fs_new::virtual_path_string out_path; // [esp+10h] [ebp-130h] BYREF
  vostok::vfs::vfs_locked_iterator out_iterator; // [esp+12Ch] [ebp-14h] BYREF
  vostok::vfs::find_environment *enva; // [esp+14Ch] [ebp+Ch]

  if ( node == env->node )
    goto LABEL_8;
  result = vostok::vfs::overlapped_chain_is_expanded(env, node);
  if ( result != result_success )
    return result;
  vostok::vfs::change_subfat_ref_for_overlapped(
    node,
    (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>)1,
    &env->mount_operation_id);
  if ( (node->m_flags & 0x300) == 0 )
  {
LABEL_8:
    if ( (node->m_flags & 1) != 0 && ((env->find_flags.m_flags & 1) != 0 || node == env->node) )
    {
      v8 = vostok::vfs::cast_folder<1>(node);
      for ( i = v8->m_first_child.pointer; i; i = i->m_next.pointer )
      {
        enva = (vostok::vfs::find_environment *)vostok::vfs::try_pin_tree(i, env);
        if ( enva != (vostok::vfs::find_environment *)1 )
        {
          for ( j = v8->m_first_child.pointer; j != i; j = j->m_next.pointer )
            vostok::vfs::decref_children(
              j,
              (vostok::vfs::find_enum)env->find_flags.m_flags,
              &env->file_system->hashset,
              env->mount_operation_id,
              0);
          return (vostok::vfs::result_enum)enva;
        }
      }
    }
    return 1;
  }
  else
  {
    out_path.m_string.m_begin = out_path.m_string.m_buffer;
    out_path.m_string.m_end = out_path.m_string.m_buffer;
    out_path.m_string.m_max_end = &out_path.m_separator;
    out_path.m_string.m_buffer[0] = 0;
    out_path.m_separator = 47;
    vostok::vfs::find_link_target_path<1>(&out_path);
    m_flags = env->find_flags.m_flags;
    allocator = env->allocator;
    file_system = env->file_system;
    memset(&out_iterator, 0, sizeof(out_iterator));
    sync = vostok::vfs::try_find_sync(out_path.m_string.m_begin, &out_iterator, m_flags, file_system, allocator);
    out_iterator.m_node = 0;
    out_iterator.m_link_target = 0;
    v6 = sync;
    vostok::vfs::vfs_locked_iterator::clear(v7, (int)&out_iterator);
    return v6;
  }
}
