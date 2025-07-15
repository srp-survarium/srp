void __thiscall vostok::render::grass_patch::init_collision(vostok::render::grass_patch *this, int a2)
{
  int v3; // esi
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  unsigned int v8; // xmm1_4
  unsigned int v9; // xmm2_4
  vostok::math::float4x4 *v10; // eax
  vostok::collision::geometry_instance *v11; // eax
  vostok::collision::object *v12; // eax
  vostok::math::float4x4 v13; // [esp+14h] [ebp-D4h] BYREF
  vostok::math::float4x4 v14; // [esp+54h] [ebp-94h] BYREF
  vostok::math::float4x4 matrix; // [esp+94h] [ebp-54h] BYREF
  float v16; // [esp+D4h] [ebp-14h]
  vostok::math::float3 v17; // [esp+D8h] [ebp-10h] BYREF
  float v18; // [esp+F0h] [ebp+8h]
  vostok::math::float4x4 *v19; // [esp+F0h] [ebp+8h]

  if ( (_S5_5 & 1) == 0 )
  {
    _S5_5 |= 1u;
    s_randomizer_0.m_seed = 100000;
  }
  v3 = *(_DWORD *)(a2 + 20);
  *(float *)(a2 + 96) = float_max_19;
  for ( *(float *)(a2 + 108) = float_min_15; v3; v3 = *(_DWORD *)(v3 + 8) )
    vostok::math::aabb::modify((vostok::math::aabb *)(v3 + 60), (vostok::math::aabb *)(a2 + 92));
  *(float *)(a2 + 96) = *(float *)(a2 + 96) - 0.2;
  *(float *)(a2 + 108) = *(float *)(a2 + 108) + 3.0;
  v4 = *(float *)(a2 + 108) + *(float *)(a2 + 96);
  v5 = *(float *)(a2 + 112) + *(float *)(a2 + 100);
  v17.x = (float)(*(float *)(a2 + 92) + *(float *)(a2 + 104)) * 0.5;
  v17.y = v4 * 0.5;
  v17.z = v5 * 0.5;
  *(vostok::math::float3 *)(a2 + 16512) = v17;
  v18 = vostok::math::random32::random_f(&s_randomizer_0, 0.1);
  v16 = vostok::math::random32::random_f(&s_randomizer_0, 0.1);
  v17.z = vostok::math::random32::random_f(&s_randomizer_0, 0.1);
  v6 = v16 - 0.25;
  v7 = v17.z - 0.25;
  *(float *)(a2 + 16512) = *(float *)(a2 + 16512) + (float)(v18 - 0.25);
  *(float *)(a2 + 16516) = *(float *)(a2 + 16516) + v6;
  *(float *)(a2 + 16520) = *(float *)(a2 + 16520) + v7;
  *(float *)&v8 = (float)(*(float *)(a2 + 108) - *(float *)(a2 + 96)) * 0.5;
  *(float *)&v9 = (float)(*(float *)(a2 + 112) - *(float *)(a2 + 100)) * 0.5;
  v17.x = (float)(*(float *)(a2 + 104) - *(float *)(a2 + 92)) * 0.5;
  *(_QWORD *)&v17.elements[1] = __PAIR64__(v9, v8);
  v19 = vostok::math::create_translation((const vostok::math::float3 *)(a2 + 16512), &v14);
  v10 = vostok::math::create_scale(&v17, &v13);
  vostok::math::mul4x3(v19, v10, &matrix);
  v11 = vostok::collision::new_box_geometry_instance(&vostok::memory::g_mt_allocator, &matrix);
  *(_DWORD *)(a2 + 84) = v11;
  v12 = vostok::collision::new_collision_object(
          &vostok::memory::g_mt_allocator,
          (unsigned int)v11,
          (vostok::collision::geometry_instance *)a2);
  *(_DWORD *)(a2 + 88) = v12;
  (***(void (__thiscall ****)(_DWORD, vostok::collision::object *, vostok::math::float4x4 *))(a2 + 80))(
    *(_DWORD *)(a2 + 80),
    v12,
    &matrix);
}
