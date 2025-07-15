void __usercall vostok::animation::mixing::multiplication_lexeme::multiplication_lexeme(
        vostok::animation::mixing::multiplication_lexeme *this@<edi>,
        vostok::animation::mixing::base_lexeme *left@<eax>,
        vostok::animation::mixing::weight_lexeme *right@<ecx>)
{
  vostok::animation::mixing::weight_lexeme *m_data; // ebp
  vostok::mutable_buffer *m_buffer; // eax
  vostok::animation::mixing::binary_tree_base_node *v6; // eax

  if ( right->m_cloned )
  {
    m_data = right;
  }
  else
  {
    m_buffer = right->m_buffer;
    m_data = (vostok::animation::mixing::weight_lexeme *)m_buffer->m_data;
    m_buffer->m_size -= 40;
    m_buffer->m_data = (char *)&m_data[1];
    if ( m_data )
      vostok::animation::mixing::weight_lexeme::weight_lexeme(right, (int)m_data);
    m_data->m_cloned = 1;
  }
  v6 = (vostok::animation::mixing::binary_tree_base_node *)vostok::animation::mixing::animation_lexeme::cloned_in_buffer(
                                                             (vostok::animation::mixing::animation_lexeme *)right,
                                                             left);
  this->m_next_weight = 0;
  this->m_same_weight = 0;
  this->m_next_unique_interpolator = 0;
  this->m_reference_count = 0;
  this->__vftable = (vostok::animation::mixing::multiplication_lexeme_vtbl *)&vostok::animation::mixing::binary_tree_binary_operation_node::`vftable';
  this->m_left.m_object = 0;
  if ( v6 )
  {
    this->m_left.m_object = v6;
    ++v6->m_reference_count;
  }
  this->m_right.m_object = 0;
  if ( m_data )
  {
    this->m_right.m_object = m_data;
    ++m_data->m_reference_count;
  }
  this->__vftable = (vostok::animation::mixing::multiplication_lexeme_vtbl *)&vostok::animation::mixing::binary_tree_multiplication_node::`vftable';
  this->m_buffer = left[15].m_buffer;
  this->m_cloned = 0;
  this->__vftable = (vostok::animation::mixing::multiplication_lexeme_vtbl *)&vostok::animation::mixing::multiplication_lexeme::`vftable';
}


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
