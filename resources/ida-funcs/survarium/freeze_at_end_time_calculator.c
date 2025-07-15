double __cdecl survarium::freeze_at_end_time_calculator(
        float animation_length,
        float animation_time_before_time_scale_starts,
        unsigned int time_scale_start_time_in_ms,
        unsigned int current_time_in_ms,
        unsigned int target_time_in_ms,
        float time_scale)
{
  return (double)(target_time_in_ms - time_scale_start_time_in_ms) * time_scale * 0.001
       + animation_time_before_time_scale_starts;
}
