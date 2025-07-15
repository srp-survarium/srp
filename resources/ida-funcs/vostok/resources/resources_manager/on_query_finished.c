void __usercall vostok::resources::resources_manager::on_query_finished(
        vostok::resources::queries_result *query@<eax>,
        vostok::resources::resources_manager *a2@<ecx>)
{
  vostok::resources::thread_local_data *thread_local_data; // eax
  vostok::threading::mutex *v4; // ecx
  vostok::resources::resources_manager *v5; // ecx

  thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                        a2,
                        (unsigned int)&s_resources_manager_buffer,
                        query->m_thread_id,
                        1);
  vostok::intrusive_list<vostok::resources::queries_result,vostok::resources::queries_result *,36,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    &thread_local_data->finished_queries,
    query,
    v4);
  if ( query->m_thread_id == s_resources_manager_buffer.m_cooker_thread_id )
    SetEvent(*(HANDLE *)s_resources_manager_buffer.m_cooker_wakeup_event.m_event.m_event);
  if ( query->m_thread_id == s_resources_manager_buffer.m_resources_thread_id )
    vostok::resources::resources_manager::wakeup_resources_thread(v5, (int)&s_resources_manager_buffer);
}
