double __userpurge vostok::animation::mixing::n_ary_tree_animation_time_calculator::computed_animation_time@<st0>(
        vostok::animation::mixing::n_ary_tree_animation_time_calculator *this@<ecx>,
        unsigned int target_time_in_ms@<eax>,
        float animation_time_before_scale_starts,
        unsigned int time_scale_start_time_in_ms,
        unsigned int current_time_in_ms,
        float time_scale)
{
  double result; // st7
  vostok::animation::mixing::n_ary_tree_animation_node *m_animation; // esi
  float v9; // [esp+0h] [ebp-24h]

  if ( !this->m_animation->m_time_calculator.m_Closure.m_pthis
    && !this->m_animation->m_time_calculator.m_Closure.m_pFunction )
  {
    return (double)(target_time_in_ms - time_scale_start_time_in_ms) * time_scale * 0.001
         + animation_time_before_scale_starts;
  }
  m_animation = this->m_animation;
  result = vostok::animation::mixing::animation_interval::length(m_animation->m_animation_intervals);
  v9 = result;
  ((void (__stdcall *)(_DWORD, _DWORD, unsigned int, unsigned int, const unsigned int, _DWORD))m_animation->m_time_calculator.m_Closure.m_pFunction)(
    LODWORD(v9),
    LODWORD(animation_time_before_scale_starts),
    time_scale_start_time_in_ms,
    current_time_in_ms,
    target_time_in_ms,
    LODWORD(time_scale));
  return result;
}
