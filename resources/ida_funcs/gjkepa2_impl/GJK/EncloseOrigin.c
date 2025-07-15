bool __thiscall gjkepa2_impl::GJK::EncloseOrigin(gjkepa2_impl::GJK *this)
{
  gjkepa2_impl::GJK::sSimplex *m_simplex; // eax
  gjkepa2_impl::GJK::sSimplex *v3; // eax
  unsigned int rank; // ecx
  gjkepa2_impl::GJK::sSV *v5; // esi
  gjkepa2_impl::GJK::sSimplex *v6; // eax
  float v7; // xmm1_4
  gjkepa2_impl::GJK::sSimplex *v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // xmm1_4
  unsigned int v11; // ecx
  gjkepa2_impl::GJK::sSV *v12; // esi
  gjkepa2_impl::GJK::sSimplex *v13; // eax
  bool result; // al
  float *m128_f32; // ecx
  float *v16; // eax
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm1_4
  unsigned int v20; // eax
  gjkepa2_impl::GJK::sSimplex *v21; // eax
  unsigned int v22; // ecx
  gjkepa2_impl::GJK::sSV *v23; // esi
  gjkepa2_impl::GJK::sSimplex *v24; // eax
  float v25; // xmm0_4
  gjkepa2_impl::GJK::sSimplex *v26; // eax
  gjkepa2_impl::GJK::sSimplex *v27; // eax
  float *v28; // edx
  float v29; // xmm0_4
  float v30; // xmm5_4
  float v31; // xmm2_4
  float *v32; // edx
  float v33; // xmm1_4
  float v34; // xmm3_4
  float v35; // xmm6_4
  float v36; // xmm7_4
  unsigned int v37; // xmm0_4
  gjkepa2_impl::GJK::sSimplex *v38; // eax
  float *v39; // ecx
  float *v40; // edx
  float v41; // xmm4_4
  float v42; // xmm3_4
  float v43; // xmm5_4
  float *v44; // edx
  float *v45; // eax
  float v46; // xmm2_4
  float v47; // xmm0_4
  float v48; // xmm6_4
  float v49; // xmm1_4
  float v50; // xmm0_4
  unsigned int i; // [esp+1A4h] [ebp-44h]
  unsigned int v52; // [esp+1A4h] [ebp-44h]
  btVector3 v53; // [esp+1A8h] [ebp-40h] BYREF
  float v54; // [esp+1B8h] [ebp-30h]
  float v55; // [esp+1BCh] [ebp-2Ch]
  float v56; // [esp+1C0h] [ebp-28h]
  btVector3 v57; // [esp+1C8h] [ebp-20h] BYREF
  btVector3 v; // [esp+1D8h] [ebp-10h] BYREF

  m_simplex = this->m_simplex;
  switch ( m_simplex->rank )
  {
    case 1u:
      for ( i = 0; i < 3; ++i )
      {
        memset(&v53, 0, sizeof(v53));
        v53.mVec128.m128_i32[i] = (int)clear_value;
        v3 = this->m_simplex;
        v3->p[v3->rank] = 0.0;
        v3->c[v3->rank] = this->m_free[--this->m_nfree];
        rank = v3->rank;
        v5 = v3->c[rank];
        v3->rank = rank + 1;
        gjkepa2_impl::GJK::getsupport(this, &v53, v5);
        if ( gjkepa2_impl::GJK::EncloseOrigin(this) )
          goto LABEL_7;
        v6 = this->m_simplex;
        v7 = v53.mVec128.m128_f32[0];
        this->m_free[this->m_nfree++] = v6->c[--v6->rank];
        v8 = this->m_simplex;
        v9 = v8->rank;
        v57.mVec128.m128_f32[0] = -v7;
        v57.mVec128.m128_i32[1] = v53.mVec128.m128_i32[1] ^ 0x80000000;
        *(float *)&v10 = -v53.mVec128.m128_f32[2];
        v8->p[v9] = 0.0;
        v8->c[v8->rank] = this->m_free[--this->m_nfree];
        v11 = v8->rank;
        v12 = v8->c[v11];
        v57.mVec128.m128_u64[1] = v10;
        v8->rank = v11 + 1;
        gjkepa2_impl::GJK::getsupport(this, &v57, v12);
        if ( gjkepa2_impl::GJK::EncloseOrigin(this) )
          goto LABEL_7;
        v13 = this->m_simplex;
        this->m_free[this->m_nfree++] = v13->c[--v13->rank];
      }
      result = 0;
      break;
    case 2u:
      m128_f32 = m_simplex->c[0]->d.mVec128.m128_f32;
      v16 = m_simplex->c[1]->d.mVec128.m128_f32;
      v17 = v16[4] - m128_f32[4];
      v18 = v16[5] - m128_f32[5];
      v19 = v16[6] - m128_f32[6];
      v20 = 0;
      v57.mVec128.m128_u64[0] = __PAIR64__(LODWORD(v18), LODWORD(v17));
      v57.mVec128.m128_f32[2] = v19;
      v52 = 0;
      v53.mVec128.m128_i32[3] = 0;
      do
      {
        v54 = 0.0;
        v55 = 0.0;
        v56 = 0.0;
        *((_DWORD *)&v54 + v20) = clear_value;
        v53.mVec128.m128_f32[2] = (float)(v55 * v17) - (float)(v18 * v54);
        v53.mVec128.m128_f32[1] = (float)(v19 * v54) - (float)(v56 * v17);
        v53.mVec128.m128_f32[0] = (float)(v56 * v18) - (float)(v55 * v19);
        if ( (float)((float)((float)(v53.mVec128.m128_f32[2] * v53.mVec128.m128_f32[2])
                           + (float)(v53.mVec128.m128_f32[1] * v53.mVec128.m128_f32[1]))
                   + (float)(v53.mVec128.m128_f32[0] * v53.mVec128.m128_f32[0])) > 0.0 )
        {
          v21 = this->m_simplex;
          v21->p[v21->rank] = 0.0;
          v21->c[v21->rank] = this->m_free[--this->m_nfree];
          v22 = v21->rank;
          v23 = v21->c[v22];
          v21->rank = v22 + 1;
          gjkepa2_impl::GJK::getsupport(this, &v53, v23);
          if ( gjkepa2_impl::GJK::EncloseOrigin(this) )
            goto LABEL_7;
          v24 = this->m_simplex;
          v25 = v53.mVec128.m128_f32[0];
          this->m_free[this->m_nfree++] = v24->c[--v24->rank];
          v26 = this->m_simplex;
          v.mVec128.m128_f32[0] = -v25;
          v.mVec128.m128_i32[1] = v53.mVec128.m128_i32[1] ^ 0x80000000;
          v.mVec128.m128_u64[1] = v53.mVec128.m128_u32[2] ^ 0x80000000LL;
          gjkepa2_impl::GJK::appendvertice(this, v26, &v);
          if ( gjkepa2_impl::GJK::EncloseOrigin(this) )
            goto LABEL_7;
          v27 = this->m_simplex;
          --v27->rank;
          v18 = v57.mVec128.m128_f32[1];
          v17 = v57.mVec128.m128_f32[0];
          this->m_free[this->m_nfree++] = v27->c[v27->rank];
          v20 = v52;
        }
        v19 = v57.mVec128.m128_f32[2];
        v52 = ++v20;
      }
      while ( v20 < 3 );
      result = 0;
      break;
    case 3u:
      v28 = m_simplex->c[2]->d.mVec128.m128_f32;
      v29 = v28[5] - m_simplex->c[0]->w.mVec128.m128_f32[1];
      v30 = v28[4] - m_simplex->c[0]->w.mVec128.m128_f32[0];
      v31 = v28[6] - m_simplex->c[0]->w.mVec128.m128_f32[2];
      v32 = m_simplex->c[1]->d.mVec128.m128_f32;
      v33 = v32[6] - m_simplex->c[0]->w.mVec128.m128_f32[2];
      v34 = v32[5] - m_simplex->c[0]->w.mVec128.m128_f32[1];
      v35 = v32[4] - m_simplex->c[0]->w.mVec128.m128_f32[0];
      v36 = v33 * v29;
      *(float *)&v37 = (float)(v29 * v35) - (float)(v34 * v30);
      v53.mVec128.m128_u64[1] = v37;
      v53.mVec128.m128_f32[0] = (float)(v34 * v31) - v36;
      v53.mVec128.m128_f32[1] = (float)(v33 * v30) - (float)(v31 * v35);
      if ( (float)((float)((float)(*(float *)&v37 * *(float *)&v37)
                         + (float)(v53.mVec128.m128_f32[1] * v53.mVec128.m128_f32[1]))
                 + (float)(v53.mVec128.m128_f32[0] * v53.mVec128.m128_f32[0])) <= 0.0 )
        goto LABEL_20;
      gjkepa2_impl::GJK::appendvertice(this, m_simplex, &v53);
      if ( gjkepa2_impl::GJK::EncloseOrigin(this) )
        goto LABEL_7;
      gjkepa2_impl::GJK::removevertice(this, this->m_simplex);
      v38 = this->m_simplex;
      v.mVec128.m128_u64[0] = v53.mVec128.m128_u64[0] ^ 0x8000000080000000uLL;
      v.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(-v53.mVec128.m128_f32[2]);
      gjkepa2_impl::GJK::appendvertice(this, v38, &v);
      if ( gjkepa2_impl::GJK::EncloseOrigin(this) )
        goto LABEL_7;
      gjkepa2_impl::GJK::removevertice(this, this->m_simplex);
      result = 0;
      break;
    case 4u:
      v39 = m_simplex->c[3]->d.mVec128.m128_f32;
      v40 = m_simplex->c[2]->d.mVec128.m128_f32;
      v41 = v40[5] - v39[5];
      v42 = v40[4] - v39[4];
      v43 = v40[6] - v39[6];
      v44 = m_simplex->c[1]->d.mVec128.m128_f32;
      v45 = m_simplex->c[0]->d.mVec128.m128_f32;
      v46 = v45[6] - v39[6];
      v47 = v44[5] - v39[5];
      v48 = v44[4] - v39[4];
      v57.mVec128.m128_f32[0] = v45[4] - v39[4];
      v49 = v45[5] - v39[5];
      v.mVec128.m128_f32[1] = v47;
      v50 = v44[6] - v39[6];
      if ( fabsf(
             (float)((float)((float)((float)((float)((float)(v46 * v41) * v48) + (float)((float)(v49 * v50) * v42))
                                   - (float)((float)(v50 * v41) * v57.mVec128.m128_f32[0]))
                           - (float)((float)(v49 * v43) * v48))
                   + (float)((float)(v.mVec128.m128_f32[1] * v43) * v57.mVec128.m128_f32[0]))
           - (float)((float)(v46 * v.mVec128.m128_f32[1]) * v42)) <= 0.0 )
        goto LABEL_20;
LABEL_7:
      result = 1;
      break;
    default:
LABEL_20:
      result = 0;
      break;
  }
  return result;
}
