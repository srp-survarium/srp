void __userpurge vostok::animation::mixing::n_ary_tree::update_animation_state(
        vostok::animation::mixing::n_ary_tree_animation_node *animation_node@<eax>,
        vostok::animation::mixing::n_ary_tree *this,
        unsigned int start_time_in_ms,
        unsigned int target_time_in_ms)
{
  vostok::animation::mixing::animation_state *m_animation_state; // esi
  bool v6; // zf
  vostok::animation::mixing::n_ary_tree_animation_node *m_time_driving_animation; // ecx
  unsigned int v8; // [esp+0h] [ebp-50h]
  float v9; // [esp+4h] [ebp-4Ch]
  unsigned int v10; // [esp+8h] [ebp-48h]
  vostok::animation::mixing::n_ary_tree_weight_calculator v11; // [esp+Ch] [ebp-44h] BYREF
  vostok::animation::mixing::n_ary_tree_animation_time_calculator v12; // [esp+30h] [ebp-20h] BYREF

  m_animation_state = animation_node->m_animation_state;
  vostok::animation::mixing::n_ary_tree_weight_calculator::n_ary_tree_weight_calculator(
    &v11,
    animation_node,
    start_time_in_ms);
  vostok::animation::mixing::n_ary_tree_weight_calculator::visit(&v11, animation_node);
  v6 = !m_animation_state->is_freezed;
  m_animation_state->weight = v11.m_weight;
  if ( v6 )
  {
    m_time_driving_animation = animation_node->m_time_driving_animation;
    if ( m_time_driving_animation )
      m_animation_state->animation_interval_time = (float)(animation_node->m_animation_intervals[m_animation_state->animation_interval_id].m_length
                                                         / m_time_driving_animation->m_animation_intervals[m_time_driving_animation->m_animation_state->animation_interval_id].m_length)
                                                 * m_time_driving_animation->m_animation_state->animation_interval_time;
    else
      m_animation_state->animation_interval_time = vostok::animation::mixing::n_ary_tree_animation_time_calculator::n_ary_tree_animation_time_calculator(
                                                     &v12,
                                                     start_time_in_ms,
                                                     animation_node,
                                                     m_animation_state->animation_interval_time,
                                                     (struct vostok::animation::mixing::n_ary_tree_animation_node *)this,
                                                     v8,
                                                     v9,
                                                     v10,
                                                     (bool)v11.__vftable)->m_animation_time;
    vostok::animation::mixing::n_ary_tree::update_animation_time(m_animation_state);
  }
}
