void __usercall vostok::memory::base_allocator::finalize(vostok::memory::base_allocator *this@<ecx>, _DWORD *a2@<esi>)
{
  (*(void (__thiscall **)(_DWORD *))(*a2 + 36))(a2);
  a2[1] = 0;
  a2[2] = 0;
  a2[3] = 0;
}
