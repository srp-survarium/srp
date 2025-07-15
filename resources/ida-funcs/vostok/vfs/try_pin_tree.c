vostok::vfs::result_enum __cdecl vostok::vfs::try_pin_tree(
        vostok::vfs::base_node<1> *node,
        vostok::vfs::find_environment *env)
{
  const char *v3; // eax
  vostok::vfs::find_enum m_flags; // [esp-Ch] [ebp-188h]
  vostok::vfs::virtual_file_system *file_system; // [esp-8h] [ebp-184h]
  vostok::memory::base_allocator *allocator; // [esp-4h] [ebp-180h]
  bool v7; // [esp+3h] [ebp-179h]
  vostok::vfs::result_enum v8; // [esp+28h] [ebp-154h]
  vostok::vfs::base_node<1> *i; // [esp+2Ch] [ebp-150h]
  vostok::vfs::base_node<1> *it_child; // [esp+30h] [ebp-14Ch]
  vostok::fs_new::virtual_path_string link_target_path; // [esp+34h] [ebp-148h] BYREF
  vostok::vfs::result_enum link_result; // [esp+150h] [ebp-2Ch]
  vostok::vfs::vfs_locked_iterator link_iterator; // [esp+154h] [ebp-28h] BYREF
  vostok::vfs::result_enum result; // [esp+168h] [ebp-14h]
  bool go_recursive; // [esp+16Fh] [ebp-Dh]
  vostok::vfs::base_folder_node<1> *folder; // [esp+170h] [ebp-Ch]
  vostok::vfs::result_enum child_result; // [esp+174h] [ebp-8h]
  vostok::vfs::base_node<1> *node_which_failed; // [esp+178h] [ebp-4h]

  if ( node == env->node )
    goto LABEL_6;
  result = vostok::vfs::overlapped_chain_is_expanded(node, env);
  if ( result != result_error )
    return result;
  vostok::vfs::change_subfat_ref_for_overlapped(1, node, &env->mount_operation_id);
  if ( (node->m_flags & 0x300) == 0 )
  {
LABEL_6:
    if ( (node->m_flags & 1) == 1 )
    {
      v7 = (env->find_flags.m_flags & 1) != 0 || node == env->node;
      go_recursive = v7;
      if ( v7 )
      {
        child_result = result_error;
        node_which_failed = 0;
        folder = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(node);
        for ( it_child = folder->m_first_child.pointer; it_child; it_child = it_child->m_next.pointer )
        {
          child_result = vostok::vfs::try_pin_tree(it_child, env);
          if ( child_result != result_error )
          {
            node_which_failed = it_child;
            break;
          }
        }
        if ( node_which_failed )
        {
          for ( i = folder->m_first_child.pointer; i != node_which_failed; i = i->m_next.pointer )
            vostok::vfs::decref_children(
              i,
              (vostok::vfs::find_enum)env->find_flags.m_flags,
              &env->file_system->hashset,
              env->mount_operation_id,
              0);
          return child_result;
        }
        else
        {
          return 1;
        }
      }
      else
      {
        return 1;
      }
    }
    else
    {
      return 1;
    }
  }
  else
  {
    vostok::fs_new::virtual_path_string::virtual_path_string(&link_target_path);
    vostok::vfs::find_link_target_path<1>(node, (vostok::fs_new::native_path_string *)&link_target_path);
    vostok::vfs::vfs_iterator::vfs_iterator(&link_iterator);
    link_iterator.mount_operation_id = 0;
    allocator = env->allocator;
    file_system = env->file_system;
    m_flags = env->find_flags.m_flags;
    v3 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&link_target_path);
    link_result = vostok::vfs::try_find_sync(v3, &link_iterator, m_flags, file_system, allocator);
    vostok::vfs::vfs_locked_iterator::clear_without_unpin(&link_iterator);
    v8 = link_result;
    vostok::vfs::vfs_locked_iterator::~vfs_locked_iterator(&link_iterator);
    return v8;
  }
}
