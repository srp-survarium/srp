void __usercall vostok::resources::resources_manager::add_resource_to_create(
        vostok::resources::resources_manager *this@<edi>,
        vostok::resources::query_result *query@<eax>,
        int a3@<ecx>)
{
  vostok::resources::cook_base *cook; // eax
  unsigned int m_creation_thread_id; // ecx
  unsigned int v6; // edx
  unsigned int v7; // eax
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v8; // ecx
  vostok::resources::thread_local_data *thread_local_data; // eax
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v10; // ecx
  bool *v11; // [esp+0h] [ebp-4h]

  cook = vostok::resources::resources_manager::find_cook(a3, query->m_class_id);
  m_creation_thread_id = cook->m_creation_thread_id;
  if ( m_creation_thread_id == -2 )
  {
    v6 = *(_DWORD *)&byte_203D8[(unsigned int)vostok::resources::g_resources_manager.m_variable];
  }
  else
  {
    if ( m_creation_thread_id != -4 )
      goto LABEL_6;
    v6 = *(int *)((char *)&dword_203CC + (unsigned int)vostok::resources::g_resources_manager.m_variable);
  }
  cook->m_creation_thread_id = v6;
LABEL_6:
  v7 = cook->m_creation_thread_id;
  v8 = *(vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> **)&byte_203D8[(_DWORD)this];
  if ( (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)v7 == v8 )
  {
    vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v8,
      (int *)((char *)&dword_203E8 + (_DWORD)this),
      query,
      v11);
    SetEvent(*(HANDLE *)((char *)&dword_203E0 + (_DWORD)this));
  }
  else
  {
    thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                          (vostok::resources::resources_manager *)v8,
                          this,
                          v7,
                          1);
    vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v10,
      &thread_local_data->to_create_resource.m_size,
      query,
      v11);
  }
}
