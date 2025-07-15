vostok::math::float3 *__usercall vostok::math::slerp@<eax>(
        const vostok::math::float3 *current@<ecx>,
        const vostok::math::float3 *target@<eax>,
        vostok::math::float3 *amount,
        const vostok::math::float3 *up_in_case_of_collinear,
        float *p_y)
{
  float y; // xmm6_4
  float v6; // xmm0_4
  float z; // xmm5_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm5_4
  float v11; // xmm7_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm6_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  long double v19; // rdi
  vostok::math::quaternion *v20; // ecx
  const struct vostok::math::float3 *v21; // eax
  const vostok::math::quaternion *v22; // ebx
  vostok::math::quaternion *v23; // eax
  vostok::math::float3 *result; // eax
  long double v25; // [esp+0h] [ebp-5Ch]
  float v26; // [esp+0h] [ebp-5Ch]
  long double v27; // [esp+8h] [ebp-54h] BYREF
  struct vostok::math::float3 v28; // [esp+1Ch] [ebp-40h] BYREF
  vostok::math::quaternion v29; // [esp+2Ch] [ebp-30h] BYREF
  vostok::math::quaternion v30; // [esp+3Ch] [ebp-20h] BYREF
  float v31; // [esp+4Ch] [ebp-10h]
  int v32; // [esp+50h] [ebp-Ch]
  float x; // [esp+54h] [ebp-8h]

  y = target->y;
  v6 = current->y;
  z = current->z;
  v8 = (float)(target->z * v6) - (float)(y * z);
  v9 = target->x * z;
  v10 = current->x * target->z;
  v11 = target->x * v6;
  x = current->x;
  v12 = v9 - v10;
  v13 = (float)(x * y) - v11;
  v14 = fsqrt((float)((float)(v8 * v8) + (float)(v13 * v13)) + (float)(v12 * v12));
  v32 = LODWORD(v14) & 0x7FFFFFFF;
  if ( COERCE_FLOAT(LODWORD(v14) & 0x7FFFFFFF) >= 0.001 )
  {
    v16 = s_bm_current_air_resistance / fsqrt((float)((float)(v8 * v8) + (float)(v13 * v13)) + (float)(v12 * v12));
    v30.y = v16 * v8;
    v30.z = v16 * v12;
    v30.w = v16 * v13;
    p_y = &v30.y;
  }
  v17 = current->z;
  v18 = current->y;
  v29.y = *p_y;
  HIDWORD(v19) = p_y + 1;
  v31 = v17;
  v32 = LODWORD(v18);
  v29.z = *(float *)(_DWORD *)HIDWORD(v19);
  HIDWORD(v19) += 4;
  v29.w = *(float *)(_DWORD *)HIDWORD(v19);
  HIDWORD(v19) += 4;
  LODWORD(v19) = &v30;
  __libm_sse2_atan2(v25, v27);
  v21 = vostok::math::quaternion::quaternion(v20, &v29.y, v19, v14 * *(float *)&up_in_case_of_collinear, &v28, v26);
  *(_QWORD *)&v29.x = __PAIR64__(v32, LODWORD(x));
  *(_QWORD *)&v29.vector.elements[2] = LODWORD(v31);
  *(_QWORD *)&v30.x = __PAIR64__(v32, LODWORD(x));
  *(_QWORD *)&v30.vector.elements[2] = LODWORD(v31);
  v22 = (const vostok::math::quaternion *)v21;
  HIDWORD(v19) = vostok::math::conjugate((const vostok::math::quaternion *)v21, &v29);
  v23 = vostok::math::operator*(&v30, v22, (vostok::math::quaternion *)((char *)&v27 + 4));
  HIDWORD(v19) = vostok::math::operator*((const vostok::math::quaternion *)HIDWORD(v19), v23, &v30);
  result = amount;
  *amount = *(vostok::math::float3 *)HIDWORD(v19);
  return result;
}


vostok::math::quaternion *__cdecl vostok::math::slerp(
        vostok::math::quaternion *result,
        const vostok::math::quaternion *q0,
        const vostok::math::quaternion *q1,
        float t)
{
  slerp_optimized(q0, q1, result, t);
  return result;
}
