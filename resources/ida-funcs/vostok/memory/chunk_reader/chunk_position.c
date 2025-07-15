unsigned int __thiscall vostok::memory::chunk_reader::chunk_position(
        vostok::memory::chunk_reader *this,
        vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader>::predicate chunk_id)
{
  vostok::memory::chunk_reader::chunk_type m_type; // eax

  m_type = this->m_type;
  if ( m_type == chunk_type_sequential )
    return vostok::memory::sequential_chunk_reader<vostok::memory::chunk_reader>::chunk_position(
             this,
             chunk_id.m_chunk_id);
  if ( m_type == chunk_type_array )
    return vostok::memory::array_chunk_reader<vostok::memory::chunk_reader>::chunk_position(
             (vostok::memory::array_chunk_reader<vostok::memory::chunk_reader> *)&this->gap0 + 1,
             (unsigned int)(&this->gap0 + 1),
             chunk_id.m_chunk_id);
  return vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader>::chunk_position(
           (vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader> *)&this->gap0 + 2,
           (unsigned int)(&this->gap0 + 2),
           chunk_id);
}
