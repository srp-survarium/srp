vostok::math::float4x4 *__fastcall vostok::math::mul4x3(
        const vostok::math::float4x4 *right,
        const vostok::math::float4x4 *left,
        vostok::math::float4x4 *a3)
{
  vostok::math::float4x4 *result; // eax
  float x; // xmm5_4
  float v5; // xmm2_4
  float v6; // xmm6_4
  float y; // xmm7_4
  float v8; // xmm4_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float z; // xmm0_4
  float v13; // xmm7_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm7_4
  float w; // xmm2_4
  float v19; // xmm7_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm7_4
  float v24; // xmm1_4
  float v25; // xmm7_4
  float v26; // xmm5_4
  float v27; // xmm6_4
  float v28; // xmm5_4
  float v29; // xmm6_4
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm5_4
  float v33; // xmm0_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm6_4
  float v39; // xmm5_4
  float v40; // xmm6_4
  float v41; // xmm5_4
  float v42; // xmm1_4
  float v43; // xmm3_4
  float v44; // xmm0_4
  float v45; // xmm2_4
  float v46; // xmm5_4
  float v47; // xmm0_4
  float v48; // xmm2_4
  float v49; // xmm0_4
  float v50; // xmm6_4
  float v51; // xmm5_4
  float v52; // xmm4_4
  float v53; // xmm5_4
  float v54; // xmm4_4
  float v55; // xmm5_4
  float v56; // xmm0_4

  result = a3;
  x = right->j.x;
  v5 = left->i.x;
  v6 = right->i.x;
  y = left->i.y;
  v8 = right->k.x;
  v9 = right->k.y;
  v10 = right->j.y * y;
  a3->i.x = (float)((float)(right->i.x * left->i.x) + (float)(x * y)) + (float)(left->i.z * v8);
  v11 = (float)(right->i.y * v5) + v10;
  z = right->k.z;
  v13 = right->i.z * v5;
  a3->i.y = v11 + (float)(v9 * left->i.z);
  v14 = left->i.y;
  v15 = z;
  v16 = left->i.z;
  v17 = (float)(v13 + (float)(right->j.z * v14)) + (float)(v15 * v16);
  w = right->i.w;
  a3->i.z = v17;
  v19 = (float)(w * left->i.x) + (float)(right->j.w * v14);
  v20 = left->j.y;
  v21 = right->k.w * v16;
  v22 = left->j.x;
  v23 = v19 + v21;
  v24 = left->j.z;
  a3->i.w = v23;
  v25 = (float)((float)(v22 * v6) + (float)(v20 * x)) + (float)(v24 * v8);
  v26 = right->i.y;
  a3->j.x = v25;
  v27 = (float)((float)(v22 * v26) + (float)(v20 * right->j.y)) + (float)(v24 * v9);
  v28 = right->i.z;
  a3->j.y = v27;
  v29 = (float)(v22 * v28) + (float)(v20 * right->j.z);
  v30 = v22 * right->i.w;
  v31 = v20 * right->j.w;
  v32 = right->i.x;
  a3->j.z = v29 + (float)(v24 * right->k.z);
  v33 = v30 + v31;
  v34 = left->k.z;
  v35 = v33 + (float)(v24 * right->k.w);
  v36 = left->k.x;
  a3->j.w = v35;
  v37 = left->k.y;
  v38 = (float)((float)(v36 * v32) + (float)(v37 * right->j.x)) + (float)(v34 * v8);
  v39 = right->i.y;
  a3->k.x = v38;
  v40 = (float)((float)(v36 * v39) + (float)(v37 * right->j.y)) + (float)(v34 * v9);
  v41 = right->i.w;
  a3->k.z = (float)((float)(v36 * right->i.z) + (float)(v37 * right->j.z)) + (float)(v34 * right->k.z);
  v42 = left->c.x;
  v43 = v42 * v41;
  v44 = v37 * right->j.w;
  v45 = v34 * right->k.w;
  v46 = right->i.x;
  a3->k.y = v40;
  v47 = v44 + v45;
  v48 = left->c.z;
  a3->k.w = v47 + v43;
  v49 = left->c.y;
  v50 = (float)(v42 * v46) + (float)(v49 * right->j.x);
  v51 = v48 * v8;
  v52 = right->j.y;
  a3->c.x = (float)(v50 + v51) + right->c.x;
  v53 = (float)(v49 * v52) + (float)(v42 * right->i.y);
  v54 = right->j.z;
  a3->c.y = (float)(v53 + (float)(v48 * right->k.y)) + right->c.y;
  v55 = (float)(v49 * v54) + (float)(v42 * right->i.z);
  v56 = (float)((float)((float)(v49 * right->j.w) + (float)(v48 * right->k.w)) + right->c.w) + v43;
  a3->c.z = (float)(v55 + (float)(v48 * right->k.z)) + right->c.z;
  a3->c.w = v56;
  return result;
}
