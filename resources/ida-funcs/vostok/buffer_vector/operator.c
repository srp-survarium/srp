vostok::buffer_vector<float> *__usercall vostok::buffer_vector<float>::operator=@<eax>(
        vostok::buffer_vector<float> *this@<ecx>,
        vostok::buffer_vector<float> *result@<eax>)
{
  float *m_begin; // edx
  float *m_end; // esi
  float *v4; // ecx

  m_begin = result->m_begin;
  m_end = this->m_end;
  v4 = this->m_begin;
  result->m_end = &result->m_begin[m_end - v4];
  while ( v4 != m_end )
  {
    if ( m_begin )
      *m_begin = *v4;
    ++v4;
    ++m_begin;
  }
  return result;
}


vostok::buffer_vector<survarium::animations_registry::animations_tuple> *__usercall vostok::buffer_vector<survarium::animations_registry::animations_tuple>::operator=@<eax>(
        vostok::buffer_vector<survarium::animations_registry::animations_tuple> *this@<esi>,
        const vostok::buffer_vector<survarium::animations_registry::animations_tuple> *other@<eax>)
{
  survarium::animations_registry::animations_tuple *m_begin; // ebx
  survarium::animations_registry::animations_tuple *v3; // eax
  survarium::animations_registry::animations_tuple *v4; // ecx
  const survarium::animations_registry::animations_tuple *v5; // edi
  survarium::animations_registry::animations_tuple *m_end; // [esp+Ch] [ebp-4h]

  m_begin = other->m_begin;
  m_end = other->m_end;
  vostok::buffer_vector<survarium::animations_registry::animations_tuple>::destroy(this->m_begin, &this->m_end);
  v3 = this->m_begin;
  v4 = &this->m_begin[m_end - m_begin];
  this->m_end = v4;
  v5 = v3;
  while ( m_begin != m_end )
  {
    if ( v5 )
      survarium::animations_registry::animations_tuple::animations_tuple(v4, v5, (int)m_begin);
    ++m_begin;
    ++v5;
  }
  return this;
}
