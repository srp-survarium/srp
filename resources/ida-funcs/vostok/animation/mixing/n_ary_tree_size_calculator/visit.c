void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::binary_tree_addition_node *node)
{
  vostok::animation::mixing::n_ary_tree_comparer *m_comparer; // eax
  vostok::animation::mixing::n_ary_tree_comparer *v4; // eax

  m_comparer = this->m_comparer;
  if ( m_comparer )
    m_comparer->m_needed_buffer_size += 8;
  else
    this->m_size += 8;
  v4 = this->m_comparer;
  if ( v4 )
    v4->m_needed_buffer_size += 4;
  else
    this->m_size += 4;
  node->m_left.m_object->accept(node->m_left.m_object, this);
  node->m_right.m_object->accept(node->m_right.m_object, this);
}


void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::binary_tree_animation_node *node)
{
  vostok::animation::mixing::n_ary_tree_comparer *m_comparer; // eax
  vostok::animation::mixing::n_ary_tree_comparer *v3; // edx
  unsigned int m_animation_intervals_count; // eax

  m_comparer = this->m_comparer;
  if ( m_comparer )
    m_comparer->m_needed_buffer_size += 88;
  else
    this->m_size += 88;
  v3 = this->m_comparer;
  m_animation_intervals_count = node->m_animation_intervals_count;
  if ( v3 )
    v3->m_needed_buffer_size += 12 * m_animation_intervals_count;
  else
    this->m_size += 12 * m_animation_intervals_count;
}


void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::binary_tree_multiplication_node *node)
{
  vostok::animation::mixing::n_ary_tree_comparer *m_comparer; // eax
  vostok::animation::mixing::n_ary_tree_comparer *v4; // eax

  m_comparer = this->m_comparer;
  if ( m_comparer )
    m_comparer->m_needed_buffer_size += 8;
  else
    this->m_size += 8;
  v4 = this->m_comparer;
  if ( v4 )
    v4->m_needed_buffer_size += 4;
  else
    this->m_size += 4;
  node->m_left.m_object->accept(node->m_left.m_object, this);
  node->m_right.m_object->accept(node->m_right.m_object, this);
}


void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::binary_tree_subtraction_node *node)
{
  vostok::animation::mixing::n_ary_tree_comparer *m_comparer; // eax
  vostok::animation::mixing::n_ary_tree_comparer *v4; // eax

  m_comparer = this->m_comparer;
  if ( m_comparer )
    m_comparer->m_needed_buffer_size += 8;
  else
    this->m_size += 8;
  v4 = this->m_comparer;
  if ( v4 )
    v4->m_needed_buffer_size += 4;
  else
    this->m_size += 4;
  node->m_left.m_object->accept(node->m_left.m_object, this);
  node->m_right.m_object->accept(node->m_right.m_object, this);
}


void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::binary_tree_weight_node *node)
{
  vostok::animation::mixing::n_ary_tree_comparer *m_comparer; // eax
  vostok::animation::mixing::n_ary_tree_comparer *v3; // eax

  m_comparer = this->m_comparer;
  if ( m_comparer )
    m_comparer->m_needed_buffer_size += 12;
  else
    this->m_size += 12;
  v3 = this->m_comparer;
  if ( v3 )
    v3->m_needed_buffer_size += 4;
  else
    this->m_size += 4;
}


void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::n_ary_tree_addition_node *node)
{
  vostok::animation::mixing::n_ary_tree_size_calculator::propagate<vostok::animation::mixing::n_ary_tree_multiplication_node>(
    (vostok::animation::mixing::n_ary_tree_size_calculator *)((char *)this - 4),
    node);
}


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


void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::n_ary_tree_multiplication_node *node)
{
  vostok::animation::mixing::n_ary_tree_size_calculator::propagate<vostok::animation::mixing::n_ary_tree_multiplication_node>(
    (vostok::animation::mixing::n_ary_tree_size_calculator *)((char *)this - 4),
    (vostok::animation::mixing::n_ary_tree_addition_node *)node);
}


void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::n_ary_tree_subtraction_node *node)
{
  vostok::animation::mixing::n_ary_tree_size_calculator::propagate<vostok::animation::mixing::n_ary_tree_multiplication_node>(
    (vostok::animation::mixing::n_ary_tree_size_calculator *)((char *)this - 4),
    (vostok::animation::mixing::n_ary_tree_addition_node *)node);
}


void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v2; // eax

  v2 = this->vostok::animation::mixing::n_ary_tree_visitor::__vftable;
  if ( v2 )
    v2->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_weight_transition_node *))((char *)v2->visit + 20);
  else
    this->m_comparer = (vostok::animation::mixing::n_ary_tree_comparer *)((char *)this->m_comparer + 20);
}


void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *node)
{
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v3; // eax

  v3 = this->vostok::animation::mixing::n_ary_tree_visitor::__vftable;
  if ( v3 )
    v3->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_weight_transition_node *))((char *)v3->visit + 20);
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


void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::n_ary_tree_weight_node *node)
{
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v2; // eax

  v2 = this->vostok::animation::mixing::n_ary_tree_visitor::__vftable;
  if ( v2 )
    v2->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_weight_transition_node *))((char *)v2->visit + 12);
  else
    this->m_comparer = (vostok::animation::mixing::n_ary_tree_comparer *)((char *)this->m_comparer + 12);
}


void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node)
{
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v3; // eax

  v3 = this->vostok::animation::mixing::n_ary_tree_visitor::__vftable;
  if ( v3 )
    v3->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_weight_transition_node *))((char *)v3->visit + 20);
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
