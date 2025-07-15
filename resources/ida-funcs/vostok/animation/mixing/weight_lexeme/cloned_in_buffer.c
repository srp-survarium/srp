vostok::animation::mixing::weight_lexeme *__thiscall vostok::animation::mixing::weight_lexeme::cloned_in_buffer(
        vostok::animation::mixing::weight_lexeme *this)
{
  vostok::animation::mixing::weight_lexeme *result; // eax
  vostok::mutable_buffer *m_buffer; // edx
  unsigned int m_reference_count; // edx

  if ( this->m_cloned )
    return this;
  m_buffer = this->m_buffer;
  result = (vostok::animation::mixing::weight_lexeme *)m_buffer->m_data;
  m_buffer->m_size -= 40;
  m_buffer->m_data = (char *)&result[1];
  if ( result )
  {
    result->m_next_weight = this->m_next_weight;
    result->m_same_weight = this->m_same_weight;
    result->m_next_unique_interpolator = this->m_next_unique_interpolator;
    m_reference_count = this->m_reference_count;
    result->__vftable = (vostok::animation::mixing::weight_lexeme_vtbl *)&vostok::animation::mixing::binary_tree_weight_node::`vftable';
    result->m_reference_count = m_reference_count;
    result->m_interpolator = this->m_interpolator;
    result->m_weight = this->m_weight;
    result->m_simplified_weight = this->m_simplified_weight;
    result->m_buffer = this->m_buffer;
    result->m_cloned = 0;
    result->__vftable = (vostok::animation::mixing::weight_lexeme_vtbl *)&vostok::animation::mixing::weight_lexeme::`vftable';
  }
  result->m_cloned = 1;
  return result;
}
