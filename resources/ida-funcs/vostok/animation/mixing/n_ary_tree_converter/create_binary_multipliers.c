vostok::animation::mixing::binary_tree_base_node *__userpurge vostok::animation::mixing::n_ary_tree_converter::create_binary_multipliers@<eax>(
        vostok::animation::mixing::binary_tree_base_node *start_weight@<eax>,
        vostok::animation::mixing::n_ary_tree_converter *this,
        vostok::mutable_buffer *buffer)
{
  vostok::animation::mixing::binary_tree_base_node *i; // esi
  boost::detail::function::vtable_base *vtable; // edi

  for ( i = start_weight->m_next_weight; i; start_weight = (vostok::animation::mixing::binary_tree_base_node *)vtable )
  {
    vtable = this->m_animation_resolver.vtable;
    (&this->m_animation_resolver.vtable)[1] -= 7;
    this->m_animation_resolver.vtable = vtable + 7;
    if ( vtable )
    {
      vostok::animation::mixing::binary_tree_binary_operation_node::binary_tree_binary_operation_node(
        (vostok::animation::mixing::binary_tree_binary_operation_node *)vtable,
        start_weight,
        i);
      vtable->manager = (void (__cdecl *)(const boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, boost::detail::function::functor_manager_operation_type))&vostok::animation::mixing::binary_tree_multiplication_node::`vftable';
    }
    i = i->m_next_weight;
  }
  return start_weight;
}
