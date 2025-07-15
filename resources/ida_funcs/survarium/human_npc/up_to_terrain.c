void __usercall survarium::human_npc::up_to_terrain(survarium::human_npc *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  int v3; // ecx
  float v4; // eax
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  vostok::math::float3 *v8; // edi
  long double v9; // st7
  const vostok::math::float4x4 *v10; // xmm6_4
  unsigned int v11; // xmm4_4
  unsigned int v12; // xmm5_4
  const vostok::math::float4x4 *v13; // eax
  survarium::human_npc *v14; // ecx
  vostok::math::float3 position; // [esp+20h] [ebp-88h] BYREF
  float v16; // [esp+2Ch] [ebp-7Ch]
  _DWORD v17[2]; // [esp+30h] [ebp-78h] BYREF
  float v18; // [esp+38h] [ebp-70h]
  vostok::physics::closest_ray_result result; // [esp+3Ch] [ebp-6Ch] BYREF
  vostok::math::float4x4 v20; // [esp+64h] [ebp-44h] BYREF

  v2 = *(_DWORD *)(a2 + 336);
  v17[0] = *(_DWORD *)(a2 + 608);
  *(float *)&v17[1] = *(float *)(a2 + 612) + *(float *)&clear_value;
  v18 = *(float *)(a2 + 616);
  v3 = *(_DWORD *)(v2 + 176);
  *(_QWORD *)&position.x = 0xBF80000000000000uLL;
  position.z = 0.0;
  (*(void (__thiscall **)(int, vostok::physics::closest_ray_result *, _DWORD *, vostok::math::float3 *, _DWORD, int, int))(*(_DWORD *)v3 + 60))(
    v3,
    &result,
    v17,
    &position,
    10.0,
    32,
    2);
  if ( result.object )
  {
    *(_QWORD *)&position.x = __PAIR64__(LODWORD(result.hit_point_world.y), v17[0]);
    position.z = v18;
    v4 = v18;
    *(_QWORD *)(a2 + 716) = __PAIR64__(LODWORD(result.hit_point_world.y), v17[0]);
    *(float *)(a2 + 724) = v4;
  }
  if ( *(float *)(a2 + 716) != *(float *)(a2 + 608)
    || *(float *)(a2 + 720) != *(float *)(a2 + 612)
    || *(float *)(a2 + 724) != *(float *)(a2 + 616) )
  {
    v5 = *(float *)(a2 + 716) - *(float *)(a2 + 608);
    v6 = *(float *)(a2 + 724) - *(float *)(a2 + 616);
    v7 = *(float *)(a2 + 720) - *(float *)(a2 + 612);
    v8 = *(vostok::math::float3 **)(*(_DWORD *)(a2 + 336) + 168);
    v9 = v8[83].z / (sqrtf((float)((float)(v5 * v5) + (float)(v6 * v6)) + (float)(v7 * v7)) / *(float *)(a2 + 728));
    v16 = v9;
    if ( v9 <= 1.0 )
      *(float *)&v10 = v16;
    else
      v10 = clear_value;
    *(float *)&v11 = *(float *)(a2 + 612)
                   + (float)((float)(*(float *)(a2 + 720) - *(float *)(a2 + 612)) * *(float *)&v10);
    *(float *)&v12 = *(float *)(a2 + 616)
                   + (float)((float)(*(float *)(a2 + 724) - *(float *)(a2 + 616)) * *(float *)&v10);
    position.x = *(float *)(a2 + 608) + (float)((float)(*(float *)(a2 + 716) - *(float *)(a2 + 608)) * *(float *)&v10);
    *(_QWORD *)&position.elements[1] = __PAIR64__(v12, v11);
    v13 = vostok::math::create_translation(&v20, &position);
    survarium::human_npc::set_translation(v14, v8, (survarium::human_npc *)a2, v13);
  }
}
