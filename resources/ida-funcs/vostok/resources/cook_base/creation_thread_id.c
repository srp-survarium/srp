unsigned int __usercall vostok::resources::cook_base::creation_thread_id@<eax>(
        vostok::resources::cook_base *this@<ecx>,
        int a2@<eax>)
{
  int v2; // ecx
  volatile int m_cooker_thread_id; // ecx

  v2 = *(_DWORD *)(a2 + 16);
  if ( v2 == -2 )
  {
    m_cooker_thread_id = s_resources_manager_buffer.m_cooker_thread_id;
LABEL_5:
    *(_DWORD *)(a2 + 16) = m_cooker_thread_id;
    return *(_DWORD *)(a2 + 16);
  }
  if ( v2 == -4 )
  {
    m_cooker_thread_id = s_resources_manager_buffer.m_resources_thread_id;
    goto LABEL_5;
  }
  return *(_DWORD *)(a2 + 16);
}
