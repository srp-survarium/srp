void __thiscall vostok::animation::mixing::n_ary_tree_destroyer::visit(
        vostok::animation::mixing::n_ary_tree_destroyer *this,
        vostok::animation::mixing::n_ary_tree_animation_node *node)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v2; // esi
  vostok::animation::mixing::n_ary_tree_animation_node *v4; // ebx
  const vostok::animation::mixing::animation_interval *m_animation_intervals; // ebx
  const vostok::animation::mixing::animation_interval *v6; // esi

  v2 = node + 1;
  v4 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)node + 4 * node->m_operands_count + 88);
  while ( v2 != v4 )
  {
    (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, vostok::animation::mixing::n_ary_tree_destroyer *))v2->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
     + 2))(
      v2->__vftable,
      this);
    v2 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v2 + 4);
  }
  ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_animation_node *, _DWORD))node->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node)(
    node,
    0);
  m_animation_intervals = node->m_animation_intervals;
  v6 = &m_animation_intervals[node->m_animation_intervals_count];
  while ( m_animation_intervals != v6 )
  {
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&m_animation_intervals->m_third_view_animation);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&m_animation_intervals->m_first_view_animation);
    ++m_animation_intervals;
  }
}


void __thiscall vostok::animation::mixing::n_ary_tree_destroyer::visit(
        vostok::animation::mixing::n_ary_tree_destroyer *this,
        vostok::animation::mixing::n_ary_tree_addition_node *node)
{
  vostok::animation::mixing::n_ary_tree_addition_node *v2; // esi
  vostok::animation::mixing::n_ary_tree_addition_node *v4; // ebx

  v2 = node + 1;
  v4 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)node + 4 * node->m_operands_count + 8);
  while ( v2 != v4 )
  {
    (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_addition_node_vtbl *, vostok::animation::mixing::n_ary_tree_destroyer *))v2->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
     + 2))(
      v2->__vftable,
      this);
    v2 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)v2 + 4);
  }
  ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_addition_node *, _DWORD))node->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node)(
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
