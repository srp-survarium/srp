void __thiscall vostok::vfs::base_node<1>::reverse_bytes_for_final_class(
        vostok::vfs::base_node<1> *this,
        vostok::vfs::reverse_direction_enum direction)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  vostok::vfs::archive_file_node<1> *archive_file; // [esp+2ACh] [ebp-20h]
  vostok::vfs::archive_compressed_file_node<1> *compressed_file; // [esp+2B0h] [ebp-1Ch]
  vostok::vfs::archive_inline_file_node<1> *inline_file; // [esp+2B4h] [ebp-18h]
  vostok::vfs::archive_inline_compressed_file_node<1> *compressed_inline_file; // [esp+2B8h] [ebp-14h]
  vostok::vfs::base_folder_node<1> *folder; // [esp+2BCh] [ebp-10h]
  vostok::vfs::hard_link_node<1> *res; // [esp+2C0h] [ebp-Ch]
  vostok::vfs::soft_link_node<1> *link; // [esp+2C4h] [ebp-8h]
  vostok::vfs::external_subfat_node<1> *node; // [esp+2C8h] [ebp-4h]

  if ( direction == reverse_direction_to_native )
    vostok::vfs::reverse_bytes<unsigned short>(&this->m_flags);
  if ( (this->m_flags & 0x1000) == 0x1000 )
  {
    node = vostok::vfs::node_cast<vostok::vfs::external_subfat_node,vostok::vfs::base_node,1>(this);
    vostok::vfs::reverse_bytes<vostok::platform_pointer_selector<char,1>::helper>((vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper *)node);
    vostok::vfs::reverse_bytes<vostok::vfs::vfs_reader_writer_lock>((vostok::vfs::vfs_reader_writer_lock *)&node->external_fat_size);
    vostok::vfs::base_node<1>::reverse_bytes(&node->base);
  }
  else if ( (this->m_flags & 0x100) == 0x100 )
  {
    link = (vostok::vfs::soft_link_node<1> *)vostok::vfs::node_cast<vostok::vfs::soft_link_node,vostok::vfs::base_node,1>(this);
    vostok::vfs::reverse_bytes<vostok::platform_pointer_selector<char,1>::helper>((vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper *)link);
    vostok::vfs::base_node<1>::reverse_bytes(&link->base);
  }
  else if ( (this->m_flags & 0x200) == 0x200 )
  {
    res = vostok::vfs::node_cast<vostok::vfs::soft_link_node,vostok::vfs::base_node,1>(this);
    vostok::vfs::reverse_bytes<vostok::platform_pointer_selector<char,1>::helper>(&res->referenced);
    vostok::vfs::base_node<1>::reverse_bytes(&res->base);
  }
  else if ( (this->m_flags & 1) == 1 )
  {
    folder = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(this);
    survarium::weapon_user_dead_state::finalize(v2);
    vostok::vfs::reverse_bytes<vostok::platform_pointer_selector<char,1>::helper>(&folder->m_first_child);
    vostok::vfs::reverse_bytes<vostok::vfs::vfs_reader_writer_lock>(&folder->m_readers_writers_counters);
    vostok::vfs::base_node<1>::reverse_bytes(&folder->base);
  }
  else if ( (this->m_flags & 0x40) == 0x40 )
  {
    if ( (this->m_flags & 0x10) == 0x10 )
    {
      compressed_inline_file = vostok::vfs::node_cast<vostok::vfs::archive_inline_compressed_file_node,vostok::vfs::base_node,1>(this);
      survarium::weapon_user_dead_state::finalize(v3);
      vostok::vfs::archive_inline_compressed_file_node<1>::reverse_bytes(compressed_inline_file);
    }
    else
    {
      inline_file = vostok::vfs::node_cast<vostok::vfs::archive_inline_file_node,vostok::vfs::base_node,1>(this);
      survarium::weapon_user_dead_state::finalize(v4);
      vostok::vfs::archive_inline_file_node<1>::reverse_bytes(inline_file);
    }
  }
  else if ( (this->m_flags & 2) != 2 )
  {
    if ( (this->m_flags & 0x10) == 0x10 )
    {
      compressed_file = vostok::vfs::node_cast<vostok::vfs::archive_compressed_file_node,vostok::vfs::base_node,1>(this);
      survarium::weapon_user_dead_state::finalize(v5);
      vostok::vfs::archive_compressed_file_node<1>::reverse_bytes(compressed_file);
    }
    else
    {
      archive_file = vostok::vfs::node_cast<vostok::vfs::archive_file_node,vostok::vfs::base_node,1>(this);
      survarium::weapon_user_dead_state::finalize(v6);
      vostok::vfs::archive_file_node<1>::reverse_bytes(archive_file);
    }
  }
  if ( direction == reverse_direction_to_native )
    vostok::vfs::reverse_bytes<unsigned short>(&this->m_flags);
}
