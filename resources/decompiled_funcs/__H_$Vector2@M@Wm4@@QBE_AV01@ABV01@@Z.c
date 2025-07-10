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
