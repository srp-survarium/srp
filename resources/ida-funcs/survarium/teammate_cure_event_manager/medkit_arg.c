unsigned __int8 __usercall survarium::teammate_cure_event_manager::medkit_arg@<al>(
        const survarium::medkit *medkit@<eax>,
        survarium::game_world_core *game_world_core@<ecx>,
        unsigned __int8 receiver)
{
  survarium::base_player *v4; // eax
  int *v5; // eax
  unsigned __int8 m_influences_count; // bl
  survarium::damage_model *m_influences; // ecx
  float *m_applied_influence; // esi
  int v10; // [esp+Ch] [ebp-Ch]
  survarium::damage_model *v11; // [esp+10h] [ebp-8h]
  unsigned __int8 v12; // [esp+17h] [ebp-1h]

  v4 = survarium::game_world_core::player(game_world_core, receiver);
  v5 = (int *)v4->damage_model(&v4->survarium::inventory_holder);
  m_influences_count = medkit->m_influences_count;
  v12 = 0;
  if ( !m_influences_count )
    return 0;
  m_influences = (survarium::damage_model *)medkit->m_influences;
  m_applied_influence = medkit->m_applied_influence;
  v11 = m_influences;
  v10 = *v5;
  while ( (float)(m_applied_influence[v12]
                / survarium::damage_model::get_body_part(m_influences, v10, (char *)v11 + 20 * v12)->m_max_health) < 0.5 )
  {
    if ( ++v12 == m_influences_count )
      return 0;
  }
  return 1;
}
