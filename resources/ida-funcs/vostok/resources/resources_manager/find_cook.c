vostok::resources::cook_base *__fastcall vostok::resources::resources_manager::find_cook(
        int a1,
        vostok::resources::class_id_enum resource_class)
{
  vostok::resources::cook_base **m_end; // eax
  int v3; // ecx

  m_end = s_cooks_registry.m_end;
  if ( s_cooks_registry.m_begin != s_cooks_registry.m_end )
    return s_cooks_registry.m_begin[resource_class];
  v3 = 517;
  do
  {
    if ( m_end )
    {
      *m_end = 0;
      m_end = s_cooks_registry.m_end;
    }
    ++m_end;
    --v3;
    s_cooks_registry.m_end = m_end;
  }
  while ( v3 );
  return s_cooks_registry.m_begin[resource_class];
}
