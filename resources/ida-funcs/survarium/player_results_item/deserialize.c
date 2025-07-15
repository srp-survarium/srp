void __thiscall survarium::player_results_item::deserialize(
        survarium::player_results_item *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *a3)
{
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v5; // [esp+14h] [ebp+8h]

  vostok::network_core::buffer_reader::r_string(
    (vostok::network_core::buffer_reader *)this,
    (char *)a3,
    (unsigned __int8 *)reader);
  v5 = *(const unsigned __int8 **)a3->m_pointer;
  a3->m_pointer += 4;
  reader[5].m_pointer = v5;
  LOWORD(reader[5].m_buffer_size) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  LOWORD(reader[6].m_buffer) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  HIWORD(reader[6].m_buffer) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  m_pointer = a3->m_pointer;
  HIBYTE(v5) = *m_pointer;
  a3->m_pointer = m_pointer + 1;
  LOBYTE(reader[6].m_pointer) = HIBYTE(v5);
  HIWORD(reader[5].m_buffer_size) = vostok::network_core::buffer_reader::r<unsigned short>(a3);
}
