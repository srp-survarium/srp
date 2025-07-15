void __thiscall survarium::match_player_stats::deserialize(
        survarium::match_player_stats *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *a3)
{
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v5; // esi
  const unsigned __int8 *v6; // esi
  const unsigned __int8 *v7; // [esp+14h] [ebp+8h]

  m_pointer = a3->m_pointer;
  v7 = *(const unsigned __int8 **)m_pointer;
  a3->m_pointer = m_pointer + 4;
  reader[2].m_buffer = v7;
  LOWORD(reader->m_buffer) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  HIWORD(reader->m_buffer) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  LOWORD(reader->m_pointer) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  HIWORD(reader->m_pointer) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  LOWORD(reader->m_buffer_size) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  HIWORD(reader->m_buffer_size) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  LOWORD(reader[1].m_buffer) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  HIWORD(reader[1].m_buffer) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  LOWORD(reader[1].m_pointer) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  HIWORD(reader[1].m_pointer) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  LOWORD(reader[1].m_buffer_size) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  HIWORD(reader[1].m_buffer_size) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  v5 = a3->m_pointer;
  HIBYTE(v7) = *v5;
  a3->m_pointer = v5 + 1;
  LOBYTE(reader[2].m_pointer) = HIBYTE(v7);
  v6 = a3->m_pointer;
  HIBYTE(v7) = *v6;
  a3->m_pointer = v6 + 1;
  BYTE1(reader[2].m_pointer) = HIBYTE(v7);
  HIWORD(reader[2].m_pointer) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  LOWORD(reader[2].m_buffer_size) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
}
