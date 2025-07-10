void __thiscall vostok::memory::writer::write(vostok::memory::writer *this, unsigned __int8 *ptr, unsigned int count)
{
  unsigned int v4; // ecx
  unsigned int m_mem_size; // eax
  unsigned int v6; // ecx
  unsigned __int8 *m_data; // eax
  vostok::memory::base_allocator *m_allocator; // ecx
  unsigned __int8 *v9; // eax
  unsigned int m_position; // eax

  v4 = count + this->m_position;
  m_mem_size = this->m_mem_size;
  if ( v4 > m_mem_size )
  {
    if ( !m_mem_size )
      this->m_mem_size = 128;
    if ( this->m_mem_size <= v4 )
    {
      do
      {
        v6 = 2 * this->m_mem_size;
        this->m_mem_size = v6;
      }
      while ( v6 <= count + this->m_position );
    }
    m_data = this->m_data;
    m_allocator = this->m_allocator;
    if ( m_data )
      v9 = (unsigned __int8 *)m_allocator->call_realloc(m_allocator, m_data, this->m_mem_size);
    else
      v9 = (unsigned __int8 *)m_allocator->call_malloc(m_allocator, this->m_mem_size);
    this->m_data = v9;
  }
  memcpy(&this->m_data[this->m_position], ptr, count);
  this->m_position += count;
  m_position = this->m_position;
  if ( m_position > this->m_file_size )
    this->m_file_size = m_position;
}
