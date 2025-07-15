char __thiscall btTriangleShape::isInside(btTriangleShape *this, const btVector3 *pt, float tolerance)
{
  float v4; // xmm0_4
  int v5; // ebx
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm4_4
  float v11; // [esp+10h] [ebp-30h] BYREF
  float v12; // [esp+14h] [ebp-2Ch]
  float v13; // [esp+18h] [ebp-28h]
  float v14; // [esp+20h] [ebp-20h] BYREF
  float v15; // [esp+24h] [ebp-1Ch]
  float v16; // [esp+28h] [ebp-18h]
  float v17; // [esp+30h] [ebp-10h] BYREF
  float v18; // [esp+34h] [ebp-Ch]
  float v19; // [esp+38h] [ebp-8h]

  btTriangleShape::calcNormal((btTriangleShape *)&v11, (float *)this);
  v4 = (float)((float)((float)(pt->mVec128.m128_f32[0] * v11) + (float)(pt->mVec128.m128_f32[1] * v12))
             + (float)(pt->mVec128.m128_f32[2] * v13))
     - (float)((float)((float)(this->m_vertices1[0].mVec128.m128_f32[1] * v12)
                     + (float)(this->m_vertices1[0].mVec128.m128_f32[2] * v13))
             + (float)(this->m_vertices1[0].mVec128.m128_f32[0] * v11));
  if ( v4 >= COERCE_FLOAT(LODWORD(tolerance) ^ _mask__NegFloat_) && tolerance >= v4 )
  {
    v5 = 0;
    while ( 1 )
    {
      this->getEdge(this, v5, (btVector3 *)&v14, (btVector3 *)&v17);
      v6 = (float)(v12 * (float)(v17 - v14)) - (float)((float)(v18 - v15) * v11);
      v7 = (float)((float)(v18 - v15) * v13) - (float)((float)(v19 - v16) * v12);
      v8 = (float)((float)(v19 - v16) * v11) - (float)((float)(v17 - v14) * v13);
      v9 = fsqrt((float)((float)(v6 * v6) + (float)(v8 * v8)) + (float)(v7 * v7));
      if ( COERCE_FLOAT(LODWORD(tolerance) ^ _mask__NegFloat_) > (float)((float)((float)((float)(pt->mVec128.m128_f32[0]
                                                                                               * (float)(v7 * (float)(s_bm_current_air_resistance / v9)))
                                                                                       + (float)(pt->mVec128.m128_f32[2]
                                                                                               * (float)(v6 * (float)(s_bm_current_air_resistance / v9))))
                                                                               + (float)(pt->mVec128.m128_f32[1]
                                                                                       * (float)(v8
                                                                                               * (float)(s_bm_current_air_resistance / v9))))
                                                                       - (float)((float)((float)((float)(v8 * (float)(s_bm_current_air_resistance / v9))
                                                                                               * v15)
                                                                                       + (float)((float)(v6 * (float)(s_bm_current_air_resistance / v9))
                                                                                               * v16))
                                                                               + (float)((float)(v7
                                                                                               * (float)(s_bm_current_air_resistance / v9))
                                                                                       * v14))) )
        break;
      if ( ++v5 >= 3 )
        return 1;
    }
  }
  return 0;
}
