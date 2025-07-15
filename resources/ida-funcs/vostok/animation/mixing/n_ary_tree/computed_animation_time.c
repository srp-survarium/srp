double __userpurge vostok::animation::mixing::n_ary_tree::computed_animation_time@<st0>(
        vostok::animation::mixing::n_ary_tree_animation_node *animation@<ecx>,
        unsigned int target_time_in_ms@<edx>,
        vostok::animation::mixing::n_ary_tree *this,
        unsigned int animation_time_before_scale_starts,
        unsigned int time_scale_start_time_in_ms,
        float current_time_in_ms,
        const float time_scale)
{
  if ( animation->m_time_calculator.m_Closure.m_pthis || animation->m_time_calculator.m_Closure.m_pFunction )
    return fastdelegate::FastDelegate6<float,float,unsigned int,unsigned int,unsigned int,float,float>::operator()(
             (fastdelegate::FastDelegate6<float,float,unsigned int,unsigned int,unsigned int,float,float> *)animation->m_animation_intervals,
             (int)&animation->m_time_calculator,
             animation->m_animation_intervals->m_length,
             *(float *)&this,
             animation_time_before_scale_starts,
             time_scale_start_time_in_ms,
             target_time_in_ms,
             current_time_in_ms);
  else
    return (double)(target_time_in_ms - animation_time_before_scale_starts) * current_time_in_ms * 0.001
         + *(float *)&this;
}
