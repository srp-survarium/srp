void __userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_weight_synchronization_group(
        vostok::animation::mixing::n_ary_tree_animation_node *begin@<eax>,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *a2@<ecx>,
        const vostok::animation::base_interpolator *this,
        vostok::animation::mixing::n_ary_tree_animation_node *end)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v4; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *v5; // eax
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v6; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *i; // esi

  v4 = begin;
  v5 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation(a2, this, begin, 0);
  for ( i = v5->m_weight_synchronization_group_id != -1 ? v5 : 0;
        ;
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation(v6, this, v4, i) )
  {
    v4 = v4->m_next_weight_animation;
    if ( v4 == end )
      break;
  }
}
