void __thiscall vostok::memory::writer::~writer(vostok::memory::writer *this)
{
  unsigned __int8 *m_data; // eax
  vostok::memory::base_allocator *m_allocator; // ecx

  this->__vftable = (vostok::memory::writer_vtbl *)&vostok::memory::writer::`vftable';
  this->m_file_size = 0;
  this->m_position = 0;
  this->m_mem_size = 0;
  if ( !this->external_data )
  {
    m_data = this->m_data;
    m_allocator = this->m_allocator;
    if ( m_data )
    {
      m_allocator->call_free(m_allocator, this->m_data);
      this->m_data = 0;
    }
  }
  this->__vftable = (vostok::memory::writer_vtbl *)&vostok::memory::writer_base::`vftable';
  if ( this->m_chunk_pos._M_impl._M_start )
    this->m_chunk_pos._M_impl._M_end_of_storage.m_allocator->call_free(
      this->m_chunk_pos._M_impl._M_end_of_storage.m_allocator,
      this->m_chunk_pos._M_impl._M_start);
}
