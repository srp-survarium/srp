int __usercall gjkepa2_impl::GJK::projectorigin@<xmm0>(
        float *w@<esi>,
        const btVector3 *a,
        const btVector3 *b,
        const btVector3 *c,
        const btVector3 *d,
        unsigned int *m)
{
  float v6; // xmm5_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  const btVector3 *v9; // ebx
  float v10; // xmm4_4
  float v11; // xmm7_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  unsigned int v19; // edx
  float *v20; // eax
  int v21; // edi
  float v22; // xmm0_4
  int v23; // ecx
  unsigned int v24; // ecx
  float v25; // xmm0_4
  unsigned int v26; // ecx
  int v27; // xmm0_4
  float v28; // xmm6_4
  float v29; // xmm1_4
  float v30; // xmm7_4
  float v31; // xmm4_4
  float v32; // xmm2_4
  float v33; // xmm5_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm3_4
  float v37; // xmm6_4
  float v38; // xmm7_4
  float v39; // xmm2_4
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm1_4
  float v44; // xmm3_4
  float v45; // xmm0_4
  float v46; // xmm3_4
  float v47; // xmm7_4
  float v48; // xmm1_4
  const vostok::math::float4x4 *v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm3_4
  float v53; // [esp+244h] [ebp-80h]
  float v54; // [esp+248h] [ebp-7Ch]
  unsigned int v55; // [esp+248h] [ebp-7Ch]
  float v56; // [esp+248h] [ebp-7Ch]
  float v57; // [esp+24Ch] [ebp-78h]
  float *v58; // [esp+24Ch] [ebp-78h]
  float v59; // [esp+24Ch] [ebp-78h]
  float v60; // [esp+24Ch] [ebp-78h]
  float v61; // [esp+250h] [ebp-74h]
  int v62; // [esp+250h] [ebp-74h]
  float v63; // [esp+250h] [ebp-74h]
  float _X; // [esp+254h] [ebp-70h]
  float v65; // [esp+254h] [ebp-70h]
  unsigned int v66; // [esp+258h] [ebp-6Ch] BYREF
  float v67; // [esp+25Ch] [ebp-68h]
  float v68; // [esp+260h] [ebp-64h]
  float v69; // [esp+264h] [ebp-60h] BYREF
  float v70; // [esp+268h] [ebp-5Ch]
  int v71; // [esp+26Ch] [ebp-58h]
  btVector3 *v72[8]; // [esp+274h] [ebp-50h]
  float v73; // [esp+294h] [ebp-30h]
  float v74; // [esp+298h] [ebp-2Ch] BYREF
  _DWORD v75[2]; // [esp+29Ch] [ebp-28h]
  float v76; // [esp+2A4h] [ebp-20h]
  float v77; // [esp+2A8h] [ebp-1Ch]
  float v78; // [esp+2ACh] [ebp-18h]
  int v79; // [esp+2B0h] [ebp-14h]
  float v80; // [esp+2B4h] [ebp-10h]
  float v81; // [esp+2B8h] [ebp-Ch]
  float v82; // [esp+2BCh] [ebp-8h]
  int v83; // [esp+2C0h] [ebp-4h]

  v6 = a->mVec128.m128_f32[0];
  v7 = a->mVec128.m128_f32[2];
  v8 = a->mVec128.m128_f32[1];
  v9 = d;
  v10 = d->mVec128.m128_f32[0];
  v11 = d->mVec128.m128_f32[1];
  v12 = d->mVec128.m128_f32[2];
  v73 = a->mVec128.m128_f32[0] - d->mVec128.m128_f32[0];
  v75[1] = 0;
  v66 = b->mVec128.m128_u32[0];
  v76 = *(float *)&v66 - v10;
  v54 = b->mVec128.m128_f32[1];
  v77 = v54 - v11;
  v61 = b->mVec128.m128_f32[2];
  v13 = v61 - v12;
  v57 = v7;
  v14 = v7 - v12;
  v79 = 0;
  v15 = c->mVec128.m128_f32[0] - v10;
  v16 = c->mVec128.m128_f32[2];
  v80 = v15;
  v17 = c->mVec128.m128_f32[1] - v11;
  v78 = v13;
  v18 = v16 - d->mVec128.m128_f32[2];
  v83 = 0;
  v74 = v8 - v11;
  v81 = v17;
  *(float *)v75 = v14;
  v82 = v18;
  *(float *)&v72[4] = v6 - *(float *)&v66;
  v72[0] = (btVector3 *)a;
  v72[1] = (btVector3 *)b;
  v72[2] = (btVector3 *)c;
  v72[3] = (btVector3 *)d;
  _X = (float)((float)((float)((float)((float)((float)(v13 * (float)(v8 - v11)) * v80)
                                     + (float)((float)(v17 * v14) * v76))
                             - (float)((float)(v17 * v13) * v73))
                     - (float)((float)(v18 * (float)(v8 - v11)) * v76))
             + (float)((float)(v18 * v77) * v73))
     - (float)((float)(v14 * v77) * v80);
  if ( (float)((float)((float)((float)(v8
                                     * (float)((float)((float)(v61 - c->mVec128.m128_f32[2])
                                                     * (float)(v6 - *(float *)&v66))
                                             - (float)((float)(v57 - v61)
                                                     * (float)(*(float *)&v66 - c->mVec128.m128_f32[0]))))
                             + (float)(v6
                                     * (float)((float)((float)(v54 - c->mVec128.m128_f32[1]) * (float)(v57 - v61))
                                             - (float)((float)(v61 - c->mVec128.m128_f32[2]) * (float)(v8 - v54)))))
                     + (float)(v57
                             * (float)((float)((float)(v8 - v54) * (float)(*(float *)&v66 - c->mVec128.m128_f32[0]))
                                     - (float)((float)(v54 - c->mVec128.m128_f32[1]) * (float)(v6 - *(float *)&v66)))))
             * _X) > 0.0
    || fabsf(_X) <= 0.0 )
  {
    return -1082130432;
  }
  v19 = 0;
  v53 = -1.0;
  v20 = &v74;
  v69 = 0.0;
  v70 = 0.0;
  v71 = 0;
  *(float *)&v66 = 0.0;
  v62 = 1;
  v58 = &v74;
  v55 = 0;
  do
  {
    v21 = *(const unsigned int *)((char *)`gjkepa2_impl::GJK::projectorigin'::`2'::imd3 + v19);
    v22 = (float)((float)((float)(v9->mVec128.m128_f32[0]
                                * (float)((float)(*(float *)&v75[4 * v21] * *v20)
                                        - (float)(*(float *)&v75[4 * v21 - 1] * v20[1])))
                        + (float)((float)((float)(*(&v73 + 4 * v21) * v20[1])
                                        - (float)(*(float *)&v75[4 * v21] * *(v20 - 1)))
                                * v9->mVec128.m128_f32[1]))
                + (float)(v9->mVec128.m128_f32[2]
                        * (float)((float)(*(float *)&v75[4 * v21 - 1] * *(v20 - 1)) - (float)(*(&v73 + 4 * v21) * *v20))))
        * _X;
    if ( v22 > 0.0 )
    {
      gjkepa2_impl::GJK::projectorigin(*(btVector3 **)((char *)v72 + v19), v72[v21], v9, &v69, &v66);
      if ( v53 < 0.0 || v53 > v22 )
      {
        v53 = v22;
        if ( (v66 & 2) != 0 )
        {
          LODWORD(v67) = 1 << v21;
          v9 = d;
          v23 = 1 << v21;
        }
        else
        {
          v23 = 0;
        }
        v24 = ((v66 & 1) != 0 ? v62 : 0) + v23 + 2 * (v66 & 4);
        *(float *)((char *)w + v55) = v69;
        v25 = v70;
        *m = v24;
        v26 = `gjkepa2_impl::GJK::projectorigin'::`2'::imd3[v21];
        w[v21] = v25;
        v27 = v71;
        w[v26] = 0.0;
        *((_DWORD *)w + 3) = v27;
      }
      v20 = v58;
      v19 = v55;
    }
    v20 += 4;
    v19 += 4;
    v58 = v20;
    v55 = v19;
    v62 = __ROL4__(v62, 1);
  }
  while ( v19 < 0xC );
  if ( v53 < 0.0 )
  {
    v28 = v9->mVec128.m128_f32[1];
    v29 = c->mVec128.m128_f32[1];
    v30 = b->mVec128.m128_f32[2];
    v31 = v9->mVec128.m128_f32[0];
    v59 = v9->mVec128.m128_f32[2];
    v53 = 0.0;
    v32 = v29 * v30;
    v33 = v28 * c->mVec128.m128_f32[2];
    v34 = v59 * v29;
    v35 = b->mVec128.m128_f32[1] * v59;
    *(float *)&v66 = *(float *)&clear_value / _X;
    v36 = b->mVec128.m128_f32[0];
    v67 = v28;
    v37 = v28 * v30;
    v38 = c->mVec128.m128_f32[0];
    v56 = v34;
    v68 = v35;
    v39 = (float)((float)((float)((float)(v32 * v31) + (float)(v33 * v36)) - (float)(v37 * v38))
                - (float)(v34 * b->mVec128.m128_f32[0]))
        + (float)(v35 * v38);
    v40 = c->mVec128.m128_f32[2];
    v41 = (float)(b->mVec128.m128_f32[1] * v40) * v31;
    *m = 15;
    v42 = (float)(v39 - v41) * *(float *)&v66;
    v65 = a->mVec128.m128_f32[1];
    v43 = a->mVec128.m128_f32[2];
    v63 = v43 * v67;
    v60 = v65 * v59;
    v44 = (float)((float)(v65 * v40) * v31) + (float)((float)(v43 * v67) * v38);
    v45 = a->mVec128.m128_f32[0];
    v46 = (float)((float)((float)(v44 - (float)(v33 * a->mVec128.m128_f32[0])) - (float)(v60 * v38))
                + (float)(v56 * a->mVec128.m128_f32[0]))
        - (float)((float)(v43 * c->mVec128.m128_f32[1]) * v31);
    v47 = *(float *)&v66;
    *w = v42;
    v48 = (float)((float)((float)((float)((float)((float)(v43 * b->mVec128.m128_f32[1]) * v31) + (float)(v37 * v45))
                                - (float)(v63 * b->mVec128.m128_f32[0]))
                        - (float)(v68 * v45))
                + (float)(v60 * b->mVec128.m128_f32[0]))
        - (float)((float)(v65 * b->mVec128.m128_f32[2]) * v31);
    v49 = clear_value;
    v50 = v48 * v47;
    v51 = v46 * v47;
    w[2] = v50;
    w[1] = v51;
    w[3] = *(float *)&v49 - (float)((float)(v50 + v51) + v42);
  }
  return LODWORD(v53);
}


float __cdecl gjkepa2_impl::GJK::projectorigin(
        const btVector3 *a,
        const btVector3 *b,
        const btVector3 *c,
        float *w,
        unsigned int *m)
{
  float v5; // xmm1_4
  float v6; // xmm6_4
  const btVector3 *v7; // ebx
  const btVector3 *v8; // esi
  float v9; // xmm5_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm7_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  unsigned int v18; // edi
  float *v19; // ecx
  float v20; // xmm5_4
  float v21; // xmm3_4
  btVector3 *v22; // eax
  float v23; // xmm7_4
  unsigned int v24; // ebx
  float v25; // xmm0_4
  float v26; // xmm3_4
  int v27; // eax
  int v28; // edx
  float v29; // xmm0_4
  unsigned int v30; // edx
  long double v31; // st7
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm3_4
  float v36; // xmm5_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm1_4
  long double v41; // st7
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm0_4
  long double v45; // st7
  long double v46; // st7
  float _X; // [esp+344h] [ebp-88h]
  float v49; // [esp+344h] [ebp-88h]
  float v50; // [esp+348h] [ebp-84h]
  float v51; // [esp+34Ch] [ebp-80h]
  float v52; // [esp+34Ch] [ebp-80h]
  float v53; // [esp+350h] [ebp-7Ch]
  float v54; // [esp+350h] [ebp-7Ch]
  float v55; // [esp+354h] [ebp-78h]
  int v56; // [esp+35Ch] [ebp-70h]
  float *v57; // [esp+360h] [ebp-6Ch]
  float v58; // [esp+364h] [ebp-68h]
  float v59; // [esp+364h] [ebp-68h]
  float v60; // [esp+368h] [ebp-64h]
  float v61; // [esp+36Ch] [ebp-60h]
  unsigned int v62; // [esp+370h] [ebp-5Ch] BYREF
  float v63; // [esp+374h] [ebp-58h] BYREF
  float v64; // [esp+378h] [ebp-54h]
  float v65; // [esp+37Ch] [ebp-50h]
  _DWORD v66[3]; // [esp+380h] [ebp-4Ch] BYREF
  float v67; // [esp+38Ch] [ebp-40h]
  float v68; // [esp+390h] [ebp-3Ch]
  float v69; // [esp+394h] [ebp-38h]
  int v70; // [esp+398h] [ebp-34h]
  float v71; // [esp+39Ch] [ebp-30h]
  float v72; // [esp+3A0h] [ebp-2Ch]
  float v73; // [esp+3A4h] [ebp-28h]
  int v74; // [esp+3A8h] [ebp-24h]
  btVector3 *v75[3]; // [esp+3B0h] [ebp-1Ch]
  float v76; // [esp+3BCh] [ebp-10h]

  v5 = b->mVec128.m128_f32[1];
  v6 = b->mVec128.m128_f32[2];
  v7 = c;
  v8 = a;
  v9 = a->mVec128.m128_f32[1] - v5;
  v61 = a->mVec128.m128_f32[0];
  v10 = a->mVec128.m128_f32[0] - b->mVec128.m128_f32[0];
  v11 = a->mVec128.m128_f32[2] - v6;
  v60 = c->mVec128.m128_f32[0];
  v58 = b->mVec128.m128_f32[0];
  v12 = b->mVec128.m128_f32[0] - c->mVec128.m128_f32[0];
  v13 = c->mVec128.m128_f32[1];
  v68 = v5 - v13;
  v14 = c->mVec128.m128_f32[2];
  v69 = v6 - v14;
  v71 = v60 - v61;
  v72 = v13 - a->mVec128.m128_f32[1];
  v73 = v14 - a->mVec128.m128_f32[2];
  v15 = (float)((float)(v6 - v14) * v9) - (float)(v68 * v11);
  *(float *)&v66[1] = v11;
  v65 = v10;
  *(float *)v66 = v9;
  v67 = v12;
  v16 = (float)(v11 * v12) - (float)(v69 * v10);
  v17 = (float)(v68 * v10) - (float)(v12 * v9);
  v75[0] = (btVector3 *)a;
  v75[1] = (btVector3 *)b;
  v75[2] = (btVector3 *)c;
  v66[2] = 0;
  v70 = 0;
  v74 = 0;
  v51 = v15;
  v53 = v16;
  v55 = v17;
  _X = (float)((float)(v17 * v17) + (float)(v16 * v16)) + (float)(v15 * v15);
  if ( _X > 0.0 )
  {
    v18 = 0;
    v19 = (float *)v66;
    v50 = -1.0;
    v63 = 0.0;
    v64 = 0.0;
    v62 = 0;
    v56 = 1;
    v57 = (float *)v66;
    do
    {
      v20 = *v19;
      v21 = v19[1];
      v22 = v75[v18];
      v23 = *(v19 - 1);
      v76 = (float)(*v19 * v17) - (float)(v21 * v16);
      if ( (float)((float)((float)(v22->mVec128.m128_f32[2] * (float)((float)(v16 * v23) - (float)(v20 * v15)))
                         + (float)(v22->mVec128.m128_f32[1] * (float)((float)(v21 * v15) - (float)(v17 * v23))))
                 + (float)(v22->mVec128.m128_f32[0] * v76)) <= 0.0 )
      {
        v26 = v50;
      }
      else
      {
        v24 = `gjkepa2_impl::GJK::projectorigin'::`2'::imd3[v18];
        v25 = gjkepa2_impl::GJK::projectorigin(v75[v24], &v63, &v62, v22);
        v26 = v50;
        if ( v50 < 0.0 || v50 > v25 )
        {
          v27 = (v62 & 1) != 0 ? v56 : 0;
          v26 = v25;
          v50 = v25;
          if ( (v62 & 2) != 0 )
            v28 = 1 << v24;
          else
            v28 = 0;
          w[v18] = v63;
          v29 = v64;
          *m = v27 + v28;
          v30 = `gjkepa2_impl::GJK::projectorigin'::`2'::imd3[v24];
          w[v24] = v29;
          w[v30] = 0.0;
        }
        v17 = v55;
        v16 = v53;
        v15 = v51;
        v8 = a;
        v7 = c;
        v19 = v57;
      }
      v19 += 4;
      ++v18;
      v57 = v19;
      v56 = __ROL4__(v56, 1);
    }
    while ( v18 < 3 );
    if ( v26 < 0.0 )
    {
      v31 = sqrtf(_X);
      v32 = (float)((float)((float)(v61 * v51) + (float)(v8->mVec128.m128_f32[1] * v53))
                  + (float)(v55 * v8->mVec128.m128_f32[2]))
          / _X;
      v33 = v51 * v32;
      v34 = v53 * v32;
      v35 = v55 * v32;
      v36 = v58 - (float)(v51 * v32);
      v37 = b->mVec128.m128_f32[1] - (float)(v53 * v32);
      v52 = v33;
      v38 = b->mVec128.m128_f32[2] - v35;
      v54 = v34;
      v49 = 1.0 / v31;
      v39 = (float)(v38 * v68) - (float)(v37 * v69);
      v40 = (float)((float)((float)(v37 * v67) - (float)(v68 * v36)) * (float)((float)(v37 * v67) - (float)(v68 * v36)))
          + (float)((float)((float)(v69 * v36) - (float)(v38 * v67)) * (float)((float)(v69 * v36) - (float)(v38 * v67)));
      *m = 7;
      v41 = sqrtf(v40 + (float)(v39 * v39));
      v42 = v7->mVec128.m128_f32[1];
      v59 = v41 * v49;
      v43 = v7->mVec128.m128_f32[2] - v35;
      *w = v59;
      v44 = v42 - v54;
      v45 = sqrtf(
              (float)((float)((float)((float)(v44 * v71) - (float)(v72 * (float)(v60 - v52)))
                            * (float)((float)(v44 * v71) - (float)(v72 * (float)(v60 - v52))))
                    + (float)((float)((float)(v73 * (float)(v60 - v52)) - (float)(v43 * v71))
                            * (float)((float)(v73 * (float)(v60 - v52)) - (float)(v43 * v71))))
            + (float)((float)((float)(v43 * v72) - (float)(v44 * v73)) * (float)((float)(v43 * v72) - (float)(v44 * v73))))
          * v49;
      w[1] = v45;
      v46 = 1.0 - (v45 + v59);
      w[2] = v46;
    }
  }
  return v46;
}


float __usercall gjkepa2_impl::GJK::projectorigin@<xmm0>(
        const btVector3 *b@<eax>,
        float *w@<edx>,
        unsigned int *m@<esi>,
        const btVector3 *a)
{
  float v4; // xmm4_4
  float v5; // xmm6_4
  float v6; // xmm5_4
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  const vostok::math::float4x4 *v11; // xmm7_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm7_4

  v4 = a->mVec128.m128_f32[0];
  v5 = a->mVec128.m128_f32[2];
  v6 = a->mVec128.m128_f32[1];
  v7 = b->mVec128.m128_f32[0] - a->mVec128.m128_f32[0];
  v8 = b->mVec128.m128_f32[2] - v5;
  v9 = b->mVec128.m128_f32[1] - v6;
  if ( (float)((float)((float)(v7 * v7) + (float)(v8 * v8)) + (float)(v9 * v9)) <= 0.0 )
    return -1.0;
  v10 = -(float)((float)((float)((float)(v5 * v8) + (float)(v4 * v7)) + (float)(v6 * v9))
               / (float)((float)((float)(v7 * v7) + (float)(v8 * v8)) + (float)(v9 * v9)));
  v11 = clear_value;
  if ( v10 < *(float *)&clear_value )
  {
    if ( v10 > 0.0 )
    {
      v20 = *(float *)&clear_value - v10;
      w[1] = v10;
      *w = v20;
      *m = 3;
      return (float)((float)((float)(v5 + (float)(v8 * v10)) * (float)(v5 + (float)(v8 * v10)))
                   + (float)((float)(v4 + (float)(v7 * v10)) * (float)(v4 + (float)(v7 * v10))))
           + (float)((float)(v6 + (float)(v9 * v10)) * (float)(v6 + (float)(v9 * v10)));
    }
    else
    {
      v18 = a->mVec128.m128_f32[1];
      v19 = a->mVec128.m128_f32[2];
      *(_DWORD *)w = clear_value;
      w[1] = 0.0;
      *m = 1;
      return (float)((float)(v18 * v18) + (float)(v19 * v19)) + (float)(v4 * v4);
    }
  }
  else
  {
    v12 = b->mVec128.m128_f32[1];
    v13 = b->mVec128.m128_f32[2];
    *w = 0.0;
    v14 = v12 * v12;
    v15 = v13 * v13;
    v16 = b->mVec128.m128_f32[0];
    *((_DWORD *)w + 1) = v11;
    *m = 2;
    return (float)(v14 + v15) + (float)(v16 * v16);
  }
}
