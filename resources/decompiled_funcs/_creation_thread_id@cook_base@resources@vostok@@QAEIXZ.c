unsigned int __usercall vostok::resources::cook_base::creation_thread_id@<eax>(
        vostok::resources::cook_base *this@<ecx>,
        int a2@<eax>)
{
  int v2; // ecx
  int v3; // edx
  int v5; // edx

  v2 = *(_DWORD *)(a2 + 16);
  if ( v2 == -2 )
  {
    v3 = *(_DWORD *)&byte_203D8[(unsigned int)vostok::resources::g_resources_manager.m_variable];
    *(_DWORD *)(a2 + 16) = v3;
    return v3;
  }
  else if ( v2 == -4 )
  {
    v5 = *(int *)((char *)&dword_203CC + (unsigned int)vostok::resources::g_resources_manager.m_variable);
    *(_DWORD *)(a2 + 16) = v5;
    return v5;
  }
  else
  {
    return *(_DWORD *)(a2 + 16);
  }
}
