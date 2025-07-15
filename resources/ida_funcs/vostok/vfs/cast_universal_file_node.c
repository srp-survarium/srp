vostok::vfs::universal_file_node<1> *__cdecl vostok::vfs::cast_universal_file_node<1>(vostok::vfs::base_node<1> *node)
{
  survarium::game_camera *v1; // ecx

  survarium::weapon_user_dead_state::finalize(v1);
  if ( (node->m_flags & 0x2000) == 0x2000 )
    return (vostok::vfs::universal_file_node<1> *)((char *)node - 24);
  else
    return 0;
}


const vostok::vfs::universal_file_node<1> *__cdecl vostok::vfs::cast_universal_file_node<1>(
        vostok::vfs::base_node<1> *node)
{
  return vostok::vfs::node_cast<vostok::vfs::universal_file_node,vostok::vfs::base_node,1>(node);
}
