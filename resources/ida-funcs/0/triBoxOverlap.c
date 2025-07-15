BOOL __usercall triBoxOverlap@<eax>(
        const vostok::math::float3 *boxhalfsize@<eax>,
        const vostok::math::float3 (*triverts)[3]@<ecx>,
        const vostok::math::float3 *boxcenter)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float x; // xmm0_4
  float v6; // xmm6_4
  float v7; // xmm4_4
  float v8; // xmm3_4
  float v9; // xmm5_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm4_4
  float v13; // xmm7_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm7_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm7_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm7_4
  float v24; // xmm1_4
  float v25; // xmm7_4
  float v26; // xmm2_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm7_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm1_4
  vostok::math::float3 v44; // [esp+0h] [ebp-64h] BYREF
  vostok::math::float3 v45; // [esp+Ch] [ebp-58h] BYREF
  vostok::math::float3 v46; // [esp+18h] [ebp-4Ch]
  __int64 v47; // [esp+24h] [ebp-40h]
  float v48; // [esp+2Ch] [ebp-38h]
  float v49; // [esp+30h] [ebp-34h]
  float v50; // [esp+34h] [ebp-30h]
  float v51; // [esp+38h] [ebp-2Ch]
  float v52; // [esp+3Ch] [ebp-28h]
  float v53; // [esp+40h] [ebp-24h]
  float v54; // [esp+44h] [ebp-20h]
  float v55; // [esp+48h] [ebp-1Ch]
  float v56; // [esp+4Ch] [ebp-18h]
  float v57; // [esp+50h] [ebp-14h]
  float v58; // [esp+54h] [ebp-10h]
  float v59; // [esp+58h] [ebp-Ch]
  __int64 v60; // [esp+5Ch] [ebp-8h]
  float v61; // [esp+6Ch] [ebp+8h]
  int v62; // [esp+6Ch] [ebp+8h]
  int v63; // [esp+6Ch] [ebp+8h]

  y = boxcenter->y;
  z = boxcenter->z;
  x = boxcenter->x;
  v6 = (*triverts)[0].y;
  v7 = (*triverts)[0].z;
  v8 = (*triverts)[0].x - boxcenter->x;
  v9 = (*triverts)[1].x - boxcenter->x;
  v46.y = (*triverts)[1].y - y;
  v46.z = (*triverts)[1].z - z;
  v10 = (*triverts)[2].x - x;
  v54 = (*triverts)[2].z - z;
  v11 = v6 - y;
  v12 = v7 - z;
  *(_QWORD *)&v45.x = __PAIR64__(LODWORD(v11), LODWORD(v8));
  v45.z = v12;
  *(_QWORD *)&v44.x = __PAIR64__(LODWORD(v11), LODWORD(v8));
  v49 = v9 - v8;
  v51 = v46.z - v12;
  v52 = v10;
  v13 = (*triverts)[2].y - y;
  v44.z = v12;
  v45.x = v52 - v9;
  v45.y = v13 - v46.y;
  v45.z = v54 - v46.z;
  *(float *)&v47 = v8 - v52;
  *((float *)&v47 + 1) = v11 - v13;
  v48 = v12 - v54;
  v60 = __PAIR64__(COERCE_UNSIGNED_INT(fabs(v46.y - v11)), COERCE_UNSIGNED_INT(fabs(v9 - v8)));
  v53 = v13;
  v50 = v46.y - v11;
  v61 = fabs(v46.z - v12);
  v14 = (float)((float)(v46.z - v12) * v11) - (float)((float)(v46.y - v11) * v12);
  v15 = (float)((float)(v46.z - v12) * v13) - (float)((float)(v46.y - v11) * v54);
  if ( v15 <= v14 )
  {
    v16 = (float)((float)(v46.z - v12) * v13) - (float)((float)(v46.y - v11) * v54);
  }
  else
  {
    v16 = (float)((float)(v46.z - v12) * v11) - (float)((float)(v46.y - v11) * v12);
    v14 = v15;
  }
  v17 = boxhalfsize->y;
  v57 = boxhalfsize->z;
  v58 = v17;
  v18 = (float)(v57 * *((float *)&v60 + 1)) + (float)(v17 * v61);
  if ( v16 > v18 || COERCE_FLOAT(LODWORD(v18) ^ _mask__NegFloat_) > v14 )
    return 0;
  v19 = (float)(v54 * v49) - (float)(v51 * v52);
  if ( v19 <= (float)((float)(v12 * v49) - (float)(v51 * v8)) )
  {
    v20 = (float)(v54 * v49) - (float)(v51 * v52);
    v19 = (float)(v12 * v49) - (float)(v51 * v8);
  }
  else
  {
    v20 = (float)(v12 * v49) - (float)(v51 * v8);
  }
  v56 = boxhalfsize->x;
  v21 = (float)(v56 * v61) + (float)(v57 * *(float *)&v60);
  if ( v20 > v21 || COERCE_FLOAT(LODWORD(v21) ^ _mask__NegFloat_) > v19 )
    return 0;
  v22 = (float)(v50 * v9) - (float)(v46.y * v49);
  if ( v22 <= (float)((float)(v50 * v52) - (float)(v53 * v49)) )
  {
    v23 = (float)(v50 * v9) - (float)(v46.y * v49);
    v22 = (float)(v50 * v52) - (float)(v53 * v49);
  }
  else
  {
    v23 = (float)(v50 * v52) - (float)(v53 * v49);
  }
  v24 = (float)(v56 * *((float *)&v60 + 1)) + (float)(v58 * *(float *)&v60);
  if ( v23 > v24 || COERCE_FLOAT(LODWORD(v24) ^ _mask__NegFloat_) > v22 )
    return 0;
  v60 = *(_QWORD *)&v45.x & 0x7FFFFFFF7FFFFFFFLL;
  v59 = v45.z;
  v62 = LODWORD(v45.z) & 0x7FFFFFFF;
  if ( (float)((float)(v45.z * v53) - (float)(v45.y * v54)) <= (float)((float)(v45.z * v11) - (float)(v45.y * v12)) )
  {
    v25 = (float)(v45.z * v53) - (float)(v45.y * v54);
    v59 = (float)(v45.z * v11) - (float)(v45.y * v12);
  }
  else
  {
    v25 = (float)(v45.z * v11) - (float)(v45.y * v12);
    v59 = (float)(v45.z * v53) - (float)(v45.y * v54);
  }
  v26 = (float)(v57 * *((float *)&v60 + 1)) + (float)(v58 * *(float *)&v62);
  if ( v25 > v26 || COERCE_FLOAT(LODWORD(v26) ^ _mask__NegFloat_) > v59 )
    return 0;
  if ( (float)((float)(v54 * v45.x) - (float)(v45.z * v52)) <= (float)((float)(v12 * v45.x) - (float)(v45.z * v8)) )
  {
    v27 = (float)(v54 * v45.x) - (float)(v45.z * v52);
    v59 = (float)(v12 * v45.x) - (float)(v45.z * v8);
  }
  else
  {
    v27 = (float)(v12 * v45.x) - (float)(v45.z * v8);
    v59 = (float)(v54 * v45.x) - (float)(v45.z * v52);
  }
  v28 = (float)(v56 * *(float *)&v62) + (float)(v57 * *(float *)&v60);
  if ( v27 > v28 || COERCE_FLOAT(LODWORD(v28) ^ _mask__NegFloat_) > v59 )
    return 0;
  v29 = (float)(v45.y * v9) - (float)(v46.y * v45.x);
  if ( v29 <= (float)((float)(v45.y * v8) - (float)(v11 * v45.x)) )
  {
    v30 = (float)(v45.y * v9) - (float)(v46.y * v45.x);
    v29 = (float)(v45.y * v8) - (float)(v11 * v45.x);
  }
  else
  {
    v30 = (float)(v45.y * v8) - (float)(v11 * v45.x);
  }
  v31 = (float)(v56 * *((float *)&v60 + 1)) + (float)(v58 * *(float *)&v60);
  if ( v30 > v31 || COERCE_FLOAT(LODWORD(v31) ^ _mask__NegFloat_) > v29 )
    return 0;
  v60 = v47 & 0x7FFFFFFF7FFFFFFFLL;
  v55 = v48;
  v32 = (float)(v46.y * v48) - (float)(v46.z * *((float *)&v47 + 1));
  v63 = LODWORD(v48) & 0x7FFFFFFF;
  if ( v32 <= (float)((float)(v11 * v48) - (float)(v12 * *((float *)&v47 + 1))) )
  {
    v33 = (float)(v46.y * v48) - (float)(v46.z * *((float *)&v47 + 1));
    v32 = (float)(v11 * v48) - (float)(v12 * *((float *)&v47 + 1));
  }
  else
  {
    v33 = (float)(v11 * v48) - (float)(v12 * *((float *)&v47 + 1));
  }
  v34 = (float)(v57 * *((float *)&v60 + 1)) + (float)(v58 * *(float *)&v63);
  if ( v33 > v34 || COERCE_FLOAT(LODWORD(v34) ^ _mask__NegFloat_) > v32 )
    return 0;
  v35 = (float)(v46.z * *(float *)&v47) - (float)(v9 * v48);
  if ( v35 <= (float)((float)(v12 * *(float *)&v47) - (float)(v8 * v48)) )
  {
    v36 = (float)(v46.z * *(float *)&v47) - (float)(v9 * v48);
    v35 = (float)(v12 * *(float *)&v47) - (float)(v8 * v48);
  }
  else
  {
    v36 = (float)(v12 * *(float *)&v47) - (float)(v8 * v48);
  }
  v37 = (float)(v56 * *(float *)&v63) + (float)(v57 * *(float *)&v60);
  if ( v36 > v37 || COERCE_FLOAT(LODWORD(v37) ^ _mask__NegFloat_) > v35 )
    return 0;
  if ( (float)((float)(v9 * *((float *)&v47 + 1)) - (float)(v46.y * *(float *)&v47)) <= (float)((float)(v52 * *((float *)&v47 + 1))
                                                                                              - (float)(v53 * *(float *)&v47)) )
  {
    v38 = (float)(v9 * *((float *)&v47 + 1)) - (float)(v46.y * *(float *)&v47);
    v59 = (float)(v52 * *((float *)&v47 + 1)) - (float)(v53 * *(float *)&v47);
  }
  else
  {
    v38 = (float)(v52 * *((float *)&v47 + 1)) - (float)(v53 * *(float *)&v47);
    v59 = (float)(v9 * *((float *)&v47 + 1)) - (float)(v46.y * *(float *)&v47);
  }
  v39 = (float)(v56 * *((float *)&v60 + 1)) + (float)(v58 * *(float *)&v60);
  if ( v38 > v39 || COERCE_FLOAT(LODWORD(v39) ^ _mask__NegFloat_) > v59 )
    return 0;
  v40 = v8;
  if ( v8 > v9 )
    v40 = v9;
  if ( v9 > v8 )
    v8 = v9;
  if ( v40 > v52 )
    v40 = v52;
  if ( v52 > v8 )
    v8 = v52;
  if ( v40 > v56 || COERCE_FLOAT(LODWORD(v56) ^ _mask__NegFloat_) > v8 )
    return 0;
  v41 = v11;
  if ( v11 > v46.y )
    v41 = v46.y;
  if ( v46.y > v11 )
    v11 = v46.y;
  if ( v41 > v53 )
    v41 = v53;
  if ( v53 > v11 )
    v11 = v53;
  if ( v41 > v58 || COERCE_FLOAT(LODWORD(v58) ^ _mask__NegFloat_) > v11 )
    return 0;
  v42 = v12;
  if ( v12 > v46.z )
    v42 = v46.z;
  if ( v46.z > v12 )
    v12 = v46.z;
  if ( v42 > v54 )
    v42 = v54;
  if ( v54 > v12 )
    v12 = v54;
  if ( v42 > v57 || COERCE_FLOAT(LODWORD(v57) ^ _mask__NegFloat_) > v12 )
    return 0;
  v46.x = (float)(v45.z * v50) - (float)(v45.y * v51);
  v46.y = (float)(v51 * v45.x) - (float)(v45.z * v49);
  v46.z = (float)(v45.y * v49) - (float)(v50 * v45.x);
  v45 = v46;
  return planeBoxOverlap(boxhalfsize, &v45, &v44);
}
