void __usercall Wm4::Vector2<float>::operator=(vostok::math::float2 *this@<ecx>, vostok::math::float2 *a2@<eax>)
{
  *a2 = *this;
}


float *__usercall Wm4::Vector2<float>::operator*@<eax>(float *result@<eax>, float *a2@<ecx>, float a3@<xmm0>)
{
  *result = *a2 * a3;
  result[1] = a2[1] * a3;
  return result;
}


Wm4::Vector2<float> *__userpurge Wm4::Vector2<float>::operator-@<eax>(
        Wm4::Vector2<float> *this@<ecx>,
        Wm4::Vector2<float> *a2@<eax>,
        Wm4::Vector2<float> *result,
        const Wm4::Vector2<float> *rkV)
{
  a2->m_afTuple[0] = result->m_afTuple[0] - this->m_afTuple[0];
  a2->m_afTuple[1] = result->m_afTuple[1] - this->m_afTuple[1];
  return a2;
}


Wm4::Vector2<float> *__userpurge Wm4::Vector2<float>::operator+@<eax>(
        Wm4::Vector2<float> *this@<ecx>,
        Wm4::Vector2<float> *a2@<eax>,
        Wm4::Vector2<float> *result,
        const Wm4::Vector2<float> *rkV)
{
  a2->m_afTuple[0] = this->m_afTuple[0] + result->m_afTuple[0];
  a2->m_afTuple[1] = this->m_afTuple[1] + result->m_afTuple[1];
  return a2;
}
