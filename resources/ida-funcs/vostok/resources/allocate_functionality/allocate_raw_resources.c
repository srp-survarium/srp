void __userpurge vostok::resources::allocate_functionality::allocate_raw_resources(
        vostok::resources::thread_local_data *tls@<eax>,
        vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *a2@<ecx>,
        vostok::resources::allocate_functionality *this,
        bool finalizing_thread)
{
  vostok::resources::query_result *v4; // eax
  vostok::resources::query_result *v5; // ecx
  vostok::resources::query_result *m_next_in_device_manager; // esi
  vostok::resources::reallocating_bool v7; // [esp+0h] [ebp-8h]

  v4 = vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
         a2,
         (int)&tls->to_allocate_raw_resource,
         0);
  if ( v4 )
  {
    do
    {
      m_next_in_device_manager = v4->m_next_in_device_manager;
      if ( (_BYTE)this )
      {
        v4->m_error_type = error_type_canceled_by_finalization;
        vostok::resources::query_result::end_query_might_destroy_this(v5, (int)v4);
      }
      else
      {
        vostok::resources::allocate_functionality::prepare_raw_resource(v4, 0, v7);
      }
      v4 = m_next_in_device_manager;
    }
    while ( m_next_in_device_manager );
    SetEvent(*(HANDLE *)s_resources_manager_buffer.m_resources_wakeup_event.m_event.m_event);
  }
}
