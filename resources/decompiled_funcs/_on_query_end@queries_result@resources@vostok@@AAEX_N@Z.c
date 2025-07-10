void __userpurge vostok::resources::queries_result::on_query_end(
        vostok::resources::queries_result *this@<ecx>,
        int a2@<eax>,
        bool result)
{
  _InterlockedExchange((volatile __int32 *)(a2 + 64), result);
  if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(a2 + 44), 0xFFFFFFFF) )
    vostok::resources::resources_manager::on_query_finished(
      (vostok::resources::resources_manager *)(a2 + 44),
      vostok::resources::g_resources_manager.m_variable,
      (vostok::resources::queries_result *)a2);
}
