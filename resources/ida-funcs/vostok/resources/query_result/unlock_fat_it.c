void __usercall vostok::resources::query_result::unlock_fat_it(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  if ( *(_DWORD *)(a2 + 164) )
  {
    _InterlockedAnd((volatile signed __int32 *)(a2 + 704), 0xFFFFFFEF);
    _InterlockedExchangeAdd(&s_resources_manager_buffer.m_count_of_pending_query_with_fat_it, 0xFFFFFFFF);
  }
}
