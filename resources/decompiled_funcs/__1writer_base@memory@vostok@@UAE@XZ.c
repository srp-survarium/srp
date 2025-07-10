void __thiscall vostok::memory::writer_base::~writer_base(vostok::memory::writer_base *this)
{
  unsigned int *M_start; // eax

  this->__vftable = (vostok::memory::writer_base_vtbl *)&vostok::memory::writer_base::`vftable';
  M_start = this->m_chunk_pos._M_impl._M_start;
  if ( M_start )
    this->m_chunk_pos._M_impl._M_end_of_storage.m_allocator->call_free(
      this->m_chunk_pos._M_impl._M_end_of_storage.m_allocator,
      M_start);
}
