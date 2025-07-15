void __fastcall vostok::render::res_xs_hw<vostok::render::gs_data>::set_name(
        vostok::render::res_xs_hw<vostok::render::gs_data> *this,
        int a2)
{
  volatile signed __int32 *m_reference_count; // ecx
  volatile signed __int32 *v3; // eax
  volatile signed __int32 *v4; // ecx

  m_reference_count = (volatile signed __int32 *)this->m_reference_count;
  v3 = 0;
  if ( m_reference_count )
  {
    v3 = m_reference_count;
    _InterlockedExchangeAdd(m_reference_count, 1u);
  }
  v4 = *(volatile signed __int32 **)(a2 + 12156);
  *(_DWORD *)(a2 + 12156) = v3;
  if ( v4 )
  {
    if ( !_InterlockedExchangeAdd(v4, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        s_manager.m_variable,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
}


void __fastcall vostok::render::res_xs_hw<vostok::render::vs_data>::set_name(
        vostok::render::res_xs_hw<vostok::render::vs_data> *this,
        int a2)
{
  volatile signed __int32 *m_reference_count; // ecx
  volatile signed __int32 *v3; // eax
  volatile signed __int32 *v4; // ecx

  m_reference_count = (volatile signed __int32 *)this->m_reference_count;
  v3 = 0;
  if ( m_reference_count )
  {
    v3 = m_reference_count;
    _InterlockedExchangeAdd(m_reference_count, 1u);
  }
  v4 = *(volatile signed __int32 **)(a2 + 12160);
  *(_DWORD *)(a2 + 12160) = v3;
  if ( v4 )
  {
    if ( !_InterlockedExchangeAdd(v4, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        s_manager.m_variable,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
}
