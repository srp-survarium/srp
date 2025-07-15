void __userpurge vostok::animation::mixing::n_ary_tree::update_animation_state(
        vostok::animation::mixing::n_ary_tree_animation_node *animation_node@<ecx>,
        unsigned int target_time_in_ms@<eax>,
        bool a3@<bl>,
        unsigned int a4@<ebp>,
        unsigned int a5@<edi>,
        float a6@<esi>,
        vostok::animation::mixing::n_ary_tree *this,
        const unsigned int start_time_in_ms)
{
  vostok::animation::mixing::animation_state *m_animation_state; // ebp
  vostok::animation::mixing::n_ary_tree_animation_node *m_time_driving_animation; // ecx
  vostok::animation::mixing::animation_state *v12; // esi
  vostok::animation::mixing::animation_interval *v13; // ebx
  vostok::animation::mixing::n_ary_tree_weight_calculator weight_calculator; // [esp+0h] [ebp-40h] BYREF
  vostok::animation::mixing::n_ary_tree_animation_time_calculator v18; // [esp+20h] [ebp-20h] BYREF
  float start_time_in_msa; // [esp+44h] [ebp+4h]

  m_animation_state = animation_node->m_animation_state;
  weight_calculator.__vftable = (vostok::animation::mixing::n_ary_tree_weight_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_calculator::`vftable';
  weight_calculator.m_animation = animation_node;
  weight_calculator.m_result = 0;
  weight_calculator.m_recursion_level = 0;
  weight_calculator.m_current_time_in_ms = target_time_in_ms;
  memset(&weight_calculator.m_weight, 0, 9);
  vostok::animation::mixing::n_ary_tree_weight_calculator::visit(&weight_calculator, animation_node);
  m_animation_state->weight = weight_calculator.m_weight;
  if ( !m_animation_state->is_freezed )
  {
    m_time_driving_animation = animation_node->m_time_driving_animation;
    if ( m_time_driving_animation )
    {
      v12 = m_time_driving_animation->m_animation_state;
      v13 = &m_time_driving_animation->m_animation_intervals[v12->animation_interval_id];
      start_time_in_msa = vostok::animation::mixing::animation_interval::length(&animation_node->m_animation_intervals[m_animation_state->animation_interval_id]);
      m_animation_state->animation_interval_time = start_time_in_msa
                                                 / vostok::animation::mixing::animation_interval::length(v13)
                                                 * v12->animation_interval_time;
    }
    else
    {
      m_animation_state->animation_interval_time = vostok::animation::mixing::n_ary_tree_animation_time_calculator::n_ary_tree_animation_time_calculator(
                                                     0,
                                                     target_time_in_ms,
                                                     animation_node,
                                                     &v18,
                                                     m_animation_state->animation_interval_time,
                                                     (struct vostok::animation::mixing::n_ary_tree_animation_node *)this,
                                                     a5,
                                                     a6,
                                                     a4,
                                                     a3)->m_animation_time;
    }
    vostok::animation::mixing::n_ary_tree::update_animation_time(m_animation_state);
  }
}
