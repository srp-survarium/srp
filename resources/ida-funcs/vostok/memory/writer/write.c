void __thiscall vostok::memory::writer::write(vostok::memory::writer *this, unsigned __int8 *ptr, unsigned int count)
{
  unsigned int m_position; // eax
  unsigned int m_mem_size; // ecx
  unsigned int v6; // eax
  unsigned __int8 *m_data; // edx
  vostok::memory::base_allocator *m_allocator; // ecx
  unsigned int v9; // eax
  unsigned __int8 *v10; // eax
  unsigned int v11; // eax

  m_position = this->m_position;
  m_mem_size = this->m_mem_size;
  v6 = count + m_position;
  if ( v6 > m_mem_size )
  {
    if ( !m_mem_size )
      this->m_mem_size = 128;
    while ( this->m_mem_size <= v6 )
    {
      this->m_mem_size *= 2;
      v6 = count + this->m_position;
    }
    m_data = this->m_data;
    m_allocator = this->m_allocator;
    v9 = this->m_mem_size;
    if ( m_data )
      v10 = (unsigned __int8 *)m_allocator->call_realloc(
                                 m_allocator,
                                 m_data,
                                 v9,
                                 "memory_writer",
                                 "vostok::memory::writer::write",
                                 ".\\memory_writer.cpp",
                                 104u);
    else
      v10 = (unsigned __int8 *)m_allocator->call_malloc(
                                 m_allocator,
                                 v9,
                                 "memory_writer",
                                 "vostok::memory::writer::write",
                                 ".\\memory_writer.cpp",
                                 102u);
    this->m_data = v10;
  }
  memcpy(&this->m_data[this->m_position], ptr, count);
  this->m_position += count;
  v11 = this->m_position;
  if ( v11 > this->m_file_size )
    this->m_file_size = v11;
}
