bool __usercall vostok::resources::cook_base::destroy_in_any_thread@<al>(
        vostok::resources::cook_base *this@<ecx>,
        int a2@<eax>)
{
  return (*(_DWORD *)(a2 + 24) & 1) == 1;
}
