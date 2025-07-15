signed __int32 __usercall vostok::resources::query_result::decrease_query_end_guard@<eax>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  return _InterlockedDecrement((volatile signed __int32 *)(a2 + 684));
}
