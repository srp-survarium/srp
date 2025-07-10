vostok::vfs::base_folder_node<1> *__cdecl vostok::vfs::cast_folder<1>(vostok::vfs::base_node<1> *node)
{
  survarium::game_camera *v1; // ecx
  vostok::vfs::physical_folder_mount_root_node<1> *physical_folder_mount_root; // [esp+10h] [ebp-18h]
  vostok::vfs::archive_folder_mount_root_node<1> *archive_folder_mount_root; // [esp+18h] [ebp-10h]
  vostok::vfs::mount_helper_node<1> *mount_helper; // [esp+1Ch] [ebp-Ch]
  vostok::vfs::physical_folder_node<1> *disk_folder; // [esp+20h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize(v1);
  if ( (node->m_flags & 1) != 1 )
    return 0;
  if ( (node->m_flags & 0x400) == 0x400 )
  {
    mount_helper = vostok::vfs::node_cast<vostok::vfs::mount_helper_node,vostok::vfs::base_node,1>(node);
    return vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::mount_helper_node,1>(mount_helper);
  }
  else if ( (node->m_flags & 8) == 8 )
  {
    if ( (node->m_flags & 4) == 4 )
    {
      archive_folder_mount_root = (vostok::vfs::archive_folder_mount_root_node<1> *)vostok::vfs::node_cast<vostok::vfs::archive_folder_mount_root_node,vostok::vfs::base_node,1>(node);
      return vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::archive_folder_mount_root_node,1>(archive_folder_mount_root);
    }
    else
    {
      physical_folder_mount_root = vostok::vfs::node_cast<vostok::vfs::physical_folder_mount_root_node,vostok::vfs::base_node,1>(node);
      return vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_mount_root_node,1>(physical_folder_mount_root);
    }
  }
  else if ( (node->m_flags & 2) == 2 )
  {
    disk_folder = vostok::vfs::node_cast<vostok::vfs::physical_folder_node,vostok::vfs::base_node,1>(node);
    return (vostok::vfs::base_folder_node<1> *)vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_node,1>((vostok::vfs::base_folder_node<1> *)disk_folder);
  }
  else
  {
    return (vostok::vfs::base_folder_node<1> *)((char *)node - 16);
  }
}
