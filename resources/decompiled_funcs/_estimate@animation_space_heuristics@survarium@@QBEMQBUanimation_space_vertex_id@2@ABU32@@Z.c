void __usercall survarium::animation_space_heuristics::estimate(
        survarium::animation_space_heuristics *this@<esi>,
        const survarium::animation_space_vertex_id *neighbour_vertex_id@<edi>)
{
  const survarium::animation_space_vertex_id *m_target_vertex_id; // eax
  float v3; // xmm2_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  long double v6; // st7
  float result; // [esp+4h] [ebp-4h]

  m_target_vertex_id = this->m_target_vertex_id;
  v3 = neighbour_vertex_id->translation.z - m_target_vertex_id->translation.z;
  v4 = neighbour_vertex_id->translation.x - m_target_vertex_id->translation.x;
  v5 = neighbour_vertex_id->translation.y - m_target_vertex_id->translation.y;
  v6 = sqrtf((float)((float)(v3 * v3) + (float)(v4 * v4)) + (float)(v5 * v5)) / (float)this->m_max_speed;
  if ( this->m_min_heuristics_value > v6 )
  {
    result = v6;
    this->m_min_heuristics_value = result;
    this->m_best_vertex_id = *neighbour_vertex_id;
  }
}
