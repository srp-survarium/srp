vostok::math::float4x4 *__fastcall vostok::math::mul4x4(
        const vostok::math::float4x4 *right,
        const vostok::math::float4x4 *left,
        vostok::math::float4x4 *a3)
{
  float x; // xmm6_4
  float v4; // xmm5_4
  float z; // xmm1_4
  float w; // xmm0_4
  vostok::math::float4x4 *result; // eax
  float v8; // xmm4_4
  float y; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm7_4
  float v12; // xmm2_4
  float v13; // xmm7_4
  float v14; // xmm3_4
  float v15; // xmm7_4
  float v16; // xmm3_4
  float v17; // xmm7_4
  float v18; // xmm3_4
  float v19; // xmm7_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm7_4
  float v24; // xmm1_4
  float v25; // xmm5_4
  float v26; // xmm6_4
  float v27; // xmm5_4
  float v28; // xmm0_4
  float v29; // xmm3_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm0_4
  float v33; // xmm2_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm6_4
  float v37; // xmm5_4
  float v38; // xmm0_4
  float v39; // xmm6_4
  float v40; // xmm5_4
  float v41; // xmm6_4
  float v42; // xmm5_4
  float v43; // xmm6_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm3_4
  float v47; // xmm0_4
  float v48; // xmm2_4
  float v49; // xmm5_4
  float v50; // xmm0_4
  float v51; // xmm6_4
  float v52; // xmm5_4
  float v53; // xmm4_4
  float v54; // xmm5_4
  float v55; // xmm4_4
  float v56; // xmm5_4
  float v57; // xmm0_4
  float v58; // xmm1_4
  float v59; // [esp+4h] [ebp+4h]

  x = right->i.x;
  v4 = right->j.x;
  z = left->i.z;
  w = left->i.w;
  result = a3;
  v8 = right->c.x;
  y = right->j.y;
  v10 = right->i.y;
  a3->i.x = (float)((float)((float)(right->i.x * left->i.x) + (float)(v4 * left->i.y)) + (float)(z * right->k.x))
          + (float)(w * v8);
  v11 = v10 * left->i.x;
  v12 = left->i.y;
  v13 = (float)((float)(v11 + (float)(y * v12)) + (float)(right->k.y * z)) + (float)(right->c.y * w);
  v14 = right->i.z;
  a3->i.y = v13;
  v15 = (float)((float)((float)(v14 * left->i.x) + (float)(right->j.z * v12)) + (float)(right->k.z * z))
      + (float)(right->c.z * w);
  v16 = right->i.w;
  a3->i.z = v15;
  v17 = (float)(v16 * left->i.x) + (float)(right->j.w * v12);
  v18 = left->j.y;
  v19 = v17 + (float)(right->k.w * z);
  v20 = left->j.z;
  v21 = right->c.w * w;
  v22 = left->j.x;
  v23 = v19 + v21;
  v24 = left->j.w;
  a3->i.w = v23;
  a3->j.x = (float)((float)((float)(v22 * x) + (float)(v18 * v4)) + (float)(v20 * right->k.x)) + (float)(v24 * v8);
  v25 = right->i.z;
  a3->j.y = (float)((float)((float)(v22 * right->i.y) + (float)(v18 * right->j.y)) + (float)(v20 * right->k.y))
          + (float)(v24 * right->c.y);
  v26 = (float)((float)((float)(v22 * v25) + (float)(v18 * right->j.z)) + (float)(v20 * right->k.z))
      + (float)(v24 * right->c.z);
  v27 = right->i.x;
  v28 = (float)(v22 * right->i.w) + (float)(v18 * right->j.w);
  v29 = right->k.w;
  a3->j.z = v26;
  v30 = v20 * v29;
  v31 = left->k.z;
  v32 = v28 + v30;
  v33 = left->k.w;
  v34 = v32 + (float)(v24 * right->c.w);
  v35 = left->k.x;
  v36 = v35 * v27;
  v37 = right->j.x;
  a3->j.w = v34;
  v38 = left->k.y;
  v39 = (float)((float)(v36 + (float)(v38 * v37)) + (float)(v31 * right->k.x)) + (float)(v33 * v8);
  v40 = right->i.y;
  a3->k.x = v39;
  v41 = v35 * v40;
  v42 = right->i.z;
  a3->k.y = (float)((float)(v41 + (float)(v38 * right->j.y)) + (float)(v31 * right->k.y)) + (float)(v33 * right->c.y);
  v43 = right->i.w;
  a3->k.z = (float)((float)((float)(v35 * v42) + (float)(v38 * right->j.z)) + (float)(v31 * right->k.z))
          + (float)(v33 * right->c.z);
  v44 = left->c.x;
  v59 = v44 * v43;
  v45 = (float)(v38 * right->j.w) + (float)(v31 * right->k.w);
  v46 = left->c.z;
  v47 = v45 + (float)(v33 * right->c.w);
  v48 = left->c.w;
  v49 = right->j.x;
  result->k.w = v47 + (float)(v44 * v43);
  v50 = left->c.y;
  v51 = (float)((float)(v50 * v49) + (float)(v44 * right->i.x)) + (float)(v46 * right->k.x);
  v52 = v48 * v8;
  v53 = right->j.y;
  result->c.x = v51 + v52;
  v54 = v50 * v53;
  v55 = right->j.z;
  result->c.y = (float)((float)(v54 + (float)(v44 * right->i.y)) + (float)(v46 * right->k.y))
              + (float)(v48 * right->c.y);
  v56 = (float)(v50 * v55) + (float)(v44 * right->i.z);
  v57 = v50 * right->j.w;
  v58 = right->k.w;
  result->c.z = (float)(v56 + (float)(v46 * right->k.z)) + (float)(v48 * right->c.z);
  result->c.w = (float)((float)(v57 + (float)(v46 * v58)) + (float)(v48 * right->c.w)) + v59;
  return result;
}
