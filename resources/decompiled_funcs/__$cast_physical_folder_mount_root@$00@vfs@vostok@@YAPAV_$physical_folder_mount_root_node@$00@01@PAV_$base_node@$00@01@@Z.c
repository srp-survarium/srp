vostok::vfs::physical_folder_mount_root_node<1> *__cdecl vostok::vfs::cast_physical_folder_mount_root<1>(
        vostok::vfs::base_node<1> *node)
{
  survarium::game_camera *v1; // ecx

  survarium::weapon_user_dead_state::finalize(v1);
  if ( (node->m_flags & 1) == 1 && (node->m_flags & 8) == 8 && (node->m_flags & 2) == 2 )
    return (vostok::vfs::physical_folder_mount_root_node<1> *)((char *)node - 136);
  else
    return 0;
}
