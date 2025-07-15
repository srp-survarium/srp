void __thiscall survarium::match_total_stats::deserialize(
        survarium::match_total_stats *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *a3)
{
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v5; // esi
  const unsigned __int8 *v6; // esi
  const unsigned __int8 *v7; // esi
  const unsigned __int8 *v8; // esi
  vostok::network_core::buffer_reader *v9; // ecx
  vostok::network_core::buffer_reader *v10; // ecx
  vostok::network_core::buffer_reader *v11; // ecx
  const unsigned __int8 *v12; // eax
  const unsigned __int8 *v13; // [esp+14h] [ebp+8h]
  unsigned int v14; // [esp+14h] [ebp+8h]

  m_pointer = a3->m_pointer;
  v13 = *(const unsigned __int8 **)m_pointer;
  a3->m_pointer = m_pointer + 4;
  reader[23].m_pointer = v13;
  v5 = a3->m_pointer;
  HIBYTE(v13) = *v5;
  a3->m_pointer = v5 + 1;
  LOBYTE(reader->m_buffer) = HIBYTE(v13);
  v6 = a3->m_pointer;
  HIBYTE(v13) = *v6;
  a3->m_pointer = v6 + 1;
  BYTE1(reader->m_buffer) = HIBYTE(v13);
  v7 = a3->m_pointer;
  HIBYTE(v13) = *v7;
  a3->m_pointer = v7 + 1;
  BYTE2(reader->m_buffer) = HIBYTE(v13);
  v8 = a3->m_pointer;
  HIBYTE(v13) = *v8;
  a3->m_pointer = v8 + 1;
  HIBYTE(reader->m_buffer) = HIBYTE(v13);
  vostok::network_core::buffer_reader::r_string(
    (vostok::network_core::buffer_reader *)&reader->m_pointer,
    (char *)a3,
    (unsigned __int8 *)&reader->m_pointer);
  LOWORD(reader[5].m_buffer_size) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  vostok::network_core::buffer_reader::r_string(v9, (char *)a3, (unsigned __int8 *)&reader[5].m_buffer_size + 2);
  HIBYTE(v13) = *a3->m_pointer++;
  BYTE2(reader[11].m_buffer) = HIBYTE(v13);
  LOWORD(reader[11].m_pointer) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  vostok::network_core::buffer_reader::r_string(v10, (char *)a3, (unsigned __int8 *)&reader[11].m_pointer + 2);
  LOWORD(reader[17].m_buffer) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  HIWORD(reader[16].m_buffer_size) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  vostok::network_core::buffer_reader::r_string(v11, (char *)a3, (unsigned __int8 *)&reader[17].m_buffer + 2);
  HIWORD(reader[22].m_pointer) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  LOWORD(reader[22].m_buffer_size) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  HIWORD(reader[22].m_buffer_size) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  LOWORD(reader[23].m_buffer) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  HIWORD(reader[23].m_buffer) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  LOWORD(reader[24].m_buffer) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  HIWORD(reader[24].m_buffer) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  HIBYTE(v13) = *a3->m_pointer++;
  LOBYTE(reader[24].m_pointer) = HIBYTE(v13);
  HIWORD(reader[24].m_pointer) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  v12 = a3->m_pointer;
  v14 = *(_DWORD *)v12;
  a3->m_pointer = v12 + 4;
  reader[23].m_buffer_size = v14;
}
