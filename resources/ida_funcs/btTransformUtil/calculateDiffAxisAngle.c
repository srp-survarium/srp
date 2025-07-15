void __usercall btTransformUtil::calculateDiffAxisAngle(
        const btTransform *transform0@<ecx>,
        const btTransform *transform1@<eax>,
        btVector3 *axis@<edi>,
        float *angle)
{
  float v4; // xmm6_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm5_4
  float v8; // xmm7_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm4_4
  float v18; // xmm7_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm4_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm6_4
  float v25; // xmm5_4
  long double v26; // st7
  int v27; // xmm1_4
  long double v28; // st7
  float v29; // xmm0_4
  long double v30; // st7
  float v31; // [esp+D8h] [ebp-7Ch]
  float v32; // [esp+D8h] [ebp-7Ch]
  float v33; // [esp+DCh] [ebp-78h]
  float v34; // [esp+E0h] [ebp-74h]
  float v35; // [esp+E4h] [ebp-70h]
  float v36; // [esp+E8h] [ebp-6Ch]
  float _X; // [esp+E8h] [ebp-6Ch]
  float v38; // [esp+ECh] [ebp-68h]
  float v39; // [esp+ECh] [ebp-68h]
  float v40; // [esp+F0h] [ebp-64h]
  float v41; // [esp+F0h] [ebp-64h]
  float v42; // [esp+F4h] [ebp-60h]
  float v43; // [esp+F4h] [ebp-60h]
  float v44; // [esp+F4h] [ebp-60h]
  float v45; // [esp+F8h] [ebp-5Ch]
  float v46; // [esp+FCh] [ebp-58h]
  float v47; // [esp+FCh] [ebp-58h]
  float v48; // [esp+100h] [ebp-54h]
  float v49; // [esp+100h] [ebp-54h]
  btQuaternion q; // [esp+104h] [ebp-50h] BYREF
  unsigned __int64 v51; // [esp+114h] [ebp-40h]
  __int64 v52; // [esp+11Ch] [ebp-38h]
  float v53[12]; // [esp+124h] [ebp-30h] BYREF

  v4 = transform0->m_basis.m_el[1].mVec128.m128_f32[1];
  v5 = transform0->m_basis.m_el[2].mVec128.m128_f32[2];
  v6 = transform0->m_basis.m_el[2].mVec128.m128_f32[1];
  v7 = transform0->m_basis.m_el[2].mVec128.m128_f32[0];
  v8 = transform0->m_basis.m_el[1].mVec128.m128_f32[0];
  v38 = transform0->m_basis.m_el[1].mVec128.m128_f32[2];
  v9 = (float)(v4 * v5) - (float)(v38 * v6);
  v40 = v6;
  v10 = (float)(v7 * v38) - (float)(v8 * v5);
  v42 = v5;
  v11 = (float)(v8 * v6) - (float)(v7 * v4);
  v12 = *(float *)&clear_value
      / (float)((float)((float)(transform0->m_basis.m_el[0].mVec128.m128_f32[0] * v9)
                      + (float)(transform0->m_basis.m_el[0].mVec128.m128_f32[1] * v10))
              + (float)(v11 * transform0->m_basis.m_el[0].mVec128.m128_f32[2]));
  v31 = transform0->m_basis.m_el[0].mVec128.m128_f32[1];
  v34 = (float)((float)(v31 * v7) - (float)(transform0->m_basis.m_el[0].mVec128.m128_f32[0] * v6)) * v12;
  v35 = v11 * v12;
  v13 = transform0->m_basis.m_el[0].mVec128.m128_f32[2];
  v33 = (float)((float)(v13 * v8) - (float)(transform0->m_basis.m_el[0].mVec128.m128_f32[0] * v38)) * v12;
  v14 = (float)(transform0->m_basis.m_el[0].mVec128.m128_f32[0] * v42) - (float)(v13 * v7);
  v36 = v10 * v12;
  v15 = (float)((float)(transform0->m_basis.m_el[0].mVec128.m128_f32[0] * v4) - (float)(v31 * v8)) * v12;
  v46 = v14 * v12;
  v16 = (float)((float)(v31 * v38) - (float)(v13 * v4)) * v12;
  v17 = (float)((float)(v13 * v40) - (float)(v31 * v42)) * v12;
  v41 = v9 * v12;
  v43 = v17;
  v18 = (float)((float)(transform1->m_basis.m_el[2].mVec128.m128_f32[1] * v33)
              + (float)(transform1->m_basis.m_el[2].mVec128.m128_f32[2] * v15))
      + (float)(transform1->m_basis.m_el[2].mVec128.m128_f32[0] * v16);
  v19 = (float)((float)(transform1->m_basis.m_el[2].mVec128.m128_f32[1] * (float)(v14 * v12))
              + (float)(transform1->m_basis.m_el[2].mVec128.m128_f32[2] * v34))
      + (float)(v17 * transform1->m_basis.m_el[2].mVec128.m128_f32[0]);
  v20 = (float)((float)(transform1->m_basis.m_el[2].mVec128.m128_f32[1] * v36)
              + (float)(transform1->m_basis.m_el[2].mVec128.m128_f32[2] * v35))
      + (float)(transform1->m_basis.m_el[2].mVec128.m128_f32[0] * (float)(v9 * v12));
  v21 = (float)((float)(transform1->m_basis.m_el[1].mVec128.m128_f32[1] * v33)
              + (float)(transform1->m_basis.m_el[1].mVec128.m128_f32[2] * v15))
      + (float)(transform1->m_basis.m_el[1].mVec128.m128_f32[0] * v16);
  v48 = (float)((float)(transform1->m_basis.m_el[1].mVec128.m128_f32[1] * (float)(v14 * v12))
              + (float)(transform1->m_basis.m_el[1].mVec128.m128_f32[2] * v34))
      + (float)(transform1->m_basis.m_el[1].mVec128.m128_f32[0] * v43);
  v39 = (float)((float)(transform1->m_basis.m_el[1].mVec128.m128_f32[1] * v36)
              + (float)(transform1->m_basis.m_el[1].mVec128.m128_f32[2] * v35))
      + (float)(transform1->m_basis.m_el[1].mVec128.m128_f32[0] * v41);
  v32 = transform1->m_basis.m_el[0].mVec128.m128_f32[2];
  v22 = transform1->m_basis.m_el[0].mVec128.m128_f32[0];
  v23 = transform1->m_basis.m_el[0].mVec128.m128_f32[0] * v16;
  v24 = v32 * v15;
  v25 = transform1->m_basis.m_el[0].mVec128.m128_f32[1];
  v53[0] = (float)((float)(transform1->m_basis.m_el[0].mVec128.m128_f32[0] * v41) + (float)(v32 * v35))
         + (float)(v25 * v36);
  v53[1] = (float)((float)(v22 * v43) + (float)(v32 * v34)) + (float)(v25 * v46);
  v53[2] = (float)(v23 + v24) + (float)(v25 * v33);
  v53[4] = v39;
  v53[3] = 0.0;
  v53[5] = v48;
  v53[6] = v21;
  v53[7] = 0.0;
  v53[8] = v20;
  v53[9] = v19;
  v53[10] = v18;
  v53[11] = 0.0;
  btMatrix3x3::getRotation(&transform0->m_basis, v53, &q);
  v26 = 1.0
      / sqrtf(
          (float)((float)((float)(q.m_floats[0] * q.m_floats[0]) + (float)(q.m_floats[1] * q.m_floats[1]))
                + (float)(q.m_floats[2] * q.m_floats[2]))
        + (float)(q.m_floats[3] * q.m_floats[3]));
  v27 = -1082130432;
  v49 = v26;
  _X = q.m_floats[3] * v49;
  q.m_floats[0] = q.m_floats[0] * v26;
  q.m_floats[1] = q.m_floats[1] * v26;
  q.m_floats[2] = v26 * q.m_floats[2];
  if ( (float)(q.m_floats[3] * v49) < -1.0
    || (v27 = (int)clear_value, (float)(q.m_floats[3] * v49) > *(float *)&clear_value) )
  {
    _X = *(float *)&v27;
  }
  v28 = acosf(_X);
  *(float *)&v51 = q.m_floats[0];
  *angle = v28 + v28;
  HIDWORD(v51) = LODWORD(q.m_floats[1]);
  *(float *)&v52 = q.m_floats[2];
  axis->mVec128.m128_u64[0] = v51;
  HIDWORD(v52) = 0;
  axis->mVec128.m128_u64[1] = (unsigned int)v52;
  v47 = axis->mVec128.m128_f32[0];
  v45 = axis->mVec128.m128_f32[1];
  v44 = axis->mVec128.m128_f32[2];
  v29 = (float)((float)(v47 * v47) + (float)(v45 * v45)) + (float)(v44 * v44);
  axis->mVec128.m128_i32[3] = 0;
  if ( v29 >= 1.4210855e-14 )
  {
    v30 = 1.0 / sqrtf(v29);
    axis->mVec128.m128_f32[0] = v47 * v30;
    axis->mVec128.m128_f32[1] = v45 * v30;
    axis->mVec128.m128_f32[2] = v30 * v44;
  }
  else
  {
    v51 = (unsigned int)clear_value;
    axis->mVec128.m128_u64[0] = (unsigned int)clear_value;
    v52 = 0;
    axis->mVec128.m128_u64[1] = 0;
  }
}
