gjkepa2_impl::EPA::eStatus::_ __thiscall gjkepa2_impl::EPA::Evaluate(
        gjkepa2_impl::EPA *this,
        gjkepa2_impl::GJK::sSV *gjk,
        gjkepa2_impl::GJK *guess,
        _DWORD *a4)
{
  gjkepa2_impl::GJK::sSimplex *m_simplex; // esi
  gjkepa2_impl::EPA::sFace **v5; // edi
  float *m128_f32; // eax
  float *v7; // ecx
  float v8; // xmm5_4
  float v9; // xmm0_4
  float v10; // xmm4_4
  float *v11; // ecx
  float v12; // xmm1_4
  gjkepa2_impl::EPA *v13; // ecx
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm6_4
  float v17; // xmm0_4
  gjkepa2_impl::EPA::sFace *v18; // eax
  gjkepa2_impl::EPA *v19; // ecx
  gjkepa2_impl::EPA::sFace *v20; // eax
  gjkepa2_impl::EPA *v21; // ecx
  gjkepa2_impl::EPA::sFace *v22; // eax
  gjkepa2_impl::EPA *v23; // ecx
  gjkepa2_impl::EPA::sFace *v24; // eax
  gjkepa2_impl::EPA *v25; // ecx
  bool v26; // zf
  gjkepa2_impl::EPA::sFace *v27; // eax
  unsigned int nf; // edx
  gjkepa2_impl::EPA::sFace *ff; // ecx
  gjkepa2_impl::EPA::sFace *v30; // esi
  gjkepa2_impl::EPA::sFace *cf; // eax
  unsigned int v32; // eax
  gjkepa2_impl::GJK::sSV *p_w; // edi
  char v34; // cl
  gjkepa2_impl::EPA::sFace *v35; // esi
  gjkepa2_impl::EPA::sFace *v36; // eax
  gjkepa2_impl::EPA::sFace *v37; // ecx
  gjkepa2_impl::EPA *v38; // ecx
  gjkepa2_impl::EPA::sFace *v39; // eax
  float *v40; // edx
  float v41; // xmm0_4
  float *v42; // eax
  float *v43; // ecx
  float v44; // xmm4_4
  float v45; // xmm5_4
  float v46; // xmm6_4
  float v47; // xmm4_4
  float v48; // xmm5_4
  float v49; // xmm1_4
  float v50; // xmm2_4
  float v51; // xmm3_4
  float v52; // xmm0_4
  float v53; // xmm2_4
  float v54; // xmm0_4
  float v55; // xmm7_4
  float v56; // xmm0_4
  float v57; // xmm3_4
  float v58; // xmm2_4
  float v59; // xmm0_4
  float v60; // xmm1_4
  float v61; // xmm0_4
  float v62; // xmm0_4
  float v63; // xmm7_4
  float v64; // xmm3_4
  float v65; // xmm1_4
  float v66; // xmm2_4
  float v67; // xmm0_4
  gjkepa2_impl::EPA::eStatus::_ result; // eax
  float v69; // xmm6_4
  float v70; // xmm2_4
  float v71; // xmm0_4
  int v72; // xmm1_4
  float v73; // xmm3_4
  float *v74; // [esp-14h] [ebp-B8h]
  float *v75; // [esp-14h] [ebp-B8h]
  float *v76; // [esp-14h] [ebp-B8h]
  char v77; // [esp+Bh] [ebp-99h]
  const btVector3 *p_n; // [esp+Ch] [ebp-98h]
  gjkepa2_impl::EPA::sFace **v79; // [esp+Ch] [ebp-98h]
  float v80; // [esp+Ch] [ebp-98h]
  gjkepa2_impl::EPA::sFace *v81; // [esp+10h] [ebp-94h]
  int v82; // [esp+10h] [ebp-94h]
  float v83; // [esp+10h] [ebp-94h]
  float v84; // [esp+14h] [ebp-90h]
  float v85; // [esp+14h] [ebp-90h]
  int v86; // [esp+18h] [ebp-8Ch]
  float v87; // [esp+18h] [ebp-8Ch]
  int v88; // [esp+1Ch] [ebp-88h]
  float v89; // [esp+1Ch] [ebp-88h]
  gjkepa2_impl::EPA::sHorizon horizon; // [esp+24h] [ebp-80h] BYREF
  gjkepa2_impl::EPA::sFace *v91; // [esp+30h] [ebp-74h]
  unsigned int pass; // [esp+3Ch] [ebp-68h]
  unsigned int v93; // [esp+40h] [ebp-64h]
  float v94; // [esp+44h] [ebp-60h]
  float v95; // [esp+48h] [ebp-5Ch]
  float v96; // [esp+54h] [ebp-50h]
  btVector3 v97[4]; // [esp+64h] [ebp-40h] BYREF

  m_simplex = guess->m_simplex;
  if ( m_simplex->rank <= 1 || !gjkepa2_impl::GJK::EncloseOrigin(guess) )
    goto LABEL_25;
  v5 = (gjkepa2_impl::EPA::sFace **)&gjk[322].w.mVec128.m128_i32[1];
  while ( *v5 )
  {
    v81 = *v5;
    gjkepa2_impl::EPA::remove((gjkepa2_impl::EPA::sList *)&gjk[322].w.m_floats[1], *v5);
    gjkepa2_impl::EPA::append((gjkepa2_impl::EPA::sList *)&gjk[322].w.m_floats[3], v81);
  }
  gjk->d.mVec128.m128_i32[0] = 0;
  gjk[322].w.mVec128.m128_i32[0] = 0;
  m128_f32 = m_simplex->c[3]->d.mVec128.m128_f32;
  v7 = m_simplex->c[2]->d.mVec128.m128_f32;
  v8 = v7[5] - m128_f32[5];
  v9 = v7[6] - m128_f32[6];
  v10 = v7[4] - m128_f32[4];
  v11 = m_simplex->c[1]->w.mVec128.m128_f32;
  *(float *)&horizon.cf = *v11 - m128_f32[4];
  *(float *)&horizon.ff = v11[1] - m128_f32[5];
  v12 = v11[2];
  v13 = (gjkepa2_impl::EPA *)m_simplex->c[0];
  v14 = m_simplex->c[0]->w.mVec128.m128_f32[2] - m128_f32[6];
  v84 = m_simplex->c[0]->w.mVec128.m128_f32[0] - m128_f32[4];
  v15 = m_simplex->c[0]->w.mVec128.m128_f32[1] - m128_f32[5];
  v16 = (float)((float)((float)((float)((float)((float)(v15 * (float)(v12 - m128_f32[6])) * v10)
                                      + (float)((float)(v14 * v8) * *(float *)&horizon.cf))
                              - (float)((float)((float)(v12 - m128_f32[6]) * v8) * v84))
                      - (float)((float)(v15 * v9) * *(float *)&horizon.cf))
              + (float)((float)(v9 * *(float *)&horizon.ff) * v84))
      - (float)((float)(v14 * *(float *)&horizon.ff) * v10);
  v95 = v8;
  if ( v16 < 0.0 )
  {
    m_simplex->c[0] = m_simplex->c[1];
    v17 = m_simplex->p[0];
    m_simplex->p[0] = m_simplex->p[1];
    m_simplex->c[1] = (gjkepa2_impl::GJK::sSV *)v13;
    m_simplex->p[1] = v17;
  }
  v18 = gjkepa2_impl::EPA::newface(v13, gjk, m_simplex->c[0], m_simplex->c[1], m_simplex->c[2]->d.mVec128.m128_f32, 1);
  v74 = m_simplex->c[3]->d.mVec128.m128_f32;
  horizon.cf = v18;
  v20 = gjkepa2_impl::EPA::newface(v19, gjk, m_simplex->c[1], m_simplex->c[0], v74, 1);
  v75 = m_simplex->c[3]->d.mVec128.m128_f32;
  horizon.ff = v20;
  v22 = gjkepa2_impl::EPA::newface(v21, gjk, m_simplex->c[2], m_simplex->c[1], v75, 1);
  v76 = m_simplex->c[3]->d.mVec128.m128_f32;
  horizon.nf = (unsigned int)v22;
  v24 = gjkepa2_impl::EPA::newface(v23, gjk, m_simplex->c[0], m_simplex->c[2], v76, 1);
  v26 = gjk[322].w.mVec128.m128_i32[2] == 4;
  v91 = v24;
  if ( v26 )
  {
    v27 = gjkepa2_impl::EPA::findbest(v25, (int)gjk);
    nf = horizon.nf;
    qmemcpy(v97, v27, sizeof(v97));
    ff = horizon.ff;
    v30 = v91;
    p_n = &v27->n;
    cf = horizon.cf;
    horizon.cf->e[0] = 0;
    cf->f[0] = ff;
    ff->e[0] = 0;
    ff->f[0] = cf;
    cf->e[1] = 0;
    cf->f[1] = (gjkepa2_impl::EPA::sFace *)nf;
    *(_BYTE *)(nf + 56) = 1;
    *(_DWORD *)(nf + 36) = cf;
    cf->e[2] = 0;
    cf->f[2] = v30;
    v30->e[0] = 2;
    v30->f[0] = cf;
    ff->e[1] = 2;
    ff->f[1] = v30;
    v30->e[2] = 1;
    v30->f[2] = ff;
    ff->e[2] = 1;
    ff->f[2] = (gjkepa2_impl::EPA::sFace *)nf;
    *(_BYTE *)(nf + 57) = 2;
    *(_DWORD *)(nf + 40) = ff;
    *(_BYTE *)(nf + 58) = 1;
    *(_DWORD *)(nf + 44) = v30;
    v30->e[1] = 2;
    v30->f[1] = (gjkepa2_impl::EPA::sFace *)nf;
    pass = 0;
    v82 = 0;
    gjk->d.mVec128.m128_i32[0] = 0;
    while ( 1 )
    {
      v32 = gjk[322].w.mVec128.m128_u32[0];
      if ( v32 >= 0x40 )
        break;
      memset(&horizon, 0, sizeof(horizon));
      p_w = (gjkepa2_impl::GJK::sSV *)&gjk[v32 + 2].w;
      v34 = ++pass;
      gjk[322].w.mVec128.m128_i32[0] = v32 + 1;
      v77 = 1;
      p_n[3].mVec128.m128_i8[11] = v34;
      gjkepa2_impl::GJK::getsupport(p_n, guess, p_w);
      v35 = (gjkepa2_impl::EPA::sFace *)p_n;
      if ( (float)((float)((float)((float)(p_w->w.mVec128.m128_f32[2] * p_n->mVec128.m128_f32[2])
                                 + (float)(p_w->w.mVec128.m128_f32[1] * p_n->mVec128.m128_f32[1]))
                         + (float)(p_w->w.mVec128.m128_f32[0] * p_n->mVec128.m128_f32[0]))
                 - p_n[1].mVec128.m128_f32[0]) <= 0.000099999997 )
      {
        gjk->d.mVec128.m128_i32[0] = 7;
        goto LABEL_24;
      }
      v93 = 0;
      v79 = (gjkepa2_impl::EPA::sFace **)&p_n[2].mVec128.m128_i32[1];
      do
      {
        if ( !v77 )
          goto LABEL_21;
        v77 &= gjkepa2_impl::EPA::expand((gjkepa2_impl::EPA *)gjk, pass, p_w, *v79++, v35->e[v93++], &horizon);
      }
      while ( v93 < 3 );
      if ( !v77 || horizon.nf < 3 )
      {
LABEL_21:
        gjk->d.mVec128.m128_i32[0] = 4;
        goto LABEL_24;
      }
      v36 = horizon.ff;
      v37 = horizon.cf;
      horizon.cf->e[1] = 2;
      v37->f[1] = v36;
      v36->e[2] = 1;
      v36->f[2] = v37;
      gjkepa2_impl::EPA::remove((gjkepa2_impl::EPA::sList *)&gjk[322].w.m_floats[1], v35);
      gjkepa2_impl::EPA::append((gjkepa2_impl::EPA::sList *)&gjk[322].w.m_floats[3], v35);
      v39 = gjkepa2_impl::EPA::findbest(v38, (int)gjk);
      p_n = &v39->n;
      if ( v39->p >= v97[1].mVec128.m128_f32[1] )
        qmemcpy(v97, v39, sizeof(v97));
      if ( (unsigned int)++v82 >= 0xFF )
        goto LABEL_24;
    }
    gjk->d.mVec128.m128_i32[0] = 6;
LABEL_24:
    v40 = (float *)v97[2].mVec128.m128_i32[0];
    v41 = v97[1].mVec128.m128_f32[0];
    v43 = (float *)v97[1].mVec128.m128_i32[3];
    v42 = (float *)v97[1].mVec128.m128_i32[2];
    v44 = v97[0].mVec128.m128_f32[0];
    v45 = v97[0].mVec128.m128_f32[1];
    v46 = v97[0].mVec128.m128_f32[2] * v97[1].mVec128.m128_f32[0];
    gjk[2].d.mVec128.m128_i32[0] = v97[1].mVec128.m128_i32[0];
    gjk[1].w = v97[0];
    v47 = v44 * v41;
    v48 = v45 * v41;
    gjk[1].d.mVec128.m128_i32[1] = 3;
    *(unsigned __int64 *)((char *)gjk->d.mVec128.m128_u64 + 4) = __PAIR64__((unsigned int)v43, (unsigned int)v42);
    gjk->d.mVec128.m128_i32[3] = (int)v40;
    v49 = v43[4];
    v50 = v40[6];
    v51 = v43[5];
    v94 = v40[4] - v47;
    v52 = v40[5];
    v96 = v49 - v47;
    v53 = v50 - v46;
    v54 = v52 - v48;
    v55 = v43[6] - v46;
    v56 = fsqrt(
            (float)((float)((float)((float)((float)(v51 - v48) * v53) - (float)(v55 * v54))
                          * (float)((float)((float)(v51 - v48) * v53) - (float)(v55 * v54)))
                  + (float)((float)((float)(v54 * v96) - (float)((float)(v51 - v48) * v94))
                          * (float)((float)(v54 * v96) - (float)((float)(v51 - v48) * v94))))
          + (float)((float)((float)(v55 * v94) - (float)(v53 * (float)(v49 - v47)))
                  * (float)((float)(v55 * v94) - (float)(v53 * (float)(v49 - v47)))));
    gjk->w.mVec128.m128_f32[1] = v56;
    v57 = v40[5];
    v58 = v42[6] - v46;
    v83 = v56;
    v59 = v42[4];
    v94 = v40[4] - v47;
    v60 = v40[6] - v46;
    v96 = v59 - v47;
    v61 = v42[5] - v48;
    v62 = fsqrt(
            (float)((float)((float)((float)(v61 * v94) - (float)((float)(v57 - v48) * v96))
                          * (float)((float)(v61 * v94) - (float)((float)(v57 - v48) * v96)))
                  + (float)((float)((float)(v60 * v96) - (float)(v58 * v94))
                          * (float)((float)(v60 * v96) - (float)(v58 * v94))))
          + (float)((float)((float)((float)(v57 - v48) * v58) - (float)(v60 * v61))
                  * (float)((float)((float)(v57 - v48) * v58) - (float)(v60 * v61))));
    gjk->w.mVec128.m128_f32[2] = v62;
    v63 = v42[4];
    v64 = v42[5];
    v65 = v42[6] - v46;
    v66 = v43[6] - v46;
    v80 = v62;
    v67 = v43[5] - v48;
    result = gjk->d.mVec128.m128_i32[0];
    v69 = v43[4] - v47;
    v70 = fsqrt(
            (float)((float)((float)((float)(v67 * (float)(v63 - v47)) - (float)((float)(v64 - v48) * v69))
                          * (float)((float)(v67 * (float)(v63 - v47)) - (float)((float)(v64 - v48) * v69)))
                  + (float)((float)((float)(v65 * v69) - (float)(v66 * (float)(v63 - v47)))
                          * (float)((float)(v65 * v69) - (float)(v66 * (float)(v63 - v47)))))
          + (float)((float)((float)((float)(v64 - v48) * v66) - (float)(v65 * v67))
                  * (float)((float)((float)(v64 - v48) * v66) - (float)(v65 * v67))));
    v71 = s_bm_current_air_resistance / (float)((float)(v70 + v80) + v83);
    gjk->w.mVec128.m128_f32[1] = v71 * v83;
    gjk->w.mVec128.m128_f32[2] = v71 * v80;
    gjk->w.mVec128.m128_f32[3] = v71 * v70;
  }
  else
  {
LABEL_25:
    result = 8;
    gjk->d.mVec128.m128_i32[0] = 8;
    v86 = a4[1] ^ _mask__NegFloat_;
    v88 = a4[2] ^ _mask__NegFloat_;
    gjk[1].w.mVec128.m128_i32[0] = *a4 ^ _mask__NegFloat_;
    gjk[1].w.mVec128.m128_i32[1] = v86;
    gjk[1].w.mVec128.m128_i32[2] = v88;
    gjk[1].w.mVec128.m128_i32[3] = 0;
    v72 = LODWORD(s_bm_current_air_resistance);
    v73 = fsqrt(
            (float)((float)(gjk[1].w.mVec128.m128_f32[0] * gjk[1].w.mVec128.m128_f32[0])
                  + (float)(gjk[1].w.mVec128.m128_f32[1] * gjk[1].w.mVec128.m128_f32[1]))
          + (float)(gjk[1].w.mVec128.m128_f32[2] * gjk[1].w.mVec128.m128_f32[2]));
    if ( v73 <= 0.0 )
    {
      v85 = s_bm_current_air_resistance;
      v87 = 0.0;
      v89 = 0.0;
    }
    else
    {
      v85 = gjk[1].w.mVec128.m128_f32[0] * (float)(s_bm_current_air_resistance / v73);
      v87 = gjk[1].w.mVec128.m128_f32[1] * (float)(s_bm_current_air_resistance / v73);
      v89 = gjk[1].w.mVec128.m128_f32[2] * (float)(s_bm_current_air_resistance / v73);
    }
    gjk[1].w.mVec128.m128_f32[0] = v85;
    gjk[1].w.mVec128.m128_f32[1] = v87;
    gjk[1].w.mVec128.m128_f32[2] = v89;
    gjk[1].w.mVec128.m128_i32[3] = 0;
    gjk[2].d.mVec128.m128_i32[0] = 0;
    gjk[1].d.mVec128.m128_i32[1] = 1;
    gjk->d.mVec128.m128_i32[1] = (int)m_simplex->c[0];
    gjk->w.mVec128.m128_i32[1] = v72;
  }
  return result;
}
