void __usercall vostok::resources::resources_manager::init_new_autoselect_quality_queries(
        vostok::resources::resources_manager *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::query_result *v2; // eax
  vostok::resources::query_result *m_next_in_device_manager; // esi
  vostok::resources::resources_manager *v4; // [esp+0h] [ebp-8h]

  v2 = vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
         (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)this,
         a2 + 131824,
         0);
  if ( v2 )
  {
    do
    {
      m_next_in_device_manager = v2->m_next_in_device_manager;
      vostok::resources::resources_manager::init_new_autoselect_quality_query(v2, v4);
      v2 = m_next_in_device_manager;
    }
    while ( m_next_in_device_manager );
  }
}
