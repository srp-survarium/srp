bool __usercall vostok::resources::cook_base::cooks_managed_resource@<al>(
        vostok::resources::cook_base *this@<ecx>,
        int a2@<eax>)
{
  return (*(_DWORD *)(a2 + 24) & 0x20) == 32;
}
