gjkepa2_impl::GJK::eStatus::_ __userpurge gjkepa2_impl::GJK::Evaluate@<eax>(
        const btVector3 *guess@<eax>,
        const gjkepa2_impl::MinkowskiDiff *a2@<edi>,
        gjkepa2_impl::GJK *this,
        gjkepa2_impl::MinkowskiDiff *shapearg)
{
  unsigned int rank; // eax
  gjkepa2_impl::GJK::sSV *v6; // esi
  gjkepa2_impl::GJK::sSV *v7; // eax
  unsigned int m_current; // ecx
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  gjkepa2_impl::GJK::sSimplex *v12; // edi
  long double v13; // st7
  unsigned int v14; // ecx
  unsigned int v15; // xmm1_4
  unsigned int v16; // eax
  gjkepa2_impl::GJK::sSV *v17; // esi
  float v18; // edi
  int v19; // esi
  float *v20; // eax
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm5_4
  __int64 *v24; // eax
  unsigned int v25; // ecx
  float *v26; // edx
  __int64 v27; // xmm0_8
  float v28; // xmm1_4
  int v29; // ecx
  float *v30; // eax
  float v31; // xmm0_4
  int v32; // esi
  int v33; // esi
  gjkepa2_impl::GJK::sSimplex *v34; // eax
  unsigned int v35; // edx
  unsigned int v36; // esi
  unsigned int v37; // ecx
  int v38; // edx
  gjkepa2_impl::GJK::sSV **v39; // ecx
  int v40; // edi
  gjkepa2_impl::GJK::sSV *v41; // edi
  double v42; // st7
  float v43; // xmm0_4
  float *v44; // edx
  float v45; // xmm2_4
  float v46; // xmm3_4
  gjkepa2_impl::GJK::sSV *v47; // edi
  double v48; // st7
  float v49; // xmm0_4
  float *v50; // edx
  float v51; // xmm2_4
  float v52; // xmm3_4
  gjkepa2_impl::GJK::sSV *v53; // edi
  float v54; // xmm0_4
  float v55; // xmm2_4
  float v56; // xmm3_4
  gjkepa2_impl::GJK::sSV *v57; // edi
  float v58; // xmm0_4
  float *v59; // edx
  float v60; // xmm2_4
  float v61; // xmm3_4
  float v62; // edi
  unsigned int v63; // ecx
  double v64; // st7
  float v65; // xmm0_4
  float *v66; // ecx
  float v67; // xmm2_4
  float v68; // xmm3_4
  gjkepa2_impl::GJK::eStatus::_ m_status; // eax
  gjkepa2_impl::GJK::sSimplex *v70; // eax
  gjkepa2_impl::GJK::eStatus::_ v71; // esi
  gjkepa2_impl::GJK::eStatus::_ result; // eax
  gjkepa2_impl::GJK::sSimplex *v73; // [esp+6DCh] [ebp-9Ch]
  int v74; // [esp+6DCh] [ebp-9Ch]
  int v75; // [esp+6DCh] [ebp-9Ch]
  int v76; // [esp+6DCh] [ebp-9Ch]
  int v77; // [esp+6DCh] [ebp-9Ch]
  unsigned int m; // [esp+6E0h] [ebp-98h] BYREF
  float v79; // [esp+6E4h] [ebp-94h]
  int v80; // [esp+6E8h] [ebp-90h]
  char *v81; // [esp+6ECh] [ebp-8Ch]
  float v82; // [esp+6F0h] [ebp-88h]
  float v83; // [esp+6F4h] [ebp-84h] BYREF
  btVector3 d; // [esp+6F8h] [ebp-80h] BYREF
  float w[4]; // [esp+708h] [ebp-70h] BYREF
  int v86; // [esp+718h] [ebp-60h]
  int v87; // [esp+71Ch] [ebp-5Ch]
  char *v88; // [esp+720h] [ebp-58h]
  float v89; // [esp+724h] [ebp-54h] BYREF
  btVector3 v90; // [esp+728h] [ebp-50h] BYREF
  unsigned __int64 v91; // [esp+738h] [ebp-40h] BYREF
  _QWORD v92[7]; // [esp+740h] [ebp-38h] BYREF

  this->m_free[0] = this->m_store;
  this->m_free[1] = &this->m_store[1];
  this->m_free[3] = &this->m_store[3];
  v86 = 0;
  v83 = 0.0;
  v87 = 0;
  this->m_free[2] = &this->m_store[2];
  this->m_nfree = 4;
  this->m_current = 0;
  this->m_status = Valid;
  gjkepa2_impl::MinkowskiDiff::operator=(shapearg, a2);
  this->m_simplices[0].rank = 0;
  this->m_distance = 0.0;
  this->m_ray = (btVector3)guess->mVec128;
  v79 = (float)((float)(this->m_ray.mVec128.m128_f32[0] * this->m_ray.mVec128.m128_f32[0])
              + (float)(this->m_ray.mVec128.m128_f32[1] * this->m_ray.mVec128.m128_f32[1]))
      + (float)(this->m_ray.mVec128.m128_f32[2] * this->m_ray.mVec128.m128_f32[2]);
  d.mVec128.m128_i32[3] = 0;
  if ( v79 <= 0.0 )
  {
    d.mVec128.m128_u64[0] = (unsigned int)clear_value;
    d.mVec128.m128_i32[2] = 0;
  }
  else
  {
    d.mVec128.m128_f32[0] = -this->m_ray.mVec128.m128_f32[0];
    d.mVec128.m128_f32[1] = -this->m_ray.mVec128.m128_f32[1];
    d.mVec128.m128_f32[2] = -this->m_ray.mVec128.m128_f32[2];
  }
  this->m_simplices[0].p[this->m_simplices[0].rank] = 0.0;
  this->m_simplices[0].c[this->m_simplices[0].rank] = this->m_free[--this->m_nfree];
  rank = this->m_simplices[0].rank;
  v6 = this->m_simplices[0].c[rank];
  this->m_simplices[0].rank = rank + 1;
  gjkepa2_impl::GJK::getsupport(this, &d, v6);
  v7 = this->m_simplices[0].c[0];
  LODWORD(this->m_simplices[0].p[0]) = clear_value;
  this->m_ray = v7->w;
  v82 = v79;
  v92[5] = v7->w.mVec128.m128_u64[0];
  v92[6] = v7->w.mVec128.m128_u64[1];
  v92[3] = v7->w.mVec128.m128_u64[0];
  v92[4] = v7->w.mVec128.m128_u64[1];
  v92[1] = v7->w.mVec128.m128_u64[0];
  v92[2] = v7->w.mVec128.m128_u64[1];
  v91 = v7->w.mVec128.m128_u64[0];
  v92[0] = v7->w.mVec128.m128_u64[1];
  do
  {
    m_current = this->m_current;
    v9 = this->m_ray.mVec128.m128_f32[2];
    v10 = this->m_ray.mVec128.m128_f32[0];
    v11 = this->m_ray.mVec128.m128_f32[1] * this->m_ray.mVec128.m128_f32[1];
    v81 = (char *)(1 - m_current);
    v12 = &this->m_simplices[m_current];
    v79 = *(float *)&v12;
    v73 = &this->m_simplices[1 - m_current];
    v13 = sqrtf((float)((float)(v10 * v10) + v11) + (float)(v9 * v9));
    *(float *)&v80 = v13;
    if ( v13 < 0.000099999997 )
    {
      this->m_status = Inside;
      break;
    }
    v14 = v12->rank;
    v90.mVec128.m128_f32[0] = -this->m_ray.mVec128.m128_f32[0];
    v90.mVec128.m128_f32[1] = -this->m_ray.mVec128.m128_f32[1];
    *(float *)&v15 = -this->m_ray.mVec128.m128_f32[2];
    v12->p[v14] = 0.0;
    v12->c[v12->rank] = this->m_free[--this->m_nfree];
    v16 = v12->rank;
    v17 = v12->c[v16];
    v12->rank = v16 + 1;
    v90.mVec128.m128_u64[1] = v15;
    gjkepa2_impl::GJK::getsupport(this, &v90, v17);
    v18 = v79;
    v19 = *(_DWORD *)(LODWORD(v79) + 32);
    v20 = *(float **)(LODWORD(v79) + 4 * v19 - 4);
    v21 = v20[4];
    v22 = v20[5];
    v23 = v20[6];
    v24 = (__int64 *)(v20 + 4);
    v25 = 0;
    v26 = (float *)v92;
    do
    {
      if ( (float)((float)((float)((float)(v23 - *v26) * (float)(v23 - *v26))
                         + (float)((float)(v22 - *(v26 - 1)) * (float)(v22 - *(v26 - 1))))
                 + (float)((float)(v21 - *(v26 - 2)) * (float)(v21 - *(v26 - 2)))) < 0.000099999997 )
      {
        v70 = &this->m_simplices[this->m_current];
LABEL_52:
        this->m_free[this->m_nfree++] = v70->c[--v70->rank];
        goto LABEL_53;
      }
      ++v25;
      v26 += 4;
    }
    while ( v25 < 4 );
    v27 = *v24;
    v28 = this->m_ray.mVec128.m128_f32[1];
    v87 = ((_BYTE)v87 + 1) & 3;
    v29 = 2 * v87;
    v92[v29 - 1] = v27;
    v92[v29] = v24[1];
    v89 = (float)((float)((float)(this->m_ray.mVec128.m128_f32[2] * v23) + (float)(v28 * v22))
                + (float)(this->m_ray.mVec128.m128_f32[0] * v21))
        / *(float *)&v80;
    v30 = &v89;
    if ( v89 <= v83 )
      v30 = &v83;
    v83 = *v30;
    v31 = v83;
    if ( (float)((float)(*(float *)&v80 - v83) - (float)(*(float *)&v80 * 0.000099999997)) <= 0.0 )
      goto LABEL_51;
    v32 = v19 - 2;
    m = 0;
    if ( !v32 )
    {
      gjkepa2_impl::GJK::projectorigin(
        (const btVector3 *)(*(_DWORD *)LODWORD(v18) + 16),
        (const btVector3 *)(*(_DWORD *)(LODWORD(v18) + 4) + 16),
        w,
        &m);
      goto LABEL_18;
    }
    v33 = v32 - 1;
    if ( !v33 )
    {
      gjkepa2_impl::GJK::projectorigin(
        (const btVector3 *)(*(_DWORD *)LODWORD(v18) + 16),
        (const btVector3 *)(*(_DWORD *)(LODWORD(v18) + 4) + 16),
        (const btVector3 *)(*(_DWORD *)(LODWORD(v18) + 8) + 16),
        w,
        &m);
LABEL_18:
      v82 = v31;
      goto LABEL_19;
    }
    if ( v33 == 1 )
    {
      gjkepa2_impl::GJK::projectorigin(
        (const btVector3 *)(*(_DWORD *)LODWORD(v18) + 16),
        (const btVector3 *)(*(_DWORD *)(LODWORD(v18) + 4) + 16),
        (const btVector3 *)(*(_DWORD *)(LODWORD(v18) + 8) + 16),
        (const btVector3 *)(*(_DWORD *)(LODWORD(v18) + 12) + 16),
        w,
        &m);
      goto LABEL_18;
    }
LABEL_19:
    if ( v82 < 0.0 )
    {
LABEL_51:
      v70 = &this->m_simplices[this->m_current];
      goto LABEL_52;
    }
    v34 = v73;
    v35 = (unsigned int)v81;
    v36 = 0;
    v73->rank = 0;
    d.mVec128.m128_u64[0] = 0;
    this->m_ray.mVec128.m128_u64[0] = 0;
    d.mVec128.m128_u64[1] = 0;
    this->m_current = v35;
    this->m_ray.mVec128.m128_u64[1] = 0;
    v38 = 1;
    v80 = *(int *)(LODWORD(v18) + 32);
    v37 = v80;
    v74 = 1;
    if ( v80 >= 4 )
    {
      v39 = (gjkepa2_impl::GJK::sSV **)(LODWORD(v18) + 8);
      v40 = -LODWORD(v18);
      v88 = (char *)w + v40;
      v81 = (char *)&w[1] + v40;
      do
      {
        v41 = *(v39 - 2);
        if ( (v38 & m) != 0 )
        {
          v42 = w[v36];
          v43 = w[v36];
          v34->c[v34->rank] = v41;
          v34->p[v34->rank++] = v42;
          v44 = (float *)*(v39 - 2);
          v45 = v44[5];
          v46 = v44[6] * v43;
          this->m_ray.mVec128.m128_f32[0] = this->m_ray.mVec128.m128_f32[0] + (float)(v43 * v44[4]);
          this->m_ray.mVec128.m128_f32[1] = this->m_ray.mVec128.m128_f32[1] + (float)(v45 * v43);
          this->m_ray.mVec128.m128_f32[2] = this->m_ray.mVec128.m128_f32[2] + v46;
        }
        else
        {
          this->m_free[this->m_nfree++] = v41;
        }
        v47 = *(v39 - 1);
        v75 = __ROL4__(v74, 1);
        if ( (v75 & m) != 0 )
        {
          v48 = w[v36 + 1];
          v49 = w[v36 + 1];
          v34->c[v34->rank] = v47;
          v34->p[v34->rank++] = v48;
          v50 = (float *)*(v39 - 1);
          v51 = v50[5];
          v52 = v50[6] * v49;
          this->m_ray.mVec128.m128_f32[0] = this->m_ray.mVec128.m128_f32[0] + (float)(v49 * v50[4]);
          this->m_ray.mVec128.m128_f32[1] = this->m_ray.mVec128.m128_f32[1] + (float)(v51 * v49);
          this->m_ray.mVec128.m128_f32[2] = this->m_ray.mVec128.m128_f32[2] + v52;
        }
        else
        {
          this->m_free[this->m_nfree++] = v47;
        }
        v53 = *v39;
        v76 = __ROL4__(v75, 1);
        if ( (v76 & m) != 0 )
        {
          v34->c[v34->rank] = v53;
          v54 = *(float *)((char *)v39 + (_DWORD)v88);
          v34->p[v34->rank++] = v54;
          v55 = (*v39)->w.mVec128.m128_f32[1] * v54;
          v56 = (*v39)->w.mVec128.m128_f32[2] * v54;
          this->m_ray.mVec128.m128_f32[0] = this->m_ray.mVec128.m128_f32[0]
                                          + (float)(v54 * (*v39)->w.mVec128.m128_f32[0]);
          this->m_ray.mVec128.m128_f32[1] = this->m_ray.mVec128.m128_f32[1] + v55;
          this->m_ray.mVec128.m128_f32[2] = this->m_ray.mVec128.m128_f32[2] + v56;
        }
        else
        {
          this->m_free[this->m_nfree++] = v53;
        }
        v57 = v39[1];
        v77 = __ROL4__(v76, 1);
        if ( (v77 & m) != 0 )
        {
          v34->c[v34->rank] = v57;
          v58 = *(float *)((char *)v39 + (_DWORD)v81);
          v34->p[v34->rank++] = v58;
          v59 = (float *)v39[1];
          v60 = v59[5];
          v61 = v59[6] * v58;
          this->m_ray.mVec128.m128_f32[0] = this->m_ray.mVec128.m128_f32[0] + (float)(v58 * v59[4]);
          this->m_ray.mVec128.m128_f32[1] = this->m_ray.mVec128.m128_f32[1] + (float)(v60 * v58);
          this->m_ray.mVec128.m128_f32[2] = this->m_ray.mVec128.m128_f32[2] + v61;
        }
        else
        {
          this->m_free[this->m_nfree++] = v57;
        }
        v38 = __ROL4__(v77, 1);
        v36 += 4;
        v39 += 4;
        v74 = v38;
      }
      while ( v36 < v80 - 3 );
      v18 = v79;
      v37 = v80;
    }
    if ( v36 < v37 )
    {
      LODWORD(v62) = LODWORD(v18) - (_DWORD)w;
      v79 = v62;
      do
      {
        v63 = LODWORD(v62) + 4 * v36;
        if ( (v38 & m) != 0 )
        {
          v64 = w[v36];
          v65 = w[v36];
          v34->c[v34->rank] = *(gjkepa2_impl::GJK::sSV **)((char *)w + v63);
          v34->p[v34->rank++] = v64;
          v66 = *(float **)((char *)w + v63);
          v67 = v66[5];
          v38 = v74;
          v68 = v66[6] * v65;
          this->m_ray.mVec128.m128_f32[0] = this->m_ray.mVec128.m128_f32[0] + (float)(v65 * v66[4]);
          this->m_ray.mVec128.m128_f32[1] = this->m_ray.mVec128.m128_f32[1] + (float)(v67 * v65);
          this->m_ray.mVec128.m128_f32[2] = this->m_ray.mVec128.m128_f32[2] + v68;
        }
        else
        {
          this->m_free[this->m_nfree++] = *(gjkepa2_impl::GJK::sSV **)((char *)w + v63);
        }
        v62 = v79;
        v38 = __ROL4__(v38, 1);
        ++v36;
        v74 = v38;
      }
      while ( v36 < v80 );
    }
    if ( m == 15 )
      this->m_status = Inside;
    if ( (unsigned int)++v86 >= 0x80 )
      m_status = Failed;
    else
      m_status = this->m_status;
    this->m_status = m_status;
  }
  while ( m_status == Valid );
LABEL_53:
  v71 = this->m_status;
  this->m_simplex = &this->m_simplices[this->m_current];
  if ( v71 )
  {
    result = v71;
    if ( v71 == Inside )
      this->m_distance = 0.0;
  }
  else
  {
    this->m_distance = sqrtf(
                         (float)((float)(this->m_ray.mVec128.m128_f32[0] * this->m_ray.mVec128.m128_f32[0])
                               + (float)(this->m_ray.mVec128.m128_f32[1] * this->m_ray.mVec128.m128_f32[1]))
                       + (float)(this->m_ray.mVec128.m128_f32[2] * this->m_ray.mVec128.m128_f32[2]));
    return 0;
  }
  return result;
}
