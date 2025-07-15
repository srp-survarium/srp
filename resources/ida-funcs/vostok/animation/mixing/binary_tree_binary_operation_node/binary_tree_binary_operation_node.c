void __usercall vostok::animation::mixing::binary_tree_binary_operation_node::binary_tree_binary_operation_node(
        vostok::animation::mixing::binary_tree_binary_operation_node *this@<ecx>,
        _DWORD *a2@<eax>)
{
  vostok::animation::mixing::binary_tree_base_node *m_object; // edx
  vostok::animation::mixing::binary_tree_base_node *v3; // ecx

  a2[1] = this->m_next_weight;
  a2[2] = this->m_same_weight;
  a2[3] = this->m_next_unique_interpolator;
  a2[4] = this->m_reference_count;
  *a2 = &vostok::animation::mixing::binary_tree_binary_operation_node::`vftable';
  a2[5] = 0;
  m_object = this->m_left.m_object;
  if ( m_object )
  {
    a2[5] = m_object;
    ++m_object->m_reference_count;
  }
  a2[6] = 0;
  v3 = this->m_right.m_object;
  if ( v3 )
  {
    a2[6] = v3;
    ++v3->m_reference_count;
  }
}


void __usercall vostok::animation::mixing::binary_tree_binary_operation_node::binary_tree_binary_operation_node(
        vostok::animation::mixing::binary_tree_binary_operation_node *this@<eax>,
        vostok::animation::mixing::binary_tree_base_node *const left@<ecx>,
        vostok::animation::mixing::binary_tree_base_node *const right@<esi>)
{
  this->m_next_weight = 0;
  this->m_same_weight = 0;
  this->m_next_unique_interpolator = 0;
  this->m_reference_count = 0;
  this->__vftable = (vostok::animation::mixing::binary_tree_binary_operation_node_vtbl *)&vostok::animation::mixing::binary_tree_binary_operation_node::`vftable';
  this->m_left.m_object = 0;
  if ( left )
  {
    this->m_left.m_object = left;
    ++left->m_reference_count;
  }
  this->m_right.m_object = 0;
  if ( right )
  {
    this->m_right.m_object = right;
    ++right->m_reference_count;
  }
}
