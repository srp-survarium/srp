void __userpurge vostok::animation::mixing::n_ary_tree_comparer::remove_weight_synchronization_group(
        vostok::animation::mixing::n_ary_tree_comparer *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_comparer *a2@<eax>,
        vostok::animation::mixing::n_ary_tree_animation_node *begin,
        vostok::animation::mixing::n_ary_tree_animation_node *end)
{
  vostok::animation::mixing::n_ary_tree_animation_node *m_next_weight_animation; // esi
  const vostok::animation::mixing::n_ary_tree_animation_node *i; // ebx

  if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))begin->m_weight_interpolator->transition_time)(begin->m_weight_interpolator) == 0.0 )
  {
    a2->m_equal = 0;
  }
  else
  {
    vostok::animation::mixing::n_ary_tree_comparer::remove_animation(a2, begin, 0, !begin->m_is_transitting_to_zero);
    m_next_weight_animation = begin->m_next_weight_animation;
    for ( i = begin->m_weight_synchronization_group_id != -1 ? begin : 0;
          m_next_weight_animation != end;
          m_next_weight_animation = m_next_weight_animation->m_next_weight_animation )
    {
      vostok::animation::mixing::n_ary_tree_comparer::remove_animation(
        a2,
        m_next_weight_animation,
        i,
        !begin->m_is_transitting_to_zero);
    }
  }
}
