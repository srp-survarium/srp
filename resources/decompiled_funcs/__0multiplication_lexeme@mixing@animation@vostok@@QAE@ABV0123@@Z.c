void __usercall vostok::animation::mixing::multiplication_lexeme::multiplication_lexeme(
        vostok::animation::mixing::multiplication_lexeme *this@<esi>,
        const vostok::animation::mixing::multiplication_lexeme *other@<edi>)
{
  vostok::animation::mixing::binary_tree_binary_operation_node::binary_tree_binary_operation_node(
    &other->vostok::animation::mixing::binary_tree_multiplication_node,
    this);
  this->__vftable = (vostok::animation::mixing::multiplication_lexeme_vtbl *)&vostok::animation::mixing::binary_tree_multiplication_node::`vftable';
  if ( other )
    this->m_buffer = other->m_buffer;
  else
    this->m_buffer = (vostok::mutable_buffer *)MEMORY[0];
  this->m_cloned = 0;
  this->__vftable = (vostok::animation::mixing::multiplication_lexeme_vtbl *)&vostok::animation::mixing::multiplication_lexeme::`vftable';
}
