void __thiscall vostok::resources::resources_manager::dispatch_allocated_raw_resources(
        vostok::resources::resources_manager *this,
        vostok::resources::resources_manager *a2)
{
  vostok::resources::query_result *v2; // eax
  vostok::resources::query_result *m_next_in_device_manager; // edi

  v2 = vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
         (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)this,
         (int)&loc_20388 + (_DWORD)a2,
         0);
  if ( v2 )
  {
    do
    {
      m_next_in_device_manager = v2->m_next_in_device_manager;
      vostok::resources::resources_manager::push_to_device_manager(v2, a2);
      v2 = m_next_in_device_manager;
    }
    while ( m_next_in_device_manager );
  }
}
