void __usercall vostok::animation::mixing::n_ary_tree_size_calculator::propagate<vostok::animation::mixing::n_ary_tree_animation_node>(
        vostok::animation::mixing::n_ary_tree_size_calculator *this@<edx>,
        vostok::animation::mixing::n_ary_tree_animation_node *node@<eax>)
{
  vostok::animation::mixing::n_ary_tree_comparer *m_comparer; // eax
  vostok::animation::mixing::n_ary_tree_comparer *v4; // ecx
  unsigned int v5; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v6; // esi
  vostok::animation::mixing::n_ary_tree_animation_node *v7; // edi
  vostok::animation::mixing::n_ary_tree_visitor *v8; // ebx

  m_comparer = this->m_comparer;
  if ( m_comparer )
    m_comparer->m_needed_buffer_size += 88;
  else
    this->m_size += 88;
  v4 = this->m_comparer;
  v5 = 4 * node->m_operands_count;
  if ( v4 )
    v4->m_needed_buffer_size += v5;
  else
    this->m_size += v5;
  v6 = node + 1;
  v7 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v6 + v5);
  if ( v6 != (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v6 + v5) )
  {
    v8 = &this->vostok::animation::mixing::n_ary_tree_visitor;
    do
    {
      (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, vostok::animation::mixing::n_ary_tree_visitor *))v6->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
       + 2))(
        v6->__vftable,
        v8);
      v6 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v6 + 4);
    }
    while ( v6 != v7 );
  }
}
