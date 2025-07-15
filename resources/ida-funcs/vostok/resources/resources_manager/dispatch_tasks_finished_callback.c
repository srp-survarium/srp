void __usercall vostok::resources::resources_manager::dispatch_tasks_finished_callback(
        vostok::resources::query_result *query@<eax>,
        vostok::resources::resources_manager *this)
{
  vostok::resources::query_result *v2; // esi
  vostok::resources::query_result *m_next_in_device_manager; // edi
  survarium::game_camera *v4; // eax
  boost::bad_function_call v5; // [esp+8h] [ebp-110h] BYREF

  v2 = query;
  if ( query )
  {
    do
    {
      m_next_in_device_manager = v2->m_next_in_device_manager;
      if ( !v2->m_tasks_finished_callback.vtable )
      {
        boost::bad_function_call::bad_function_call(&v5);
        boost::throw_exception(v4);
        stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)&v5);
      }
      (*(void (__cdecl **)(boost::detail::function::function_buffer *))(((int)v2->m_tasks_finished_callback.vtable
                                                                       & 0xFFFFFFFE)
                                                                      + 4))(&v2->m_tasks_finished_callback.functor);
      v2 = m_next_in_device_manager;
    }
    while ( m_next_in_device_manager );
  }
}
