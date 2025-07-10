void __thiscall btGeneric6DofConstraint::calculateAngleInfo(btGeneric6DofConstraint *this, btVector3 *thisa)
{
  float v3; // xmm6_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm4_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm5_4
  float v15; // xmm3_4
  float v16; // xmm6_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm7_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm5_4
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm4_4
  float v28; // xmm6_4
  float v29; // xmm7_4
  float v30; // xmm2_4
  float v31; // xmm4_4
  float v32; // xmm5_4
  float v33; // [esp+54h] [ebp-94h]
  float v34; // [esp+58h] [ebp-90h]
  float v35; // [esp+58h] [ebp-90h]
  float v36; // [esp+58h] [ebp-90h]
  float v37; // [esp+5Ch] [ebp-8Ch]
  float v38; // [esp+60h] [ebp-88h]
  float v39; // [esp+60h] [ebp-88h]
  float v40; // [esp+60h] [ebp-88h]
  float v41; // [esp+60h] [ebp-88h]
  float v42; // [esp+64h] [ebp-84h]
  float v43; // [esp+64h] [ebp-84h]
  float v44; // [esp+64h] [ebp-84h]
  float v45; // [esp+68h] [ebp-80h]
  float v46; // [esp+68h] [ebp-80h]
  float v47; // [esp+68h] [ebp-80h]
  float v48; // [esp+6Ch] [ebp-7Ch]
  float v49; // [esp+70h] [ebp-78h]
  float v50; // [esp+74h] [ebp-74h]
  unsigned __int64 v51; // [esp+78h] [ebp-70h]
  unsigned int v52; // [esp+80h] [ebp-68h]
  float v53; // [esp+8Ch] [ebp-5Ch]
  float v54; // [esp+90h] [ebp-58h]
  float v55; // [esp+94h] [ebp-54h]
  float v56; // [esp+98h] [ebp-50h]
  float v57; // [esp+A0h] [ebp-48h]
  float v58; // [esp+A4h] [ebp-44h]
  btMatrix3x3 mat; // [esp+A8h] [ebp-40h] BYREF
  float v60; // [esp+E0h] [ebp-8h]

  v3 = thisa[74].mVec128.m128_f32[1];
  v4 = thisa[75].mVec128.m128_f32[2];
  v5 = thisa[75].mVec128.m128_f32[1];
  v6 = (float)(v3 * v4) - (float)(thisa[74].mVec128.m128_f32[2] * v5);
  v7 = thisa[75].mVec128.m128_f32[0];
  v8 = v7 * v3;
  v9 = (float)(v7 * thisa[74].mVec128.m128_f32[2]) - (float)(thisa[74].mVec128.m128_f32[0] * v4);
  v10 = (float)(thisa[74].mVec128.m128_f32[0] * v5) - v8;
  v11 = *(float *)&clear_value
      / (float)((float)((float)(v10 * thisa[73].mVec128.m128_f32[2]) + (float)(thisa[73].mVec128.m128_f32[1] * v9))
              + (float)(thisa[73].mVec128.m128_f32[0] * v6));
  v12 = thisa[73].mVec128.m128_f32[0];
  v33 = thisa[73].mVec128.m128_f32[1];
  v49 = (float)((float)(v33 * thisa[75].mVec128.m128_f32[0]) - (float)(v12 * thisa[75].mVec128.m128_f32[1])) * v11;
  v50 = v10 * v11;
  v13 = thisa[73].mVec128.m128_f32[2];
  v55 = (float)((float)(v13 * thisa[74].mVec128.m128_f32[0]) - (float)(v12 * thisa[74].mVec128.m128_f32[2])) * v11;
  v56 = (float)((float)(v12 * thisa[75].mVec128.m128_f32[2]) - (float)(v13 * thisa[75].mVec128.m128_f32[0])) * v11;
  v37 = v9 * v11;
  v14 = (float)((float)(v12 * v3) - (float)(v33 * thisa[74].mVec128.m128_f32[0])) * v11;
  v38 = (float)((float)(v13 * thisa[75].mVec128.m128_f32[1]) - (float)(v33 * thisa[75].mVec128.m128_f32[2])) * v11;
  v58 = thisa[78].mVec128.m128_f32[2];
  v15 = v6 * v11;
  v16 = (float)((float)(v33 * thisa[74].mVec128.m128_f32[2]) - (float)(v13 * v3)) * v11;
  v17 = thisa[77].mVec128.m128_f32[2];
  v48 = v15;
  v18 = thisa[79].mVec128.m128_f32[2];
  v19 = thisa[78].mVec128.m128_f32[1];
  v53 = thisa[79].mVec128.m128_f32[1];
  v57 = thisa[77].mVec128.m128_f32[1];
  v20 = thisa[77].mVec128.m128_f32[0];
  v54 = thisa[78].mVec128.m128_f32[0];
  v21 = thisa[79].mVec128.m128_f32[0];
  mat.m_el[1].mVec128.m128_f32[0] = (float)((float)(v20 * v37) + (float)(v54 * v56)) + (float)(v21 * v55);
  mat.m_el[1].mVec128.m128_f32[1] = (float)((float)(v57 * v37) + (float)(v19 * v56)) + (float)(v53 * v55);
  mat.m_el[1].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT((float)((float)(v17 * v37) + (float)(v58 * v56)) + (float)(v18 * v55));
  mat.m_el[2].mVec128.m128_f32[0] = (float)((float)(v20 * v50) + (float)(v54 * v49)) + (float)(v21 * v14);
  mat.m_el[0].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT((float)((float)(v17 * v48) + (float)(v58 * v38)) + (float)(v18 * v16));
  mat.m_el[2].mVec128.m128_f32[1] = (float)((float)(v57 * v50) + (float)(v19 * v49)) + (float)(v53 * v14);
  mat.m_el[0].mVec128.m128_f32[0] = (float)((float)(v20 * v48) + (float)(v54 * v38)) + (float)(v21 * v16);
  mat.m_el[0].mVec128.m128_f32[1] = (float)((float)(v19 * v38) + (float)(v53 * v16)) + (float)(v57 * v48);
  mat.m_el[2].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT((float)((float)(v17 * v50) + (float)(v58 * v49)) + (float)(v18 * v14));
  matrixToEulerXYZ(&mat, thisa + 81);
  v22 = thisa[75].mVec128.m128_f32[2];
  v23 = thisa[78].mVec128.m128_f32[0];
  v24 = thisa[79].mVec128.m128_f32[0];
  v25 = thisa[74].mVec128.m128_f32[2];
  v26 = thisa[77].mVec128.m128_f32[0];
  v27 = thisa[73].mVec128.m128_f32[2];
  *(float *)&v51 = (float)(thisa[74].mVec128.m128_f32[2] * v24) - (float)(thisa[75].mVec128.m128_f32[2] * v23);
  *((float *)&v51 + 1) = (float)(v22 * v26) - (float)(v24 * v27);
  v60 = v22;
  thisa[83].mVec128.m128_u64[0] = v51;
  thisa[83].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT((float)(v23 * v27) - (float)(v25 * v26));
  v28 = thisa[83].mVec128.m128_f32[2];
  v29 = thisa[83].mVec128.m128_f32[0];
  *(float *)&v51 = (float)(v22 * thisa[83].mVec128.m128_f32[1]) - (float)(v25 * v28);
  *(float *)&v52 = (float)(v25 * v29) - (float)(v27 * thisa[83].mVec128.m128_f32[1]);
  *((float *)&v51 + 1) = (float)(v27 * v28) - (float)(v60 * v29);
  thisa[82].mVec128.m128_u64[0] = v51;
  thisa[82].mVec128.m128_u64[1] = v52;
  v30 = thisa[83].mVec128.m128_f32[2];
  v31 = thisa[83].mVec128.m128_f32[1];
  *(float *)&v51 = (float)(v23 * v30) - (float)(v24 * v31);
  v32 = thisa[83].mVec128.m128_f32[0];
  *((float *)&v51 + 1) = (float)(v24 * v32) - (float)(v26 * v30);
  thisa[84].mVec128.m128_u64[0] = v51;
  thisa[84].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT((float)(v26 * v31) - (float)(v23 * v32));
  v42 = thisa[82].mVec128.m128_f32[0];
  v45 = thisa[82].mVec128.m128_f32[1];
  v39 = thisa[82].mVec128.m128_f32[2];
  v34 = 1.0
      / sqrtf(
          (float)((float)(v42 * v42) + (float)(thisa[82].mVec128.m128_f32[1] * thisa[82].mVec128.m128_f32[1]))
        + (float)(v39 * v39));
  thisa[82].mVec128.m128_f32[0] = v34 * v42;
  thisa[82].mVec128.m128_f32[1] = v34 * v45;
  thisa[82].mVec128.m128_f32[2] = v34 * v39;
  v43 = thisa[83].mVec128.m128_f32[0];
  v46 = thisa[83].mVec128.m128_f32[1];
  v40 = thisa[83].mVec128.m128_f32[2];
  v35 = 1.0
      / sqrtf(
          (float)((float)(v43 * v43) + (float)(thisa[83].mVec128.m128_f32[1] * thisa[83].mVec128.m128_f32[1]))
        + (float)(v40 * v40));
  thisa[83].mVec128.m128_f32[0] = v35 * v43;
  thisa[83].mVec128.m128_f32[1] = v35 * v46;
  thisa[83].mVec128.m128_f32[2] = v35 * v40;
  v44 = thisa[84].mVec128.m128_f32[0];
  v47 = thisa[84].mVec128.m128_f32[1];
  v41 = thisa[84].mVec128.m128_f32[2];
  v36 = 1.0
      / sqrtf(
          (float)((float)(v44 * v44) + (float)(thisa[84].mVec128.m128_f32[1] * thisa[84].mVec128.m128_f32[1]))
        + (float)(v41 * v41));
  thisa[84].mVec128.m128_f32[0] = v36 * v44;
  thisa[84].mVec128.m128_f32[1] = v36 * v47;
  thisa[84].mVec128.m128_f32[2] = v36 * v41;
}
