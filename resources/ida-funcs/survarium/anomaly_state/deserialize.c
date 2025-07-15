void __userpurge survarium::anomaly_state::deserialize(
        survarium::anomaly_state *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::network_core::buffer_reader *reader,
        unsigned int time_offset)
{
  const unsigned __int8 *m_pointer; // esi
  survarium::zone_group **v6; // edi
  survarium::zone_group **v7; // esi
  vostok::network_core::buffer_reader *readera; // [esp+14h] [ebp+8h]

  m_pointer = reader->m_pointer;
  readera = *(vostok::network_core::buffer_reader **)m_pointer;
  reader->m_pointer = m_pointer + 4;
  v6 = (survarium::zone_group **)a2[8];
  v7 = (survarium::zone_group **)a2[7];
  a2[11] = readera != 0 ? (char *)readera + time_offset : 0;
  while ( v7 != v6 )
    survarium::zone_group::deserialize(*v7++, reader, time_offset);
}
