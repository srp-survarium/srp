void __usercall vostok::animation::mixing::binary_tree_initializer::binary_tree_initializer(
        vostok::animation::mixing::binary_tree_initializer *this@<ecx>,
        vostok::animation::mixing::binary_tree_subtraction_node *a2@<esi>)
{
  a2->__vftable = (vostok::animation::mixing::binary_tree_subtraction_node_vtbl *)&vostok::animation::mixing::binary_tree_initializer::`vftable';
  a2->m_next_weight = (vostok::animation::mixing::binary_tree_base_node *)this;
  this->visit(this, a2);
}
