bool __usercall vostok::resources::resource_base::needs_cook@<al>(
        vostok::resources::resource_base *this@<ecx>,
        int a2@<eax>)
{
  return (*(_DWORD *)(a2 + 8) & 0x10) == 16;
}
