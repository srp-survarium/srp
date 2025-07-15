int __thiscall Wm4::Query2<float>::ToCircumcircle(
        Wm4::Query2<float> *this,
        const Wm4::Vector2<float> *rkP,
        int iV0,
        int iV1,
        int iV2)
{
  char v6; // al
  const Wm4::Vector2<float> *m_akVertex; // edx
  float *m_afTuple; // ecx
  float v9; // xmm5_4
  float *v10; // edi
  float v11; // xmm4_4
  float *v12; // esi
  float v14; // xmm6_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm5_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm3_4
  float v25; // [esp+8h] [ebp-4h]

  v6 = Wm4::Query::Sort(&iV0, &iV1, &iV2);
  m_akVertex = this->m_akVertex;
  m_afTuple = m_akVertex[iV0].m_afTuple;
  v9 = m_afTuple[1];
  v10 = m_akVertex[iV2].m_afTuple;
  v11 = *v10;
  v12 = m_akVertex[iV1].m_afTuple;
  v14 = rkP->m_afTuple[0];
  v15 = *v12;
  v25 = *v12 - rkP->m_afTuple[0];
  v16 = v12[1];
  *(float *)&iV2 = *m_afTuple - rkP->m_afTuple[0];
  v17 = rkP->m_afTuple[1];
  *(float *)&iV0 = v16 - v17;
  v18 = v10[1];
  v19 = v9 - v17;
  *(float *)&iV1 = v18 - v17;
  v20 = (float)((float)(v16 + rkP->m_afTuple[1]) * (float)(v16 - v17)) + (float)((float)(v15 + rkP->m_afTuple[0]) * v25);
  v21 = (float)((float)(v18 + rkP->m_afTuple[1]) * (float)(v18 - v17))
      + (float)((float)(v11 + rkP->m_afTuple[0]) * (float)(v11 - v14));
  v22 = (float)((float)(v17 + m_afTuple[1]) * v19) + (float)((float)(v14 + *m_afTuple) * *(float *)&iV2);
  v23 = (float)((float)((float)((float)(v21 * *(float *)&iV0) - (float)(v20 * *(float *)&iV1)) * *(float *)&iV2)
              + (float)((float)((float)(v20 * v19) - (float)(v22 * *(float *)&iV0)) * (float)(v11 - v14)))
      + (float)((float)((float)(v22 * *(float *)&iV1) - (float)(v21 * v19)) * v25);
  if ( !v6 )
    LODWORD(v23) ^= _mask__NegFloat_;
  if ( v23 < 0.0 )
    return 1;
  if ( v23 <= 0.0 )
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
