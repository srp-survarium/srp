void __usercall vostok::resources::query_result::prepare_requery(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)(a2 + 256) = 0;
  _InterlockedExchange((volatile __int32 *)(a2 + 728), 1);
  _InterlockedAnd((volatile signed __int32 *)(a2 + 704), 0xFFFFBEFF);
  *(_DWORD *)(a2 + 332) = 0;
}
