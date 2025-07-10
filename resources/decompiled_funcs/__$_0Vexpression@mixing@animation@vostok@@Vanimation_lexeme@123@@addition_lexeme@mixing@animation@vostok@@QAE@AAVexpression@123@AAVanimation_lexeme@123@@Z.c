void __userpurge vostok::animation::mixing::addition_lexeme::addition_lexeme(
        vostok::animation::mixing::addition_lexeme *this@<edi>,
        vostok::animation::mixing::base_lexeme *right@<eax>,
        vostok::animation::mixing::animation_lexeme *a3@<ecx>,
        vostok::animation::mixing::expression *left)
{
  vostok::animation::mixing::binary_tree_base_node *v4; // eax
  vostok::animation::mixing::binary_tree_base_node *m_object; // ecx

  v4 = (vostok::animation::mixing::binary_tree_base_node *)vostok::animation::mixing::animation_lexeme::cloned_in_buffer(
                                                             a3,
                                                             right);
  m_object = left->m_node.m_object;
  this->m_next_weight = 0;
  this->m_same_weight = 0;
  this->m_next_unique_interpolator = 0;
  this->m_reference_count = 0;
  this->__vftable = (vostok::animation::mixing::addition_lexeme_vtbl *)&vostok::animation::mixing::binary_tree_binary_operation_node::`vftable';
  this->m_left.m_object = 0;
  if ( m_object )
  {
    this->m_left.m_object = m_object;
    ++m_object->m_reference_count;
  }
  this->m_right.m_object = 0;
  if ( v4 )
  {
    this->m_right.m_object = v4;
    ++v4->m_reference_count;
  }
  this->__vftable = (vostok::animation::mixing::addition_lexeme_vtbl *)&vostok::animation::mixing::binary_tree_addition_node::`vftable';
  this->m_buffer = left->m_lexeme->m_buffer;
  this->m_cloned = 0;
  this->__vftable = (vostok::animation::mixing::addition_lexeme_vtbl *)&vostok::animation::mixing::addition_lexeme::`vftable';
}
