void __thiscall vostok::animation::legs_ik_solver::deserialize(
        vostok::animation::legs_ik_solver *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *time_offset,
        unsigned int a4)
{
  const unsigned __int8 *m_pointer; // esi
  int v6; // eax
  int v7; // ecx
  int v9; // ecx
  const unsigned __int8 *v10; // esi
  unsigned int v11; // ecx
  const unsigned __int8 *v12; // esi
  const unsigned __int8 *v13; // esi
  double v14; // st7
  unsigned int m_buffer_size; // eax
  int v16; // [esp+14h] [ebp+8h]
  int v17; // [esp+14h] [ebp+8h]
  int v18; // [esp+18h] [ebp+Ch]
  const unsigned __int8 *v19; // [esp+1Ch] [ebp+10h]
  unsigned int v20; // [esp+1Ch] [ebp+10h]

  m_pointer = time_offset->m_pointer;
  v16 = *(_DWORD *)m_pointer;
  time_offset->m_pointer = m_pointer + 4;
  if ( v16 == -1 )
    v6 = -1;
  else
    v6 = a4 + v16;
  reader->m_pointer = (const unsigned __int8 *)v6;
  vostok::animation::legs_ik_solver::leg_params::deserialize(
    (int)time_offset,
    a4,
    (vostok::animation::legs_ik_solver::leg_params *)&reader[1].m_pointer,
    time_offset);
  vostok::animation::legs_ik_solver::leg_params::deserialize(
    v7,
    a4,
    (vostok::animation::legs_ik_solver::leg_params *)&reader[5].m_pointer,
    time_offset);
  v17 = *(_DWORD *)time_offset->m_pointer;
  time_offset->m_pointer += 4;
  if ( v17 == -1 )
    v9 = -1;
  else
    v9 = a4 + v17;
  reader[9].m_pointer = (const unsigned __int8 *)v9;
  v10 = time_offset->m_pointer;
  v18 = *(_DWORD *)v10;
  time_offset->m_pointer = v10 + 4;
  if ( v18 == -1 )
    v11 = -1;
  else
    v11 = a4 + v18;
  reader[9].m_buffer_size = v11;
  v12 = time_offset->m_pointer;
  v19 = *(const unsigned __int8 **)v12;
  time_offset->m_pointer = v12 + 4;
  reader[10].m_pointer = v19;
  v13 = time_offset->m_pointer;
  v20 = *(_DWORD *)v13;
  time_offset->m_pointer = v13 + 4;
  v14 = (double)(unsigned int)reader[10].m_pointer;
  reader[10].m_buffer_size = v20;
  *(float *)&reader[11].m_buffer_size = FLOAT_0_0049999999;
  *(float *)&reader[11].m_pointer = v14 * 0.001;
  m_buffer_size = reader[10].m_buffer_size;
  *(float *)&reader[12].m_buffer_size = FLOAT_0_0049999999;
  *(float *)&reader[12].m_pointer = 0.001 * (double)m_buffer_size;
}
