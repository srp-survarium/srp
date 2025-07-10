void __userpurge vostok::resources::resources_manager::push_to_translate_query(
        vostok::resources::query_result *query@<eax>,
        vostok::resources::resources_manager *this)
{
  vostok::resources::query_result *v3; // ecx
  unsigned int v4; // edi
  vostok::resources::query_result *v5; // ecx
  vostok::resources::thread_local_data *thread_local_data; // eax
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v7; // ecx
  bool *v8; // [esp+0h] [ebp-10h]

  vostok::resources::resources_manager::find_cook(query->m_class_id);
  v4 = vostok::resources::query_result::translate_thread_id(v3, (int)query);
  if ( v4 == GetCurrentThreadId() )
  {
    vostok::resources::query_result::translate_query_if_needed(v5);
  }
  else
  {
    thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                          (vostok::resources::resources_manager *)v5,
                          (unsigned int)this,
                          v4);
    vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v7,
      &thread_local_data->to_translate_query.m_size,
      query,
      v8);
    if ( v4 == *(int *)((char *)&dword_203CC + (_DWORD)this) )
    {
      SetEvent(*(HANDLE *)((char *)&dword_203D0 + (_DWORD)this));
    }
    else if ( v4 == *(_DWORD *)&byte_203D8[(_DWORD)this] )
    {
      SetEvent(*(HANDLE *)((char *)&dword_203E0 + (_DWORD)this));
    }
  }
}
