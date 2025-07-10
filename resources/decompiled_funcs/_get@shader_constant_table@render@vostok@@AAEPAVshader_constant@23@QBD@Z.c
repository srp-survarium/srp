vostok::render::shader_constant *__userpurge vostok::render::shader_constant_table::get@<eax>(
        vostok::render::shader_constant_table *this@<ecx>,
        int a2@<eax>,
        const char *name)
{
  int v3; // esi
  int v4; // edi
  vostok::render::shader_constant_table *v5; // eax
  bool v6; // bl

  v3 = *(_DWORD *)(a2 + 4);
  v4 = *(_DWORD *)(a2 + 8);
  if ( v3 == v4 )
    return 0;
  while ( 1 )
  {
    v5 = (vostok::render::shader_constant_table *)vostok::strings::shared::manager::string(
                                                    (vostok::strings::shared::manager *)this,
                                                    (const char *)s_manager.m_variable);
    this = 0;
    if ( v5 )
    {
      this = v5;
      _InterlockedExchangeAdd((volatile signed __int32 *)v5, 1u);
    }
    v6 = *(_DWORD *)(*(_DWORD *)(v3 + 16) + 32) == (_DWORD)this;
    if ( this )
    {
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF) )
        vostok::strings::shared::manager::remove(
          s_manager.m_variable,
          (vostok::strings::shared::profile *)s_manager.m_variable);
    }
    if ( v6 )
      break;
    v3 += 24;
    if ( v3 == v4 )
      return 0;
  }
  return (vostok::render::shader_constant *)v3;
}
