survarium::game_effect_time *__thiscall survarium::body_part_parameters::threshold_effect_calculator(
        survarium::body_part_parameters *this,
        survarium::game_effect_time *result,
        survarium::affects_threshold *threshold,
        const survarium::game_effect_node *effect_node,
        unsigned int current_time_in_ms,
        unsigned int target_time_in_ms)
{
  unsigned int current_interval_id; // edi
  float m_value; // xmm2_4
  float m_health; // xmm1_4
  float v10; // xmm0_4
  bool v11; // cl
  survarium::game_effect_interval *intervals; // eax
  float v13; // xmm1_4
  float v14; // xmm0_4
  bool v15; // cf
  float length; // xmm0_4
  float v18; // [esp+18h] [ebp+10h]

  current_interval_id = effect_node->state.current_interval_id;
  result->interval_id = current_interval_id;
  m_value = threshold->m_value;
  m_health = this->m_health;
  v10 = this->m_max_health * m_value;
  v18 = (double)(target_time_in_ms - current_time_in_ms) * 0.001 + effect_node->state.current_interval_time;
  result->effect_ended = 0;
  result->interval_time = v18;
  v11 = m_health >= v10 || m_value == 0.0 && m_health > 0.0;
  intervals = effect_node->intervals;
  if ( current_interval_id )
  {
    length = intervals[1].description.length;
    if ( v18 >= length )
    {
      result->interval_time = length;
      goto LABEL_14;
    }
  }
  else
  {
    v13 = intervals->description.length;
    if ( v18 >= v13 )
    {
      if ( v11 )
      {
        v14 = v18 - intervals->description.length;
        v15 = v14 < intervals[1].description.length;
        result->interval_id = 1;
        result->interval_time = v14;
        if ( !v15 )
        {
          result->interval_time = intervals[1].description.length;
LABEL_14:
          result->effect_ended = 1;
        }
      }
      else
      {
        result->interval_time = v13;
      }
    }
  }
  return result;
}
