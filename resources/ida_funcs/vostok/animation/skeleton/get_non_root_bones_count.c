int __usercall vostok::animation::skeleton::get_non_root_bones_count@<eax>(
        vostok::animation::skeleton *this@<ecx>,
        int a2@<esi>)
{
  return *(_DWORD *)(a2 + 264) - (*(_DWORD *)(a2 + 280) - (a2 + 272)) / 20;
}
