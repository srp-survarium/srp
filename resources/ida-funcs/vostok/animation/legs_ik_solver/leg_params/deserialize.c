void __fastcall vostok::animation::legs_ik_solver::leg_params::deserialize(
        int a1,
        const unsigned int time_offset,
        vostok::animation::legs_ik_solver::leg_params *this,
        vostok::network_core::buffer_reader *reader)
{
  const unsigned __int8 *m_pointer; // esi
  unsigned int v6; // ecx
  const unsigned __int8 *v7; // esi
  const unsigned __int8 *v8; // esi
  const unsigned __int8 *v9; // esi
  unsigned int v10; // ecx
  vostok::math::float3 v11; // [esp+Ch] [ebp-Ch]
  unsigned int v12; // [esp+24h] [ebp+Ch]
  int v13; // [esp+24h] [ebp+Ch]

  m_pointer = reader->m_pointer;
  v6 = *(_DWORD *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  this->heel_transition_time_in_ms = v6;
  v7 = reader->m_pointer;
  v12 = *(_DWORD *)v7;
  reader->m_pointer = v7 + 4;
  this->toe_transition_time_in_ms = v12;
  v8 = reader->m_pointer;
  v11.x = *(float *)v8;
  *(_QWORD *)&v11.elements[1] = *(_QWORD *)(v8 + 4);
  reader->m_pointer = v8 + 12;
  this->rotation_axis = v11;
  v9 = reader->m_pointer;
  v13 = *(_DWORD *)v9;
  reader->m_pointer = v9 + 4;
  if ( v13 == -1 )
    v10 = -1;
  else
    v10 = time_offset + v13;
  this->m_last_stance_time_in_ms = v10;
  this->m_heel_on_ground = vostok::network_core::buffer_reader::r<bool>(reader);
  this->m_toe_on_ground = vostok::network_core::buffer_reader::r<bool>(reader);
}
