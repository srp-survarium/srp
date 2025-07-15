survarium::game_effect_time *__thiscall survarium::body_part_parameters::effect_calculator(
        survarium::body_part_parameters *this,
        survarium::game_effect_time *result,
        const survarium::game_effect_node *effect_node,
        unsigned int current_time_in_ms,
        unsigned int target_time_in_ms)
{
  unsigned int intervals_count; // esi
  float v6; // xmm4_4
  float *p_length; // eax
  unsigned int v8; // edi
  float v9; // xmm0_4
  survarium::game_effect_time *v10; // eax
  float m_health; // xmm2_4
  float m_max_health; // xmm3_4
  float v13; // xmm0_4
  unsigned int v14; // ecx
  float v15; // xmm0_4
  survarium::game_effect_interval *intervals; // edi
  survarium::game_effect_interval *v17; // edx

  intervals_count = effect_node->intervals_count;
  v6 = 0.0;
  if ( intervals_count )
  {
    p_length = &effect_node->intervals->description.length;
    v8 = effect_node->intervals_count;
    do
    {
      v9 = *p_length;
      p_length += 4;
      --v8;
      v6 = v9 + v6;
    }
    while ( v8 );
  }
  v10 = result;
  m_health = this->m_health;
  m_max_health = this->m_max_health;
  v13 = s_bm_current_air_resistance;
  result->interval_id = 0;
  v14 = 0;
  v15 = (float)(v13 - (float)(m_health / m_max_health)) * v6;
  result->interval_time = 0.0;
  result->effect_ended = 0;
  if ( intervals_count )
  {
    intervals = effect_node->intervals;
    while ( (float)(intervals->description.length + intervals->description.start_time) < v15 )
    {
      ++v14;
      ++intervals;
      if ( v14 >= intervals_count )
        goto LABEL_10;
    }
    v17 = effect_node->intervals;
    result->interval_id = v14;
    result->interval_time = v15 - v17[v14].description.start_time;
  }
LABEL_10:
  result->effect_ended = m_health >= m_max_health;
  return v10;
}
