unsigned int __usercall vostok::vfs::base_node<1>::sizeof_with_name@<eax>(
        vostok::vfs::base_node<1> *this@<ecx>,
        vostok::vfs::base_node<1> *a2@<eax>)
{
  unsigned __int16 m_flags; // cx
  vostok::vfs::base_node<1> *v4; // eax
  vostok::vfs::physical_folder_mount_root_node<1> *v5; // eax
  char *v6; // eax
  char *v7; // edx
  unsigned int v8; // eax
  char *m_name; // eax

  m_flags = a2->m_flags;
  if ( (m_flags & 0x800) == 0x800 )
    return strlen(a2->m_name) + 57;
  if ( (m_flags & 2) == 0 )
  {
    if ( (m_flags & 4) != 0 )
    {
      if ( (m_flags & 0x1000) == 0x1000 )
        return strlen(a2->m_name) + strlen(*((const char **)a2 - 4)) + 74;
      if ( (m_flags & 1) == 0 )
      {
        if ( (m_flags & 0x10) == 0 )
          return strlen(vostok::vfs::node_cast<vostok::vfs::archive_file_node,vostok::vfs::base_node,1>(a2)->base.m_name)
               + 81;
        m_name = vostok::vfs::node_cast<vostok::vfs::archive_compressed_file_node,vostok::vfs::base_node,1>(a2)->base.m_name;
        v7 = m_name + 1;
        v8 = (unsigned int)&m_name[strlen(m_name) + 1];
        return v8 - (_DWORD)v7 + 89;
      }
      if ( (m_flags & 8) != 0 )
        return strlen(&vostok::vfs::node_cast<vostok::vfs::archive_folder_mount_root_node,vostok::vfs::base_node,1>(a2)->m_name[952])
             + 1009;
    }
    return strlen(vostok::vfs::cast_folder<1>(a2)->base.m_name) + 73;
  }
  if ( (m_flags & 1) != 0 )
  {
    if ( (m_flags & 8) != 0 )
    {
      v5 = vostok::vfs::node_cast<vostok::vfs::physical_folder_mount_root_node,vostok::vfs::base_node,1>(a2);
      return strlen(v5->physical_path.pointer)
           + strlen(v5->folder.folder.base.m_name)
           + strlen(v5->virtual_path.pointer)
           + 195;
    }
    v6 = vostok::vfs::node_cast<vostok::vfs::physical_folder_node,vostok::vfs::base_node,1>(a2)->folder.base.m_name;
    v7 = v6 + 1;
    v8 = (unsigned int)&v6[strlen(v6) + 1];
    return v8 - (_DWORD)v7 + 89;
  }
  if ( (m_flags & 8) == 0 )
    return strlen(vostok::vfs::node_cast<vostok::vfs::physical_file_node,vostok::vfs::base_node,1>(a2)->base.m_name)
         + 65;
  v4 = vostok::vfs::node_cast<vostok::vfs::physical_file_mount_root_node,vostok::vfs::base_node,1>(a2);
  return vostok::vfs::physical_file_mount_root_node<1>::sizeof_with_name((vostok::vfs::physical_file_mount_root_node<1> *)v4);
}
