void __thiscall vostok::animation::mixing::binary_tree_expression_simplifier::visit(
        vostok::animation::mixing::binary_tree_expression_simplifier *this,
        vostok::animation::mixing::binary_tree_addition_node *node)
{
  vostok::animation::mixing::binary_tree_expression_simplifier::process<vostok::animation::mixing::binary_tree_addition_node,stlp_std::plus<float>>(
    this,
    node);
}


void __thiscall vostok::animation::mixing::binary_tree_expression_simplifier::visit(
        vostok::animation::mixing::binary_tree_expression_simplifier *this,
        vostok::animation::mixing::binary_tree_animation_node *node)
{
  vostok::animation::mixing::binary_tree_animation_node *v2; // eax
  vostok::animation::mixing::binary_tree_base_node *v3; // edx
  vostok::animation::mixing::binary_tree_base_node *m_object; // eax

  v2 = 0;
  if ( node )
  {
    ++node->m_reference_count;
    v2 = node;
  }
  v3 = v2;
  m_object = this->m_result.m_object;
  this->m_result.m_object = v3;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))m_object->~vostok::animation::mixing::binary_tree_base_node)(
        m_object,
        0);
  }
}


void __thiscall vostok::animation::mixing::binary_tree_expression_simplifier::visit(
        vostok::animation::mixing::binary_tree_expression_simplifier *this,
        vostok::animation::mixing::binary_tree_multiplication_node *node)
{
  vostok::animation::mixing::binary_tree_expression_simplifier::process<vostok::animation::mixing::binary_tree_multiplication_node,stlp_std::multiplies<float>>(
    this,
    node);
}


void __thiscall vostok::animation::mixing::binary_tree_expression_simplifier::visit(
        vostok::animation::mixing::binary_tree_expression_simplifier *this,
        vostok::animation::mixing::binary_tree_subtraction_node *node)
{
  vostok::animation::mixing::binary_tree_expression_simplifier::process<vostok::animation::mixing::binary_tree_subtraction_node,stlp_std::minus<float>>(
    this,
    node);
}


void __thiscall vostok::animation::mixing::binary_tree_expression_simplifier::visit(
        vostok::animation::mixing::binary_tree_expression_simplifier *this,
        vostok::animation::mixing::binary_tree_weight_node *node)
{
  vostok::animation::mixing::binary_tree_weight_node *v2; // eax
  vostok::animation::mixing::binary_tree_base_node *m_object; // ecx
  bool v5; // zf
  vostok::animation::mixing::binary_tree_weight_node *v6; // eax
  vostok::animation::mixing::binary_tree_weight_node *v7; // ecx

  v2 = 0;
  if ( node )
  {
    ++node->m_reference_count;
    v2 = node;
  }
  m_object = this->m_result.m_object;
  this->m_result.m_object = v2;
  if ( m_object )
  {
    v5 = m_object->m_reference_count-- == 1;
    if ( v5 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))m_object->~vostok::animation::mixing::binary_tree_base_node)(
        m_object,
        0);
  }
  v6 = 0;
  if ( node )
  {
    ++node->m_reference_count;
    v6 = node;
  }
  v7 = this->m_result_weight.m_object;
  this->m_result_weight.m_object = v6;
  if ( v7 )
  {
    v5 = v7->m_reference_count-- == 1;
    if ( v5 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_weight_node *, _DWORD))v7->~vostok::animation::mixing::binary_tree_base_node)(
        v7,
        0);
  }
}
