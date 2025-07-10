vostok::vfs::base_node<1> *__thiscall vostok::vfs::base_node<1>::sizeof_with_name(vostok::vfs::base_node<1> *this)
{
  vostok::vfs::base_node<1> *result; // eax
  unsigned int v2; // esi
  vostok::vfs::base_folder_node<1> *v3; // [esp+14h] [ebp-2Ch]
  vostok::vfs::base_folder_node<1> *v4; // [esp+18h] [ebp-28h]
  vostok::vfs::base_node<1> *v5; // [esp+1Ch] [ebp-24h]
  vostok::vfs::archive_file_node<1> *v6; // [esp+20h] [ebp-20h]
  vostok::vfs::archive_compressed_file_node<1> *v7; // [esp+24h] [ebp-1Ch]
  vostok::vfs::external_subfat_node<1> *v8; // [esp+28h] [ebp-18h]
  vostok::vfs::physical_folder_node<1> *v9; // [esp+2Ch] [ebp-14h]
  vostok::vfs::physical_folder_mount_root_node<1> *v10; // [esp+30h] [ebp-10h]
  vostok::vfs::physical_file_node<1> *v11; // [esp+34h] [ebp-Ch]
  vostok::vfs::physical_file_mount_root_node<1> *v12; // [esp+38h] [ebp-8h]
  vostok::vfs::erased_node<1> *node; // [esp+3Ch] [ebp-4h]

  result = this;
  if ( (this->m_flags & 0x300) == 0 )
  {
    if ( (this->m_flags & 0x800) == 0x800 )
    {
      node = vostok::vfs::node_cast<vostok::vfs::erased_node,vostok::vfs::base_node,1>(this);
      return (vostok::vfs::base_node<1> *)(vostok::strings::length(node->base.m_name) + 57);
    }
    else if ( (this->m_flags & 2) == 2 )
    {
      if ( (this->m_flags & 1) == 1 )
      {
        if ( (this->m_flags & 8) == 8 )
        {
          v10 = vostok::vfs::node_cast<vostok::vfs::physical_folder_mount_root_node,vostok::vfs::base_node,1>(this);
          return (vostok::vfs::base_node<1> *)vostok::vfs::physical_folder_mount_root_node<1>::sizeof_with_name(v10);
        }
        else
        {
          v9 = vostok::vfs::node_cast<vostok::vfs::physical_folder_node,vostok::vfs::base_node,1>(this);
          return (vostok::vfs::base_node<1> *)(vostok::strings::length(v9->folder.base.m_name) + 89);
        }
      }
      else if ( (this->m_flags & 8) == 8 )
      {
        v12 = vostok::vfs::node_cast<vostok::vfs::physical_file_mount_root_node,vostok::vfs::base_node,1>(this);
        return (vostok::vfs::base_node<1> *)vostok::vfs::physical_file_mount_root_node<1>::sizeof_with_name(v12);
      }
      else
      {
        v11 = vostok::vfs::node_cast<vostok::vfs::physical_file_node,vostok::vfs::base_node,1>(this);
        return (vostok::vfs::base_node<1> *)(vostok::strings::length(v11->base.m_name) + 65);
      }
    }
    else if ( (this->m_flags & 4) == 4 )
    {
      if ( (this->m_flags & 0x1000) == 0x1000 )
      {
        v8 = vostok::vfs::node_cast<vostok::vfs::external_subfat_node,vostok::vfs::base_node,1>(this);
        v2 = vostok::strings::length(v8->base.m_name);
        return (vostok::vfs::base_node<1> *)(vostok::strings::length(v8->relative_path_to_external.pointer) + v2 + 74);
      }
      else if ( (this->m_flags & 1) == 1 )
      {
        if ( (this->m_flags & 8) == 8 )
        {
          v5 = vostok::vfs::node_cast<vostok::vfs::archive_folder_mount_root_node,vostok::vfs::base_node,1>(this);
          return (vostok::vfs::base_node<1> *)(vostok::strings::length(&v5->m_name[952]) + 1009);
        }
        else
        {
          v4 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(this);
          return (vostok::vfs::base_node<1> *)(vostok::strings::length(v4->base.m_name) + 73);
        }
      }
      else if ( (this->m_flags & 0x10) == 0x10 )
      {
        v7 = vostok::vfs::node_cast<vostok::vfs::archive_compressed_file_node,vostok::vfs::base_node,1>(this);
        return (vostok::vfs::base_node<1> *)(vostok::strings::length(v7->base.m_name) + 89);
      }
      else
      {
        v6 = vostok::vfs::node_cast<vostok::vfs::archive_file_node,vostok::vfs::base_node,1>(this);
        return (vostok::vfs::base_node<1> *)(vostok::strings::length(v6->base.m_name) + 81);
      }
    }
    else
    {
      v3 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(this);
      return (vostok::vfs::base_node<1> *)(vostok::strings::length(v3->base.m_name) + 73);
    }
  }
  return result;
}
