void __userpurge vostok::resources::resources_manager::on_query_finished(
        vostok::resources::resources_manager *this@<ecx>,
        vostok::resources::resources_manager *a2@<edi>,
        vostok::resources::queries_result *query)
{
  vostok::resources::thread_local_data *thread_local_data; // eax
  vostok::intrusive_list<vostok::resources::queries_result,vostok::resources::queries_result *,36,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v4; // ecx
  bool *v5; // [esp+0h] [ebp-8h]

  thread_local_data = vostok::resources::resources_manager::get_thread_local_data(this, a2, query->m_thread_id, 1);
  vostok::intrusive_list<vostok::resources::queries_result,vostok::resources::queries_result *,36,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    v4,
    thread_local_data,
    query,
    v5);
  if ( query->m_thread_id == *(_DWORD *)&byte_203D8[(_DWORD)a2] )
    SetEvent(*(HANDLE *)((char *)&dword_203E0 + (_DWORD)a2));
  if ( query->m_thread_id == *(int *)((char *)&dword_203CC + (_DWORD)a2) )
    SetEvent(*(HANDLE *)((char *)&dword_203D0 + (_DWORD)a2));
}
