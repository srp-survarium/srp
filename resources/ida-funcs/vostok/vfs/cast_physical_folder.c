vostok::vfs::physical_folder_node<1> *__cdecl vostok::vfs::cast_physical_folder<1>(vostok::vfs::base_node<1> *node)
{
  survarium::game_camera *v1; // ecx

  survarium::weapon_user_dead_state::finalize(v1);
  if ( (node->m_flags & 1) != 1 || (node->m_flags & 2) != 2 )
    return 0;
  if ( (node->m_flags & 8) == 8 )
    return &vostok::vfs::node_cast<vostok::vfs::physical_folder_mount_root_node,vostok::vfs::base_node,1>(node)->folder;
  return (vostok::vfs::physical_folder_node<1> *)((char *)node - 32);
}


vostok::vfs::physical_folder_node<1> *__cdecl vostok::vfs::cast_physical_folder<1>(
        vostok::vfs::physical_folder_mount_root_node<1> *node)
{
  return &node->folder;
}
