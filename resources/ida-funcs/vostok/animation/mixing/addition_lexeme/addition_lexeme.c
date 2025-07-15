void __userpurge vostok::animation::mixing::addition_lexeme::addition_lexeme(
        vostok::animation::mixing::addition_lexeme *this@<edi>,
        vostok::animation::mixing::expression *right@<eax>,
        vostok::animation::mixing::expression *left)
{
  vostok::animation::mixing::binary_tree_binary_operation_node::binary_tree_binary_operation_node(
    this,
    left->m_node.m_object,
    right->m_node.m_object);
  this->__vftable = (vostok::animation::mixing::addition_lexeme_vtbl *)&vostok::animation::mixing::binary_tree_addition_node::`vftable';
  this->m_buffer = left->m_lexeme->m_buffer;
  this->m_cloned = 0;
  this->__vftable = (vostok::animation::mixing::addition_lexeme_vtbl *)&vostok::animation::mixing::addition_lexeme::`vftable';
}
