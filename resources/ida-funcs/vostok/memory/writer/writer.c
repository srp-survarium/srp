void __usercall vostok::memory::writer::writer(
        vostok::memory::writer *this@<eax>,
        vostok::memory::base_allocator *allocator@<edx>)
{
  this->m_allocator = allocator;
  this->m_chunk_pos._M_impl._M_start = 0;
  this->m_chunk_pos._M_impl._M_finish = 0;
  this->m_chunk_pos._M_impl._M_end_of_storage.m_allocator = allocator;
  this->m_chunk_pos._M_impl._M_end_of_storage._M_data = 0;
  this->__vftable = (vostok::memory::writer_vtbl *)&vostok::memory::writer::`vftable';
  this->m_data = 0;
  this->m_position = 0;
  this->m_mem_size = 0;
  this->m_file_size = 0;
  this->external_data = 0;
}
