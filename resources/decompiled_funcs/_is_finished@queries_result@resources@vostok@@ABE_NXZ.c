BOOL __usercall vostok::resources::queries_result::is_finished@<eax>(
        vostok::resources::queries_result *this@<ecx>,
        int a2@<eax>)
{
  return *(_DWORD *)(a2 + 64) != -1;
}
