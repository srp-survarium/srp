BOOL __usercall triBoxOverlap@<eax>(
        const vostok::math::float3 *boxhalfsize@<edx>,
        const vostok::math::float3 (*triverts)[3]@<eax>,
        const vostok::math::float3 *boxcenter)
{
  float y; // xmm1_4
  float x; // xmm0_4
  float z; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm5_4
  float v8; // xmm4_4
  float v9; // xmm7_4
  float v10; // xmm6_4
  float v11; // xmm3_4
  float v12; // xmm7_4
  float v13; // xmm7_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm7_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm7_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm7_4
  float v24; // xmm1_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  float v28; // xmm7_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm7_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  float v34; // xmm7_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  float v37; // xmm7_4
  float v38; // xmm2_4
  float v39; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  float fey; // [esp+0h] [ebp-64h]
  int feya; // [esp+0h] [ebp-64h]
  int feyb; // [esp+0h] [ebp-64h]
  float fex; // [esp+4h] [ebp-60h]
  int fexa; // [esp+4h] [ebp-60h]
  int fexb; // [esp+4h] [ebp-60h]
  float max; // [esp+8h] [ebp-5Ch]
  float maxa; // [esp+8h] [ebp-5Ch]
  __int64 v51; // [esp+Ch] [ebp-58h]
  float min; // [esp+14h] [ebp-50h]
  float v53; // [esp+1Ch] [ebp-48h]
  float v54; // [esp+20h] [ebp-44h]
  float v55; // [esp+24h] [ebp-40h]
  float v56; // [esp+28h] [ebp-3Ch]
  float v57; // [esp+2Ch] [ebp-38h]
  float v58; // [esp+30h] [ebp-34h]
  float v59; // [esp+38h] [ebp-2Ch]
  float v60; // [esp+3Ch] [ebp-28h]
  vostok::math::float3 normal; // [esp+40h] [ebp-24h] BYREF
  vostok::math::float3 v62; // [esp+4Ch] [ebp-18h]
  vostok::math::float3 v0; // [esp+58h] [ebp-Ch] BYREF
  float fez; // [esp+68h] [ebp+4h]
  int feza; // [esp+68h] [ebp+4h]
  int fezb; // [esp+68h] [ebp+4h]

  y = boxcenter->y;
  x = boxcenter->x;
  z = boxcenter->z;
  v6 = (*triverts)[0].z;
  v7 = (*triverts)[0].x - boxcenter->x;
  v8 = (*triverts)[0].y - y;
  v59 = (*triverts)[1].y - y;
  v60 = (*triverts)[1].z - z;
  v9 = (*triverts)[2].x - boxcenter->x;
  *(_QWORD *)&v62.x = __PAIR64__(LODWORD(v8), LODWORD(v7));
  *(_QWORD *)&v0.x = __PAIR64__(LODWORD(v8), LODWORD(v7));
  v10 = (*triverts)[1].x - x;
  v55 = (*triverts)[2].z - z;
  v11 = v6 - z;
  v56 = v10 - v7;
  v58 = v60 - v11;
  v53 = v9;
  v12 = (*triverts)[2].y;
  normal.x = v53 - v10;
  v13 = v12 - y;
  normal.y = v13 - v59;
  normal.z = v55 - v60;
  v62.x = v7 - v53;
  v62.y = v8 - v13;
  v62.z = v11 - v55;
  v0.z = v11;
  fex = fabs(v10 - v7);
  v14 = (float)((float)(v60 - v11) * v8) - (float)((float)(v59 - v8) * v11);
  v54 = v13;
  v57 = v59 - v8;
  fey = fabs(v59 - v8);
  fez = fabs(v60 - v11);
  if ( (float)((float)((float)(v60 - v11) * v13) - (float)((float)(v59 - v8) * v55)) <= v14 )
  {
    max = (float)((float)(v60 - v11) * v8) - (float)((float)(v59 - v8) * v11);
    v14 = (float)((float)(v60 - v11) * v13) - (float)((float)(v59 - v8) * v55);
  }
  else
  {
    max = (float)((float)(v60 - v11) * v13) - (float)((float)(v59 - v8) * v55);
  }
  v51 = *(_QWORD *)&boxhalfsize->elements[1];
  v15 = (float)(*((float *)&v51 + 1) * fey) + (float)(*(float *)&v51 * fez);
  if ( v14 > v15 || (float)-v15 > max )
    return 0;
  v16 = (float)(v11 * v56) - (float)(v58 * v7);
  if ( (float)((float)(v55 * v56) - (float)(v58 * v53)) <= v16 )
  {
    v17 = (float)(v55 * v56) - (float)(v58 * v53);
  }
  else
  {
    v17 = (float)(v11 * v56) - (float)(v58 * v7);
    v16 = (float)(v55 * v56) - (float)(v58 * v53);
  }
  maxa = boxhalfsize->x;
  v18 = (float)(boxhalfsize->x * fez) + (float)(*((float *)&v51 + 1) * fex);
  if ( v17 > v18 || (float)-v18 > v16 )
    return 0;
  v19 = (float)(v57 * v10) - (float)(v59 * v56);
  if ( v19 <= (float)((float)(v57 * v53) - (float)(v54 * v56)) )
  {
    v20 = (float)(v57 * v10) - (float)(v59 * v56);
    v19 = (float)(v57 * v53) - (float)(v54 * v56);
  }
  else
  {
    v20 = (float)(v57 * v53) - (float)(v54 * v56);
  }
  v21 = (float)(maxa * fey) + (float)(*(float *)&v51 * fex);
  if ( v20 > v21 || (float)-v21 > v19 )
    return 0;
  fexa = LODWORD(normal.x) & 0x7FFFFFFF;
  v22 = (float)(normal.z * v8) - (float)(normal.y * v11);
  feya = LODWORD(normal.y) & 0x7FFFFFFF;
  feza = LODWORD(normal.z) & 0x7FFFFFFF;
  if ( (float)((float)(normal.z * v54) - (float)(normal.y * v55)) <= v22 )
  {
    v23 = (float)(normal.z * v54) - (float)(normal.y * v55);
  }
  else
  {
    v23 = (float)(normal.z * v8) - (float)(normal.y * v11);
    v22 = (float)(normal.z * v54) - (float)(normal.y * v55);
  }
  v24 = (float)(*((float *)&v51 + 1) * *(float *)&feya) + (float)(*(float *)&v51 * *(float *)&feza);
  if ( v23 > v24 || (float)-v24 > v22 )
    return 0;
  v25 = (float)(v55 * normal.x) - (float)(normal.z * v53);
  if ( v25 <= (float)((float)(v11 * normal.x) - (float)(normal.z * v7)) )
  {
    min = (float)(v55 * normal.x) - (float)(normal.z * v53);
    v25 = (float)(v11 * normal.x) - (float)(normal.z * v7);
  }
  else
  {
    min = (float)(v11 * normal.x) - (float)(normal.z * v7);
  }
  v26 = (float)(maxa * *(float *)&feza) + (float)(*((float *)&v51 + 1) * *(float *)&fexa);
  if ( min > v26 || (float)-v26 > v25 )
    return 0;
  v27 = (float)(normal.y * v7) - (float)(v8 * normal.x);
  if ( (float)((float)(normal.y * v10) - (float)(v59 * normal.x)) <= v27 )
  {
    v28 = (float)(normal.y * v10) - (float)(v59 * normal.x);
  }
  else
  {
    v28 = (float)(normal.y * v7) - (float)(v8 * normal.x);
    v27 = (float)(normal.y * v10) - (float)(v59 * normal.x);
  }
  v29 = (float)(maxa * *(float *)&feya) + (float)(*(float *)&v51 * *(float *)&fexa);
  if ( v28 > v29 || (float)-v29 > v27 )
    return 0;
  v30 = (float)(v8 * v62.z) - (float)(v11 * v62.y);
  fexb = LODWORD(v62.x) & 0x7FFFFFFF;
  feyb = LODWORD(v62.y) & 0x7FFFFFFF;
  fezb = LODWORD(v62.z) & 0x7FFFFFFF;
  if ( (float)((float)(v59 * v62.z) - (float)(v60 * v62.y)) <= v30 )
  {
    v31 = (float)(v59 * v62.z) - (float)(v60 * v62.y);
  }
  else
  {
    v31 = (float)(v8 * v62.z) - (float)(v11 * v62.y);
    v30 = (float)(v59 * v62.z) - (float)(v60 * v62.y);
  }
  v32 = (float)(*((float *)&v51 + 1) * *(float *)&feyb) + (float)(*(float *)&v51 * *(float *)&fezb);
  if ( v31 > v32 || (float)-v32 > v30 )
    return 0;
  v33 = (float)(v11 * v62.x) - (float)(v7 * v62.z);
  if ( (float)((float)(v60 * v62.x) - (float)(v10 * v62.z)) <= v33 )
  {
    v34 = (float)(v60 * v62.x) - (float)(v10 * v62.z);
  }
  else
  {
    v34 = (float)(v11 * v62.x) - (float)(v7 * v62.z);
    v33 = (float)(v60 * v62.x) - (float)(v10 * v62.z);
  }
  v35 = (float)(maxa * *(float *)&fezb) + (float)(*((float *)&v51 + 1) * *(float *)&fexb);
  if ( v34 > v35 || (float)-v35 > v33 )
    return 0;
  v36 = (float)(v10 * v62.y) - (float)(v59 * v62.x);
  if ( v36 <= (float)((float)(v53 * v62.y) - (float)(v54 * v62.x)) )
  {
    v37 = (float)(v10 * v62.y) - (float)(v59 * v62.x);
    v36 = (float)(v53 * v62.y) - (float)(v54 * v62.x);
  }
  else
  {
    v37 = (float)(v53 * v62.y) - (float)(v54 * v62.x);
  }
  v38 = (float)(maxa * *(float *)&feyb) + (float)(*(float *)&v51 * *(float *)&fexb);
  if ( v37 > v38 || (float)-v38 > v36 )
    return 0;
  v39 = v7;
  if ( v7 > v10 )
    v39 = v10;
  if ( v10 > v7 )
    v7 = v10;
  if ( v39 > v53 )
    v39 = v53;
  if ( v53 > v7 )
    v7 = v53;
  if ( v39 > maxa || (float)-maxa > v7 )
    return 0;
  v40 = v8;
  if ( v8 > v59 )
    v40 = v59;
  if ( v59 > v8 )
    v8 = v59;
  if ( v40 > v54 )
    v40 = v54;
  if ( v54 > v8 )
    v8 = v54;
  if ( v40 > *(float *)&v51 || (float)-*(float *)&v51 > v8 )
    return 0;
  v41 = v11;
  if ( v11 > v60 )
    v41 = v60;
  if ( v60 > v11 )
    v11 = v60;
  if ( v41 > v55 )
    v41 = v55;
  if ( v55 > v11 )
    v11 = v55;
  if ( v41 > *((float *)&v51 + 1) || (float)-*((float *)&v51 + 1) > v11 )
    return 0;
  v62.x = (float)(normal.z * v57) - (float)(normal.y * v58);
  v62.z = (float)(normal.y * v56) - (float)(v57 * normal.x);
  v62.y = (float)(v58 * normal.x) - (float)(normal.z * v56);
  normal = v62;
  return planeBoxOverlap(&v0, boxhalfsize, &normal);
}
