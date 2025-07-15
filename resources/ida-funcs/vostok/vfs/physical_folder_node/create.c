vostok::vfs::physical_folder_node<1> *__usercall vostok::vfs::physical_folder_node<1>::create@<eax>(
        vostok::memory::base_allocator *allocator@<ecx>,
        const vostok::fs_new::virtual_path_string *name@<edi>,
        vostok::vfs::mount_root_node_base<1> *mount_root)
{
  vostok::vfs::base_folder_node<1> *v3; // ecx
  char *v4; // ebx
  vostok::vfs::base_node<1> *v5; // ecx

  v4 = (char *)allocator->call_malloc(
                 allocator,
                 name->m_string.m_end - name->m_string.m_begin + 89,
                 "physical_folder_node",
                 "vostok::vfs::physical_folder_node<1>::create",
                 "c:\\survarium.deploy\\sources\\vostok\\vfs\\sources\\physical_folder_node.h",
                 68);
  if ( !v4 )
    return 0;
  *(_DWORD *)v4 = 0;
  *((_DWORD *)v4 + 1) = 0;
  *((_DWORD *)v4 + 2) = 0;
  vostok::vfs::base_folder_node<1>::base_folder_node<1>(v3, (int)(v4 + 16));
  *((_DWORD *)v4 + 9) = 0;
  *((_DWORD *)v4 + 8) = mount_root;
  *((_WORD *)v4 + 40) = 3;
  vostok::strings::copy(v4 + 83, name->m_string.m_end - name->m_string.m_begin + 1, name->m_string.m_begin);
  mount_root->mount_size += vostok::vfs::base_node<1>::sizeof_with_name(v5, (vostok::vfs::base_node<1> *)(v4 + 32));
  return (vostok::vfs::physical_folder_node<1> *)v4;
}
