void __userpurge vostok::resources::allocate_functionality::allocate_raw_resources(
        vostok::resources::thread_local_data *tls@<eax>,
        vostok::resources::allocate_functionality *this,
        bool finalizing_thread)
{
  vostok::resources::query_result *m_first; // ebx
  vostok::resources::allocate_functionality *v5; // ecx
  vostok::resources::query_result *v6; // esi
  vostok::resources::query_result *m_next_in_device_manager; // ebx
  vostok::resources::allocate_functionality *v8; // [esp+0h] [ebp-10h]

  if ( tls->to_allocate_raw_resource.m_first )
  {
    vostok::threading::mutex::lock(&tls->to_allocate_raw_resource.vostok::threading::mutex);
    m_first = tls->to_allocate_raw_resource.m_first;
    tls->to_allocate_raw_resource.m_first = 0;
    tls->to_allocate_raw_resource.m_last = 0;
    tls->to_allocate_raw_resource.m_size = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&tls->to_allocate_raw_resource.vostok::threading::mutex);
    v6 = m_first;
    if ( m_first )
    {
      do
      {
        m_next_in_device_manager = v6->m_next_in_device_manager;
        if ( (_BYTE)this )
        {
          v6->m_error_type = error_type_canceled_by_finalization;
          v5 = (vostok::resources::allocate_functionality *)_InterlockedExchangeAdd(&v6->m_query_end_guard, 0xFFFFFFFF);
          if ( !v5 )
            vostok::resources::query_result::end_query_might_destroy_this_impl(0, v6);
        }
        else
        {
          vostok::resources::allocate_functionality::prepare_raw_resource(v6, 0, v5, v8);
        }
        v6 = m_next_in_device_manager;
      }
      while ( m_next_in_device_manager );
      SetEvent(*(HANDLE *)((char *)&dword_203D0 + (unsigned int)vostok::resources::g_resources_manager.m_variable));
    }
  }
}
