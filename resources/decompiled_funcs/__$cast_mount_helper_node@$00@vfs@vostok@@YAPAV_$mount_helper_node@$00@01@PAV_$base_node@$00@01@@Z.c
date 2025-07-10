vostok::vfs::mount_helper_node<1> *__cdecl vostok::vfs::cast_mount_helper_node<1>(vostok::vfs::base_node<1> *node)
{
  survarium::game_camera *v1; // ecx

  survarium::weapon_user_dead_state::finalize(v1);
  if ( (node->m_flags & 1) == 1 && (node->m_flags & 0x400) == 0x400 )
    return (vostok::vfs::mount_helper_node<1> *)((char *)node - 24);
  else
    return 0;
}
