double __fastcall vostok::animation::mixing::n_ary_tree_animation_time_calculator::computed_animation_time(
        vostok::animation::mixing::n_ary_tree_animation_time_calculator *this,
        unsigned int target_time_in_ms,
        float animation_time_before_scale_starts,
        unsigned int time_scale_start_time_in_ms,
        unsigned int current_time_in_ms,
        float time_scale)
{
  if ( this->m_animation->m_time_calculator.m_Closure.m_pthis
    || this->m_animation->m_time_calculator.m_Closure.m_pFunction )
  {
    return fastdelegate::FastDelegate6<float,float,unsigned int,unsigned int,unsigned int,float,float>::operator()(
             (fastdelegate::FastDelegate6<float,float,unsigned int,unsigned int,unsigned int,float,float> *)this->m_animation->m_animation_intervals,
             (int)&this->m_animation->m_time_calculator,
             this->m_animation->m_animation_intervals->m_length,
             animation_time_before_scale_starts,
             time_scale_start_time_in_ms,
             current_time_in_ms,
             target_time_in_ms,
             time_scale);
  }
  else
  {
    return (double)(target_time_in_ms - time_scale_start_time_in_ms) * time_scale * 0.001
         + animation_time_before_scale_starts;
  }
}
