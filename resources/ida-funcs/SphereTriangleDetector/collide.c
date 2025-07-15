char __thiscall SphereTriangleDetector::collide(
        SphereTriangleDetector *this,
        const btVector3 *sphereCenter,
        btVector3 *point,
        btVector3 *resultNormal,
        float *depth,
        float *timeOfImpact,
        float contactBreakingThreshold)
{
  float *v7; // eax
  float v8; // xmm5_4
  float v9; // xmm4_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float *v14; // eax
  float v15; // xmm1_4
  float v16; // xmm5_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm6_4
  float v20; // xmm1_4
  float v21; // xmm3_4
  float v22; // xmm7_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  float v27; // xmm0_4
  float v28; // xmm4_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm0_4
  const btVector3 *v33; // esi
  float v34; // xmm6_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm5_4
  float v38; // xmm0_4
  float v39; // xmm4_4
  float v40; // xmm3_4
  float v41; // xmm6_4
  float v42; // xmm3_4
  unsigned int v43; // xmm1_4
  unsigned int v44; // xmm0_4
  float v45; // xmm3_4
  float v46; // xmm3_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm5_4
  float v50; // xmm4_4
  float v51; // xmm0_4
  float v52; // xmm0_4
  const btVector3 *v54; // [esp+0h] [ebp-B0h]
  char v55; // [esp+13h] [ebp-9Dh]
  float v56; // [esp+14h] [ebp-9Ch]
  int v57; // [esp+14h] [ebp-9Ch]
  float v58; // [esp+18h] [ebp-98h]
  float v59; // [esp+1Ch] [ebp-94h]
  btVector3 v60; // [esp+20h] [ebp-90h]
  unsigned __int64 v61; // [esp+30h] [ebp-80h] BYREF
  float v62; // [esp+38h] [ebp-78h]
  int v63; // [esp+3Ch] [ebp-74h]
  float v64; // [esp+4Ch] [ebp-64h]
  btVector3 v65; // [esp+50h] [ebp-60h]
  float v66; // [esp+68h] [ebp-48h]
  float v67; // [esp+6Ch] [ebp-44h]
  btVector3 v68; // [esp+70h] [ebp-40h]
  btVector3 normal; // [esp+80h] [ebp-30h] BYREF
  btVector3 p; // [esp+90h] [ebp-20h] BYREF
  float v71; // [esp+A4h] [ebp-Ch]

  v7 = (float *)sphereCenter->mVec128.m128_i32[2];
  v8 = v7[28];
  v9 = v7[21];
  v10 = v7[22];
  v11 = v7[24];
  v12 = v7[30];
  v13 = v7[25];
  v14 = v7 + 20;
  v15 = *v14;
  v64 = *(float *)(sphereCenter->mVec128.m128_i32[1] + 32) * *(float *)(sphereCenter->mVec128.m128_i32[1] + 16);
  v16 = v8 - v15;
  v58 = v64 + contactBreakingThreshold;
  v17 = v14[9] - v9;
  v18 = v12 - v10;
  v19 = v11 - v15;
  v20 = v14[6] - v10;
  v21 = v13 - v9;
  v22 = v20 * v17;
  v23 = (float)(v20 * v16) - (float)(v18 * v19);
  v24 = (float)(v17 * v19) - (float)(v21 * v16);
  v25 = (float)(v21 * v18) - v22;
  v26 = fsqrt((float)((float)(v24 * v24) + (float)(v23 * v23)) + (float)(v25 * v25));
  v60.mVec128.m128_f32[2] = v24 * (float)(s_bm_current_air_resistance / v26);
  v27 = *v14;
  v60.mVec128.m128_f32[1] = v23 * (float)(s_bm_current_air_resistance / v26);
  v28 = v25 * (float)(s_bm_current_air_resistance / v26);
  v29 = point->mVec128.m128_f32[1];
  v67 = point->mVec128.m128_f32[0];
  v30 = v67 - v27;
  v59 = point->mVec128.m128_f32[2];
  v31 = (float)(v59 - v14[2]) * v60.mVec128.m128_f32[2];
  v66 = v29;
  v32 = (float)(v31 + (float)((float)(v29 - v14[1]) * v60.mVec128.m128_f32[1])) + (float)(v30 * v28);
  v60.mVec128.m128_i32[3] = 0;
  v60.mVec128.m128_f32[0] = v28;
  v56 = v32;
  if ( v32 < 0.0 )
  {
    v60.mVec128.m128_f32[0] = v28 * -1.0;
    v60.mVec128.m128_f32[1] = v60.mVec128.m128_f32[1] * -1.0;
    v32 = v32 * -1.0;
    v56 = v32;
    v60.mVec128.m128_f32[2] = v60.mVec128.m128_f32[2] * -1.0;
  }
  v55 = 0;
  if ( v58 <= v32 )
    return 0;
  p.mVec128 = point->mVec128;
  normal.mVec128 = v60.mVec128;
  if ( SphereTriangleDetector::pointInTriangle(&normal, &p, (SphereTriangleDetector *)v14, v54) )
  {
    *(float *)&v61 = v67 - (float)(v60.mVec128.m128_f32[0] * v56);
    *((float *)&v61 + 1) = v66 - (float)(v60.mVec128.m128_f32[1] * v56);
    v62 = v59 - (float)(v60.mVec128.m128_f32[2] * v56);
    v63 = 0;
    v68.mVec128.m128_u64[0] = v61;
    v68.mVec128.m128_f32[2] = v62;
    v68.mVec128.m128_i32[3] = 0;
  }
  else
  {
    v33 = sphereCenter;
    v57 = 0;
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)sphereCenter->mVec128.m128_i32[2] + 92))(sphereCenter->mVec128.m128_i32[2]) <= 0 )
      return 0;
    v65.mVec128.m128_i32[3] = 0;
    do
    {
      (*(void (__thiscall **)(int, int, unsigned __int64 *, btVector3 *))(*(_DWORD *)v33->mVec128.m128_i32[2] + 96))(
        v33->mVec128.m128_i32[2],
        v57,
        &v61,
        &normal);
      v34 = point->mVec128.m128_f32[2] - v62;
      v35 = normal.mVec128.m128_f32[1] - *((float *)&v61 + 1);
      v36 = normal.mVec128.m128_f32[2] - v62;
      v37 = point->mVec128.m128_f32[1] - *((float *)&v61 + 1);
      v38 = normal.mVec128.m128_f32[0] - *(float *)&v61;
      v39 = point->mVec128.m128_f32[0] - *(float *)&v61;
      v40 = (float)((float)((float)(normal.mVec128.m128_f32[2] - v62) * v34)
                  + (float)((float)(normal.mVec128.m128_f32[1] - *((float *)&v61 + 1)) * v37))
          + (float)((float)(normal.mVec128.m128_f32[0] - *(float *)&v61) * v39);
      p.mVec128.m128_f32[2] = v34;
      if ( v40 <= 0.0 )
      {
        v42 = 0.0;
      }
      else
      {
        v41 = (float)((float)(v36 * v36) + (float)(v35 * v35)) + (float)(v38 * v38);
        if ( v41 <= v40 )
        {
          v42 = s_bm_current_air_resistance;
          v39 = v39 - v38;
          v37 = v37 - v35;
          v34 = p.mVec128.m128_f32[2] - v36;
        }
        else
        {
          v42 = v40 / v41;
          v71 = v35 * v42;
          v37 = v37 - (float)(v35 * v42);
          v39 = v39 - (float)(v38 * v42);
          v34 = p.mVec128.m128_f32[2] - (float)(v36 * v42);
        }
      }
      v65.mVec128.m128_f32[1] = (float)(v35 * v42) + *((float *)&v61 + 1);
      v65.mVec128.m128_f32[0] = (float)(v38 * v42) + *(float *)&v61;
      v65.mVec128.m128_f32[2] = (float)(v36 * v42) + v62;
      if ( (float)(v58 * v58) > (float)((float)((float)(v34 * v34) + (float)(v37 * v37)) + (float)(v39 * v39)) )
      {
        v68.mVec128 = v65.mVec128;
        v33 = sphereCenter;
        v55 = 1;
      }
      ++v57;
    }
    while ( v57 < (*(int (__thiscall **)(int))(*(_DWORD *)v33->mVec128.m128_i32[2] + 92))(v33->mVec128.m128_i32[2]) );
    if ( !v55 )
      return 0;
  }
  *(float *)&v43 = point->mVec128.m128_f32[1] - v68.mVec128.m128_f32[1];
  *(float *)&v44 = point->mVec128.m128_f32[0] - v68.mVec128.m128_f32[0];
  v45 = point->mVec128.m128_f32[2];
  v65.mVec128.m128_i32[3] = 0;
  v65.mVec128.m128_f32[2] = v45 - v68.mVec128.m128_f32[2];
  v65.mVec128.m128_u64[0] = __PAIR64__(v43, v44);
  v46 = (float)((float)(v65.mVec128.m128_f32[2] * v65.mVec128.m128_f32[2]) + (float)(*(float *)&v43 * *(float *)&v43))
      + (float)(*(float *)&v44 * *(float *)&v44);
  if ( (float)(v58 * v58) <= v46 )
    return 0;
  if ( v46 <= 0.00000011920929 )
  {
    v52 = v64;
    *(_QWORD *)depth = v60.mVec128.m128_u64[0];
    depth[2] = v60.mVec128.m128_f32[2];
    depth[3] = 0.0;
  }
  else
  {
    *(btVector3 *)depth = (btVector3)v65.mVec128;
    v47 = depth[1];
    v48 = *depth;
    v49 = depth[2];
    v50 = s_bm_current_air_resistance / fsqrt((float)((float)(v48 * v48) + (float)(v47 * v47)) + (float)(v49 * v49));
    depth[2] = v49 * v50;
    v51 = v64;
    depth[1] = v47 * v50;
    *depth = v48 * v50;
    v52 = v51 - fsqrt(v46);
  }
  *resultNormal = (btVector3)v68.mVec128;
  *(_DWORD *)timeOfImpact = LODWORD(v52) ^ _mask__NegFloat_;
  return 1;
}
