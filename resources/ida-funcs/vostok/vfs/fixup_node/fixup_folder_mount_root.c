void __usercall vostok::vfs::fixup_node::fixup_folder_mount_root(
        vostok::vfs::fixup_node *this@<ecx>,
        vostok::vfs::base_node<1> **a2@<eax>)
{
  vostok::fs_new::virtual_path_string *v3; // ecx
  vostok::vfs::base_node<1> *v4; // edi

  vostok::vfs::fixup_node::fixup_folder_node(this, (int)a2);
  v4 = vostok::vfs::node_cast<vostok::vfs::archive_folder_mount_root_node,vostok::vfs::base_node,1>(*a2);
  if ( v4 != (vostok::vfs::base_node<1> *)-104 )
    vostok::fs_new::virtual_path_string::virtual_path_string(v3, (int)&v4->m_name[53]);
  if ( v4 != (vostok::vfs::base_node<1> *)-364 )
    vostok::fs_new::native_path_string::native_path_string((vostok::fs_new::native_path_string *)&v4->m_name[313]);
  if ( v4 != (vostok::vfs::base_node<1> *)-624 )
    vostok::fs_new::native_path_string::native_path_string((vostok::fs_new::native_path_string *)&v4->m_name[573]);
  if ( v4 != (vostok::vfs::base_node<1> *)-884 )
  {
    *(_DWORD *)&v4->m_name[833] = &v4->m_name[845];
    *(_DWORD *)&v4->m_name[837] = &v4->m_name[845];
    *(_DWORD *)&v4->m_name[841] = &v4->m_name[877];
    v4->m_name[845] = 0;
    v4->m_name[845] = 0;
  }
  *(_DWORD *)&v4->m_name[13] = *a2;
}
