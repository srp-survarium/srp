unsigned int __usercall vostok::resources::query_result::translate_thread_id@<eax>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<esi>)
{
  vostok::resources::cook_base *cook; // eax
  unsigned int m_allocate_thread_id; // ecx
  unsigned int v4; // edx
  unsigned int result; // eax

  cook = vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  m_allocate_thread_id = cook->m_allocate_thread_id;
  if ( m_allocate_thread_id == -2 )
  {
    v4 = *(_DWORD *)&byte_203D8[(unsigned int)vostok::resources::g_resources_manager.m_variable];
  }
  else
  {
    if ( m_allocate_thread_id != -4 )
      goto LABEL_6;
    v4 = *(int *)((char *)&dword_203CC + (unsigned int)vostok::resources::g_resources_manager.m_variable);
  }
  cook->m_allocate_thread_id = v4;
LABEL_6:
  result = cook->m_allocate_thread_id;
  if ( result == -5 )
    return *(_DWORD *)(a2 + 700);
  return result;
}
