BOOL __usercall vostok::resources::cook_base::does_deallocate@<eax>(
        vostok::resources::cook_base *this@<ecx>,
        int a2@<eax>)
{
  return (*(_BYTE *)(a2 + 24) & 0x2E) == 0;
}
