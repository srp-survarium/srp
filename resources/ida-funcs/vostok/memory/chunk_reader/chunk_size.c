unsigned int __thiscall vostok::memory::chunk_reader::chunk_size(
        vostok::memory::chunk_reader *this,
        vostok::memory::chunk_reader *chunk_id,
        vostok::memory::chunk_reader::chunk_type *type,
        unsigned int *a4)
{
  const unsigned __int8 *m_pointer; // esi
  vostok::memory::chunk_reader *v7; // [esp+14h] [ebp+8h]

  chunk_id->m_reader.m_pointer = &chunk_id->m_reader.m_data[vostok::memory::chunk_reader::chunk_position(
                                                              chunk_id,
                                                              (vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader>::predicate)type)];
  chunk_id->m_reader.m_pointer += 4;
  m_pointer = chunk_id->m_reader.m_pointer;
  v7 = *(vostok::memory::chunk_reader **)m_pointer;
  chunk_id->m_reader.m_pointer = m_pointer + 4;
  *a4 = (unsigned int)v7 >> 30;
  return (unsigned int)v7 & 0x3FFFFFFF;
}
