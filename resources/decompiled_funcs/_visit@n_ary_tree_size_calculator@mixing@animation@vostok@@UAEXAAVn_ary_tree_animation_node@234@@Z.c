void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::n_ary_tree_animation_node *node)
{
  vostok::animation::mixing::n_ary_tree_size_calculator *v2; // edx
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v3; // ecx
  unsigned int m_animation_intervals_count; // esi
  vostok::animation::mixing::n_ary_tree_comparer *m_comparer; // ecx

  v2 = (vostok::animation::mixing::n_ary_tree_size_calculator *)((char *)this - 4);
  v3 = this->vostok::animation::mixing::n_ary_tree_visitor::__vftable;
  m_animation_intervals_count = node->m_animation_intervals_count;
  if ( v3 )
    v3->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_weight_transition_node *))((char *)v3->visit + 12 * m_animation_intervals_count);
  else
    v2->m_size += 12 * m_animation_intervals_count;
  m_comparer = v2->m_comparer;
  if ( m_comparer )
    m_comparer->m_needed_buffer_size += 4;
  else
    v2->m_size += 4;
  vostok::animation::mixing::n_ary_tree_size_calculator::propagate<vostok::animation::mixing::n_ary_tree_animation_node>(
    v2,
    node);
}
