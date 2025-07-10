void __fastcall vostok::resources::resources_manager::register_cook(int a1, vostok::resources::cook_base *cook)
{
  vostok::resources::cook_base **m_begin; // ecx
  vostok::resources::cook_base **m_end; // eax
  int v4; // ecx

  m_begin = s_cooks_registry.m_begin;
  m_end = s_cooks_registry.m_end;
  if ( s_cooks_registry.m_begin == s_cooks_registry.m_end )
  {
    v4 = 517;
    do
    {
      if ( m_end )
      {
        *m_end = 0;
        m_end = s_cooks_registry.m_end;
      }
      ++m_end;
      --v4;
      s_cooks_registry.m_end = m_end;
    }
    while ( v4 );
    m_begin = s_cooks_registry.m_begin;
  }
  m_begin[cook->m_class_id] = cook;
}
