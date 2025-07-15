vostok::math::float4x4 *__fastcall vostok::math::mul4x4(
        const vostok::math::float4x4 *right,
        const vostok::math::float4x4 *left,
        vostok::math::float4x4 *a3)
{
  float x; // xmm5_4
  float v4; // xmm6_4
  vostok::math::float4x4 *result; // eax
  float v6; // xmm4_4
  float v7; // xmm7_4
  float y; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float z; // xmm1_4
  float v13; // xmm7_4
  float v14; // xmm2_4
  float w; // xmm0_4
  float v16; // xmm7_4
  float v17; // xmm2_4
  float v18; // xmm7_4
  float v19; // xmm2_4
  float v20; // xmm7_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm7_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm7_4
  float v28; // xmm1_4
  float v29; // xmm7_4
  float v30; // xmm5_4
  float v31; // xmm6_4
  float v32; // xmm5_4
  float v33; // xmm6_4
  float v34; // xmm5_4
  float v35; // xmm0_4
  float v36; // xmm3_4
  float v37; // xmm2_4
  float v38; // xmm3_4
  float v39; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm0_4
  float v44; // xmm6_4
  float v45; // xmm5_4
  float v46; // xmm4_4
  float v47; // xmm5_4
  float v48; // xmm4_4
  float v49; // xmm5_4
  float v50; // xmm1_4
  float v51; // xmm4_4
  float v52; // xmm5_4
  float v53; // xmm0_4
  float v54; // xmm3_4
  float v55; // xmm0_4
  float v56; // xmm2_4
  float v57; // xmm0_4
  float v58; // xmm6_4
  float v59; // xmm5_4
  float v60; // xmm6_4
  float v61; // xmm5_4
  float v62; // xmm6_4
  float v63; // xmm0_4
  float v64; // xmm1_4

  x = right->j.x;
  v4 = right->i.x;
  result = a3;
  v6 = right->c.x;
  v7 = right->i.y * left->i.x;
  y = right->k.y;
  v9 = right->c.y;
  a3->i.x = (float)((float)((float)(right->i.x * left->i.x) + (float)(x * left->i.y)) + (float)(left->i.z * right->k.x))
          + (float)(left->i.w * v6);
  v10 = left->i.y;
  v11 = y;
  z = left->i.z;
  v13 = (float)(v7 + (float)(right->j.y * v10)) + (float)(v11 * z);
  v14 = v9;
  w = left->i.w;
  v16 = v13 + (float)(v14 * w);
  v17 = right->i.z;
  a3->i.y = v16;
  v18 = (float)((float)((float)(v17 * left->i.x) + (float)(right->j.z * v10)) + (float)(right->k.z * z))
      + (float)(right->c.z * w);
  v19 = right->i.w;
  a3->i.z = v18;
  v20 = v19 * left->i.x;
  v21 = right->j.w * v10;
  v22 = left->j.y;
  v23 = (float)(v20 + v21) + (float)(right->k.w * z);
  v24 = left->j.z;
  v25 = right->c.w * w;
  v26 = left->j.x;
  v27 = v23 + v25;
  v28 = left->j.w;
  a3->i.w = v27;
  v29 = (float)((float)((float)(v26 * v4) + (float)(v22 * x)) + (float)(v24 * right->k.x)) + (float)(v28 * v6);
  v30 = right->i.y;
  a3->j.x = v29;
  v31 = v26 * v30;
  v32 = right->i.z;
  a3->j.y = (float)((float)(v31 + (float)(v22 * right->j.y)) + (float)(v24 * right->k.y)) + (float)(v28 * right->c.y);
  v33 = (float)((float)(v26 * v32) + (float)(v22 * right->j.z)) + (float)(v24 * right->k.z);
  v34 = right->i.x;
  v35 = (float)(v26 * right->i.w) + (float)(v22 * right->j.w);
  v36 = right->k.w;
  a3->j.z = v33 + (float)(v28 * right->c.z);
  v37 = v24 * v36;
  v38 = left->k.z;
  v39 = v35 + v37;
  v40 = left->k.w;
  v41 = v39 + (float)(v28 * right->c.w);
  v42 = left->k.x;
  a3->j.w = v41;
  v43 = left->k.y;
  v44 = (float)((float)(v42 * v34) + (float)(v43 * right->j.x)) + (float)(v38 * right->k.x);
  v45 = v40 * v6;
  v46 = right->i.y;
  a3->k.x = v44 + v45;
  v47 = v42 * v46;
  v48 = right->i.z;
  a3->k.y = (float)((float)(v47 + (float)(v43 * right->j.y)) + (float)(v38 * right->k.y)) + (float)(v40 * right->c.y);
  v49 = right->i.w;
  a3->k.z = (float)((float)((float)(v42 * v48) + (float)(v43 * right->j.z)) + (float)(v38 * right->k.z))
          + (float)(v40 * right->c.z);
  v50 = left->c.x;
  v51 = v50 * v49;
  v52 = right->j.x;
  v53 = (float)(v43 * right->j.w) + (float)(v38 * right->k.w);
  v54 = left->c.z;
  v55 = v53 + (float)(v40 * right->c.w);
  v56 = left->c.w;
  a3->k.w = v55 + v51;
  v57 = left->c.y;
  v58 = v57 * v52;
  v59 = right->j.y;
  a3->c.x = (float)((float)(v58 + (float)(v50 * right->i.x)) + (float)(v54 * right->k.x)) + (float)(v56 * right->c.x);
  v60 = v57 * v59;
  v61 = right->j.z;
  a3->c.y = (float)((float)(v60 + (float)(v50 * right->i.y)) + (float)(v54 * right->k.y)) + (float)(v56 * right->c.y);
  v62 = (float)(v57 * v61) + (float)(v50 * right->i.z);
  v63 = v57 * right->j.w;
  v64 = right->k.w;
  a3->c.z = (float)(v62 + (float)(v54 * right->k.z)) + (float)(v56 * right->c.z);
  a3->c.w = (float)((float)(v63 + (float)(v54 * v64)) + (float)(v56 * right->c.w)) + v51;
  return result;
}
