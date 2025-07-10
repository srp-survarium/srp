void __cdecl vostok::vfs::decref_children(
        vostok::vfs::base_node<1> *node,
        vostok::vfs::find_enum find_flags,
        vostok::vfs::vfs_hashset *hashset,
        unsigned int mount_operation_id,
        bool is_root_node)
{
  survarium::game_camera *v5; // ecx
  bool v6; // [esp+3h] [ebp-1Dh]
  vostok::vfs::base_node<1> *ref_node; // [esp+Ch] [ebp-14h]
  vostok::vfs::base_node<1> *next_child; // [esp+10h] [ebp-10h]
  vostok::vfs::base_node<1> *it_child; // [esp+14h] [ebp-Ch]

  v6 = (find_flags & 1) != 0 || is_root_node;
  if ( (node->m_flags & 1) == 1 && v6 )
  {
    for ( it_child = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(node)->m_first_child.pointer;
          it_child;
          it_child = next_child )
    {
      next_child = it_child->m_next.pointer;
      vostok::vfs::decref_children(it_child, find_flags, hashset, mount_operation_id, 0);
    }
  }
  if ( !is_root_node )
  {
    if ( (node->m_flags & 0x200) == 0x200 )
    {
      ref_node = vostok::vfs::find_referenced_link_node(node);
      survarium::weapon_user_dead_state::finalize(v5);
      vostok::vfs::decref_children(ref_node, find_flags, hashset, mount_operation_id, 0);
    }
    vostok::vfs::change_subfat_ref_for_overlapped(-1, node, &mount_operation_id);
  }
}
