void __thiscall vostok::vfs::unmounter::hot_unmount_node(
        vostok::vfs::unmounter *this,
        vostok::vfs::base_node<1> *node,
        unsigned int hash)
{
  survarium::game_camera *v3; // ecx
  _DWORD v5[13]; // [esp+30h] [ebp-58h] BYREF
  _DWORD v6[6]; // [esp+64h] [ebp-24h] BYREF
  char v7; // [esp+7Fh] [ebp-9h]
  vostok::vfs::physical_file_node<1> *file; // [esp+80h] [ebp-8h]
  vostok::vfs::physical_folder_node<1> *physical_folder; // [esp+84h] [ebp-4h]

  vostok::vfs::vfs_hashset::erase(this->m_hashset, hash, node);
  if ( vostok::vfs::node_cast<vostok::vfs::mount_root_node_base,vostok::vfs::base_node,1>(node) == this->m_root_node_to_unmount )
  {
    this->m_root_node_to_unmount->erased = 1;
  }
  else
  {
    physical_folder = vostok::vfs::node_cast<vostok::vfs::physical_folder_node,vostok::vfs::base_node,1>(node);
    if ( physical_folder )
    {
      v6[4] = v6;
      v6[0] = 4;
      v6[1] = 4;
      v6[2] = &physical_folder->m_folder_flags;
      v6[3] = 4;
      if ( (physical_folder->m_folder_flags.m_flags & 4) != 4 )
        vostok::vfs::mount_root_node_base<1>::prepend_erased_node(this->m_root_node_to_unmount, node);
    }
    else
    {
      file = vostok::vfs::node_cast<vostok::vfs::physical_file_node,vostok::vfs::base_node,1>(node);
      v7 = 0;
      survarium::weapon_user_dead_state::finalize(v3);
      v5[2] = v5;
      v5[0] = 8;
      v5[1] = 8;
      if ( (file->m_file_flags.m_flags & 8) != 8 )
        vostok::vfs::mount_root_node_base<1>::prepend_erased_node(this->m_root_node_to_unmount, node);
    }
  }
}
