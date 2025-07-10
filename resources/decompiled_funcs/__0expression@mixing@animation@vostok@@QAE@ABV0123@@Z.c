void __usercall vostok::animation::mixing::expression::expression(
        vostok::animation::mixing::expression *this@<eax>,
        const vostok::animation::mixing::expression *__that@<edx>)
{
  vostok::animation::mixing::binary_tree_base_node *m_object; // ecx

  this->m_node.m_object = 0;
  m_object = __that->m_node.m_object;
  if ( __that->m_node.m_object )
  {
    this->m_node.m_object = m_object;
    ++m_object->m_reference_count;
  }
  this->m_lexeme = __that->m_lexeme;
}
