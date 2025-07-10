void __usercall vostok::resources::query_result::add_loaded_bytes(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)(a2 + 676) += this;
}
