int __cdecl vostok::vfs::get_raw_file_size_impl<1>(const vostok::vfs::base_node<1> *node)
{
  survarium::game_camera *v1; // ecx
  vostok::vfs::base_node<1> *referenced; // [esp+28h] [ebp-4h]

  if ( (node->m_flags & 0x300) != 0 )
  {
    referenced = vostok::vfs::find_referenced_link_node(node);
    survarium::weapon_user_dead_state::finalize(v1);
    if ( (referenced->m_flags & 4 | referenced->m_flags & 0x51) == 4 )
      return *((_DWORD *)referenced - 6);
    else
      return vostok::vfs::get_raw_file_size_impl<1>(referenced);
  }
  else if ( (node->m_flags & 0x2000) == 0x2000 )
  {
    return vostok::vfs::node_cast<vostok::vfs::universal_file_node,vostok::vfs::base_node,1>(node)->size;
  }
  else if ( (node->m_flags & 4) == 4 )
  {
    if ( (node->m_flags & 0x40) == 0x40 )
    {
      if ( (node->m_flags & 0x10) == 0x10 )
        return vostok::vfs::node_cast<vostok::vfs::archive_inline_compressed_file_node,vostok::vfs::base_node,1>(node)->size_in_db;
      else
        return vostok::vfs::node_cast<vostok::vfs::archive_inline_file_node,vostok::vfs::base_node,1>(node)->size_in_db;
    }
    else if ( (node->m_flags & 0x10) == 0x10 )
    {
      return vostok::vfs::node_cast<vostok::vfs::archive_compressed_file_node,vostok::vfs::base_node,1>(node)->size_in_db;
    }
    else
    {
      return vostok::vfs::node_cast<vostok::vfs::archive_file_node,vostok::vfs::base_node,1>(node)->size_in_db;
    }
  }
  else
  {
    return vostok::vfs::node_cast<vostok::vfs::physical_file_node,vostok::vfs::base_node,1>(node)->m_size;
  }
}
