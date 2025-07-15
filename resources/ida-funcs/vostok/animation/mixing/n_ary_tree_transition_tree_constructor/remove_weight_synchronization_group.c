void __thiscall vostok::animation::mixing::n_ary_tree_transition_tree_constructor::remove_weight_synchronization_group(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this,
        vostok::resources::managed_resource *begin,
        vostok::animation::mixing::n_ary_tree_animation_node *end,
        vostok::animation::mixing::n_ary_tree_animation_node *a4)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v4; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *m_next_weight_animation; // edi
  vostok::resources::managed_resource *v6; // esi
  vostok::animation::mixing::animation_interval v7; // [esp-Ch] [ebp-1Ch]
  vostok::animation::mixing::animation_interval v8; // [esp-Ch] [ebp-1Ch]

  v7.m_animation_id = !end->m_is_transitting_to_zero;
  *(_QWORD *)&v7.m_first_view_animation.m_object = (unsigned int)begin;
  v4 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::remove_animation(end, v7);
  if ( v4 )
  {
    m_next_weight_animation = end->m_next_weight_animation;
    v6 = v4->m_weight_synchronization_group_id != -1 ? (vostok::resources::managed_resource *)v4 : 0;
    while ( m_next_weight_animation != a4 )
    {
      v8.m_animation_id = !end->m_is_transitting_to_zero;
      v8.m_third_view_animation.m_object = v6;
      v8.m_first_view_animation.m_object = begin;
      vostok::animation::mixing::n_ary_tree_transition_tree_constructor::remove_animation(m_next_weight_animation, v8);
      m_next_weight_animation = m_next_weight_animation->m_next_weight_animation;
    }
  }
}
