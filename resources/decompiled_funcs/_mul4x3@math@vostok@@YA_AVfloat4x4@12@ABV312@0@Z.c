vostok::math::float4x4 *__cdecl vostok::math::mul4x3(
        vostok::math::float4x4 *result,
        const vostok::math::float4x4 *left,
        const vostok::math::float4x4 *right)
{
  float y; // xmm1_4
  float x; // xmm5_4
  float z; // xmm0_4
  float v7; // xmm4_4
  vostok::math::float4x4 *v8; // eax
  float v9; // xmm3_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm2_4
  float v13; // xmm7_4
  float w; // xmm2_4
  float v15; // xmm7_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm7_4
  float v20; // xmm1_4
  float v21; // xmm7_4
  float v22; // xmm5_4
  float v23; // xmm7_4
  float v24; // xmm5_4
  float v25; // xmm6_4
  float v26; // xmm0_4
  float v27; // xmm5_4
  float v28; // xmm2_4
  float v29; // xmm5_4
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm6_4
  float v36; // xmm5_4
  float v37; // xmm6_4
  float v38; // xmm5_4
  float v39; // xmm7_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // xmm2_4
  float v43; // xmm0_4
  float v44; // xmm2_4
  float v45; // xmm6_4
  float v46; // xmm0_4
  float v47; // xmm7_4
  float v48; // xmm4_4
  float v49; // xmm6_4
  float v50; // xmm3_4
  float v51; // xmm4_4
  float v52; // xmm0_4
  float righta; // [esp+Ch] [ebp+Ch]

  y = left->i.y;
  x = right->i.x;
  z = left->i.z;
  v7 = right->j.x;
  v8 = result;
  v9 = right->k.x;
  v10 = right->i.y * left->i.x;
  result->i.x = (float)((float)(right->i.x * left->i.x) + (float)(v7 * y)) + (float)(z * v9);
  v11 = right->j.y;
  v12 = right->i.z;
  result->i.y = (float)(v10 + (float)(v11 * y)) + (float)(right->k.y * z);
  v13 = (float)((float)(v12 * left->i.x) + (float)(right->j.z * y)) + (float)(right->k.z * z);
  w = right->i.w;
  result->i.z = v13;
  v15 = (float)(w * left->i.x) + (float)(right->j.w * y);
  v16 = left->j.y;
  v17 = right->k.w * z;
  v18 = left->j.x;
  v19 = v15 + v17;
  v20 = left->j.z;
  result->i.w = v19;
  v21 = (float)((float)(v18 * x) + (float)(v16 * v7)) + (float)(v20 * v9);
  v22 = right->i.y;
  result->j.x = v21;
  v23 = (float)(v18 * v22) + (float)(v16 * v11);
  v24 = right->i.z;
  result->j.y = v23 + (float)(v20 * right->k.y);
  v25 = (float)(v18 * v24) + (float)(v16 * right->j.z);
  v26 = v18 * right->i.w;
  v27 = right->j.w;
  result->j.z = v25 + (float)(v20 * right->k.z);
  v28 = v16 * v27;
  v29 = right->i.x;
  v30 = v26 + v28;
  v31 = left->k.z;
  v32 = v30 + (float)(v20 * right->k.w);
  v33 = left->k.x;
  result->j.w = v32;
  v34 = left->k.y;
  v35 = (float)((float)(v33 * v29) + (float)(v34 * v7)) + (float)(v31 * v9);
  v36 = right->i.y;
  result->k.x = v35;
  v37 = v33 * v36;
  v38 = right->k.y;
  result->k.y = (float)(v37 + (float)(v34 * right->j.y)) + (float)(v31 * v38);
  v39 = right->i.w;
  result->k.z = (float)((float)(v33 * right->i.z) + (float)(v34 * right->j.z)) + (float)(v31 * right->k.z);
  v40 = left->c.x;
  v41 = v34 * right->j.w;
  v42 = v31 * right->k.w;
  righta = v40 * v39;
  v43 = v41 + v42;
  v44 = left->c.z;
  v45 = right->i.x;
  result->k.w = v43 + (float)(v40 * v39);
  v46 = left->c.y;
  v47 = (float)((float)((float)(v40 * v45) + (float)(v46 * v7)) + (float)(v44 * v9)) + right->c.x;
  v48 = v46 * right->j.y;
  v49 = v40 * right->i.y;
  result->c.x = v47;
  v50 = right->j.z;
  result->c.y = (float)((float)(v48 + v49) + (float)(v44 * v38)) + right->c.y;
  v51 = (float)(v46 * v50) + (float)(v40 * right->i.z);
  v52 = (float)((float)((float)(v46 * right->j.w) + (float)(v44 * right->k.w)) + right->c.w) + righta;
  result->c.z = (float)(v51 + (float)(v44 * right->k.z)) + right->c.z;
  result->c.w = v52;
  return v8;
}
