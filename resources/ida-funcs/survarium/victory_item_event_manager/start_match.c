void __userpurge survarium::victory_item_event_manager::start_match(
        const survarium::match_options *options@<eax>,
        survarium::victory_item_event_manager *this,
        survarium::gather_victory_items_rule *rule)
{
  const survarium::victory_items_container_core *container_by_team; // eax
  int v4; // eax
  const survarium::victory_items_container_core *v5; // eax
  int v6; // esi
  survarium::victory_item_core *m_object; // ecx
  float *v8; // eax
  float x; // xmm0_4
  float y; // xmm3_4
  float z; // xmm7_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm5_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  survarium::victory_item_status *v17; // eax
  float v18; // xmm0_4
  unsigned __int8 v19; // [esp+Fh] [ebp-81h]
  vostok::math::float4x4 v20; // [esp+10h] [ebp-80h] BYREF
  vostok::math::float4x4 v21; // [esp+50h] [ebp-40h] BYREF

  this->m_game_rule = rule;
  this->m_match_options = options;
  container_by_team = survarium::gather_victory_items_rule::get_container_by_team(rule, team_1);
  v4 = (int)&container_by_team->get_transform(container_by_team, &v21)->c.0;
  *(_QWORD *)&this->m_container_positions[0].x = *(_QWORD *)v4;
  this->m_container_positions[0].z = *(float *)(v4 + 8);
  v5 = survarium::gather_victory_items_rule::get_container_by_team(rule, team_2);
  this->m_container_positions[1] = *(vostok::math::float3 *)&v5->get_transform(v5, &v20)->lines[3].x;
  v19 = 0;
  while ( v19 < this->m_match_options->victory_items_count )
  {
    v6 = v19;
    m_object = rule->m_victory_items._M_impl._M_start[v19].m_object;
    v8 = (float *)m_object->get_transform(&m_object->survarium::interactive_object, &v20);
    ++v19;
    x = this->m_container_positions[0].x;
    y = this->m_container_positions[0].y;
    z = this->m_container_positions[0].z;
    v12 = this->m_container_positions[1].x - x;
    v13 = this->m_container_positions[1].y - y;
    v14 = v8[13] - y;
    v15 = this->m_container_positions[1].z - z;
    v16 = (float)((float)(v12 * (float)(v8[12] - x)) + (float)(v13 * v14)) + (float)(v15 * (float)(v8[14] - z));
    v17 = &this->m_victory_items.elems[v6];
    v18 = v16 / (float)((float)((float)(v15 * v15) + (float)(v13 * v13)) + (float)(v12 * v12));
    v17->nearest_positions[0] = v18;
    v17->nearest_positions[1] = v18;
  }
}
