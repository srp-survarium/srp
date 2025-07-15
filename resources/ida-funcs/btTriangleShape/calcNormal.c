void __usercall btTriangleShape::calcNormal(btTriangleShape *this@<ecx>, float *a2@<eax>)
{
  float v2; // xmm3_4
  float v3; // xmm2_4
  float v4; // xmm0_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm1_4
  int m_shapeType; // xmm1_4
  void *m_userPointer; // xmm0_4
  float v10; // xmm3_4

  v2 = a2[25] - a2[21];
  v3 = a2[30] - a2[22];
  v4 = a2[24] - a2[20];
  v5 = a2[28] - a2[20];
  v6 = a2[29] - a2[21];
  v7 = a2[26] - a2[22];
  *(float *)&this->__vftable = (float)(v2 * v3) - (float)(v7 * v6);
  *(float *)&this->m_shapeType = (float)(v7 * v5) - (float)(v3 * v4);
  *(float *)&this->m_userPointer = (float)(v4 * v6) - (float)(v2 * v5);
  *((_DWORD *)&this->btCollisionShape + 3) = 0;
  m_shapeType = this->m_shapeType;
  m_userPointer = this->m_userPointer;
  v10 = s_bm_current_air_resistance
      / fsqrt(
          (float)((float)(*(float *)&this->__vftable * *(float *)&this->__vftable)
                + (float)(*(float *)&m_shapeType * *(float *)&m_shapeType))
        + (float)(*(float *)&m_userPointer * *(float *)&m_userPointer));
  *(float *)&this->__vftable = *(float *)&this->__vftable * v10;
  *(float *)&this->m_shapeType = *(float *)&m_shapeType * v10;
  *(float *)&this->m_userPointer = *(float *)&m_userPointer * v10;
}
