vostok::animation::mixing::binary_tree_expression_simplifier *__thiscall vostok::animation::mixing::binary_tree_expression_simplifier::`scalar deleting destructor'(
        vostok::animation::mixing::binary_tree_expression_simplifier *this,
        char a2)
{
  vostok::animation::mixing::binary_tree_weight_node *m_object; // eax
  bool v4; // zf
  vostok::animation::mixing::binary_tree_base_node *v5; // eax

  m_object = this->m_result_weight.m_object;
  if ( m_object )
  {
    v4 = m_object->m_reference_count-- == 1;
    if ( v4 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_weight_node *, _DWORD))this->m_result_weight.m_object->~vostok::animation::mixing::binary_tree_base_node)(
        this->m_result_weight.m_object,
        0);
  }
  v5 = this->m_result.m_object;
  if ( v5 )
  {
    v4 = v5->m_reference_count-- == 1;
    if ( v4 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))this->m_result.m_object->~vostok::animation::mixing::binary_tree_base_node)(
        this->m_result.m_object,
        0);
  }
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
