void __thiscall survarium::network_client::send_local_player_input(
        survarium::network_client *this,
        const survarium::player_input *input,
        unsigned int time_in_ms,
        const vostok::math::float4x4 *transform,
        float look_pitch)
{
  survarium::client_player_update *m_end; // eax
  survarium::client_player_update *v7; // eax
  vostok::buffer_vector<survarium::client_player_update> v8; // [esp+10h] [ebp-64h] BYREF
  survarium::player_input v9; // [esp+18h] [ebp-5Ch] BYREF
  _BYTE v10[68]; // [esp+2Ch] [ebp-48h] BYREF
  unsigned int v11; // [esp+70h] [ebp-4h]

  if ( this->m_player_inputs.m_end - this->m_player_inputs.m_begin == 32 )
  {
    v8.m_end = this->m_player_inputs.m_begin;
    v8.m_begin = v8.m_end + 1;
    vostok::buffer_vector<survarium::client_player_update>::erase(&v8, &this->m_player_inputs, &v8.m_end, &v8.m_begin);
  }
  survarium::player_input::player_input(&v9);
  m_end = this->m_player_inputs.m_end;
  if ( m_end )
  {
    m_end->input = v9;
    qmemcpy(&m_end->state, v10, sizeof(m_end->state));
    m_end->time_in_ms = v11;
  }
  v7 = this->m_player_inputs.m_end++;
  v7->input = *input;
  qmemcpy(&v7->state, transform, 0x40u);
  v7->state.look_pitch = look_pitch;
  v7->time_in_ms = time_in_ms;
}
