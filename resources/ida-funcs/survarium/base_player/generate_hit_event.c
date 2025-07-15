void __userpurge survarium::base_player::generate_hit_event(
        const survarium::bullet *bullet@<eax>,
        survarium::game_world_core *m_current_active_object@<ecx>,
        survarium::base_player *this,
        unsigned int current_time_in_ms,
        int initiator_id,
        survarium::damage_model *victim_id,
        const float amount,
        const float pain_amount,
        int bullet_first_hit)
{
  survarium::base_player *v10; // edi
  survarium::player_stances_enum m_initiator_stance; // eax
  vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::node *v12; // ebx
  char v13; // al
  survarium::damage_model *v14; // ecx
  unsigned int m_id; // eax
  const vostok::math::float4x4 *v16; // eax
  survarium::statistics_events_handler *m_statistics_events_handler; // ecx
  survarium::statistics_events_handler *v18; // ecx
  survarium::profile_slot_enum m_slot_id; // [esp+2Ch] [ebp-8h]
  int v20; // [esp+30h] [ebp-4h]

  if ( (_BYTE)initiator_id == 0xFF )
    v10 = 0;
  else
    v10 = survarium::game_world_core::player(this->m_game_world_core, initiator_id);
  v20 = -1;
  if ( bullet )
  {
    m_initiator_stance = bullet->m_initiator_stance;
  }
  else
  {
    if ( !v10 )
      goto LABEL_11;
    m_current_active_object = (survarium::game_world_core *)v10->m_current_active_object;
    if ( !m_current_active_object )
      goto LABEL_11;
    m_initiator_stance = (*(int (__thiscall **)(survarium::game_world_core *))(m_current_active_object->m_game_events_history.m_items.m_size
                                                                             + 108))(m_current_active_object);
  }
  v20 = m_initiator_stance;
  if ( bullet )
  {
    m_slot_id = bullet->m_weapon->m_slot_id;
    goto LABEL_12;
  }
LABEL_11:
  m_slot_id = max_slots_count;
LABEL_12:
  if ( v10 )
  {
    v12 = survarium::game_world_core::new_game_statistic_event_history_item(
            m_current_active_object,
            (int)this->m_game_world_core,
            current_time_in_ms);
    v13 = 1;
    v12->data[0] = initiator_id;
    LOBYTE(v14) = (_BYTE)victim_id;
    v12->data[40] = 1;
    *(_DWORD *)&v12->data[24] = 2;
    v12->data[1] = (char)victim_id;
    if ( !bullet || bullet->m_damage <= 0.0 )
      v13 = 0;
    v12->data[2] = v13;
    if ( bullet )
      m_id = bullet->m_id;
    else
      m_id = -1;
    *(_DWORD *)&v12->data[4] = m_id;
    *(float *)&v12->data[8] = pain_amount
                            / survarium::damage_model::get_body_part(v14, (int)this->m_damage_model.m_object, "pain")->m_max_health;
    v16 = v10->transform(&v10->survarium::collision_user);
    *(float *)&v12->data[12] = v16->c.x;
    *(float *)&v12->data[16] = v16->c.y;
    *(float *)&v12->data[20] = v16->c.z;
    survarium::game_world_core::commit_game_statistic_event_history_item(
      this->m_game_world_core,
      (survarium::game_statistic_event_history_item *)v12);
    m_statistics_events_handler = this->m_game_world_core->m_statistics_events_handler;
    if ( m_statistics_events_handler && COERCE_FLOAT(LODWORD(pain_amount) & 0x7FFFFFFF) >= 0.000001 )
      ((void (__stdcall *)(int, survarium::damage_model *, _DWORD))m_statistics_events_handler->on_pain_body_part_damage_received)(
        initiator_id,
        victim_id,
        LODWORD(pain_amount));
  }
  v18 = this->m_game_world_core->m_statistics_events_handler;
  if ( v18 )
    ((void (__stdcall *)(unsigned int, int, int, survarium::damage_model *, _DWORD, survarium::profile_slot_enum, int))v18->on_player_damaged)(
      current_time_in_ms,
      initiator_id,
      v20,
      victim_id,
      LODWORD(amount),
      m_slot_id,
      bullet_first_hit);
}
