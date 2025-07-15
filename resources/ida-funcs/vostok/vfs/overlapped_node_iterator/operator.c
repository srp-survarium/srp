void __usercall vostok::vfs::overlapped_node_iterator::operator++(
        vostok::vfs::overlapped_node_iterator *this@<ecx>,
        int a2@<esi>)
{
  vostok::vfs::base_node<1> *v2; // eax
  const char *v3; // [esp-4h] [ebp-4h]

  v2 = *(vostok::vfs::base_node<1> **)(*(_DWORD *)(a2 + 4) + 16);
  v3 = *(const char **)a2;
  *(_DWORD *)(a2 + 4) = v2;
  *(_DWORD *)(a2 + 4) = vostok::vfs::vfs_hashset::skip_nodes_with_wrong_path(v2, v3);
}
