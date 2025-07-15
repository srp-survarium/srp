void __thiscall survarium::inventory_item_descr::deserialize(
        survarium::inventory_item_descr *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *mode,
        int a4)
{
  unsigned __int16 v5; // ax
  vostok::network_core::buffer_reader *v6; // ecx
  const unsigned __int8 *m_pointer; // esi
  unsigned __int16 v8; // ax
  const unsigned __int8 *v9; // [esp+14h] [ebp+8h]
  vostok::network_core::buffer_reader *v10; // [esp+18h] [ebp+Ch]

  v5 = vostok::network_core::buffer_reader::r<unsigned short>(mode);
  v6 = reader;
  LOWORD(reader[1].m_buffer) = v5;
  m_pointer = mode->m_pointer;
  v10 = *(vostok::network_core::buffer_reader **)m_pointer;
  mode->m_pointer = m_pointer + 4;
  reader->m_buffer_size = (const unsigned int)v10;
  if ( a4 == 2 || !a4 )
  {
    v8 = vostok::network_core::buffer_reader::r<unsigned short>(mode);
    v6 = reader;
    reader->m_buffer = (const unsigned __int8 *)v8;
  }
  if ( a4 == 2 || a4 == 1 )
  {
    v9 = *(const unsigned __int8 **)mode->m_pointer;
    mode->m_pointer += 4;
    v6->m_pointer = v9;
  }
}
