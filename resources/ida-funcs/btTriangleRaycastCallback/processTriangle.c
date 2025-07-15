void __thiscall btTriangleRaycastCallback::processTriangle(
        btTriangleRaycastCallback *this,
        btVector3 *triangle,
        int partId,
        int triangleIndex)
{
  float v5; // xmm0_4
  float v6; // xmm6_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm7_4
  float v11; // xmm1_4
  float v12; // xmm4_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm5_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float v21; // xmm2_4
  float v22; // xmm4_4
  float v23; // xmm2_4
  float v24; // xmm4_4
  float v25; // xmm1_4
  float v26; // xmm4_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm4_4
  unsigned int m_flags; // eax
  float v31; // xmm2_4
  float m_hitFraction; // xmm1_4
  float v33; // xmm5_4
  float v34; // xmm4_4
  float v35; // xmm1_4
  float v36; // xmm0_4
  float v37; // xmm4_4
  float v38; // xmm5_4
  float v39; // xmm7_4
  float v40; // xmm4_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  double v43; // st7
  float v44; // [esp+18h] [ebp-94h]
  float v45[5]; // [esp+1Ch] [ebp-90h] BYREF
  float v46; // [esp+30h] [ebp-7Ch]
  float v47; // [esp+34h] [ebp-78h]
  int v48; // [esp+38h] [ebp-74h]
  float v49; // [esp+44h] [ebp-68h]
  float v50; // [esp+48h] [ebp-64h]
  float v51; // [esp+4Ch] [ebp-60h] BYREF
  float v52; // [esp+50h] [ebp-5Ch]
  float v53; // [esp+54h] [ebp-58h]
  int v54; // [esp+58h] [ebp-54h]
  float v55; // [esp+5Ch] [ebp-50h]
  float v56; // [esp+60h] [ebp-4Ch]
  float v57; // [esp+64h] [ebp-48h]
  float v58; // [esp+6Ch] [ebp-40h]
  float v59; // [esp+70h] [ebp-3Ch]
  float v60; // [esp+74h] [ebp-38h]
  float v61; // [esp+78h] [ebp-34h]
  float v62; // [esp+7Ch] [ebp-30h]
  float v63; // [esp+80h] [ebp-2Ch]
  float v64; // [esp+84h] [ebp-28h]
  float v65; // [esp+88h] [ebp-24h]
  float v66; // [esp+90h] [ebp-1Ch]
  float v67; // [esp+94h] [ebp-18h]
  float v68; // [esp+A4h] [ebp-8h]

  v5 = triangle[1].mVec128.m128_f32[0];
  v6 = triangle->mVec128.m128_f32[0];
  v7 = triangle->mVec128.m128_f32[2];
  v8 = triangle[2].mVec128.m128_f32[2];
  v9 = triangle[1].mVec128.m128_f32[1];
  v10 = triangle->mVec128.m128_f32[1];
  v65 = triangle[2].mVec128.m128_f32[0];
  v51 = v65 - v6;
  v11 = triangle[2].mVec128.m128_f32[1];
  v64 = v9;
  v58 = v8;
  v12 = v8 - v7;
  v13 = v9 - v10;
  v60 = v5;
  v45[0] = v5 - v6;
  v14 = triangle[1].mVec128.m128_f32[2];
  v62 = v11;
  v59 = v14;
  v15 = v14 - v7;
  v50 = v7;
  v48 = 0;
  v16 = (float)(v11 - v10) * v15;
  v17 = (float)(v15 * (float)(v65 - v6)) - (float)(v12 * v45[0]);
  v18 = (float)(v12 * v13) - v16;
  v47 = (float)((float)(v11 - v10) * v45[0]) - (float)(v13 * (float)(v65 - v6));
  v19 = this->m_from.mVec128.m128_f32[1] * v17;
  v45[4] = v18;
  v46 = v17;
  v20 = (float)((float)(v50 * v47) + (float)(v10 * v17)) + (float)(v6 * v18);
  v21 = (float)(this->m_from.mVec128.m128_f32[2] * v47) + v19;
  v22 = this->m_from.mVec128.m128_f32[0];
  v51 = v18;
  v23 = v21 + (float)(v22 * v18);
  v24 = this->m_to.mVec128.m128_f32[2];
  v25 = this->m_to.mVec128.m128_f32[1];
  v52 = v17;
  v26 = (float)(v24 * v47) + (float)(v25 * v17);
  v27 = this->m_to.mVec128.m128_f32[0];
  v53 = v47;
  v28 = v23 - v20;
  v29 = (float)(v26 + (float)(v27 * v18)) - v20;
  v54 = 0;
  v63 = v28;
  if ( (float)(v29 * v28) < 0.0 )
  {
    m_flags = this->m_flags;
    if ( (m_flags & 1) == 0 || v28 <= 0.0 )
    {
      v31 = v28 / (float)(v28 - v29);
      m_hitFraction = this->m_hitFraction;
      v49 = v31;
      if ( m_hitFraction > v31 )
      {
        v33 = this->m_from.mVec128.m128_f32[1];
        v34 = this->m_to.mVec128.m128_f32[0];
        v35 = (float)((float)(v47 * v47) + (float)(v17 * v17)) + (float)(v18 * v18);
        v36 = this->m_from.mVec128.m128_f32[0];
        v61 = v35;
        v44 = v35 * -0.000099999997;
        v37 = (float)(v34 * v31) + (float)(v36 * (float)(s_bm_current_air_resistance - v31));
        v38 = (float)(v33 * (float)(s_bm_current_air_resistance - v31)) + (float)(this->m_to.mVec128.m128_f32[1] * v31);
        v68 = (float)(this->m_from.mVec128.m128_f32[2] * (float)(s_bm_current_air_resistance - v31))
            + (float)(this->m_to.mVec128.m128_f32[2] * v31);
        v56 = v10 - v38;
        v39 = v60 - v37;
        v66 = v64 - v38;
        v67 = v59 - v68;
        v57 = v50 - v68;
        v55 = v6 - v37;
        if ( (float)((float)((float)((float)((float)((float)(v64 - v38) * v55) - (float)(v56 * v39)) * v47)
                           + (float)((float)((float)((float)(v50 - v68) * v39) - (float)((float)(v59 - v68) * v55)) * v46))
                   + (float)((float)((float)((float)(v59 - v68) * v56) - (float)((float)(v64 - v38) * (float)(v50 - v68)))
                           * v18)) >= (float)(v35 * -0.000099999997) )
        {
          v45[0] = v65 - v37;
          if ( (float)((float)((float)((float)((float)((float)(v62 - v38) * v39) - (float)(v66 * v45[0])) * v47)
                             + (float)((float)((float)(v67 * v45[0]) - (float)((float)(v58 - v68) * v39)) * v46))
                     + (float)((float)((float)((float)(v58 - v68) * v66) - (float)((float)(v62 - v38) * v67)) * v18)) >= v44
            && (float)((float)((float)((float)((float)(v56 * v45[0]) - (float)((float)(v62 - v38) * v55)) * v47)
                             + (float)((float)((float)((float)(v58 - v68) * v55) - (float)(v57 * v45[0])) * v46))
                     + (float)((float)((float)((float)(v62 - v38) * v57) - (float)((float)(v58 - v68) * v56)) * v18)) >= v44 )
          {
            v40 = s_bm_current_air_resistance / fsqrt(v61);
            v41 = v52 * v40;
            v42 = v53 * v40;
            v51 = v40 * v18;
            v52 = v52 * v40;
            v53 = v53 * v40;
            if ( (m_flags & 2) != 0 || v63 <= 0.0 )
            {
              LODWORD(v45[1]) = LODWORD(v41) ^ _mask__NegFloat_;
              LODWORD(v45[0]) = COERCE_UNSIGNED_INT(v40 * v18) ^ _mask__NegFloat_;
              LODWORD(v45[2]) = LODWORD(v42) ^ _mask__NegFloat_;
              v45[3] = 0.0;
              v43 = ((double (__thiscall *)(btTriangleRaycastCallback *, float *, _DWORD, int, int))this->reportHit)(
                      this,
                      v45,
                      LODWORD(v49),
                      partId,
                      triangleIndex);
            }
            else
            {
              v43 = ((double (__thiscall *)(btTriangleRaycastCallback *, float *, _DWORD, int, int))this->reportHit)(
                      this,
                      &v51,
                      LODWORD(v49),
                      partId,
                      triangleIndex);
            }
            this->m_hitFraction = v43;
          }
        }
      }
    }
  }
}
