void __userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_weight_synchronization_group(
        vostok::animation::mixing::n_ary_tree_animation_node *begin@<eax>,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *a2@<ecx>,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this,
        vostok::animation::mixing::n_ary_tree_animation_node *end)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v5; // eax
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v6; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *m_next_weight_animation; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *i; // esi

  v5 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation(a2, this, begin, 0);
  m_next_weight_animation = begin->m_next_weight_animation;
  for ( i = v5->m_weight_synchronization_group_id != -1 ? v5 : 0;
        m_next_weight_animation != end;
        m_next_weight_animation = m_next_weight_animation->m_next_weight_animation )
  {
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation(
      v6,
      this,
      m_next_weight_animation,
      i);
  }
}
