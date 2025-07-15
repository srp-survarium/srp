void __usercall vostok::resources::resources_manager::dispatch_decompressed_resources(
        vostok::resources::resources_manager *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::query_result *v2; // eax
  vostok::resources::query_result *v3; // ecx
  vostok::resources::query_result *m_next_in_device_manager; // esi

  v2 = vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
         (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)this,
         a2 + 132280,
         0);
  if ( v2 )
  {
    do
    {
      v3 = (vostok::resources::query_result *)&v2->624;
      m_next_in_device_manager = v2->m_next_in_device_manager;
      v2->m_next_in_device_manager = 0;
      if ( v2->m_error_type )
        vostok::resources::query_result::end_query_might_destroy_this(v3, (int)v2);
      else
        vostok::resources::query_result::prepare_final_resource(v3, v2);
      v2 = m_next_in_device_manager;
    }
    while ( m_next_in_device_manager );
  }
}
