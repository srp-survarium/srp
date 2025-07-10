int __thiscall Wm4::Query2<float>::ToLine(Wm4::Query2<float> *this, const Wm4::Vector2<float> *rkP, int iV0, int iV1)
{
  int v4; // edx
  int v5; // eax
  char v6; // bl
  const Wm4::Vector2<float> *m_akVertex; // ecx
  int v8; // edx
  float *m_afTuple; // eax
  double v10; // st7
  double v11; // st7
  double v12; // st6
  _DWORD v14[2]; // [esp+Ch] [ebp-8h]
  float fDet2a; // [esp+1Ch] [ebp+8h]
  float fDet2b; // [esp+1Ch] [ebp+8h]
  float fDet2c; // [esp+1Ch] [ebp+8h]
  float fDet2d; // [esp+1Ch] [ebp+8h]
  float fDet2; // [esp+1Ch] [ebp+8h]

  if ( iV0 >= iV1 )
  {
    v4 = 0;
    v5 = 1;
    v6 = 0;
  }
  else
  {
    v4 = 1;
    v5 = 0;
    v6 = 1;
  }
  m_akVertex = this->m_akVertex;
  v14[0] = iV0;
  v14[1] = iV1;
  v8 = v14[v4];
  m_afTuple = m_akVertex[v14[v5]].m_afTuple;
  fDet2a = m_akVertex[v8].m_afTuple[1] - m_afTuple[1];
  v10 = fDet2a;
  fDet2b = rkP->m_afTuple[0] - *m_afTuple;
  v11 = v10 * fDet2b;
  fDet2c = rkP->m_afTuple[1] - m_afTuple[1];
  v12 = fDet2c;
  fDet2d = m_akVertex[v8].m_afTuple[0] - *m_afTuple;
  fDet2 = v11 - v12 * fDet2d;
  if ( !v6 )
    fDet2 = -fDet2;
  if ( fDet2 > 0.0 )
    return 1;
  if ( fDet2 >= 0.0 )
    return 0;
  return -1;
}
