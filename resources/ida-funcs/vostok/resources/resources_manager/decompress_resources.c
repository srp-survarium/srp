void __thiscall vostok::resources::resources_manager::decompress_resources(vostok::resources::resources_manager *this)
{
  vostok::resources::resources_manager *v1; // ecx
  vostok::resources::query_result *v2; // esi
  vostok::resources::query_result *m_next_in_device_manager; // edi
  vostok::resources::resources_manager *v4; // ecx

  v2 = vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
         (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)this,
         (int)&s_resources_manager_buffer.m_resources_to_decompress,
         0);
  if ( v2 )
  {
    do
    {
      m_next_in_device_manager = v2->m_next_in_device_manager;
      vostok::resources::resources_manager::decompress_resource(v1, v2);
      v2 = m_next_in_device_manager;
      vostok::resources::resources_manager::wakeup_resources_thread(v4, (int)&s_resources_manager_buffer);
    }
    while ( m_next_in_device_manager );
  }
}
