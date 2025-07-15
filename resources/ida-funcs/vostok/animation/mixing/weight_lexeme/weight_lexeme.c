void __userpurge vostok::animation::mixing::weight_lexeme::weight_lexeme(
        vostok::animation::mixing::weight_lexeme *this@<esi>,
        vostok::mutable_buffer *buffer@<edi>,
        const vostok::animation::base_interpolator *interpolator@<ecx>,
        float weight)
{
  this->m_interpolator = interpolator->clone(interpolator, buffer);
  this->m_next_weight = 0;
  this->m_same_weight = 0;
  this->m_next_unique_interpolator = 0;
  this->m_reference_count = 0;
  this->m_weight = weight;
  this->m_simplified_weight = weight;
  this->m_buffer = buffer;
  this->m_cloned = 0;
  this->__vftable = (vostok::animation::mixing::weight_lexeme_vtbl *)&vostok::animation::mixing::weight_lexeme::`vftable';
}
