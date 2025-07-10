void __userpurge vostok::resources::query_result::finish_normal_query(
        vostok::resources::query_result *this@<ecx>,
        vostok::resources::query_result *a2@<eax>,
        vostok::resources::cook_base::result_enum create_resource_result)
{
  volatile int m_flags; // ecx
  vostok::resources::resources_manager *m_variable; // ebx
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v6; // ecx
  vostok::resources::query_result *v7; // ecx
  bool *v8; // [esp+0h] [ebp-10h]

  if ( create_resource_result != result_postponed )
    vostok::threading::interlocked_or(&a2->m_flags, (unsigned int)&loc_1FFFFE + 2);
  vostok::resources::query_result::set_deleter_object_if_needed(0, (int)a2);
  m_flags = a2->m_flags;
  if ( (m_flags & 0x100000) == 0 )
  {
    if ( a2->m_save_generated_data )
    {
      vostok::threading::interlocked_and(&a2->m_flags, 0xFFDFFFFF);
      m_variable = vostok::resources::g_resources_manager.m_variable;
      vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        v6,
        (char *)&loc_2044D + (unsigned int)vostok::resources::g_resources_manager.m_variable + 3,
        a2,
        v8);
      SetEvent(*(HANDLE *)((char *)&dword_203D0 + (_DWORD)m_variable));
    }
    else
    {
      vostok::resources::query_result::do_create_resource_end_part((vostok::resources::query_result *)m_flags, (int)a2);
      vostok::resources::query_result::try_push_created_resource_to_manager_might_destroy_this(v7);
    }
  }
}
