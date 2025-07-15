void __userpurge vostok::memory::managed_node::managed_node(
        vostok::memory::managed_node *this@<ecx>,
        int a2@<eax>,
        vostok::memory::managed_node_type type,
        unsigned int size)
{
  *(_BYTE *)(a2 + 48) = type;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 44) = 0;
  *(_DWORD *)(a2 + 40) = size;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 16) = 0;
}
