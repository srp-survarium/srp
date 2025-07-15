int __thiscall Wm4::Query2<float>::ToLine(Wm4::Query2<float> *this, const Wm4::Vector2<float> *rkP, int iV0, int iV1)
{
  bool v5; // al
  const Wm4::Vector2<float> *m_akVertex; // ecx
  float v7; // xmm0_4

  v5 = Wm4::Query::Sort(&iV0, &iV1);
  m_akVertex = this->m_akVertex;
  v7 = (float)((float)(m_akVertex[iV1].m_afTuple[1] - m_akVertex[iV0].m_afTuple[1])
             * (float)(rkP->m_afTuple[0] - m_akVertex[iV0].m_afTuple[0]))
     - (float)((float)(rkP->m_afTuple[1] - m_akVertex[iV0].m_afTuple[1])
             * (float)(m_akVertex[iV1].m_afTuple[0] - m_akVertex[iV0].m_afTuple[0]));
  if ( !v5 )
    LODWORD(v7) ^= _mask__NegFloat_;
  if ( v7 > 0.0 )
    return 1;
  if ( v7 >= 0.0 )
    return 0;
  return -1;
}


int __thiscall Wm4::Query2<float>::ToLine(Wm4::Query2<float> *this, int i, int iV0, int iV1)
{
  return ((int (__stdcall *)(const Wm4::Vector2<float> *, int, int))this->ToLine)(&this->m_akVertex[i], iV0, iV1);
}
