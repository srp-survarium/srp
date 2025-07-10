void __thiscall vostok::animation::mixing::n_ary_tree_transition_tree_constructor::remove_weight_synchronization_group(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *begin,
        vostok::animation::mixing::n_ary_tree_animation_node *end,
        vostok::animation::mixing::n_ary_tree_animation_node *enda)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v4; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *m_next_weight_animation; // esi
  vostok::animation::mixing::n_ary_tree_animation_node *i; // edi

  v4 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::remove_animation(
         begin,
         end,
         0,
         !end->m_is_transitting_to_zero);
  if ( v4 )
  {
    m_next_weight_animation = end->m_next_weight_animation;
    for ( i = v4->m_weight_synchronization_group_id != -1 ? v4 : 0;
          m_next_weight_animation != enda;
          m_next_weight_animation = m_next_weight_animation->m_next_weight_animation )
    {
      vostok::animation::mixing::n_ary_tree_transition_tree_constructor::remove_animation(
        begin,
        m_next_weight_animation,
        i,
        !end->m_is_transitting_to_zero);
    }
  }
}
