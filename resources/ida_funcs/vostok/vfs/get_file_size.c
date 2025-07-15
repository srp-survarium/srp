int __cdecl vostok::vfs::get_file_size<1>(const vostok::vfs::base_node<1> *node)
{
  survarium::game_camera *v1; // ecx
  survarium::game_camera *v3; // ecx
  const vostok::vfs::physical_file_node<1> *full; // [esp+20h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize(v1);
  if ( (node->m_flags & 0x2000) == 0x2000 )
    return vostok::vfs::node_cast<vostok::vfs::universal_file_node,vostok::vfs::base_node,1>(node)->uncompressed_size;
  if ( (node->m_flags & 4) == 4 )
  {
    if ( (node->m_flags & 0x1000) == 0x1000 )
    {
      return vostok::vfs::node_cast<vostok::vfs::external_subfat_node,vostok::vfs::base_node,1>(node)->external_fat_size;
    }
    else if ( (node->m_flags & 0x40) == 0x40 )
    {
      if ( (node->m_flags & 0x10) == 0x10 )
        return vostok::vfs::node_cast<vostok::vfs::archive_inline_compressed_file_node,vostok::vfs::base_node,1>(node)->uncompressed_size;
      else
        return vostok::vfs::node_cast<vostok::vfs::archive_inline_file_node,vostok::vfs::base_node,1>(node)->size_in_db;
    }
    else if ( (node->m_flags & 0x10) == 0x10 )
    {
      return vostok::vfs::node_cast<vostok::vfs::archive_compressed_file_node,vostok::vfs::base_node,1>(node)->uncompressed_size;
    }
    else
    {
      return vostok::vfs::node_cast<vostok::vfs::archive_file_node,vostok::vfs::base_node,1>(node)->size_in_db;
    }
  }
  else
  {
    full = vostok::vfs::node_cast<vostok::vfs::physical_file_node,vostok::vfs::base_node,1>(node);
    survarium::weapon_user_dead_state::finalize(v3);
    return full->m_size;
  }
}
