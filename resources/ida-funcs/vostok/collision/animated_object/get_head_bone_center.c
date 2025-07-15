vostok::math::float3 *__usercall vostok::collision::animated_object::get_head_bone_center@<eax>(
        vostok::collision::animated_object *this@<ecx>,
        int a2@<eax>,
        int a3@<esi>)
{
  int v3; // ecx
  int v4; // eax
  __int64 v5; // xmm0_8
  float z; // eax
  vostok::math::float4x4 v8; // [esp+8h] [ebp-40h] BYREF

  if ( *(_DWORD *)(a2 + 32) )
  {
    v3 = *(_DWORD *)(112 * *(_DWORD *)(a2 + 40) + *(_DWORD *)a2 + 108);
    v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 8))(v3);
    v5 = *(_QWORD *)(v4 + 48);
    z = *(float *)(v4 + 56);
    *(_QWORD *)a3 = v5;
  }
  else
  {
    vostok::physics::from_bullet(
      (const btTransform *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 36) + 16) + 24) + 80 * *(_DWORD *)(a2 + 40)),
      *(btMatrix3x3 **)(a2 + 36),
      &v8);
    z = v8.c.z;
    *(_QWORD *)a3 = *(_QWORD *)&v8.lines[3].x;
  }
  *(float *)(a3 + 8) = z;
  return (vostok::math::float3 *)a3;
}
