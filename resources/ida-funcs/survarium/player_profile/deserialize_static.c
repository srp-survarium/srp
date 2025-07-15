void __thiscall survarium::player_profile::deserialize_static(
        survarium::player_profile *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *readera)
{
  const unsigned __int8 *m_pointer; // esi
  vostok::network_core::buffer_reader *v5; // ecx
  survarium::player_profile *v6; // ecx
  const unsigned __int8 **p_m_pointer; // edx
  const unsigned __int8 *v8; // esi
  const unsigned __int8 *v9; // eax
  int v10; // ecx
  const unsigned __int8 *v11; // xmm0_4
  int v12; // [esp+18h] [ebp+8h]
  int readerb; // [esp+1Ch] [ebp+Ch]
  unsigned __int8 reader_3; // [esp+1Fh] [ebp+Fh]

  m_pointer = readera->m_pointer;
  reader_3 = *m_pointer;
  readera->m_pointer = m_pointer + 1;
  reader[36].m_buffer_size = reader_3;
  LOBYTE(reader[37].m_buffer) = vostok::network_core::buffer_reader::r<bool>(readera);
  vostok::network_core::buffer_reader::r_string(v5, (char *)readera, (unsigned __int8 *)&reader->m_buffer_size);
  survarium::player_profile::deserialize_slots(v6, reader, readera);
  p_m_pointer = &reader[37].m_pointer;
  memset(&reader[37].m_pointer, 0, 0x50u);
  v8 = readera->m_pointer;
  v12 = *(_DWORD *)v8;
  v9 = v8 + 4;
  readera->m_pointer = v8 + 4;
  v10 = 0;
  readerb = 20;
  do
  {
    if ( ((1 << v10) & v12) != 0 )
    {
      *(float *)&v11 = *(float *)&p_m_pointer[v10] + *(float *)v9;
      v9 += 4;
      readera->m_pointer = v9;
      p_m_pointer[v10] = v11;
    }
    ++v10;
    --readerb;
  }
  while ( readerb );
}
