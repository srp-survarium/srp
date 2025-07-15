void __usercall vostok::animation::mixing::binary_tree_expression_simplifier::binary_tree_expression_simplifier(
        vostok::animation::mixing::binary_tree_expression_simplifier *this@<esi>,
        vostok::animation::mixing::binary_tree_base_node *expression_node@<ecx>,
        vostok::mutable_buffer *buffer@<eax>)
{
  this->m_buffer = buffer;
  this->__vftable = (vostok::animation::mixing::binary_tree_expression_simplifier_vtbl *)&vostok::animation::mixing::binary_tree_expression_simplifier::`vftable';
  this->m_result.m_object = 0;
  this->m_result_weight.m_object = 0;
  expression_node->accept(expression_node, this);
}
