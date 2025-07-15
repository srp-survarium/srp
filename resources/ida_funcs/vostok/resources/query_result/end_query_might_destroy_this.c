char __usercall vostok::resources::query_result::end_query_might_destroy_this@<al>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)(a2 + 684), 0xFFFFFFFF) )
    return 0;
  vostok::resources::query_result::end_query_might_destroy_this_impl((vostok::resources::query_result *)(a2 + 684));
  return 1;
}
