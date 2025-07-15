survarium::game_effect_time *__userpurge survarium::default_game_effect_time_calculator::operator()@<eax>(
        const survarium::game_effect_node *node@<edx>,
        unsigned int *a2@<ecx>,
        survarium::default_game_effect_time_calculator *this,
        const unsigned int current_time_in_ms,
        const unsigned int target_time_in_ms)
{
  unsigned int current_interval_id; // eax
  survarium::game_effect_interval *intervals; // esi
  double v7; // st7
  unsigned int v8; // edx
  int v9; // eax
  float v10; // xmm0_4
  unsigned int v11; // eax
  bool v12; // cf
  double length; // st7

  current_interval_id = node->state.current_interval_id;
  *a2 = current_interval_id;
  intervals = node->intervals;
  *((_BYTE *)a2 + 8) = 0;
  v7 = (double)(current_time_in_ms - (unsigned int)this) * 0.001 + node->state.current_interval_time;
  *((float *)a2 + 1) = v7;
  if ( v7 >= intervals[current_interval_id].description.length )
  {
    v8 = node->intervals_count - 1;
    while ( 1 )
    {
      v9 = *a2;
      if ( *a2 == v8 )
        break;
      v10 = *((float *)a2 + 1) - intervals[v9].description.length;
      v11 = v9 + 1;
      *a2 = v11;
      v12 = v10 < intervals[v11].description.length;
      *((float *)a2 + 1) = v10;
      if ( v12 )
        return (survarium::game_effect_time *)a2;
    }
    length = intervals[v9].description.length;
    *((_BYTE *)a2 + 8) = 1;
    *((float *)a2 + 1) = length;
  }
  return (survarium::game_effect_time *)a2;
}
