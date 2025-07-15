void __usercall vostok::resources::query_result::increase_query_end_guard(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  _InterlockedExchangeAdd((volatile signed __int32 *)(a2 + 684), 1u);
}
