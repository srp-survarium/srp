vostok::vfs::physical_file_node<1> *__cdecl vostok::vfs::physical_file_node<1>::create(
        vostok::vfs::mount_root_node_base<1> *mount_root,
        const vostok::fs_new::virtual_path_string *name,
        const unsigned int file_size)
{
  int v3; // ecx
  int v4; // edi
  vostok::vfs::physical_file_node<1> *result; // eax
  vostok::vfs::base_node<1> *v6; // ecx

  v4 = (*(int (__thiscall **)(int, int, const char *, const char *, const char *, int))(*(_DWORD *)v3 + 16))(
         v3,
         name->m_string.m_end - name->m_string.m_begin + 65,
         "physical_file_node",
         "vostok::vfs::physical_file_node<1>::create",
         "c:\\survarium.deploy\\sources\\vostok\\vfs\\sources\\physical_file_node.h",
         152);
  result = 0;
  if ( v4 )
  {
    *(_DWORD *)v4 = 0;
    *(_DWORD *)(v4 + 4) = 0;
    vostok::vfs::base_node<1>::base_node<1>((vostok::vfs::base_node<1> *)(v4 + 8), 0);
    *(_DWORD *)v4 = file_size;
    *(_WORD *)(v4 + 56) = 2;
    *(_DWORD *)(v4 + 8) = mount_root;
    *(_DWORD *)(v4 + 12) = 0;
    vostok::strings::copy((char *)(v4 + 59), name->m_string.m_end - name->m_string.m_begin + 1, name->m_string.m_begin);
    mount_root->mount_size += vostok::vfs::base_node<1>::sizeof_with_name(v6, (vostok::vfs::base_node<1> *)(v4 + 8));
    return (vostok::vfs::physical_file_node<1> *)v4;
  }
  return result;
}
