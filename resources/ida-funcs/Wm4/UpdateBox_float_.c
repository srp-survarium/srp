void __usercall Wm4::UpdateBox_float_(
        const Wm4::Vector2<float> *rkLPoint@<edi>,
        const Wm4::Vector2<float> *rkBPoint@<esi>,
        const Wm4::Vector2<float> *rkV@<ecx>,
        Wm4::Box2<float> *rkBox@<eax>,
        const Wm4::Vector2<float> *rkRPoint,
        const Wm4::Vector2<float> *rkTPoint,
        const Wm4::Vector2<float> *rkU,
        float *rfMinAreaDiv4)
{
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  float v11; // xmm7_4
  float v12; // xmm1_4
  float v13; // xmm5_4
  float v14; // xmm4_4
  float v15; // xmm1_4
  float v16; // xmm0_4

  v8 = (float)((float)(rkU->m_afTuple[0] * (float)(rkRPoint->m_afTuple[0] - rkLPoint->m_afTuple[0]))
             + (float)((float)(rkRPoint->m_afTuple[1] - rkLPoint->m_afTuple[1]) * rkU->m_afTuple[1]))
     * 0.5;
  v9 = (float)((float)(rkV->m_afTuple[1] * (float)(rkTPoint->m_afTuple[1] - rkBPoint->m_afTuple[1]))
             + (float)(rkV->m_afTuple[0] * (float)(rkTPoint->m_afTuple[0] - rkBPoint->m_afTuple[0])))
     * 0.5;
  if ( *rfMinAreaDiv4 > (float)(v9 * v8) )
  {
    rkBox->Axis[0] = *rkU;
    *rfMinAreaDiv4 = v9 * v8;
    rkBox->Axis[1] = *rkV;
    rkBox->Extent[1] = v9;
    rkBox->Extent[0] = v8;
    v10 = rkLPoint->m_afTuple[1];
    v11 = rkV->m_afTuple[1];
    v12 = v9
        - (float)((float)(v11 * (float)(v10 - rkBPoint->m_afTuple[1]))
                + (float)(rkV->m_afTuple[0] * (float)(rkLPoint->m_afTuple[0] - rkBPoint->m_afTuple[0])));
    v13 = rkV->m_afTuple[0] * v12;
    v14 = v11 * v12;
    v15 = rkU->m_afTuple[0] * v8;
    v16 = v8 * rkU->m_afTuple[1];
    rkBox->Center.m_afTuple[0] = (float)(rkLPoint->m_afTuple[0] + v15) + v13;
    rkBox->Center.m_afTuple[1] = (float)(v10 + v16) + v14;
  }
}
