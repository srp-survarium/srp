survarium::game_effect_time *__thiscall survarium::damage_zone_core::effect_calculator(
        survarium::damage_zone_core *this,
        survarium::game_effect_time *result,
        const survarium::base_player *player,
        const survarium::game_effect_node *effect_node,
        unsigned int current_time_in_ms,
        unsigned int target_time_in_ms)
{
  float v6; // xmm0_4
  unsigned int intervals_count; // edx
  float *p_length; // eax
  survarium::game_effect_time *v9; // eax
  unsigned int v10; // edx
  float v11; // xmm0_4
  unsigned int v12; // ecx
  survarium::game_effect_interval *i; // esi
  survarium::game_effect_interval *intervals; // edx
  float v15; // [esp+0h] [ebp-4h]

  v6 = 0.0;
  intervals_count = effect_node->intervals_count;
  v15 = 0.0;
  if ( intervals_count )
  {
    p_length = &effect_node->intervals->description.length;
    do
    {
      v6 = *p_length + v15;
      p_length += 4;
      --intervals_count;
      v15 = v6;
    }
    while ( intervals_count );
  }
  survarium::damage_zone_core::effect_intensity(this, (int)this, player);
  v9 = result;
  v10 = effect_node->intervals_count;
  result->interval_id = 0;
  v11 = v6 * v15;
  v12 = 0;
  result->interval_time = 0.0;
  result->effect_ended = 0;
  if ( v10 )
  {
    for ( i = effect_node->intervals; (float)(i->description.length + i->description.start_time) < v11; ++i )
    {
      if ( ++v12 >= v10 )
        return v9;
    }
    intervals = effect_node->intervals;
    result->interval_id = v12;
    result->interval_time = v11 - intervals[v12].description.start_time;
  }
  return v9;
}
