vostok::math::float4x4 *__cdecl vostok::math::lerp(
        vostok::math::float4x4 *result,
        const vostok::math::float4x4 *left,
        const vostok::math::float4x4 *right,
        float amount)
{
  vostok::math::float4x4 *v4; // ecx
  vostok::math::float3 *angles_xyz; // eax
  __int64 v7; // xmm0_8
  float z; // eax
  vostok::math::float4x4 *v9; // ecx
  vostok::math::float3 *v10; // eax
  float v11; // edx
  float v12; // xmm4_4
  float v13; // xmm5_4
  vostok::math::quaternion v15; // [esp-8h] [ebp-50h] BYREF
  vostok::math::quaternion right_rotation; // [esp+14h] [ebp-34h] BYREF
  vostok::math::quaternion left_rotation; // [esp+24h] [ebp-24h] BYREF
  vostok::math::quaternion q; // [esp+34h] [ebp-14h] BYREF

  angles_xyz = vostok::math::float4x4::get_angles_xyz(v4, &right_rotation.x, &left->i.x);
  v7 = *(_QWORD *)&angles_xyz->x;
  z = angles_xyz->z;
  *(_QWORD *)&v15.x = v7;
  v15.z = z;
  vostok::math::quaternion::quaternion(&v15, &left_rotation.x, *(vostok::math::float3 *)&v15.x);
  v10 = vostok::math::float4x4::get_angles_xyz(v9, &right_rotation.x, &right->i.x);
  v11 = v10->z;
  *(_QWORD *)&v15.x = *(_QWORD *)&v10->x;
  v15.z = v11;
  vostok::math::quaternion::quaternion(&v15, &right_rotation.x, *(vostok::math::float3 *)&v15.x);
  slerp_optimized(&left_rotation, &right_rotation, amount);
  memset(&right_rotation, 0, 12);
  vostok::math::create_matrix(&q, (const vostok::math::float3 *)&right_rotation, result);
  v12 = left->c.y + (float)((float)(right->c.y - left->c.y) * amount);
  v13 = left->c.z + (float)((float)(right->c.z - left->c.z) * amount);
  right_rotation.x = left->c.x + (float)((float)(right->c.x - left->c.x) * amount);
  right_rotation.y = v12;
  *(_QWORD *)&result->lines[3].x = *(_QWORD *)&right_rotation.x;
  result->c.z = v13;
  return result;
}
