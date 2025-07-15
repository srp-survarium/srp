void __usercall vostok::resources::query_result::prepare_requery(
        vostok::resources::query_result *this@<ecx>,
        int a2@<esi>)
{
  *(_DWORD *)(a2 + 256) = 0;
  _InterlockedExchange((volatile __int32 *)(a2 + 712), 1);
  vostok::threading::interlocked_and((volatile int *)(a2 + 688), 0xFFFFBEFF);
  *(_DWORD *)(a2 + 316) = 0;
}
