double __userpurge vostok::animation::mixing::n_ary_tree::computed_animation_time@<st0>(
        vostok::animation::mixing::n_ary_tree_animation_node *animation@<esi>,
        unsigned int target_time_in_ms@<eax>,
        vostok::animation::mixing::n_ary_tree *this,
        const float animation_time_before_scale_starts,
        unsigned int time_scale_start_time_in_ms,
        float current_time_in_ms,
        const float time_scale)
{
  double result; // st7
  float v9; // [esp+0h] [ebp-20h]

  if ( !animation->m_time_calculator.m_Closure.m_pthis && !animation->m_time_calculator.m_Closure.m_pFunction )
    return (double)(target_time_in_ms - LODWORD(animation_time_before_scale_starts)) * current_time_in_ms * 0.001
         + *(float *)&this;
  result = vostok::animation::mixing::animation_interval::length(animation->m_animation_intervals);
  v9 = result;
  ((void (__stdcall *)(_DWORD, vostok::animation::mixing::n_ary_tree *, _DWORD, unsigned int, unsigned int, _DWORD))animation->m_time_calculator.m_Closure.m_pFunction)(
    LODWORD(v9),
    this,
    LODWORD(animation_time_before_scale_starts),
    time_scale_start_time_in_ms,
    target_time_in_ms,
    LODWORD(current_time_in_ms));
  return result;
}
