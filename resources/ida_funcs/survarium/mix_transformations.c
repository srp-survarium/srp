vostok::math::float4x4 *__usercall survarium::mix_transformations@<eax>(
        const vostok::math::float4x4 *first@<ecx>,
        const vostok::math::float4x4 *second@<eax>,
        int coeff,
        float coeffa)
{
  survarium::mix_transformations(first, second, coeff, coeffa, coeffa);
  return (vostok::math::float4x4 *)coeff;
}


vostok::math::float4x4 *__usercall survarium::mix_transformations@<eax>(
        const vostok::math::float4x4 *first@<ecx>,
        const vostok::math::float4x4 *second@<eax>,
        int a3@<edi>,
        float a4@<xmm1>,
        float orientation_coeff)
{
  unsigned int v7; // xmm2_4
  unsigned int v8; // xmm3_4
  const vostok::math::quaternion *v9; // eax
  const vostok::math::quaternion *v10; // ebx
  const vostok::math::quaternion *v11; // eax
  vostok::math::float3 position; // [esp+10h] [ebp-3Ch] BYREF
  vostok::math::quaternion q; // [esp+1Ch] [ebp-30h] BYREF
  vostok::math::quaternion v15; // [esp+2Ch] [ebp-20h] BYREF
  vostok::math::quaternion v16; // [esp+3Ch] [ebp-10h] BYREF

  *(float *)&v7 = (float)(first->c.y * (float)(*(float *)&clear_value - a4)) + (float)(second->c.y * a4);
  *(float *)&v8 = (float)(first->c.z * (float)(*(float *)&clear_value - a4)) + (float)(second->c.z * a4);
  position.x = (float)(first->c.x * (float)(*(float *)&clear_value - a4)) + (float)(a4 * second->c.x);
  *(_QWORD *)&position.elements[1] = __PAIR64__(v8, v7);
  vostok::math::quaternion::quaternion(&v15, second);
  v10 = v9;
  vostok::math::quaternion::quaternion(&v16, first);
  slerp_optimized(v11, v10, orientation_coeff);
  vostok::math::create_matrix(&q, &position);
  return (vostok::math::float4x4 *)a3;
}
