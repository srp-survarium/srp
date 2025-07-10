void __thiscall survarium::player::serialize_current_state(
        survarium::player *this,
        survarium::player *current_time_in_ms,
        unsigned int current_time_in_msa)
{
  survarium::client_player_history_item *v3; // eax

  v3 = survarium::circular_buffer<survarium::client_player_history_item>::new_item(
         (survarium::circular_buffer<survarium::client_player_history_item> *)this,
         (int *)((char *)&dword_10E1C + (_DWORD)current_time_in_ms));
  v3->time_in_ms = current_time_in_msa;
  v3->action.input.angular_velocity = current_time_in_ms->m_input.angular_velocity;
  v3->action.input.angular_acceleration = current_time_in_ms->m_input.angular_acceleration;
  v3->action.input.actions_mask = *(int *)((char *)&dword_10EE0 + (_DWORD)current_time_in_ms);
  qmemcpy(&v3->action.state, &byte_10D44[(_DWORD)current_time_in_ms], 0x40u);
  v3->action.state.look_pitch = current_time_in_ms->m_target.look_pitch;
  v3->action.weapon_state.slot_id = current_time_in_ms->m_inventory.m_object->m_active_slot;
}
