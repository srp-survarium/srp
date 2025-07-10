void __thiscall vostok::animation::mixing::n_ary_tree_destroyer::visit(
        vostok::animation::mixing::n_ary_tree_destroyer *this,
        vostok::animation::mixing::n_ary_tree_animation_node *node)
{
  const vostok::animation::mixing::animation_interval *m_animation_intervals; // esi
  const vostok::animation::mixing::animation_interval *i; // edi

  vostok::animation::mixing::n_ary_tree_destroyer::propagate<vostok::animation::mixing::n_ary_tree_animation_node>(
    this,
    this,
    node);
  m_animation_intervals = node->m_animation_intervals;
  for ( i = &m_animation_intervals[node->m_animation_intervals_count]; m_animation_intervals != i; ++m_animation_intervals )
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&m_animation_intervals->m_animation);
}
