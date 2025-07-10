bool __usercall vostok::resources::cook_base::does_create_resource@<al>(
        vostok::resources::cook_base *this@<ecx>,
        int a2@<eax>)
{
  return (*(_BYTE *)(a2 + 24) & 8) != 8;
}
