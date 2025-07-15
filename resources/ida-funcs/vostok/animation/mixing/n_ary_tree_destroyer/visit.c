void __thiscall vostok::animation::mixing::n_ary_tree_destroyer::visit(
        vostok::animation::mixing::n_ary_tree_destroyer *this,
        vostok::animation::mixing::n_ary_tree_addition_node *node)
{
  vostok::animation::mixing::n_ary_tree_destroyer::propagate<vostok::animation::mixing::n_ary_tree_multiplication_node>(
    this,
    this,
    node);
}


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


void __thiscall vostok::animation::mixing::n_ary_tree_destroyer::visit(
        vostok::animation::mixing::n_ary_tree_destroyer *this,
        vostok::animation::mixing::n_ary_tree_multiplication_node *node)
{
  vostok::animation::mixing::n_ary_tree_destroyer::propagate<vostok::animation::mixing::n_ary_tree_multiplication_node>(
    this,
    this,
    (vostok::animation::mixing::n_ary_tree_addition_node *)node);
}


void __thiscall vostok::animation::mixing::n_ary_tree_destroyer::visit(
        vostok::animation::mixing::n_ary_tree_destroyer *this,
        vostok::animation::mixing::n_ary_tree_subtraction_node *node)
{
  vostok::animation::mixing::n_ary_tree_destroyer::propagate<vostok::animation::mixing::n_ary_tree_multiplication_node>(
    this,
    this,
    (vostok::animation::mixing::n_ary_tree_addition_node *)node);
}


void __thiscall vostok::animation::mixing::n_ary_tree_destroyer::visit(
        vostok::animation::mixing::n_ary_tree_destroyer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_time_scale_node *, _DWORD))node->~vostok::animation::mixing::n_ary_tree_base_node)(
    node,
    0);
}


void __thiscall vostok::animation::mixing::n_ary_tree_destroyer::visit(
        vostok::animation::mixing::n_ary_tree_destroyer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *node)
{
  node->m_from->accept(node->m_from, this);
  node->m_to->accept(node->m_to, this);
  ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_time_scale_transition_node *, _DWORD))node->~vostok::animation::mixing::n_ary_tree_base_node)(
    node,
    0);
}


void __thiscall vostok::animation::mixing::n_ary_tree_destroyer::visit(
        vostok::animation::mixing::n_ary_tree_destroyer *this,
        vostok::animation::mixing::n_ary_tree_weight_node *node)
{
  ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_weight_node *, _DWORD))node->~vostok::animation::mixing::n_ary_tree_base_node)(
    node,
    0);
}


void __thiscall vostok::animation::mixing::n_ary_tree_destroyer::visit(
        vostok::animation::mixing::n_ary_tree_destroyer *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node)
{
  node->m_from->accept(node->m_from, this);
  node->m_to->accept(node->m_to, this);
  ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_weight_transition_node *, _DWORD))node->~vostok::animation::mixing::n_ary_tree_base_node)(
    node,
    0);
}
