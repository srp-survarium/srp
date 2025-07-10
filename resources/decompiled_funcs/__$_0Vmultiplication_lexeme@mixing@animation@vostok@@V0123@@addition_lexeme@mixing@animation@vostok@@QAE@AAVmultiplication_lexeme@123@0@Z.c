void __thiscall vostok::animation::mixing::addition_lexeme::addition_lexeme(
        vostok::animation::mixing::multiplication_lexeme *right,
        vostok::animation::mixing::addition_lexeme *this,
        vostok::animation::mixing::multiplication_lexeme *left)
{
  vostok::animation::mixing::multiplication_lexeme *v3; // ebx
  vostok::mutable_buffer *m_buffer; // eax
  vostok::animation::mixing::multiplication_lexeme *m_data; // esi
  vostok::animation::mixing::multiplication_lexeme *v6; // ecx
  vostok::animation::mixing::multiplication_lexeme *v7; // esi
  vostok::mutable_buffer *v8; // eax

  if ( right->m_cloned )
  {
    v3 = right;
  }
  else
  {
    m_buffer = right->m_buffer;
    m_data = (vostok::animation::mixing::multiplication_lexeme *)m_buffer->m_data;
    m_buffer->m_size -= 36;
    m_buffer->m_data = (char *)&m_data[1];
    if ( m_data )
      vostok::animation::mixing::multiplication_lexeme::multiplication_lexeme(m_data, right);
    m_data->m_cloned = 1;
    v3 = m_data;
  }
  v6 = left;
  if ( left->m_cloned )
  {
    v7 = left;
  }
  else
  {
    v8 = left->m_buffer;
    v7 = (vostok::animation::mixing::multiplication_lexeme *)v8->m_data;
    v8->m_size -= 36;
    v8->m_data = (char *)&v7[1];
    if ( v7 )
    {
      vostok::animation::mixing::multiplication_lexeme::multiplication_lexeme(v7, left);
      v6 = left;
    }
    v7->m_cloned = 1;
  }
  this->m_next_weight = 0;
  this->m_same_weight = 0;
  this->m_next_unique_interpolator = 0;
  this->m_reference_count = 0;
  this->__vftable = (vostok::animation::mixing::addition_lexeme_vtbl *)&vostok::animation::mixing::binary_tree_binary_operation_node::`vftable';
  this->m_left.m_object = 0;
  if ( v7 )
  {
    this->m_left.m_object = v7;
    ++v7->m_reference_count;
  }
  this->m_right.m_object = 0;
  if ( v3 )
  {
    this->m_right.m_object = v3;
    ++v3->m_reference_count;
  }
  this->__vftable = (vostok::animation::mixing::addition_lexeme_vtbl *)&vostok::animation::mixing::binary_tree_addition_node::`vftable';
  this->m_buffer = v6->m_buffer;
  this->m_cloned = 0;
  this->__vftable = (vostok::animation::mixing::addition_lexeme_vtbl *)&vostok::animation::mixing::addition_lexeme::`vftable';
}
