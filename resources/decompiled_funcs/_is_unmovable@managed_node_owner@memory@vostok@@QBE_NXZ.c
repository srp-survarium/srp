BOOL __usercall vostok::memory::managed_node_owner::is_unmovable@<eax>(
        vostok::memory::managed_node_owner *this@<ecx>,
        int a2@<eax>)
{
  return *(_DWORD *)(*(_DWORD *)(a2 + 4) + 32) != 0;
}
