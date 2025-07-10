void __thiscall vostok::resources::queries_result::translate_request_paths(
        vostok::resources::queries_result *this,
        vostok::resources::queries_result *thisa)
{
  unsigned int v2; // edi
  vostok::resources::class_id_enum *p_m_class_id; // esi

  v2 = 0;
  if ( thisa->m_size )
  {
    p_m_class_id = &thisa->m_queries[0].m_class_id;
    do
    {
      if ( !*((_DWORD *)p_m_class_id + 19)
        && !*((_DWORD *)p_m_class_id + 20)
        && *p_m_class_id != fs_iterator_class
        && *p_m_class_id != fs_iterator_recursive_class )
      {
        vostok::resources::query_result::translate_request_path(0, (int)(p_m_class_id - 33));
      }
      ++v2;
      p_m_class_id += 180;
    }
    while ( v2 < thisa->m_size );
  }
}
