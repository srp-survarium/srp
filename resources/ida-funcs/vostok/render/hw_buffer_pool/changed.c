char __thiscall vostok::render::hw_buffer_pool::changed(vostok::render::hw_buffer_pool *this)
{
  vostok::render::hw_buffer_pool_chunk **m_begin; // eax
  vostok::render::hw_buffer_pool_chunk **m_end; // ecx

  m_begin = this->m_chunks.m_begin;
  m_end = this->m_chunks.m_end;
  while ( 1 )
  {
    if ( m_begin == m_end )
      return 0;
    if ( (*m_begin)->m_changed )
      break;
    ++m_begin;
  }
  return 1;
}
