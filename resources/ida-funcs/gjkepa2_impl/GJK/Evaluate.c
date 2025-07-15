gjkepa2_impl::GJK::eStatus::_ __thiscall gjkepa2_impl::GJK::Evaluate(
        gjkepa2_impl::GJK *this,
        gjkepa2_impl::GJK *shapearg,
        gjkepa2_impl::MinkowskiDiff *guess,
        int *a4)
{
  btVector3 *p_w; // eax
  float v5; // xmm0_4
  unsigned int m_current; // eax
  gjkepa2_impl::GJK::sSimplex *v7; // esi
  unsigned int rank; // eax
  float *m128_f32; // esi
  float v10; // xmm1_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  unsigned int v13; // edi
  float *v14; // ecx
  int v15; // ecx
  _DWORD *v16; // edi
  _DWORD *v17; // esi
  float v18; // xmm0_4
  float v19; // xmm3_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  bool v24; // cc
  float *v25; // ecx
  float v26; // xmm3_4
  unsigned int v27; // eax
  unsigned int v28; // eax
  float v29; // xmm0_4
  gjkepa2_impl::GJK::sSimplex *v30; // edx
  unsigned int v31; // eax
  unsigned int v32; // ecx
  unsigned int v33; // eax
  float **v34; // eax
  float *v35; // esi
  float v36; // xmm4_4
  float *v37; // eax
  float v38; // xmm1_4
  float v39; // xmm2_4
  gjkepa2_impl::GJK::eStatus::_ m_status; // eax
  gjkepa2_impl::GJK::sSimplex *v41; // eax
  gjkepa2_impl::GJK::eStatus::_ result; // eax
  float v43; // [esp+8h] [ebp-9Ch]
  gjkepa2_impl::GJK::sSimplex *v44; // [esp+8h] [ebp-9Ch]
  unsigned int m; // [esp+Ch] [ebp-98h] BYREF
  float v46; // [esp+10h] [ebp-94h]
  btVector3 v; // [esp+14h] [ebp-90h] BYREF
  float v48; // [esp+28h] [ebp-7Ch] BYREF
  int v49; // [esp+2Ch] [ebp-78h]
  gjkepa2_impl::GJK::sSimplex *v50; // [esp+30h] [ebp-74h]
  int v51; // [esp+34h] [ebp-70h]
  unsigned int v52; // [esp+38h] [ebp-6Ch]
  float v53; // [esp+3Ch] [ebp-68h]
  float v54; // [esp+40h] [ebp-64h] BYREF
  btVector3 v55; // [esp+44h] [ebp-60h] BYREF
  int v56; // [esp+54h] [ebp-50h]
  unsigned __int64 v57; // [esp+58h] [ebp-4Ch]
  int v58; // [esp+60h] [ebp-44h]
  _DWORD v59[2]; // [esp+64h] [ebp-40h] BYREF
  _DWORD v60[14]; // [esp+6Ch] [ebp-38h] BYREF

  shapearg->m_free[0] = shapearg->m_store;
  shapearg->m_free[1] = &shapearg->m_store[1];
  shapearg->m_free[2] = &shapearg->m_store[2];
  shapearg->m_free[3] = &shapearg->m_store[3];
  v51 = 0;
  v48 = 0.0;
  v49 = 0;
  shapearg->m_nfree = 4;
  shapearg->m_current = 0;
  shapearg->m_status = Valid;
  gjkepa2_impl::MinkowskiDiff::operator=(&this->m_shape, &shapearg->m_shape, guess);
  shapearg->m_simplices[0].rank = 0;
  shapearg->m_distance = 0.0;
  shapearg->m_ray = *(btVector3 *)a4;
  v43 = (float)((float)(shapearg->m_ray.mVec128.m128_f32[0] * shapearg->m_ray.mVec128.m128_f32[0])
              + (float)(shapearg->m_ray.mVec128.m128_f32[1] * shapearg->m_ray.mVec128.m128_f32[1]))
      + (float)(shapearg->m_ray.mVec128.m128_f32[2] * shapearg->m_ray.mVec128.m128_f32[2]);
  v.mVec128.m128_i32[3] = 0;
  if ( v43 <= 0.0 )
  {
    v.mVec128.m128_u64[0] = LODWORD(s_bm_current_air_resistance);
    v.mVec128.m128_i32[2] = 0;
  }
  else
  {
    v.mVec128.m128_i32[0] = shapearg->m_ray.mVec128.m128_i32[0] ^ _mask__NegFloat_;
    v.mVec128.m128_i32[1] = shapearg->m_ray.mVec128.m128_i32[1] ^ _mask__NegFloat_;
    v.mVec128.m128_i32[2] = shapearg->m_ray.mVec128.m128_i32[2] ^ _mask__NegFloat_;
  }
  gjkepa2_impl::GJK::appendvertice(shapearg, shapearg->m_simplices, &v);
  p_w = &shapearg->m_simplices[0].c[0]->w;
  shapearg->m_simplices[0].p[0] = s_bm_current_air_resistance;
  shapearg->m_ray = (btVector3)p_w->mVec128;
  v60[10] = p_w->mVec128.m128_i32[0];
  v60[11] = p_w->mVec128.m128_i32[1];
  v60[12] = p_w->mVec128.m128_i32[2];
  v60[13] = p_w->mVec128.m128_i32[3];
  v60[6] = p_w->mVec128.m128_i32[0];
  v60[7] = p_w->mVec128.m128_i32[1];
  v60[8] = p_w->mVec128.m128_i32[2];
  v60[9] = p_w->mVec128.m128_i32[3];
  v60[2] = p_w->mVec128.m128_i32[0];
  v60[3] = p_w->mVec128.m128_i32[1];
  v60[4] = p_w->mVec128.m128_i32[2];
  v60[5] = p_w->mVec128.m128_i32[3];
  v59[0] = p_w->mVec128.m128_i32[0];
  v59[1] = p_w->mVec128.m128_i32[1];
  v60[0] = p_w->mVec128.m128_i32[2];
  v46 = v43;
  v5 = 0.0;
  v60[1] = p_w->mVec128.m128_i32[3];
  do
  {
    m_current = shapearg->m_current;
    v52 = 1 - m_current;
    v7 = &shapearg->m_simplices[m_current];
    v50 = &shapearg->m_simplices[1 - m_current];
    v44 = v7;
    v53 = fsqrt(
            (float)((float)(shapearg->m_ray.mVec128.m128_f32[0] * shapearg->m_ray.mVec128.m128_f32[0])
                  + (float)(shapearg->m_ray.mVec128.m128_f32[1] * shapearg->m_ray.mVec128.m128_f32[1]))
          + (float)(shapearg->m_ray.mVec128.m128_f32[2] * shapearg->m_ray.mVec128.m128_f32[2]));
    if ( v53 < 0.000099999997 )
    {
      shapearg->m_status = Inside;
      break;
    }
    v55.mVec128.m128_i32[0] = shapearg->m_ray.mVec128.m128_i32[0] ^ _mask__NegFloat_;
    v55.mVec128.m128_i32[1] = shapearg->m_ray.mVec128.m128_i32[1] ^ _mask__NegFloat_;
    v55.mVec128.m128_u64[1] = shapearg->m_ray.mVec128.m128_u32[2] ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
    gjkepa2_impl::GJK::appendvertice(shapearg, v7, &v55);
    rank = v7->rank;
    m128_f32 = v7->c[rank - 1]->w.mVec128.m128_f32;
    v10 = *m128_f32;
    v11 = m128_f32[1];
    v12 = m128_f32[2];
    v13 = 0;
    v14 = (float *)v60;
    do
    {
      if ( (float)((float)((float)((float)(v12 - *v14) * (float)(v12 - *v14))
                         + (float)((float)(v11 - *(v14 - 1)) * (float)(v11 - *(v14 - 1))))
                 + (float)((float)(v10 - *(v14 - 2)) * (float)(v10 - *(v14 - 2)))) < 0.000099999997 )
      {
        v5 = 0.0;
LABEL_35:
        v41 = &shapearg->m_simplices[shapearg->m_current];
        shapearg->m_free[shapearg->m_nfree++] = v41->c[--v41->rank];
        goto LABEL_36;
      }
      ++v13;
      v14 += 4;
    }
    while ( v13 < 4 );
    v15 = ((_BYTE)v49 + 1) & 3;
    v16 = &v59[4 * v15];
    *v16 = *(_DWORD *)m128_f32;
    v17 = m128_f32 + 1;
    ++v16;
    v49 = v15;
    v18 = shapearg->m_ray.mVec128.m128_f32[2];
    v19 = shapearg->m_ray.mVec128.m128_f32[1];
    v20 = v10 * shapearg->m_ray.mVec128.m128_f32[0];
    *v16 = *v17++;
    *++v16 = *v17;
    v21 = (float)((float)(v18 * v12) + (float)(v19 * v11)) + v20;
    v22 = v53;
    v23 = v21 / v53;
    v24 = v23 <= v48;
    v16[1] = v17[1];
    v54 = v23;
    v25 = &v54;
    if ( v24 )
      v25 = &v48;
    v26 = v22 - *v25;
    v48 = *v25;
    v5 = 0.0;
    if ( (float)(v26 - (float)(v22 * 0.000099999997)) <= 0.0 )
      goto LABEL_35;
    m = 0;
    v27 = rank - 2;
    if ( !v27 )
    {
      v29 = gjkepa2_impl::GJK::projectorigin(&v44->c[1]->w, v.mVec128.m128_f32, &m, &v44->c[0]->w);
      goto LABEL_18;
    }
    v28 = v27 - 1;
    if ( !v28 )
    {
      v29 = COERCE_FLOAT(gjkepa2_impl::GJK::projectorigin(v.mVec128.m128_f32, &v44->c[0]->w, &v44->c[1]->w, &v44->c[2]->w, &m));
LABEL_18:
      v46 = v29;
      v5 = 0.0;
      goto LABEL_19;
    }
    if ( v28 == 1 )
    {
      v29 = COERCE_FLOAT(
              gjkepa2_impl::GJK::projectorigin(
                &v44->c[3]->w,
                &v44->c[0]->w,
                &v44->c[1]->w,
                &v44->c[2]->w,
                v.mVec128.m128_f32,
                &m));
      goto LABEL_18;
    }
LABEL_19:
    if ( v46 < 0.0 )
      goto LABEL_35;
    v30 = v50;
    v31 = v52;
    v32 = 0;
    v50->rank = 0;
    v56 = 0;
    v57 = 0;
    v58 = 0;
    shapearg->m_ray.mVec128.m128_i32[0] = 0;
    *(unsigned __int64 *)((char *)shapearg->m_ray.mVec128.m128_u64 + 4) = v57;
    shapearg->m_current = v31;
    shapearg->m_ray.mVec128.m128_i32[3] = v58;
    v50 = (gjkepa2_impl::GJK::sSimplex *)v44->rank;
    if ( v50 )
    {
      v33 = (char *)v44 - (char *)&v;
      v52 = (char *)v44 - (char *)&v;
      do
      {
        if ( ((1 << v32) & m) != 0 )
        {
          v34 = (float **)((char *)&v.mVec128.m128_i32[v32] + v33);
          v30->c[v30->rank] = (gjkepa2_impl::GJK::sSV *)*v34;
          v35 = &v.mVec128.m128_f32[v32];
          v36 = *v35;
          v30->p[v30->rank++] = *v35;
          v37 = *v34;
          v38 = (float)(v37[5] * v36) + shapearg->m_ray.mVec128.m128_f32[1];
          v39 = (float)(v37[6] * v36) + shapearg->m_ray.mVec128.m128_f32[2];
          shapearg->m_ray.mVec128.m128_f32[0] = shapearg->m_ray.mVec128.m128_f32[0] + (float)(v36 * v37[4]);
          shapearg->m_ray.mVec128.m128_f32[1] = v38;
          shapearg->m_ray.mVec128.m128_f32[2] = v39;
          v33 = v52;
        }
        else
        {
          shapearg->m_free[shapearg->m_nfree++] = *(gjkepa2_impl::GJK::sSV **)((char *)&v.mVec128.m128_i32[v32] + v33);
        }
        ++v32;
      }
      while ( v32 < (unsigned int)v50 );
    }
    if ( m == 15 )
      shapearg->m_status = Inside;
    if ( (unsigned int)++v51 >= 0x80 )
      m_status = Failed;
    else
      m_status = shapearg->m_status;
    shapearg->m_status = m_status;
  }
  while ( m_status == Valid );
LABEL_36:
  shapearg->m_simplex = &shapearg->m_simplices[shapearg->m_current];
  result = shapearg->m_status;
  if ( result == Valid )
  {
    v5 = fsqrt(
           (float)((float)(shapearg->m_ray.mVec128.m128_f32[0] * shapearg->m_ray.mVec128.m128_f32[0])
                 + (float)(shapearg->m_ray.mVec128.m128_f32[1] * shapearg->m_ray.mVec128.m128_f32[1]))
         + (float)(shapearg->m_ray.mVec128.m128_f32[2] * shapearg->m_ray.mVec128.m128_f32[2]));
    goto LABEL_40;
  }
  if ( result == Inside )
LABEL_40:
    shapearg->m_distance = v5;
  return result;
}
