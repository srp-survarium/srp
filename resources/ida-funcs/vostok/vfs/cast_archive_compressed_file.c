vostok::vfs::archive_compressed_file_node<1> *__cdecl vostok::vfs::cast_archive_compressed_file<1>(
        vostok::vfs::base_node<1> *node)
{
  survarium::game_camera *v1; // ecx

  survarium::weapon_user_dead_state::finalize(v1);
  if ( (node->m_flags & 1) != 1
    && (node->m_flags & 4) == 4
    && (node->m_flags & 0x10) == 0x10
    && (node->m_flags & 0x40) != 0x40 )
  {
    return (vostok::vfs::archive_compressed_file_node<1> *)((char *)node - 32);
  }
  else
  {
    return 0;
  }
}


const vostok::vfs::archive_compressed_file_node<1> *__cdecl vostok::vfs::cast_archive_compressed_file<1>(
        vostok::vfs::base_node<1> *node)
{
  return vostok::vfs::node_cast<vostok::vfs::archive_compressed_file_node,vostok::vfs::base_node,1>(node);
}
