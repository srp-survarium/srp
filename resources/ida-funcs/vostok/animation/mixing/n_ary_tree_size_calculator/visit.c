void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::binary_tree_animation_node *node)
{
  vostok::animation::mixing::n_ary_tree_comparer *m_comparer; // eax
  vostok::animation::mixing::n_ary_tree_comparer *v3; // edx
  unsigned int v4; // eax

  m_comparer = this->m_comparer;
  if ( m_comparer )
    m_comparer->m_needed_buffer_size += 88;
  else
    this->m_size += 88;
  v3 = this->m_comparer;
  v4 = 20 * node->m_animation_intervals_count;
  if ( v3 )
    v3->m_needed_buffer_size += v4;
  else
    this->m_size += v4;
}


void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::binary_tree_addition_node *node)
{
  vostok::animation::mixing::n_ary_tree_comparer *m_comparer; // eax

  m_comparer = this->m_comparer;
  if ( m_comparer )
    m_comparer->m_needed_buffer_size += 8;
  else
    this->m_size += 8;
  vostok::animation::mixing::n_ary_tree_size_calculator::advance_buffer<vostok::animation::mixing::n_ary_tree_base_node *>(
    this,
    1u);
  vostok::animation::mixing::n_ary_tree_size_calculator::propagate(node, this);
}


void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::binary_tree_weight_node *node)
{
  vostok::animation::mixing::n_ary_tree_comparer *m_comparer; // eax

  m_comparer = this->m_comparer;
  if ( m_comparer )
    m_comparer->m_needed_buffer_size += 12;
  else
    this->m_size += 12;
  vostok::animation::mixing::n_ary_tree_size_calculator::advance_buffer<vostok::animation::mixing::n_ary_tree_base_node *>(
    this,
    1u);
}


void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::n_ary_tree_addition_node *node)
{
  unsigned int *p_m_size; // ebx
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v3; // eax
  unsigned int m_operands_count; // edi
  vostok::animation::mixing::n_ary_tree_addition_node *v5; // esi
  vostok::animation::mixing::n_ary_tree_addition_node *v6; // edi
  char *v7; // ebx

  p_m_size = &this[-1].m_size;
  v3 = this->vostok::animation::mixing::n_ary_tree_visitor::__vftable;
  if ( v3 )
    v3->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_animation_node *))((char *)v3->visit + 8);
  else
    p_m_size[3] += 8;
  m_operands_count = node->m_operands_count;
  vostok::animation::mixing::n_ary_tree_size_calculator::advance_buffer<vostok::animation::mixing::n_ary_tree_base_node *>(
    (vostok::animation::mixing::n_ary_tree_size_calculator *)((char *)this - 4),
    m_operands_count);
  v5 = node + 1;
  v6 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)node + 4 * m_operands_count + 8);
  if ( &node[1] != v6 )
  {
    v7 = (char *)(p_m_size + 1);
    do
    {
      (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_addition_node_vtbl *, char *))v5->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
       + 2))(
        v5->__vftable,
        v7);
      v5 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)v5 + 4);
    }
    while ( v5 != v6 );
  }
}


void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::n_ary_tree_animation_node *node)
{
  vostok::animation::mixing::n_ary_tree_size_calculator *v2; // esi
  unsigned int v3; // eax
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v4; // ecx
  vostok::animation::mixing::n_ary_tree_comparer *m_comparer; // eax
  vostok::animation::mixing::n_ary_tree_comparer *v6; // eax
  unsigned int m_operands_count; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *v8; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *v9; // ebx
  vostok::animation::mixing::n_ary_tree_visitor *v10; // esi

  v2 = (vostok::animation::mixing::n_ary_tree_size_calculator *)((char *)this - 4);
  v3 = 20 * node->m_animation_intervals_count;
  v4 = this->vostok::animation::mixing::n_ary_tree_visitor::__vftable;
  if ( v4 )
    v4->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_animation_node *))((char *)v4->visit + v3);
  else
    v2->m_size += v3;
  m_comparer = v2->m_comparer;
  if ( m_comparer )
    m_comparer->m_needed_buffer_size += 4;
  else
    v2->m_size += 4;
  v6 = v2->m_comparer;
  if ( v6 )
    v6->m_needed_buffer_size += 88;
  else
    v2->m_size += 88;
  m_operands_count = node->m_operands_count;
  vostok::animation::mixing::n_ary_tree_size_calculator::advance_buffer<vostok::animation::mixing::n_ary_tree_base_node *>(
    v2,
    m_operands_count);
  v8 = node + 1;
  v9 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)node + 4 * m_operands_count + 88);
  if ( &node[1] != v9 )
  {
    v10 = &v2->vostok::animation::mixing::n_ary_tree_visitor;
    do
    {
      (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, vostok::animation::mixing::n_ary_tree_visitor *))v8->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
       + 2))(
        v8->__vftable,
        v10);
      v8 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v8 + 4);
    }
    while ( v8 != v9 );
  }
}


void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v2; // eax

  v2 = this->vostok::animation::mixing::n_ary_tree_visitor::__vftable;
  if ( v2 )
    v2->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_animation_node *))((char *)v2->visit + 20);
  else
    this->m_comparer = (vostok::animation::mixing::n_ary_tree_comparer *)((char *)this->m_comparer + 20);
}


void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node)
{
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v3; // eax

  v3 = this->vostok::animation::mixing::n_ary_tree_visitor::__vftable;
  if ( v3 )
    v3->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_animation_node *))((char *)v3->visit + 20);
  else
    this->m_comparer = (vostok::animation::mixing::n_ary_tree_comparer *)((char *)this->m_comparer + 20);
  node->m_from->accept(
    node->m_from,
    this != (vostok::animation::mixing::n_ary_tree_size_calculator *)4
  ? (vostok::animation::mixing::n_ary_tree_visitor *)this
  : 0);
  node->m_to->accept(
    node->m_to,
    this != (vostok::animation::mixing::n_ary_tree_size_calculator *)4
  ? (vostok::animation::mixing::n_ary_tree_visitor *)this
  : 0);
}
