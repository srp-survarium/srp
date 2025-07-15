void __thiscall survarium::damage_model::deserialize(
        survarium::damage_model *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *time_offset,
        unsigned int time_offseta)
{
  const unsigned __int8 *m_pointer; // esi
  int v6; // ecx
  vostok::network_core::buffer_reader *v7; // eax
  const unsigned __int8 *v8; // esi
  unsigned int v9; // ecx
  const unsigned __int8 *v10; // esi
  survarium::body_part_parameters *m_buffer_size; // ecx
  survarium::body_part_parameters *next; // esi
  _DWORD *v13; // eax
  _DWORD *v14; // esi
  _DWORD *v15; // edi
  vostok::network_core::buffer_reader *readera; // [esp+18h] [ebp+Ch]
  vostok::network_core::buffer_reader *readerb; // [esp+18h] [ebp+Ch]
  vostok::network_core::buffer_reader *readerc; // [esp+18h] [ebp+Ch]

  m_pointer = time_offset->m_pointer;
  readera = *(vostok::network_core::buffer_reader **)m_pointer;
  time_offset->m_pointer = m_pointer + 4;
  if ( readera == (vostok::network_core::buffer_reader *)-1 )
    v6 = -1;
  else
    v6 = (int)readera + time_offseta;
  v7 = reader;
  reader[137].m_pointer = (const unsigned __int8 *)v6;
  v8 = time_offset->m_pointer;
  readerb = *(vostok::network_core::buffer_reader **)v8;
  time_offset->m_pointer = v8 + 4;
  if ( readerb == (vostok::network_core::buffer_reader *)-1 )
    v9 = -1;
  else
    v9 = (unsigned int)readerb + time_offseta;
  reader[137].m_buffer_size = v9;
  v10 = time_offset->m_pointer;
  readerc = *(vostok::network_core::buffer_reader **)v10;
  time_offset->m_pointer = v10 + 4;
  reader[138].m_buffer = (const unsigned __int8 *)readerc;
  m_buffer_size = (survarium::body_part_parameters *)reader[22].m_buffer_size;
  if ( m_buffer_size )
  {
    do
    {
      next = m_buffer_size->next;
      survarium::body_part_parameters::deserialize(m_buffer_size, time_offset, time_offseta);
      m_buffer_size = next;
    }
    while ( next );
    v7 = reader;
  }
  LOBYTE(v7[145].m_pointer) = 0;
  BYTE1(v7[145].m_pointer) = 0;
  v13 = (_DWORD *)v7[22].m_buffer_size;
  if ( v13 )
  {
    v14 = v13;
    do
    {
      v15 = (_DWORD *)*v14;
      if ( survarium::body_part_parameters::is_affect_applied(m_buffer_size, (int)v14, affects_type_leg_damage) )
      {
        ++LOBYTE(reader[145].m_pointer);
      }
      else if ( survarium::body_part_parameters::is_affect_applied(m_buffer_size, (int)v14, affects_type_hand_damage) )
      {
        ++BYTE1(reader[145].m_pointer);
      }
      v14 = v15;
    }
    while ( v15 );
  }
}
