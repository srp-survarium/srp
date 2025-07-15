int __thiscall Wm4::Query2<float>::ToCircumcircle(
        Wm4::Query2<float> *this,
        const Wm4::Vector2<float> *rkP,
        float iV0,
        float iV1,
        float iV2)
{
  bool v6; // al
  const Wm4::Vector2<float> *m_akVertex; // ecx
  float v8; // edx
  float v9; // esi
  float v10; // edi
  float *v12; // ebp
  float *v13; // ebx
  double v14; // st7
  double v15; // st7
  double v16; // st7
  float fZ1; // [esp+14h] [ebp-30h]
  float fZ2; // [esp+20h] [ebp-24h]
  bool bPositive; // [esp+37h] [ebp-Dh]
  float fD1y; // [esp+38h] [ebp-Ch]
  float fD0y; // [esp+3Ch] [ebp-8h]
  float fD0x; // [esp+40h] [ebp-4h]
  float fD1x; // [esp+48h] [ebp+4h]

  v6 = Wm4::Query::Sort((int *)&iV0, (int *)&iV1, (int *)&iV2);
  m_akVertex = this->m_akVertex;
  v8 = iV0;
  v9 = iV1;
  v10 = iV2;
  bPositive = v6;
  v12 = &m_akVertex[LODWORD(iV1)].m_afTuple[1];
  v13 = &m_akVertex[LODWORD(iV2)].m_afTuple[1];
  fD0x = m_akVertex[LODWORD(iV0)].m_afTuple[0] - rkP->m_afTuple[0];
  fD0y = m_akVertex[LODWORD(iV0)].m_afTuple[1] - rkP->m_afTuple[1];
  fD1x = m_akVertex[LODWORD(iV1)].m_afTuple[0] - rkP->m_afTuple[0];
  fD1y = *v12 - rkP->m_afTuple[1];
  iV1 = m_akVertex[LODWORD(iV2)].m_afTuple[0] - rkP->m_afTuple[0];
  iV2 = *v13 - rkP->m_afTuple[1];
  iV0 = rkP->m_afTuple[0] + m_akVertex[LODWORD(v10)].m_afTuple[0];
  v14 = iV0 * iV1;
  iV0 = *v13 + rkP->m_afTuple[1];
  iV0 = iV0 * iV2 + v14;
  fZ2 = iV0;
  iV0 = rkP->m_afTuple[0] + m_akVertex[LODWORD(v9)].m_afTuple[0];
  v15 = iV0 * fD1x;
  iV0 = *v12 + rkP->m_afTuple[1];
  iV0 = iV0 * fD1y + v15;
  fZ1 = iV0;
  iV0 = m_akVertex[LODWORD(v8)].m_afTuple[1] + rkP->m_afTuple[1];
  v16 = iV0 * fD0y;
  iV0 = m_akVertex[LODWORD(v8)].m_afTuple[0] + rkP->m_afTuple[0];
  iV0 = iV0 * fD0x + v16;
  iV0 = Wm4::Query2<float>::Det3(fD0x, fD0y, iV0, fD1x, fD1y, fZ1, iV1, iV2, fZ2);
  if ( !bPositive )
    iV0 = -iV0;
  if ( iV0 < 0.0 )
    return 1;
  if ( iV0 <= 0.0 )
    return 0;
  return -1;
}


int __thiscall Wm4::Query2<float>::ToCircumcircle(Wm4::Query2<float> *this, int i, int iV0, int iV1, int iV2)
{
  return ((int (__stdcall *)(const Wm4::Vector2<float> *, int, int, int))this->ToCircumcircle)(
           &this->m_akVertex[i],
           iV0,
           iV1,
           iV2);
}
