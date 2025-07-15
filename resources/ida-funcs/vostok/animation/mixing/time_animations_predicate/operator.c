bool __usercall vostok::animation::mixing::time_animations_predicate::operator()@<al>(
        const vostok::animation::mixing::n_ary_tree_animation_node *const left@<ecx>,
        const vostok::animation::mixing::n_ary_tree_animation_node *const right@<eax>)
{
  unsigned int m_time_synchronization_group_id; // edx
  unsigned int v3; // esi

  m_time_synchronization_group_id = left->m_time_synchronization_group_id;
  v3 = right->m_time_synchronization_group_id;
  if ( m_time_synchronization_group_id < v3 )
    return 1;
  if ( m_time_synchronization_group_id > v3 )
    return 0;
  if ( left->m_is_time_driving_animation )
  {
    if ( !right->m_is_time_driving_animation )
      return 1;
  }
  else if ( right->m_is_time_driving_animation )
  {
    return 0;
  }
  if ( !left->m_time_driving_animation )
  {
    if ( !right->m_time_driving_animation )
      return left < right;
    return 1;
  }
  if ( !right->m_time_driving_animation )
    return 0;
  return left < right;
}
