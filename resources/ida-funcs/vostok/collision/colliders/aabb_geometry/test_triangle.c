BOOL __thiscall vostok::collision::colliders::aabb_geometry::test_triangle(
        vostok::collision::colliders::aabb_geometry *this,
        float **triangle_id,
        int a3)
{
  _DWORD *v3; // ebx
  int v4; // eax
  int v5; // esi
  float *v6; // eax
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  vostok::math::float3 v14[3]; // [esp+Ch] [ebp-3Ch] BYREF
  vostok::math::float3 v15; // [esp+30h] [ebp-18h] BYREF
  vostok::math::float3 v16; // [esp+3Ch] [ebp-Ch] BYREF

  v3 = (_DWORD *)(*(int (__thiscall **)(float *, int))(*(_DWORD *)triangle_id[18] + 44))(triangle_id[18], a3);
  v4 = (*(int (__thiscall **)(float *))(*(_DWORD *)triangle_id[18] + 36))(triangle_id[18]);
  v14[0] = *(vostok::math::float3 *)(v4 + 12 * *v3);
  v14[1] = *(vostok::math::float3 *)(v4 + 12 * v3[1]);
  v5 = v4 + 12 * v3[2];
  v6 = *triangle_id;
  v7 = (*triangle_id)[3] - **triangle_id;
  v8 = (*triangle_id)[4] - (*triangle_id)[1];
  v9 = (*triangle_id)[5] - (*triangle_id)[2];
  v14[2].x = *(float *)v5;
  v15.x = v7 * 0.5;
  v10 = *v6 + v6[3];
  v15.y = v8 * 0.5;
  v11 = v6[4] + v6[1];
  v15.z = v9 * 0.5;
  v12 = v6[5] + v6[2];
  *(_QWORD *)&v14[2].elements[1] = *(_QWORD *)(v5 + 4);
  v16.x = v10 * 0.5;
  v16.y = v11 * 0.5;
  v16.z = v12 * 0.5;
  return triBoxOverlap(&v15, (const vostok::math::float3 (*)[3])v14, &v16);
}
