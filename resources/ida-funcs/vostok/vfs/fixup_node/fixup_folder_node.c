void __usercall vostok::vfs::fixup_node::fixup_folder_node(vostok::vfs::fixup_node *this@<ecx>, int a2@<esi>)
{
  vostok::vfs::base_folder_node<1> *v2; // eax
  int v3; // ecx

  v2 = *(vostok::vfs::base_folder_node<1> **)a2;
  if ( *(_DWORD *)a2 )
    v2 = vostok::vfs::cast_folder<1>((vostok::vfs::base_node<1> *)v2);
  if ( v2->m_first_child.pointer )
    v3 = (int)v2->m_first_child.pointer + *(_DWORD *)(a2 + 4);
  else
    v3 = 0;
  v2->m_first_child.pointer = (vostok::vfs::base_node<1> *)v3;
  HIDWORD(v2->m_first_child.max_storage) = 0;
}
