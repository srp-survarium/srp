bool __usercall vostok::resources::resource_base::in_grm_observed_list@<al>(
        vostok::resources::resource_base *this@<ecx>,
        int a2@<eax>)
{
  return (*(_DWORD *)(a2 + 8) & 0x20) == 32;
}
