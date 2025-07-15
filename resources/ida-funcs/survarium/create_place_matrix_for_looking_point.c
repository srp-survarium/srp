vostok::math::float4x4 *__usercall survarium::create_place_matrix_for_looking_point@<eax>(
        const vostok::math::float3 *hit_point@<ecx>,
        const vostok::math::float4x4 *head_transform@<eax>,
        vostok::math::float4x4 *normal,
        float *a4)
{
  float z; // xmm2_4
  float y; // xmm5_4
  float v8; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm3_4
  vostok::math::float4x4 *result; // eax
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm1_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm4_4
  float v23; // xmm4_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float *v26; // esi
  float v27; // xmm5_4
  float v28; // xmm6_4
  float v29; // xmm3_4
  float v30; // xmm4_4
  float v31; // xmm7_4
  float v32; // xmm1_4
  float v33; // xmm5_4
  float v34; // xmm3_4
  float v35; // xmm6_4
  float v36; // xmm1_4
  float v37; // xmm4_4
  float v38; // xmm6_4
  float v39; // xmm0_4
  float v40; // xmm1_4
  float v41; // xmm2_4
  float *v42; // esi
  float v43; // [esp+10h] [ebp-18h] BYREF
  __int64 v44; // [esp+14h] [ebp-14h]
  float v45; // [esp+1Ch] [ebp-Ch] BYREF
  __int64 v46; // [esp+20h] [ebp-8h]

  vostok::math::create_translation(hit_point, normal);
  z = head_transform->k.z;
  y = head_transform->k.y;
  v8 = (float)(a4[1] * z) - (float)(a4[2] * y);
  v9 = *a4;
  v10 = (float)(head_transform->k.x * a4[2]) - (float)(*a4 * z);
  v11 = (float)(*a4 * y) - (float)(head_transform->k.x * a4[1]);
  if ( fsqrt((float)((float)(v11 * v11) + (float)(v8 * v8)) + (float)(v10 * v10)) <= 0.001 )
  {
    v27 = head_transform->i.y;
    v28 = head_transform->i.z;
    v29 = (float)(a4[2] * v27) - (float)(a4[1] * v28);
    v30 = (float)(v9 * v28) - (float)(a4[2] * head_transform->i.x);
    v31 = (float)(a4[1] * head_transform->i.x) - (float)(v9 * v27);
    v32 = s_bm_current_air_resistance / fsqrt((float)((float)(v31 * v31) + (float)(v30 * v30)) + (float)(v29 * v29));
    v33 = v32 * v29;
    v34 = a4[1];
    v35 = v32 * v30;
    *((float *)&v46 + 1) = v32 * v31;
    v36 = a4[2];
    *(float *)&v46 = v35;
    result = normal;
    v37 = (float)(*((float *)&v46 + 1) * v34) - (float)(v35 * v36);
    v38 = v9 * *((float *)&v46 + 1);
    v39 = (float)(v9 * *(float *)&v46) - (float)(v34 * v33);
    v45 = v33;
    v40 = (float)(v36 * v33) - v38;
    v41 = s_bm_current_air_resistance / fsqrt((float)((float)(v39 * v39) + (float)(v40 * v40)) + (float)(v37 * v37));
    v43 = v41 * v37;
    *(float *)&v44 = v41 * v40;
    *((float *)&v44 + 1) = v41 * v39;
    normal->i.x = v41 * v37;
    *(_QWORD *)&normal->e01 = v44;
    *(_QWORD *)&normal->lines[1].x = *(_QWORD *)a4;
    normal->j.z = a4[2];
    v26 = &v45;
  }
  else
  {
    v12 = s_bm_current_air_resistance;
    result = normal;
    v14 = s_bm_current_air_resistance / fsqrt((float)((float)(v11 * v11) + (float)(v8 * v8)) + (float)(v10 * v10));
    v15 = v14 * v8;
    v16 = a4[1];
    v17 = v14 * v10;
    v18 = a4[2];
    *((float *)&v46 + 1) = v14 * v11;
    *(float *)&v46 = v17;
    v19 = (float)(v17 * v18) - (float)((float)(v14 * v11) * v16);
    v45 = v15;
    v20 = v15 * v18;
    v21 = a4[1];
    v22 = v9 * *((float *)&v46 + 1);
    normal->i.x = v15;
    *(_QWORD *)&normal->e01 = v46;
    v23 = v22 - v20;
    v24 = (float)(v15 * v21) - (float)(v9 * v17);
    normal->j.x = *a4;
    v25 = v12 / fsqrt((float)((float)(v24 * v24) + (float)(v23 * v23)) + (float)(v19 * v19));
    normal->j.y = a4[1];
    v43 = v25 * v19;
    normal->j.z = a4[2];
    *(float *)&v44 = v25 * v23;
    *((float *)&v44 + 1) = v25 * v24;
    v26 = &v43;
  }
  result->k.x = *v26;
  v42 = v26 + 1;
  result->k.y = *v42;
  result->k.z = v42[1];
  return result;
}
