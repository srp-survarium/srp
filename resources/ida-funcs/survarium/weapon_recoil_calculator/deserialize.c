void __userpurge survarium::weapon_recoil_calculator::deserialize(
        survarium::weapon_recoil_calculator *this@<ecx>,
        vostok::network_core::buffer_reader *reader@<eax>,
        const unsigned int time_offset)
{
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v4; // esi
  float v5; // xmm0_4
  const unsigned __int8 *v6; // esi
  float v7; // xmm0_4
  const unsigned __int8 *v8; // esi
  float v9; // xmm0_4
  const unsigned __int8 *v10; // esi
  float v11; // xmm0_4
  const unsigned __int8 *v12; // esi
  float v13; // xmm0_4
  const unsigned __int8 *v14; // esi
  unsigned int v15; // ebx
  unsigned int v16; // edx
  const unsigned __int8 *v17; // esi
  unsigned int v18; // edx
  const unsigned __int8 *v19; // esi
  unsigned int v20; // [esp+Ch] [ebp-4h]
  int v21; // [esp+Ch] [ebp-4h]
  int v22; // [esp+Ch] [ebp-4h]
  int v23; // [esp+Ch] [ebp-4h]
  float v24; // [esp+18h] [ebp+8h]

  m_pointer = reader->m_pointer;
  v20 = *(_DWORD *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  this->m_random.m_seed = v20;
  v4 = reader->m_pointer;
  v5 = *(float *)v4;
  reader->m_pointer = v4 + 4;
  this->m_vertical_target = v5;
  v6 = reader->m_pointer;
  v7 = *(float *)v6;
  reader->m_pointer = v6 + 4;
  this->m_horizontal_target = v7;
  v8 = reader->m_pointer;
  v9 = *(float *)v8;
  reader->m_pointer = v8 + 4;
  this->m_back_target = v9;
  v10 = reader->m_pointer;
  v11 = *(float *)v10;
  reader->m_pointer = v10 + 4;
  this->m_vertical_value_at_last_shoot = v11;
  v12 = reader->m_pointer;
  v13 = *(float *)v12;
  reader->m_pointer = v12 + 4;
  this->m_horizontal_value_at_last_shoot = v13;
  v14 = reader->m_pointer;
  v21 = *(_DWORD *)v14;
  reader->m_pointer = v14 + 4;
  v15 = -1;
  if ( v21 == -1 )
    v16 = -1;
  else
    v16 = time_offset + v21;
  this->m_time_to_start_side_compensation = v16;
  v17 = reader->m_pointer;
  v22 = *(_DWORD *)v17;
  reader->m_pointer = v17 + 4;
  if ( v22 == -1 )
    v18 = -1;
  else
    v18 = time_offset + v22;
  this->m_time_to_start_back_compensation = v18;
  v19 = reader->m_pointer;
  v23 = *(_DWORD *)v19;
  reader->m_pointer = v19 + 4;
  if ( v23 != -1 )
    v15 = v23 + time_offset;
  this->m_time_of_last_shoot = v15;
  v24 = *(float *)reader->m_pointer;
  reader->m_pointer += 4;
  this->m_player_recoil_multiplier = v24;
}
