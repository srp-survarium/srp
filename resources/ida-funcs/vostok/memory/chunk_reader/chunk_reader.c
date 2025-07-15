void __userpurge vostok::memory::chunk_reader::chunk_reader(
        vostok::memory::chunk_reader *this@<esi>,
        const unsigned __int8 *data@<eax>,
        vostok::memory::chunk_reader *a3@<ecx>,
        unsigned int size,
        vostok::memory::chunk_reader::chunk_type type)
{
  this->m_reader.m_data = data;
  this->m_reader.m_pointer = data;
  this->m_reader.m_size = size;
  this->m_chunks = 0;
  this->m_chunk_count = 0;
  this->m_type = chunk_type_sequential;
  vostok::memory::chunk_reader::construct(a3);
}
