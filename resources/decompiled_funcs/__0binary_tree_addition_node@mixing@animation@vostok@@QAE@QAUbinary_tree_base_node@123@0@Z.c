void __usercall vostok::animation::mixing::binary_tree_addition_node::binary_tree_addition_node(
        vostok::animation::mixing::binary_tree_addition_node *this@<eax>,
        vostok::animation::mixing::binary_tree_base_node *const left@<ecx>,
        vostok::animation::mixing::binary_tree_base_node *const right@<esi>)
{
  this->m_next_weight = 0;
  this->m_same_weight = 0;
  this->m_next_unique_interpolator = 0;
  this->m_reference_count = 0;
  this->__vftable = (vostok::animation::mixing::binary_tree_addition_node_vtbl *)&vostok::animation::mixing::binary_tree_binary_operation_node::`vftable';
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
  this->__vftable = (vostok::animation::mixing::binary_tree_addition_node_vtbl *)&vostok::animation::mixing::binary_tree_addition_node::`vftable';
}
