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
