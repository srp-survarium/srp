void __thiscall survarium::game_statistics_handler::on_medkit_action(
        survarium::game_statistics_handler *this,
        const survarium::medkit *medkit,
        bool activated,
        unsigned __int8 inflictor)
{
  survarium::game_world_core *m_game_world_core; // ecx
  unsigned __int8 v6; // al
  survarium::curing_event_status *v7; // esi
  survarium::game_world_core *v8; // [esp-4h] [ebp-Ch]

  m_game_world_core = this->m_game_world_core;
  if ( activated )
  {
    v6 = survarium::teammate_cure_event_manager::medkit_arg(medkit, m_game_world_core, inflictor);
    m_game_world_core = v8;
  }
  else
  {
    v6 = 0;
  }
  v7 = &this->m_shared_statistics.m_teammate_cure_event_manager.m_curing_event_statuses.elems[inflictor];
  if ( activated )
  {
    ++v7->m_medkits_active;
  }
  else
  {
    if ( v6 )
      survarium::curing_event_status::on_event_conditions_are_met(
        (survarium::curing_event_status *)m_game_world_core,
        (int)&this->m_shared_statistics.m_teammate_cure_event_manager.m_curing_event_statuses.elems[inflictor]);
    if ( !--v7->m_medkits_active )
      v7->m_event_conditions_are_met = 0;
  }
}
