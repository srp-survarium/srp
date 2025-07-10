bool __thiscall vostok::memory::chunk_reader::chunk_exists(vostok::memory::chunk_reader *this)
{
  vostok::memory::chunk_reader::chunk_type m_type; // eax

  m_type = this->m_type;
  if ( m_type == chunk_type_sequential )
    return vostok::memory::sequential_chunk_reader<vostok::memory::chunk_reader>::chunk_position(this, 0x58u) != -1;
  if ( m_type == chunk_type_array )
    return vostok::memory::array_chunk_reader<vostok::memory::chunk_reader>::chunk_position(
             (vostok::memory::array_chunk_reader<vostok::memory::chunk_reader> *)this,
             (int)(&this->gap0 + 1),
             0x58u) != -1;
  return vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader>::chunk_position(
           (vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader> *)this,
           (int)(&this->gap0 + 2),
           0x58u) != -1;
}
