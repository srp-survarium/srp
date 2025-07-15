void __thiscall vostok::resources::queries_result::~queries_result(
        vostok::resources::queries_result *this,
        vostok::resources::queries_result *thisa)
{
  unsigned int v2; // edi
  vostok::resources::query_result *m_queries; // esi
  unsigned int m_size; // eax
  volatile int *p_m_pending_queries_count; // ecx
  boost::detail::function::vtable_base *vtable; // eax
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  v2 = 0;
  if ( thisa->m_size )
  {
    m_queries = thisa->m_queries;
    do
    {
      ((void (__thiscall *)(vostok::resources::query_result *, _DWORD))m_queries->~vostok::resources::query_result_for_cook)(
        m_queries,
        0);
      ++v2;
      ++m_queries;
    }
    while ( v2 < thisa->m_size );
  }
  m_size = thisa->m_size;
  if ( m_size )
  {
    p_m_pending_queries_count = &vostok::resources::g_resources_manager.m_variable->m_pending_queries_count;
    do
    {
      _InterlockedExchangeAdd(p_m_pending_queries_count, 0xFFFFFFFF);
      --m_size;
    }
    while ( m_size );
  }
  vtable = thisa->m_callback.vtable;
  if ( thisa->m_callback.vtable )
  {
    if ( ((unsigned __int8)vtable & 1) == 0 )
    {
      v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((unsigned int)vtable & 0xFFFFFFFE);
      if ( v7 )
        v7(&thisa->m_callback.functor, &thisa->m_callback.functor, 2);
    }
    thisa->m_callback.vtable = 0;
  }
}
