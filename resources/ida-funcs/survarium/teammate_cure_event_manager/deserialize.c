void __thiscall survarium::teammate_cure_event_manager::deserialize(
        survarium::teammate_cure_event_manager *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *time_offset,
        int a4)
{
  const unsigned int *v4; // ebx
  const unsigned __int8 *m_pointer; // esi
  int v6; // [esp+Ch] [ebp-8h]
  unsigned __int8 i; // [esp+13h] [ebp-1h]

  for ( i = 0; i != *((_BYTE *)reader[69].m_pointer + 29772); ++i )
  {
    v4 = &reader[2].m_buffer_size + 10 * i;
    m_pointer = time_offset->m_pointer;
    v6 = *(_DWORD *)m_pointer;
    time_offset->m_pointer = m_pointer + 4;
    *((_DWORD *)&reader[5].m_pointer + 10 * i) = v6 != 0 ? a4 + v6 : 0;
    *((_WORD *)v4 + 18) = vostok::network_core::buffer_reader::r<unsigned short>(time_offset);
    *((_BYTE *)v4 + 38) = vostok::network_core::buffer_reader::r<bool>(time_offset);
  }
}
