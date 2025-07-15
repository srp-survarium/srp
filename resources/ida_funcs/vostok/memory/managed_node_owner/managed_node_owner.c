void __usercall vostok::memory::managed_node_owner::managed_node_owner(
        vostok::memory::managed_node_owner *this@<ecx>,
        _DWORD *a2@<eax>)
{
  *a2 = &vostok::memory::managed_node_owner::`vftable';
  a2[1] = 0;
  a2[2] = &vostok::memory::g_resources_managed_allocator;
}
