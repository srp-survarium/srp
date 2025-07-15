void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_animation_node *left,
        vostok::animation::mixing::n_ary_tree_animation_node *right)
{
  vostok::animation::mixing::animation_comparer_predicate v3; // [esp+4h] [ebp-8h] BYREF

  v3.m_animated_object_resolver = this->m_animated_object_resolver;
  v3.m_use_synchronized_animations = 1;
  v3.m_use_overriding_animations = 1;
  this->result = vostok::animation::mixing::animation_comparer_predicate::operator()(&v3, left, right);
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_addition_node *left,
        vostok::animation::mixing::n_ary_tree_addition_node *right)
{
  vostok::animation::mixing::n_ary_tree_addition_node *v3; // esi
  vostok::animation::mixing::n_ary_tree_addition_node *v4; // ebx
  vostok::animation::mixing::n_ary_tree_addition_node *v5; // edi
  vostok::animation::mixing::n_ary_tree_addition_node *v7; // [esp+18h] [ebp+8h]

  v3 = left + 1;
  v4 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)left + 4 * left->m_operands_count + 8);
  v5 = right + 1;
  v7 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)right + 4 * right->m_operands_count + 8);
  if ( v3 == v4 )
    goto LABEL_7;
  do
  {
    if ( v5 == v7 )
      break;
    (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_addition_node_vtbl *, vostok::animation::mixing::n_ary_tree_node_comparer *, vostok::animation::mixing::n_ary_tree_addition_node_vtbl *))v3->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
     + 1))(
      v3->__vftable,
      this,
      v5->__vftable);
    if ( this->result )
      return;
    v3 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)v3 + 4);
    v5 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)v5 + 4);
  }
  while ( v3 != v4 );
  if ( v3 == v4 )
  {
LABEL_7:
    if ( v5 != v7 )
      this->result = less;
  }
  else
  {
    this->result = more;
  }
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *left,
        vostok::animation::mixing::n_ary_tree_time_scale_node *right)
{
  vostok::animation::comparison_result_enum v4; // eax

  if ( vostok::animation::mixing::n_ary_tree_time_scale_node::less(left, right, this->m_compare_dynamic_members) )
    v4 = less;
  else
    v4 = vostok::animation::mixing::n_ary_tree_time_scale_node::less(right, left, this->m_compare_dynamic_members)
       ? more
       : equal;
  this->result = v4;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *left,
        vostok::animation::mixing::n_ary_tree_animation_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *left,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *right)
{
  vostok::animation::comparison_result_enum result; // eax

  right->m_to->accept(right->m_to, this, left);
  result = this->result;
  if ( result == more )
  {
    result = less;
  }
  else if ( result == less )
  {
    result = more;
  }
  this->result = result;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_animation_node *left,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_weight_node *left,
        vostok::animation::mixing::n_ary_tree_weight_node *right)
{
  int v4; // ecx
  vostok::animation::comparison_result_enum v5; // eax

  if ( vostok::animation::mixing::operator<(left, right, (int)this) )
    v5 = less;
  else
    v5 = vostok::animation::mixing::operator<(right, left, v4) ? more : equal;
  this->result = v5;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *left,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *right)
{
  left->m_from->accept(left->m_from, this, right->m_from);
  if ( this->result == equal )
    left->m_to->accept(left->m_to, this, right->m_to);
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *left,
        vostok::animation::mixing::n_ary_tree_time_scale_node *right)
{
  left->m_to->accept(left->m_to, this, right);
}
