vostok::memory::writer_base *__thiscall vostok::memory::writer_base::`scalar deleting destructor'(
        vostok::memory::writer_base *this,
        char a2)
{
  unsigned int *M_start; // eax

  this->__vftable = (vostok::memory::writer_base_vtbl *)&vostok::memory::writer_base::`vftable';
  M_start = this->m_chunk_pos._M_impl._M_start;
  if ( M_start )
    this->m_chunk_pos._M_impl._M_end_of_storage.m_allocator->call_free(
      this->m_chunk_pos._M_impl._M_end_of_storage.m_allocator,
      M_start);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
