vostok::math::float3 *__userpurge vostok::collision::animated_object::get_eyes_direction@<eax>(
        vostok::collision::animated_object *this@<ecx>,
        int a2@<eax>,
        vostok::math::float3 *result)
{
  int v4; // ecx
  int v5; // eax
  int v6; // ecx
  float *v7; // edi
  float *v8; // eax
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  vostok::math::float3 *v14; // eax
  long double v15; // st7
  float v16; // [esp+14h] [ebp-50h]
  __int64 direction; // [esp+18h] [ebp-4Ch]
  vostok::math::float3 directiona; // [esp+18h] [ebp-4Ch]
  float direction_8; // [esp+20h] [ebp-44h]
  vostok::math::float4x4 v20; // [esp+24h] [ebp-40h] BYREF

  if ( *(_DWORD *)(a2 + 32) )
  {
    v4 = **(_DWORD **)(*(_DWORD *)(*(_DWORD *)(112 * *(_DWORD *)(a2 + 40) + *(_DWORD *)a2 + 108) + 136) + 264);
    v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 8))(v4);
    v6 = *(_DWORD *)(112 * *(_DWORD *)(a2 + 40) + *(_DWORD *)a2 + 108);
    v7 = (float *)v5;
    v8 = (float *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 8))(v6);
    v9 = v7[10];
    v10 = v7[9];
    v11 = v7[8];
    v12 = (float)((float)(v8[4] * v10) + (float)(v8[8] * v9)) + (float)(v11 * *v8);
    v13 = (float)((float)(v8[1] * v11) + (float)(v8[5] * v10)) + (float)(v8[9] * v9);
    direction_8 = (float)((float)(v8[2] * v11) + (float)(v8[6] * v10)) + (float)(v8[10] * v9);
    v16 = 1.0 / sqrtf((float)((float)(direction_8 * direction_8) + (float)(v13 * v13)) + (float)(v12 * v12));
    *(float *)&direction = v16 * v12;
    *((float *)&direction + 1) = v16 * v13;
    *(_QWORD *)&result->x = direction;
    result->z = direction_8 * v16;
    return result;
  }
  else
  {
    vostok::physics::from_bullet(
      (const btTransform *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 36) + 16) + 24) + 80 * *(_DWORD *)(a2 + 40)),
      *(btMatrix3x3 **)(a2 + 36),
      &v20);
    *(_QWORD *)&directiona.elements[1] = *(_QWORD *)&v20.lines[2].elements[1];
    v15 = 1.0 / sqrtf((float)((float)(v20.k.x * v20.k.x) + (float)(v20.k.y * v20.k.y)) + (float)(v20.k.z * v20.k.z));
    v14 = result;
    directiona.x = v20.k.x * v15;
    directiona.y = directiona.y * v15;
    directiona.z = v15 * directiona.z;
    *result = directiona;
  }
  return v14;
}
