void __thiscall btTriangleRaycastCallback::processTriangle(
        btTriangleRaycastCallback *this,
        btVector3 *triangle,
        int partId,
        int triangleIndex)
{
  float v5; // xmm0_4
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm6_4
  float v11; // xmm6_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  unsigned int m_flags; // ebx
  float v18; // xmm7_4
  float v19; // xmm6_4
  float v20; // xmm1_4
  float v21; // xmm7_4
  float v22; // xmm6_4
  float v23; // xmm4_4
  float v24; // xmm7_4
  float v25; // xmm4_4
  long double v26; // st7
  double v27; // st7
  float v28; // [esp+358h] [ebp-9Ch]
  float v29; // [esp+358h] [ebp-9Ch]
  float v30; // [esp+35Ch] [ebp-98h]
  float v31; // [esp+360h] [ebp-94h]
  float v32; // [esp+364h] [ebp-90h]
  float v33; // [esp+368h] [ebp-8Ch]
  __m128i v34; // [esp+374h] [ebp-80h] BYREF
  float v35; // [esp+384h] [ebp-70h]
  float v36; // [esp+388h] [ebp-6Ch]
  float v37; // [esp+38Ch] [ebp-68h]
  float v38; // [esp+394h] [ebp-60h]
  float v39; // [esp+398h] [ebp-5Ch]
  __m128i v40; // [esp+3A4h] [ebp-50h] BYREF
  float v41; // [esp+3B4h] [ebp-40h]
  float v42; // [esp+3B8h] [ebp-3Ch]
  float v43; // [esp+3BCh] [ebp-38h]
  float v44; // [esp+3D0h] [ebp-24h]
  float v45; // [esp+3D4h] [ebp-20h]
  float v46; // [esp+3D8h] [ebp-1Ch]
  float v47; // [esp+3DCh] [ebp-18h]
  float v48; // [esp+3E0h] [ebp-14h]
  float _X; // [esp+3E4h] [ebp-10h]
  float v50; // [esp+3E8h] [ebp-Ch]
  float v51; // [esp+3ECh] [ebp-8h]
  float v52; // [esp+3F0h] [ebp-4h]

  v5 = triangle[1].mVec128.m128_f32[0];
  v6 = triangle->mVec128.m128_f32[0];
  v7 = triangle->mVec128.m128_f32[1];
  v8 = triangle[1].mVec128.m128_f32[2];
  v9 = triangle[2].mVec128.m128_f32[1];
  v10 = triangle[2].mVec128.m128_f32[2];
  v31 = triangle->mVec128.m128_f32[2];
  v45 = triangle[1].mVec128.m128_f32[1];
  v52 = v10;
  v11 = v10 - v31;
  v51 = v5;
  v38 = v5 - v6;
  v48 = triangle[2].mVec128.m128_f32[0];
  v41 = v48 - v6;
  v46 = v8;
  v12 = v8 - v31;
  v44 = v9;
  v13 = v9 - v7;
  v14 = (float)(v11 * (float)(v45 - v7)) - (float)(v13 * v12);
  v15 = (float)(v12 * (float)(v48 - v6)) - (float)(v11 * v38);
  v16 = (float)(v13 * v38) - (float)((float)(v45 - v7) * (float)(v48 - v6));
  v34.m128i_i64[0] = __PAIR64__(LODWORD(v15), LODWORD(v14));
  v34.m128i_i64[1] = LODWORD(v16);
  v40 = _mm_load_si128(&v34);
  v28 = (float)((float)((float)(this->m_to.mVec128.m128_f32[2] * v16) + (float)(this->m_to.mVec128.m128_f32[1] * v15))
              + (float)(this->m_to.mVec128.m128_f32[0] * v14))
      - (float)((float)((float)(v31 * v16) + (float)(v7 * v15)) + (float)(v6 * v14));
  v47 = (float)((float)((float)(this->m_from.mVec128.m128_f32[2] * v16) + (float)(this->m_from.mVec128.m128_f32[1] * v15))
              + (float)(this->m_from.mVec128.m128_f32[0] * v14))
      - (float)((float)((float)(v31 * v16) + (float)(v7 * v15)) + (float)(v6 * v14));
  if ( (float)(v28 * v47) < 0.0 )
  {
    m_flags = this->m_flags;
    if ( (m_flags & 1) == 0 || v47 <= 0.0 )
    {
      v18 = v47 / (float)(v47 - v28);
      v30 = v18;
      if ( this->m_hitFraction > v18 )
      {
        v19 = this->m_to.mVec128.m128_f32[0];
        _X = (float)((float)(v16 * v16) + (float)(v15 * v15)) + (float)(v14 * v14);
        v29 = _X * -0.000099999997;
        v20 = *(float *)&clear_value - v18;
        v35 = (float)(v19 * v18) + (float)(this->m_from.mVec128.m128_f32[0] * (float)(*(float *)&clear_value - v18));
        v50 = this->m_from.mVec128.m128_f32[1] * (float)(*(float *)&clear_value - v18);
        v21 = v50 + (float)(this->m_to.mVec128.m128_f32[1] * v18);
        v22 = (float)(this->m_from.mVec128.m128_f32[2] * v20) + (float)(this->m_to.mVec128.m128_f32[2] * v30);
        v32 = v6 - v35;
        v33 = v7 - v21;
        v36 = v50 + (float)(this->m_to.mVec128.m128_f32[1] * v30);
        v23 = v45 - v21;
        v24 = v51 - v35;
        v42 = v23;
        v37 = v22;
        v43 = v46 - v22;
        if ( (float)((float)((float)((float)((float)(v23 * v32) - (float)(v33 * (float)(v51 - v35))) * v16)
                           + (float)((float)((float)((float)(v31 - v22) * (float)(v51 - v35)) - (float)(v43 * v32)) * v15))
                   + (float)((float)((float)(v43 * v33) - (float)(v23 * (float)(v31 - v22))) * v14)) >= (float)(_X * -0.000099999997) )
        {
          v38 = v48 - v35;
          v39 = v44 - v36;
          v25 = (float)((float)(v52 - v37) * v42) - (float)((float)(v44 - v36) * v43);
          v36 = (float)(v43 * (float)(v48 - v35)) - (float)((float)(v52 - v37) * v24);
          if ( (float)((float)((float)((float)((float)(v39 * v24) - (float)(v42 * (float)(v48 - v35))) * v16)
                             + (float)(v36 * v15))
                     + (float)(v25 * v14)) >= v29
            && (float)((float)((float)((float)((float)(v33 * v38) - (float)(v39 * v32)) * v16)
                             + (float)((float)((float)((float)(v52 - v37) * v32) - (float)((float)(v31 - v22) * v38))
                                     * v15))
                     + (float)((float)((float)(v39 * (float)(v31 - v22)) - (float)((float)(v52 - v37) * v33)) * v14)) >= v29 )
          {
            v26 = 1.0 / sqrtf(_X);
            *(float *)v40.m128i_i32 = *(float *)v34.m128i_i32 * v26;
            *(float *)&v40.m128i_i32[1] = *(float *)&v40.m128i_i32[1] * v26;
            *(float *)&v40.m128i_i32[2] = v26 * *(float *)&v40.m128i_i32[2];
            if ( (m_flags & 2) != 0 || v47 <= 0.0 )
            {
              v34.m128i_i64[0] = v40.m128i_i64[0] ^ 0x8000000080000000uLL;
              v34.m128i_i64[1] = COERCE_UNSIGNED_INT(-*(float *)&v40.m128i_i32[2]);
              v27 = ((double (__thiscall *)(btTriangleRaycastCallback *, __m128i *, _DWORD, int, int))this->reportHit)(
                      this,
                      &v34,
                      LODWORD(v30),
                      partId,
                      triangleIndex);
            }
            else
            {
              v27 = ((double (__thiscall *)(btTriangleRaycastCallback *, __m128i *, _DWORD, int, int))this->reportHit)(
                      this,
                      &v40,
                      LODWORD(v30),
                      partId,
                      triangleIndex);
            }
            this->m_hitFraction = v27;
          }
        }
      }
    }
  }
}
