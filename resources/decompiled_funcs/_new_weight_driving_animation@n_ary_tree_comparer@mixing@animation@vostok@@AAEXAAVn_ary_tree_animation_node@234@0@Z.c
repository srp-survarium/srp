void __userpurge vostok::animation::mixing::n_ary_tree_comparer::new_weight_driving_animation(
        vostok::animation::mixing::n_ary_tree_comparer *this@<edi>,
        vostok::animation::mixing::n_ary_tree_animation_node *new_weight_driving_animation@<esi>,
        vostok::animation::mixing::n_ary_tree_animation_node *new_driving_animation_in_previous_target)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v3; // ebp
  bool v4; // al
  vostok::animation::mixing::animation_state *m_animation_state; // ecx
  vostok::animation::mixing::animation_state *v6; // eax
  bool v7; // al
  vostok::animation::mixing::n_ary_tree_comparer *v8; // ecx
  vostok::animation::interpolator_comparer interpolator_comparer; // [esp+8h] [ebp-10h] BYREF
  unsigned int operands_offset; // [esp+Ch] [ebp-Ch] BYREF
  int v11; // [esp+10h] [ebp-8h] BYREF
  vostok::animation::mixing::n_ary_tree_animation_node *v12; // [esp+14h] [ebp-4h]

  v3 = new_driving_animation_in_previous_target;
  if ( new_driving_animation_in_previous_target->m_weight_driving_animation )
    this->m_equal = 0;
  if ( new_weight_driving_animation->m_override_existing_animation
    && new_weight_driving_animation->m_animation_state->animation_time != v3->m_animation_state->animation_time )
  {
    this->m_equal = 0;
  }
  v3->m_weight_interpolator->accept(
    v3->m_weight_interpolator,
    &interpolator_comparer,
    new_weight_driving_animation->m_weight_interpolator);
  v4 = this->m_equal && interpolator_comparer.result == equal;
  this->m_equal = v4;
  if ( new_weight_driving_animation->m_override_existing_animation )
  {
    v7 = 0;
    if ( v4 )
    {
      m_animation_state = v3->m_animation_state;
      v6 = new_weight_driving_animation->m_animation_state;
      if ( m_animation_state->animation_interval_id == v6->animation_interval_id
        && m_animation_state->animation_interval_time == v6->animation_interval_time )
      {
        v7 = 1;
      }
    }
    this->m_equal = v7;
  }
  vostok::animation::mixing::computed_operands_count(v3, (vostok::animation::mixing::n_ary_tree_animation_node *)&v11);
  new_driving_animation_in_previous_target = v12;
  vostok::animation::mixing::n_ary_tree_comparer::new_animation(
    &operands_offset,
    (vostok::animation::mixing::n_ary_tree_comparer *)v12,
    this,
    new_weight_driving_animation,
    (unsigned int *)&new_driving_animation_in_previous_target);
  v8 = (vostok::animation::mixing::n_ary_tree_comparer *)(4 * ((_DWORD)new_driving_animation_in_previous_target + v11));
  this->m_needed_buffer_size += (unsigned int)v8;
  vostok::animation::mixing::n_ary_tree_comparer::add_operands(
    v8,
    this,
    v3,
    new_weight_driving_animation,
    operands_offset != 0);
}
