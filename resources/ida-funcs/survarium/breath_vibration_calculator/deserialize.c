void __userpurge survarium::breath_vibration_calculator::deserialize(
        vostok::network_core::buffer_reader *reader@<edx>,
        survarium::breath_vibration_calculator *this,
        vostok::network_core::buffer_reader *client_reader,
        const unsigned int time_offset)
{
  const unsigned __int8 *m_pointer; // esi
  float v6; // xmm0_4
  const unsigned __int8 *v7; // esi
  const unsigned __int8 *v8; // esi
  float v9; // xmm0_4
  const unsigned __int8 *v10; // esi
  float v11; // xmm0_4
  const unsigned __int8 *v12; // esi
  float v13; // xmm0_4
  const unsigned __int8 *v14; // esi
  const survarium::weapon_core *m_weapon; // eax
  vostok::ai::fsm_state *m_first; // ebx
  survarium::weapon_breath_vibration_params *p_m_breath_vibration_params; // eax
  vostok::math::float2 v18; // [esp+Ch] [ebp-8h]
  vostok::ai::fsm *v19; // [esp+1Ch] [ebp+8h]

  m_pointer = reader->m_pointer;
  v6 = *(float *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  this->m_phase_time = v6;
  v7 = reader->m_pointer;
  v18 = *(vostok::math::float2 *)v7;
  reader->m_pointer = v7 + 8;
  this->m_vibration = v18;
  v8 = reader->m_pointer;
  v9 = *(float *)v8;
  reader->m_pointer = v8 + 4;
  this->m_amplitude = v9;
  v10 = reader->m_pointer;
  v11 = *(float *)v10;
  reader->m_pointer = v10 + 4;
  this->m_breath_holding_reserve = v11;
  v12 = reader->m_pointer;
  v13 = *(float *)v12;
  reader->m_pointer = v12 + 4;
  this->m_speed_factor = v13;
  v14 = reader->m_pointer;
  v19 = *(vostok::ai::fsm **)v14;
  reader->m_pointer = v14 + 4;
  LODWORD(this->m_penalty_factor) = v19;
  vostok::ai::fsm::deserialize(&this->m_logic, reader, client_reader);
  m_weapon = this->m_weapon;
  m_first = this->m_logic.m_states.m_first;
  p_m_breath_vibration_params = &m_weapon->m_breath_vibration_params;
  while ( m_first )
  {
    m_first[1].transitions.m_size = (unsigned int)p_m_breath_vibration_params;
    m_first = m_first->next;
  }
}
