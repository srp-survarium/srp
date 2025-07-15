void __thiscall vostok::memory::chunk_reader::construct(vostok::memory::chunk_reader *this)
{
  vostok::memory::chunk_reader::chunk_type m_type; // eax

  m_type = this->m_type;
  if ( m_type )
  {
    if ( m_type == chunk_type_array )
      vostok::memory::array_chunk_reader<vostok::memory::chunk_reader>::construct((vostok::memory::array_chunk_reader<vostok::memory::chunk_reader> *)&this->gap0 + 1);
    else
      vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader>::construct(
        (vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader> *)this,
        (int)(&this->gap0 + 2));
  }
  else
  {
    this->m_last_position = 0;
  }
}
