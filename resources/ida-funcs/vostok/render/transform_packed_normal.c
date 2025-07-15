// local variable allocation has failed, the output may be wrong!
vostok::math::color *__usercall vostok::render::transform_packed_normal@<eax>(
        const vostok::math::float4x4 *transform_matrix@<eax>,
        const vostok::math::color *packed_normal@<ecx>,
        int *a3@<edi>)
{
  float x; // xmm4_4
  float b; // xmm0_4
  int g; // edx
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float y; // xmm4_4
  vostok::render::base_basis *basis; // [esp+0h] [ebp-10h] OVERLAPPED BYREF
  vostok::math::float3 v13; // [esp+4h] [ebp-Ch]

  x = transform_matrix->j.x;
  b = (float)packed_normal->b;
  g = packed_normal->g;
  basis = (vostok::render::base_basis *)packed_normal->r;
  v13.z = (double)(int)basis * 0.0039215689;
  v6 = (float)((float)((float)g * 0.0039215689) * 2.0) - *(float *)&clear_value;
  v7 = (float)((float)(b * 0.0039215689) * 2.0) - *(float *)&clear_value;
  v8 = (float)(v13.z * 2.0) - *(float *)&clear_value;
  v9 = (float)((float)(transform_matrix->k.x * v8) + (float)(x * v6)) + (float)(transform_matrix->i.x * v7);
  y = transform_matrix->j.y;
  v13.x = v9;
  v13.y = (float)((float)(transform_matrix->k.y * v8) + (float)(y * v6)) + (float)(transform_matrix->i.y * v7);
  v13.z = (float)((float)(transform_matrix->k.z * v8) + (float)(transform_matrix->j.z * v6))
        + (float)(transform_matrix->i.z * v7);
  vostok::render::base_basis::set(basis, &basis, v13);
  *a3 = BYTE2(basis) | ((BYTE1(basis) | (((unsigned __int8)basis | 0x7F00) << 8)) << 8);
  return (vostok::math::color *)a3;
}
