void __userpurge vostok::animation::mixing::n_ary_tree_comparer::remove_weight_synchronization_group(
        vostok::animation::mixing::n_ary_tree_comparer *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_comparer *a2@<eax>,
        vostok::animation::mixing::n_ary_tree_animation_node *begin,
        vostok::animation::mixing::n_ary_tree_animation_node *end)
{
  vostok::animation::mixing::n_ary_tree_animation_node *m_next_weight_animation; // ecx
  const vostok::animation::mixing::n_ary_tree_animation_node *v6; // esi
  vostok::animation::mixing::n_ary_tree_animation_node *v7; // [esp+Ch] [ebp-4h]

  if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))begin->m_weight_interpolator->transition_time)(begin->m_weight_interpolator) == 0.0 )
  {
    a2->m_equal = 0;
  }
  else
  {
    vostok::animation::mixing::n_ary_tree_comparer::remove_animation(a2, begin, 0, !begin->m_is_transitting_to_zero);
    m_next_weight_animation = begin->m_next_weight_animation;
    v6 = begin->m_weight_synchronization_group_id != -1 ? begin : 0;
    v7 = m_next_weight_animation;
    if ( m_next_weight_animation != end )
    {
      while ( 1 )
      {
        vostok::animation::mixing::n_ary_tree_comparer::remove_animation(
          a2,
          m_next_weight_animation,
          v6,
          !begin->m_is_transitting_to_zero);
        v7 = v7->m_next_weight_animation;
        if ( v7 == end )
          break;
        m_next_weight_animation = v7;
      }
    }
  }
}
