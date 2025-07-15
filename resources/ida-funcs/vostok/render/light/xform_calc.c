void __userpurge vostok::render::light::xform_calc(vostok::render::light *this@<ecx>, long double a2@<esi:edi>, int a3)
{
  float v3; // xmm4_4
  float v4; // xmm0_4
  float v5; // xmm7_4
  float v6; // xmm1_4
  float v7; // xmm4_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  double v20; // xmm0_8
  vostok::math::float4x4 *scale; // eax
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm1_4
  vostok::math::float4x4 *v26; // ecx
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  vostok::math::float3 v34; // [esp+Ch] [ebp-138h] BYREF
  __int64 v35; // [esp+18h] [ebp-12Ch]
  float v36; // [esp+20h] [ebp-124h]
  __int64 v37; // [esp+24h] [ebp-120h]
  float v38; // [esp+2Ch] [ebp-118h]
  float v39; // [esp+30h] [ebp-114h]
  float v40; // [esp+34h] [ebp-110h]
  float v41; // [esp+38h] [ebp-10Ch]
  float v42; // [esp+3Ch] [ebp-108h]
  float v43; // [esp+40h] [ebp-104h]
  vostok::math::float4x4 v44; // [esp+44h] [ebp-100h] BYREF
  vostok::math::float4x4 v45; // [esp+84h] [ebp-C0h] BYREF
  vostok::math::float4x4 v46; // [esp+C4h] [ebp-80h] BYREF
  char v47[64]; // [esp+104h] [ebp-40h] BYREF

  v41 = *(float *)(a3 + 548);
  v42 = *(float *)(a3 + 552);
  v43 = *(float *)(a3 + 556);
  if ( (float)((float)((float)(*(float *)(a3 + 580) * *(float *)(a3 + 580))
                     + (float)(*(float *)(a3 + 576) * *(float *)(a3 + 576)))
             + (float)(*(float *)(a3 + 584) * *(float *)(a3 + 584))) <= 0.0000099999997 )
  {
    v4 = s_bm_current_air_resistance;
    v39 = v43 * 0.0;
    v9 = s_bm_current_air_resistance;
    v10 = 0.0;
    *((float *)&v37 + 1) = s_bm_current_air_resistance;
    v38 = 0.0;
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(v41 * 0.0) + v42) + (float)(v43 * 0.0)) & _mask__AbsFloat_) > 0.99000001 )
    {
      v9 = 0.0;
      v10 = s_bm_current_air_resistance;
      HIDWORD(v37) = 0;
      v38 = s_bm_current_air_resistance;
    }
    v11 = (float)(v9 * v43) - (float)(v10 * v42);
    v34.z = (float)(v42 * 0.0) - (float)(v9 * v41);
    v12 = s_bm_current_air_resistance
        / fsqrt(
            (float)((float)(v11 * v11) + (float)(v34.z * v34.z))
          + (float)((float)((float)(v10 * v41) - v39) * (float)((float)(v10 * v41) - v39)));
    *(float *)&v35 = v12 * v11;
    v36 = v34.z * v12;
    *((float *)&v35 + 1) = (float)((float)(v10 * v41) - v39) * v12;
    v34.z = (float)(*((float *)&v35 + 1) * v41) - (float)(v42 * (float)(v12 * v11));
    v34.x = (float)(v42 * v36) - (float)(v43 * *((float *)&v35 + 1));
    v34.y = (float)(v43 * (float)(v12 * v11)) - (float)(v36 * v41);
    v13 = s_bm_current_air_resistance
        / fsqrt(
            (float)((float)(v34.x * v34.x)
                  + (float)((float)((float)(*((float *)&v35 + 1) * v41) - (float)(v42 * *(float *)&v35))
                          * (float)((float)(*((float *)&v35 + 1) * v41) - (float)(v42 * *(float *)&v35))))
          + (float)(v34.y * v34.y));
    *(float *)&v37 = v13 * v34.x;
    *((float *)&v37 + 1) = v34.y * v13;
    v38 = v34.z * v13;
  }
  else
  {
    v35 = *(_QWORD *)(a3 + 576);
    v36 = *(float *)(a3 + 584);
    v3 = fsqrt(
           (float)((float)(v36 * v36) + (float)(*((float *)&v35 + 1) * *((float *)&v35 + 1)))
         + (float)(*(float *)&v35 * *(float *)&v35));
    v4 = s_bm_current_air_resistance;
    v5 = (float)(s_bm_current_air_resistance / v3) * *(float *)&v35;
    v36 = v36 * (float)(s_bm_current_air_resistance / v3);
    *((float *)&v35 + 1) = *((float *)&v35 + 1) * (float)(s_bm_current_air_resistance / v3);
    v6 = (float)(v42 * v36) - (float)(v43 * *((float *)&v35 + 1));
    v34.z = (float)(*((float *)&v35 + 1) * v41) - (float)(v42 * v5);
    v7 = s_bm_current_air_resistance
       / fsqrt(
           (float)((float)(v6 * v6) + (float)(v34.z * v34.z))
         + (float)((float)((float)(v43 * v5) - (float)(v36 * v41)) * (float)((float)(v43 * v5) - (float)(v36 * v41))));
    v38 = v34.z * v7;
    *((float *)&v37 + 1) = (float)((float)(v43 * v5) - (float)(v36 * v41)) * v7;
    *(float *)&v37 = v7 * v6;
    v34.x = (float)(*((float *)&v37 + 1) * v43) - (float)((float)(v34.z * v7) * v42);
    v34.y = (float)((float)(v34.z * v7) * v41) - (float)(v43 * (float)(v7 * v6));
    v34.z = (float)(v42 * (float)(v7 * v6)) - (float)(*((float *)&v37 + 1) * v41);
    v8 = s_bm_current_air_resistance
       / fsqrt((float)((float)(v34.x * v34.x) + (float)(v34.z * v34.z)) + (float)(v34.y * v34.y));
    *(float *)&v35 = v8 * v34.x;
    *((float *)&v35 + 1) = v34.y * v8;
    v36 = v34.z * v8;
  }
  *(_QWORD *)&v44.i.x = v35;
  *(_QWORD *)&v44.lines[0].elements[2] = LODWORD(v36);
  *(_QWORD *)&v44.lines[1].x = v37;
  *(_QWORD *)&v44.lines[1].elements[2] = LODWORD(v38);
  v14 = *(_DWORD *)(a3 + 860);
  *(_QWORD *)&v44.lines[2].x = *(_QWORD *)(a3 + 548);
  *(_QWORD *)&v44.lines[2].elements[2] = *(unsigned int *)(a3 + 556);
  *(_QWORD *)&v44.lines[3].x = *(_QWORD *)(a3 + 532);
  v15 = v14 & 0xF;
  v44.c.z = *(float *)(a3 + 540);
  v44.c.w = v4;
  if ( !v15 )
  {
    v27 = *(float *)(a3 + 608);
    goto LABEL_20;
  }
  v16 = v15 - 1;
  if ( !v16 )
  {
    v40 = *(float *)(a3 + 608);
    v33 = *(float *)(a3 + 572);
    __libm_sse2_tan(a2);
    v32 = v40;
    v34.x = (float)(v33 * 0.5) * v40;
    v34.y = v34.x;
    goto LABEL_17;
  }
  v17 = v16 - 1;
  if ( !v17 )
  {
    v31 = *(float *)(a3 + 608);
    v34.x = v31 + *(float *)(a3 + 592);
    v34.y = *(float *)(a3 + 596) + v31;
    v32 = *(float *)(a3 + 600) + v31;
LABEL_17:
    v34.z = v32;
LABEL_22:
    vostok::math::create_scale(&v34, &v46);
    vostok::math::mul4x3(&v44, &v46, &v45);
    goto LABEL_23;
  }
  v18 = v17 - 1;
  if ( !v18 )
  {
    v28 = *(float *)(a3 + 600);
    v29 = *(float *)(a3 + 608);
    v34.x = v29 + *(float *)(a3 + 592);
    v34.y = v34.x;
    v30 = v29 + v28;
LABEL_21:
    v34.z = v30;
    goto LABEL_22;
  }
  v19 = v18 - 2;
  if ( !v19 )
  {
    v27 = *(float *)(a3 + 608) + *(float *)(a3 + 592);
LABEL_20:
    v30 = v27 * 1.05;
    v34.x = v30;
    v34.y = v30;
    goto LABEL_21;
  }
  if ( v19 != 1 )
  {
    vostok::math::float4x4::identity((vostok::math::float4x4 *)this, (vostok::math::float4x4 *)(a3 + 388));
    return;
  }
  v40 = *(float *)(a3 + 608);
  v20 = (float)(*(float *)(a3 + 572) * 0.5);
  __libm_sse2_tan(a2);
  *(float *)&v20 = v20;
  v39 = *(float *)&v20 * v40;
  scale = vostok::math::create_scale((const vostok::math::float3 *)(a3 + 592), (vostok::math::float4x4 *)v47);
  vostok::math::mul4x3(&v44, scale, &v45);
  v34.x = *(float *)(a3 + 592) + (float)(*(float *)&v20 * v40);
  v34.y = v40 * 0.5;
  *(float *)&v20 = *(float *)(a3 + 600) + (float)(*(float *)&v20 * v40);
  qmemcpy((void *)(a3 + 452), &v45, 0x40u);
  v34.z = *(float *)&v20;
  vostok::math::create_scale(&v34, &v45);
  *(_QWORD *)&v44.i.x = v35;
  *(_QWORD *)&v44.lines[0].elements[2] = LODWORD(v36);
  v22 = *(float *)(a3 + 608);
  *(_QWORD *)&v44.lines[1].x = v37;
  *(_QWORD *)&v44.lines[1].elements[2] = LODWORD(v38);
  *(_QWORD *)&v44.lines[2].x = *(_QWORD *)(a3 + 548);
  *(_QWORD *)&v44.lines[2].elements[2] = *(unsigned int *)(a3 + 556);
  memset(&v44.lines[3], 0, 12);
  v44.c.w = s_bm_current_air_resistance;
  v23 = (float)(*((float *)&v37 + 1) * v22) * 0.5;
  v24 = (float)(v38 * v22) * 0.5;
  v25 = *(float *)(a3 + 532) - (float)((float)(v22 * *(float *)&v37) * 0.5);
  v34.y = *(float *)(a3 + 536) - v23;
  *(float *)&v20 = *(float *)(a3 + 540) - v24;
  v34.x = v25;
  v34.z = *(float *)&v20;
  vostok::math::mul4x3(&v44, &v45, &v46);
  v26 = vostok::math::create_translation(&v34, &v44);
  vostok::math::mul4x3(v26, &v46, &v45);
LABEL_23:
  qmemcpy((void *)(a3 + 388), &v45, 0x40u);
}
