const char *__cdecl vostok::vfs::get_mount_log_type(
        vostok::vfs::base_node<1> *attach_node,
        vostok::vfs::mount_root_node_base<1> *mount_root_base)
{
  survarium::game_camera *v3; // ecx
  vostok::vfs::base_node<1> *mount_root_node; // [esp+8h] [ebp-4h]

  mount_root_node = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::mount_root_node_base,1>(mount_root_base);
  if ( attach_node )
  {
    if ( (attach_node->m_flags & 0x1000) == 0x1000 )
    {
      return "external sub_fat";
    }
    else if ( (attach_node->m_flags & 0x80) == 0x80 )
    {
      return "sub_fat";
    }
    else
    {
      return "auto-archive";
    }
  }
  else
  {
    v3 = (survarium::game_camera *)(mount_root_node->m_flags & 2);
    if ( v3 == (survarium::game_camera *)2 )
    {
      if ( (mount_root_node->m_flags & 1) == 1 )
        return "physical folder";
      else
        return "physical file";
    }
    else
    {
      survarium::weapon_user_dead_state::finalize(v3);
      return "archive folder";
    }
  }
}
