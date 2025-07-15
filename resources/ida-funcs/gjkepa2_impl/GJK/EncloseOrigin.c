char __thiscall gjkepa2_impl::GJK::EncloseOrigin(gjkepa2_impl::GJK *this)
{
  gjkepa2_impl::GJK::sSimplex *m_simplex; // eax
  float *v3; // ecx
  float *v4; // edx
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm3_4
  float *v8; // edx
  float *v9; // eax
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm6_4
  float v14; // xmm1_4
  float *v16; // edx
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm4_4
  float *v20; // edx
  float v21; // xmm3_4
  float v22; // xmm1_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  float v25; // xmm7_4
  unsigned int v26; // xmm0_4
  gjkepa2_impl::GJK::sSimplex *v27; // eax
  int v28; // xmm1_4
  gjkepa2_impl::GJK::sSimplex *v29; // eax
  gjkepa2_impl::GJK::sSimplex *v30; // eax
  float *m128_f32; // ecx
  float *v32; // eax
  float v33; // xmm6_4
  float v34; // xmm2_4
  float v35; // xmm5_4
  int v36; // edi
  gjkepa2_impl::GJK::sSimplex *v37; // eax
  int v38; // xmm1_4
  gjkepa2_impl::GJK::sSimplex *v39; // eax
  gjkepa2_impl::GJK::sSimplex *v40; // eax
  int v41; // edi
  gjkepa2_impl::GJK::sSimplex *v42; // eax
  gjkepa2_impl::GJK::sSimplex *v43; // eax
  int v44; // xmm1_4
  gjkepa2_impl::GJK::sSimplex *v45; // eax
  gjkepa2_impl::GJK::sSimplex *v46; // eax
  btVector3 v; // [esp+10h] [ebp-40h] BYREF
  btVector3 v48; // [esp+20h] [ebp-30h] BYREF
  btVector3 v49; // [esp+30h] [ebp-20h] BYREF
  btVector3 v50; // [esp+40h] [ebp-10h] BYREF

  m_simplex = this->m_simplex;
  switch ( m_simplex->rank )
  {
    case 1u:
      v41 = 0;
      while ( 1 )
      {
        memset(&v, 0, sizeof(v));
        v42 = this->m_simplex;
        v.mVec128.m128_f32[v41] = s_bm_current_air_resistance;
        gjkepa2_impl::GJK::appendvertice(this, v42, &v);
        if ( gjkepa2_impl::GJK::EncloseOrigin(this) )
          break;
        v43 = this->m_simplex;
        --v43->rank;
        v44 = v.mVec128.m128_i32[0];
        this->m_free[this->m_nfree++] = v43->c[v43->rank];
        v50.mVec128.m128_i32[0] = v44 ^ _mask__NegFloat_;
        v50.mVec128.m128_i32[1] = v.mVec128.m128_i32[1] ^ _mask__NegFloat_;
        v45 = this->m_simplex;
        v50.mVec128.m128_u64[1] = v.mVec128.m128_i32[2] ^ (unsigned int)_mask__NegFloat_;
        gjkepa2_impl::GJK::appendvertice(this, v45, &v50);
        if ( gjkepa2_impl::GJK::EncloseOrigin(this) )
          break;
        v46 = this->m_simplex;
        this->m_free[this->m_nfree++] = v46->c[--v46->rank];
        if ( (unsigned int)++v41 >= 3 )
          return 0;
      }
      return 1;
    case 2u:
      m128_f32 = m_simplex->c[0]->d.mVec128.m128_f32;
      v32 = m_simplex->c[1]->d.mVec128.m128_f32;
      v33 = v32[5] - m128_f32[5];
      v34 = v32[6] - m128_f32[6];
      v35 = v32[4] - m128_f32[4];
      v49.mVec128.m128_f32[0] = v35;
      *(unsigned __int64 *)((char *)v49.mVec128.m128_u64 + 4) = __PAIR64__(LODWORD(v34), LODWORD(v33));
      v36 = 0;
      v48.mVec128.m128_i32[3] = 0;
      while ( 1 )
      {
        memset(&v, 0, 12);
        v.mVec128.m128_f32[v36] = s_bm_current_air_resistance;
        v48.mVec128.m128_f32[2] = (float)(v.mVec128.m128_f32[1] * v35) - (float)(v33 * v.mVec128.m128_f32[0]);
        v48.mVec128.m128_f32[1] = (float)(v34 * v.mVec128.m128_f32[0]) - (float)(v.mVec128.m128_f32[2] * v35);
        v48.mVec128.m128_f32[0] = (float)(v.mVec128.m128_f32[2] * v33) - (float)(v.mVec128.m128_f32[1] * v34);
        if ( (float)((float)((float)(v48.mVec128.m128_f32[2] * v48.mVec128.m128_f32[2])
                           + (float)(v48.mVec128.m128_f32[1] * v48.mVec128.m128_f32[1]))
                   + (float)(v48.mVec128.m128_f32[0] * v48.mVec128.m128_f32[0])) > 0.0 )
        {
          gjkepa2_impl::GJK::appendvertice(this, this->m_simplex, &v48);
          if ( gjkepa2_impl::GJK::EncloseOrigin(this) )
            return 1;
          v37 = this->m_simplex;
          --v37->rank;
          v38 = v48.mVec128.m128_i32[0];
          this->m_free[this->m_nfree++] = v37->c[v37->rank];
          v50.mVec128.m128_i32[0] = v38 ^ _mask__NegFloat_;
          v50.mVec128.m128_i32[1] = v48.mVec128.m128_i32[1] ^ _mask__NegFloat_;
          v39 = this->m_simplex;
          v50.mVec128.m128_u64[1] = v48.mVec128.m128_i32[2] ^ (unsigned int)_mask__NegFloat_;
          gjkepa2_impl::GJK::appendvertice(this, v39, &v50);
          if ( gjkepa2_impl::GJK::EncloseOrigin(this) )
            return 1;
          v40 = this->m_simplex;
          --v40->rank;
          v33 = v49.mVec128.m128_f32[1];
          v35 = v49.mVec128.m128_f32[0];
          this->m_free[this->m_nfree++] = v40->c[v40->rank];
        }
        v34 = v49.mVec128.m128_f32[2];
        if ( (unsigned int)++v36 >= 3 )
          return 0;
      }
    case 3u:
      v16 = m_simplex->c[2]->d.mVec128.m128_f32;
      v17 = v16[6] - m_simplex->c[0]->w.mVec128.m128_f32[2];
      v18 = v16[5] - m_simplex->c[0]->w.mVec128.m128_f32[1];
      v19 = v16[4];
      v20 = m_simplex->c[1]->d.mVec128.m128_f32;
      v21 = v20[5] - m_simplex->c[0]->w.mVec128.m128_f32[1];
      v22 = v20[6] - m_simplex->c[0]->w.mVec128.m128_f32[2];
      v23 = v19 - m_simplex->c[0]->w.mVec128.m128_f32[0];
      v24 = v20[4] - m_simplex->c[0]->w.mVec128.m128_f32[0];
      v25 = v22 * v18;
      *(float *)&v26 = (float)(v18 * v24) - (float)(v21 * v23);
      v.mVec128.m128_u64[1] = v26;
      v.mVec128.m128_f32[1] = (float)(v22 * v23) - (float)(v17 * v24);
      v.mVec128.m128_f32[0] = (float)(v21 * v17) - v25;
      if ( (float)((float)((float)(*(float *)&v26 * *(float *)&v26)
                         + (float)(v.mVec128.m128_f32[1] * v.mVec128.m128_f32[1]))
                 + (float)(v.mVec128.m128_f32[0] * v.mVec128.m128_f32[0])) > 0.0 )
      {
        gjkepa2_impl::GJK::appendvertice(this, m_simplex, &v);
        if ( gjkepa2_impl::GJK::EncloseOrigin(this) )
          return 1;
        v27 = this->m_simplex;
        --v27->rank;
        v28 = v.mVec128.m128_i32[0];
        this->m_free[this->m_nfree++] = v27->c[v27->rank];
        v49.mVec128.m128_i32[0] = v28 ^ _mask__NegFloat_;
        v49.mVec128.m128_i32[1] = v.mVec128.m128_i32[1] ^ _mask__NegFloat_;
        v29 = this->m_simplex;
        v49.mVec128.m128_u64[1] = v.mVec128.m128_i32[2] ^ (unsigned int)_mask__NegFloat_;
        gjkepa2_impl::GJK::appendvertice(this, v29, &v49);
        if ( gjkepa2_impl::GJK::EncloseOrigin(this) )
          return 1;
        v30 = this->m_simplex;
        this->m_free[this->m_nfree++] = v30->c[--v30->rank];
      }
      break;
    case 4u:
      v3 = m_simplex->c[3]->d.mVec128.m128_f32;
      v4 = m_simplex->c[2]->d.mVec128.m128_f32;
      v5 = v4[5] - v3[5];
      v6 = v4[6] - v3[6];
      v7 = v4[4];
      v8 = m_simplex->c[1]->d.mVec128.m128_f32;
      v9 = m_simplex->c[0]->d.mVec128.m128_f32;
      v10 = v9[6] - v3[6];
      v11 = v7 - v3[4];
      v49.mVec128.m128_f32[1] = v8[5] - v3[5];
      v12 = v8[6] - v3[6];
      v9 += 4;
      v13 = v8[4] - v3[4];
      v50.mVec128.m128_f32[0] = *v9 - v3[4];
      v14 = v9[1] - v3[5];
      if ( COERCE_FLOAT(
             COERCE_UNSIGNED_INT(
               (float)((float)((float)((float)((float)((float)(v10 * v5) * v13) + (float)((float)(v14 * v12) * v11))
                                     - (float)((float)(v12 * v5) * v50.mVec128.m128_f32[0]))
                             - (float)((float)(v14 * v6) * v13))
                     + (float)((float)(v49.mVec128.m128_f32[1] * v6) * v50.mVec128.m128_f32[0]))
             - (float)((float)(v10 * v49.mVec128.m128_f32[1]) * v11))
           & _mask__AbsFloat_) > 0.0 )
        return 1;
      break;
  }
  return 0;
}
