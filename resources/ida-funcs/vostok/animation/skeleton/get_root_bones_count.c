int __usercall vostok::animation::skeleton::get_root_bones_count@<eax>(
        vostok::animation::skeleton *this@<ecx>,
        int a2@<eax>)
{
  return (*(_DWORD *)(a2 + 280) - (a2 + 272)) / 20;
}
