int __usercall gjkepa2_impl::GJK::projectorigin@<xmm0>(
        const btVector3 *d@<esi>,
        const btVector3 *a,
        const btVector3 *b,
        const btVector3 *c,
        float *w,
        unsigned int *m)
{
  const btVector3 *v6; // eax
  float v7; // xmm3_4
  float v8; // xmm7_4
  const btVector3 *v9; // ecx
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm5_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm4_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm6_4
  float v21; // xmm7_4
  float v22; // xmm3_4
  float v23; // xmm7_4
  float v24; // xmm4_4
  float v25; // xmm6_4
  float v26; // xmm7_4
  float v27; // xmm6_4
  float v28; // xmm7_4
  float *v29; // edi
  float v30; // xmm0_4
  float v31; // xmm7_4
  float *v32; // edx
  float v33; // xmm0_4
  float v34; // ecx
  float v35; // xmm0_4
  float v36; // xmm7_4
  float v37; // xmm2_4
  float v38; // xmm3_4
  float v39; // xmm5_4
  float v40; // xmm0_4
  float v41; // xmm6_4
  float v42; // xmm1_4
  float v43; // xmm3_4
  float v44; // xmm7_4
  float v45; // xmm2_4
  float v46; // xmm0_4
  float v47; // xmm4_4
  float v48; // xmm0_4
  float v49; // xmm3_4
  float v50; // xmm2_4
  float v51; // xmm4_4
  float v52; // xmm2_4
  float v53; // xmm1_4
  float v54; // xmm3_4
  float v55; // xmm4_4
  float v56; // xmm3_4
  float v57; // xmm4_4
  float v58; // xmm3_4
  float v59; // xmm6_4
  float v60; // xmm4_4
  float v61; // xmm0_4
  float v62; // xmm3_4
  float v63; // xmm1_4
  const btVector3 *v65; // [esp-Ch] [ebp-ACh]
  float v66; // [esp+10h] [ebp-90h] BYREF
  float v67; // [esp+14h] [ebp-8Ch]
  float v68; // [esp+18h] [ebp-88h]
  float v69; // [esp+1Ch] [ebp-84h]
  float v70; // [esp+20h] [ebp-80h]
  float v71; // [esp+24h] [ebp-7Ch]
  float v72; // [esp+28h] [ebp-78h]
  float v73; // [esp+2Ch] [ebp-74h]
  float v74; // [esp+30h] [ebp-70h] BYREF
  int v75; // [esp+34h] [ebp-6Ch]
  float v76; // [esp+38h] [ebp-68h]
  float v77; // [esp+40h] [ebp-60h] BYREF
  float v78; // [esp+44h] [ebp-5Ch] BYREF
  float v79; // [esp+48h] [ebp-58h]
  int v80; // [esp+4Ch] [ebp-54h]
  float v81; // [esp+50h] [ebp-50h]
  float v82; // [esp+54h] [ebp-4Ch]
  float v83; // [esp+58h] [ebp-48h]
  int v84; // [esp+5Ch] [ebp-44h]
  float v85; // [esp+60h] [ebp-40h]
  float v86; // [esp+64h] [ebp-3Ch]
  float v87; // [esp+68h] [ebp-38h]
  int v88; // [esp+6Ch] [ebp-34h]
  _DWORD v89[8]; // [esp+70h] [ebp-30h]
  float v90; // [esp+90h] [ebp-10h]

  v6 = b;
  v7 = d->mVec128.m128_f32[0];
  v8 = d->mVec128.m128_f32[1];
  v9 = a;
  v10 = b->mVec128.m128_f32[2];
  v11 = a->mVec128.m128_f32[0];
  v12 = a->mVec128.m128_f32[1];
  v13 = d->mVec128.m128_f32[2];
  v71 = b->mVec128.m128_f32[0];
  v81 = v71 - v7;
  v67 = b->mVec128.m128_f32[1];
  v82 = v67 - v8;
  v14 = d->mVec128.m128_f32[2];
  v66 = v10;
  v15 = v10 - v14;
  v73 = v11;
  v77 = v11 - v7;
  v16 = a->mVec128.m128_f32[2];
  v17 = c->mVec128.m128_f32[0] - v7;
  v18 = c->mVec128.m128_f32[2];
  v85 = v17;
  v19 = c->mVec128.m128_f32[1] - v8;
  v83 = v15;
  v69 = v16;
  v86 = v19;
  v20 = v12 - v8;
  v21 = d->mVec128.m128_f32[2];
  v78 = v20;
  v22 = v18 - v21;
  v23 = c->mVec128.m128_f32[0];
  v79 = v16 - v13;
  v87 = v22;
  v24 = (float)((float)((float)((float)((float)((float)(v15 * v20) * v85) + (float)((float)(v19 * v79) * v81))
                              - (float)((float)(v19 * v15) * v77))
                      - (float)((float)(v22 * v20) * v81))
              + (float)((float)(v22 * v82) * v77))
      - (float)((float)(v79 * v82) * v85);
  *(float *)&v89[4] = v73 - v71;
  v89[0] = a;
  v89[1] = b;
  v89[2] = c;
  v89[3] = d;
  v80 = 0;
  v84 = 0;
  v88 = 0;
  v72 = v24;
  v25 = v71 - v23;
  v26 = c->mVec128.m128_f32[1];
  v74 = v25;
  v27 = v67 - v26;
  v28 = c->mVec128.m128_f32[2];
  v76 = v66 - v28;
  v90 = (float)(v27 * (float)(v16 - v66)) - (float)((float)(v66 - v28) * (float)(v12 - v67));
  if ( (float)((float)((float)((float)(v12
                                     * (float)((float)((float)(v66 - v28) * (float)(v73 - v71))
                                             - (float)((float)(v69 - v66) * v74)))
                             + (float)(v73 * v90))
                     + (float)(v69 * (float)((float)((float)(v12 - v67) * v74) - (float)(v27 * (float)(v73 - v71)))))
             * v24) > 0.0
    || COERCE_FLOAT(LODWORD(v24) & _mask__AbsFloat_) <= 0.0 )
  {
    return LODWORD(FLOAT_N1_0);
  }
  v66 = 0.0;
  v68 = 0.0;
  *(float *)&v29 = COERCE_FLOAT(&v78);
  v69 = FLOAT_N1_0;
  v74 = 0.0;
  v75 = 0;
  v76 = 0.0;
  v67 = COERCE_FLOAT(&v78);
  do
  {
    v30 = *v29;
    v31 = v29[1];
    v71 = `gjkepa2_impl::GJK::projectorigin'::`2'::imd3[LODWORD(v68)];
    v32 = &v77 + 4 * LODWORD(v71);
    if ( (float)((float)((float)((float)(d->mVec128.m128_f32[0] * (float)((float)(v32[2] * v30) - (float)(v32[1] * v31)))
                               + (float)((float)((float)(*v32 * v31) - (float)(v32[2] * *(v29 - 1)))
                                       * d->mVec128.m128_f32[1]))
                       + (float)(d->mVec128.m128_f32[2] * (float)((float)(v32[1] * *(v29 - 1)) - (float)(*v32 * *v29))))
               * v24) > 0.0 )
    {
      v65 = (const btVector3 *)v89[LODWORD(v71)];
      LODWORD(v70) = 4 * LODWORD(v71);
      v33 = COERCE_FLOAT(gjkepa2_impl::GJK::projectorigin(&v74, (const btVector3 *)v89[LODWORD(v68)], v65, d, (unsigned int *)&v66));
      if ( v69 < 0.0 || v69 > v33 )
      {
        *m = ((LOBYTE(v66) & 1) != 0 ? 1 << SLOBYTE(v68) : 0)
           + ((LOBYTE(v66) & 2) != 0 ? 1 << SLOBYTE(v71) : 0)
           + 2 * (LOBYTE(v66) & 4);
        v69 = v33;
        w[LODWORD(v68)] = v74;
        v34 = v70;
        *(_DWORD *)((char *)w + LODWORD(v70)) = v75;
        v35 = v76;
        w[*(_DWORD *)((char *)`gjkepa2_impl::GJK::projectorigin'::`2'::imd3 + LODWORD(v34))] = 0.0;
        w[3] = v35;
      }
      *(float *)&v29 = v67;
      v9 = a;
      v6 = b;
      v24 = v72;
    }
    ++LODWORD(v68);
    v29 += 4;
    v67 = *(float *)&v29;
  }
  while ( LODWORD(v68) < 3 );
  if ( v69 < 0.0 )
  {
    v36 = d->mVec128.m128_f32[1];
    v37 = d->mVec128.m128_f32[2];
    v38 = c->mVec128.m128_f32[1];
    v39 = s_bm_current_air_resistance;
    v40 = v6->mVec128.m128_f32[2];
    v69 = 0.0;
    v41 = v36 * c->mVec128.m128_f32[2];
    v42 = v37 * v38;
    v43 = v6->mVec128.m128_f32[1] * v37;
    v44 = v36 * v40;
    v66 = s_bm_current_air_resistance / v24;
    v45 = (float)(c->mVec128.m128_f32[1] * v40) * d->mVec128.m128_f32[0];
    v46 = v6->mVec128.m128_f32[0];
    v68 = v43;
    v47 = v41 * v46;
    v48 = c->mVec128.m128_f32[0];
    v49 = v43 * c->mVec128.m128_f32[0];
    v71 = v42;
    v50 = (float)((float)(v45 + v47) - (float)(v44 * v48)) - (float)(v42 * v6->mVec128.m128_f32[0]);
    v51 = d->mVec128.m128_f32[1];
    v52 = (float)((float)(v50 + v49)
                - (float)((float)(v6->mVec128.m128_f32[1] * c->mVec128.m128_f32[2]) * d->mVec128.m128_f32[0]))
        * v66;
    v67 = v9->mVec128.m128_f32[1];
    v53 = v9->mVec128.m128_f32[2];
    v54 = v53 * v51;
    v55 = d->mVec128.m128_f32[2];
    v72 = v54;
    v56 = v67 * v55;
    v57 = c->mVec128.m128_f32[2];
    v70 = v56;
    v58 = (float)((float)((float)(v67 * v57) * d->mVec128.m128_f32[0]) + (float)(v72 * v48))
        - (float)(v41 * v9->mVec128.m128_f32[0]);
    v59 = v70;
    v73 = v9->mVec128.m128_f32[0];
    v60 = v70 * v48;
    v61 = v71 * v73;
    *m = 15;
    *w = v52;
    v70 = v53;
    v70 = v53 * c->mVec128.m128_f32[1];
    v62 = (float)((float)((float)(v58 - v60) + v61) - (float)(v70 * d->mVec128.m128_f32[0])) * v66;
    v63 = (float)((float)((float)((float)((float)((float)((float)(v53 * v6->mVec128.m128_f32[1]) * d->mVec128.m128_f32[0])
                                                + (float)(v44 * v73))
                                        - (float)(v72 * v6->mVec128.m128_f32[0]))
                                - (float)(v68 * v73))
                        + (float)(v59 * v6->mVec128.m128_f32[0]))
                - (float)((float)(v67 * v6->mVec128.m128_f32[2]) * d->mVec128.m128_f32[0]))
        * v66;
    w[2] = v63;
    w[1] = v62;
    w[3] = v39 - (float)((float)(v63 + v62) + v52);
  }
  return LODWORD(v69);
}


int __usercall gjkepa2_impl::GJK::projectorigin@<xmm0>(
        float *w@<edi>,
        const btVector3 *a,
        const btVector3 *b,
        const btVector3 *c,
        unsigned int *m)
{
  const btVector3 *v5; // edx
  const btVector3 *v6; // ecx
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm5_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm6_4
  float v13; // xmm3_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm5_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm0_4
  float *v23; // eax
  const btVector3 *v24; // esi
  float v25; // xmm0_4
  float v26; // xmm6_4
  float v27; // xmm4_4
  float v28; // xmm7_4
  float v29; // xmm3_4
  float v30; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm3_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm4_4
  float v36; // xmm2_4
  float v37; // xmm0_4
  float v38; // xmm7_4
  float v39; // xmm5_4
  float v40; // xmm1_4
  float v41; // xmm1_4
  float v43; // [esp+Ch] [ebp-ACh]
  unsigned int v44; // [esp+10h] [ebp-A8h]
  float v45; // [esp+14h] [ebp-A4h]
  float v46; // [esp+14h] [ebp-A4h]
  float v47; // [esp+18h] [ebp-A0h]
  unsigned int v48; // [esp+1Ch] [ebp-9Ch] BYREF
  float v49; // [esp+20h] [ebp-98h]
  float *v50; // [esp+24h] [ebp-94h]
  float v51; // [esp+28h] [ebp-90h]
  float v52; // [esp+2Ch] [ebp-8Ch]
  float v53; // [esp+30h] [ebp-88h]
  float v54; // [esp+44h] [ebp-74h]
  float v55[6]; // [esp+48h] [ebp-70h]
  float v56; // [esp+60h] [ebp-58h] BYREF
  float v57; // [esp+64h] [ebp-54h]
  float v58; // [esp+68h] [ebp-50h]
  float v59[3]; // [esp+6Ch] [ebp-4Ch] BYREF
  float v60; // [esp+78h] [ebp-40h]
  float v61; // [esp+7Ch] [ebp-3Ch]
  float v62; // [esp+80h] [ebp-38h]
  int v63; // [esp+84h] [ebp-34h]
  float v64; // [esp+88h] [ebp-30h]
  float v65; // [esp+8Ch] [ebp-2Ch]
  float v66; // [esp+90h] [ebp-28h]
  int v67; // [esp+94h] [ebp-24h]
  float v68; // [esp+A4h] [ebp-14h]
  float v69; // [esp+A8h] [ebp-10h]

  v5 = b;
  v6 = c;
  v7 = b->mVec128.m128_f32[0];
  v8 = b->mVec128.m128_f32[1];
  v9 = b->mVec128.m128_f32[2];
  v68 = c->mVec128.m128_f32[0];
  v10 = a->mVec128.m128_f32[0];
  v11 = a->mVec128.m128_f32[1] - v8;
  v49 = v7;
  v12 = v10 - v7;
  v60 = v7 - v68;
  v13 = c->mVec128.m128_f32[1];
  v14 = v8 - v13;
  v64 = v68 - v10;
  v15 = v13 - a->mVec128.m128_f32[1];
  v59[0] = v11;
  v16 = a->mVec128.m128_f32[2];
  v61 = v14;
  v17 = c->mVec128.m128_f32[2];
  v18 = v16 - v9;
  v19 = v9 - v17;
  v65 = v15;
  v66 = v17 - a->mVec128.m128_f32[2];
  v58 = v12;
  v20 = (float)(v19 * v59[0]) - (float)(v18 * v61);
  v21 = (float)(v61 * v12) - (float)(v60 * v59[0]);
  v59[1] = v18;
  v22 = (float)(v18 * v60) - (float)(v19 * v12);
  LODWORD(v55[0]) = a;
  LODWORD(v55[1]) = b;
  LODWORD(v55[2]) = c;
  v45 = v10;
  v59[2] = 0.0;
  v62 = v19;
  v63 = 0;
  v67 = 0;
  v51 = v20;
  v52 = v22;
  v53 = v21;
  v54 = (float)((float)(v21 * v21) + (float)(v22 * v22)) + (float)(v20 * v20);
  if ( v54 <= 0.0 )
    return LODWORD(FLOAT_N1_0);
  v48 = 0;
  v44 = 0;
  v23 = v59;
  v47 = FLOAT_N1_0;
  v56 = 0.0;
  v57 = 0.0;
  v50 = v59;
  do
  {
    v24 = (const btVector3 *)LODWORD(v55[v44]);
    v69 = (float)(v21 * *v23) - (float)(v22 * v23[1]);
    if ( (float)((float)((float)(v24->mVec128.m128_f32[2] * (float)((float)(v22 * *(v23 - 1)) - (float)(v20 * *v23)))
                       + (float)(v24->mVec128.m128_f32[1] * (float)((float)(v20 * v23[1]) - (float)(v21 * *(v23 - 1)))))
               + (float)(v24->mVec128.m128_f32[0] * v69)) <= 0.0 )
    {
      v26 = v47;
    }
    else
    {
      LODWORD(v43) = 4 * LODWORD(`gjkepa2_impl::GJK::projectorigin'::`2'::imd3[v44]);
      v25 = gjkepa2_impl::GJK::projectorigin(*(const btVector3 **)((char *)v55 + LODWORD(v43)), &v56, &v48, v24);
      v26 = v47;
      if ( v47 < 0.0 || v47 > v25 )
      {
        *m = ((v48 & 1) != 0 ? 1 << v44 : 0)
           + ((v48 & 2) != 0 ? 1 << LODWORD(`gjkepa2_impl::GJK::projectorigin'::`2'::imd3[v44]) : 0);
        v26 = v25;
        w[v44] = v56;
        *(float *)((char *)w + LODWORD(v43)) = v57;
        v47 = v25;
        w[*(_DWORD *)((char *)`gjkepa2_impl::GJK::projectorigin'::`2'::imd3 + LODWORD(v43))] = 0.0;
      }
      v19 = v62;
      v10 = v45;
      v20 = v51;
      v21 = v53;
      v23 = v50;
      v5 = b;
      v6 = c;
    }
    ++v44;
    v22 = v52;
    v23 += 4;
    v50 = v23;
  }
  while ( v44 < 3 );
  if ( v26 < 0.0 )
  {
    v46 = fsqrt(v54);
    v27 = (float)((float)((float)(v10 * v20) + (float)(a->mVec128.m128_f32[1] * v52))
                + (float)(v21 * a->mVec128.m128_f32[2]))
        / v54;
    v28 = v20 * v27;
    v29 = v21 * v27;
    v30 = v5->mVec128.m128_f32[2] - v29;
    v52 = v52 * v27;
    v26 = (float)((float)(v29 * v29) + (float)(v52 * v52)) + (float)(v28 * v28);
    v55[0] = v49 - v28;
    v31 = v5->mVec128.m128_f32[1] - (float)(v22 * v27);
    v53 = v29;
    v32 = s_bm_current_air_resistance;
    v33 = (float)((float)((float)((float)(v31 * v60) - (float)(v61 * (float)(v49 - v28)))
                        * (float)((float)(v31 * v60) - (float)(v61 * (float)(v49 - v28))))
                + (float)((float)((float)(v19 * (float)(v49 - v28)) - (float)(v30 * v60))
                        * (float)((float)(v19 * (float)(v49 - v28)) - (float)(v30 * v60))))
        + (float)((float)((float)(v30 * v61) - (float)(v31 * v19)) * (float)((float)(v30 * v61) - (float)(v31 * v19)));
    v34 = v6->mVec128.m128_f32[1] - v52;
    v35 = fsqrt(v33) * (float)(s_bm_current_air_resistance / v46);
    v49 = s_bm_current_air_resistance / v46;
    v36 = v6->mVec128.m128_f32[2] - v53;
    v55[0] = v68 - v28;
    v37 = v36 * v65;
    v38 = v34 * v66;
    v39 = (float)(v66 * v55[0]) - (float)(v36 * v64);
    v40 = (float)(v34 * v64) - (float)(v65 * v55[0]);
    *m = 7;
    *w = v35;
    v41 = fsqrt((float)((float)(v40 * v40) + (float)(v39 * v39)) + (float)((float)(v37 - v38) * (float)(v37 - v38)))
        * v49;
    w[1] = v41;
    w[2] = v32 - (float)(v41 + v35);
  }
  return LODWORD(v26);
}


float __usercall gjkepa2_impl::GJK::projectorigin@<xmm0>(
        const btVector3 *b@<eax>,
        float *w@<edx>,
        unsigned int *m@<esi>,
        const btVector3 *a)
{
  float v4; // xmm1_4
  float v5; // xmm5_4
  float v6; // xmm6_4
  float v7; // xmm4_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // [esp+Ch] [ebp-4h]

  v4 = a->mVec128.m128_f32[2];
  v5 = a->mVec128.m128_f32[0];
  v6 = a->mVec128.m128_f32[1];
  v7 = b->mVec128.m128_f32[0] - a->mVec128.m128_f32[0];
  v8 = b->mVec128.m128_f32[2] - v4;
  v9 = b->mVec128.m128_f32[1] - v6;
  v10 = (float)((float)(v7 * v7) + (float)(v8 * v8)) + (float)(v9 * v9);
  v20 = v4;
  if ( v10 <= 0.0 )
    return FLOAT_N1_0;
  LODWORD(v11) = COERCE_UNSIGNED_INT((float)((float)((float)(v4 * v8) + (float)(v5 * v7)) + (float)(v6 * v9)) / v10)
               ^ _mask__NegFloat_;
  if ( v11 < s_bm_current_air_resistance )
  {
    if ( v11 > 0.0 )
    {
      *w = s_bm_current_air_resistance - v11;
      w[1] = v11;
      v18 = (float)((float)(v20 + (float)(v8 * v11)) * (float)(v20 + (float)(v8 * v11)))
          + (float)((float)(v5 + (float)(v7 * v11)) * (float)(v5 + (float)(v7 * v11)));
      *m = 3;
      v19 = (float)(v6 + (float)(v9 * v11)) * (float)(v6 + (float)(v9 * v11));
    }
    else
    {
      v16 = a->mVec128.m128_f32[1];
      v17 = a->mVec128.m128_f32[2];
      *w = s_bm_current_air_resistance;
      w[1] = 0.0;
      *m = 1;
      v18 = (float)(v16 * v16) + (float)(v17 * v17);
      v19 = v5 * v5;
    }
    return v18 + v19;
  }
  else
  {
    v12 = b->mVec128.m128_f32[1];
    w[1] = s_bm_current_air_resistance;
    *w = 0.0;
    v13 = b->mVec128.m128_f32[0];
    v14 = (float)(v12 * v12) + (float)(b->mVec128.m128_f32[2] * b->mVec128.m128_f32[2]);
    *m = 2;
    return v14 + (float)(v13 * v13);
  }
}
