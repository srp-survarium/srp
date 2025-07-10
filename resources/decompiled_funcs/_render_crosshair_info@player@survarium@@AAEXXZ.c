void __usercall survarium::player::render_crosshair_info(survarium::player *this@<ecx>, int a2@<esi>)
{
  __int64 v2; // xmm0_8
  float v3; // ecx
  int v4; // eax
  vostok::resources::unmanaged_resource *v5; // eax
  vostok::resources::unmanaged_resource *v6; // edi
  vostok::math::float3 ray_from; // [esp+24h] [ebp-44h] BYREF
  vostok::math::float3 ray_dir; // [esp+30h] [ebp-38h] BYREF
  vostok::physics::closest_ray_result result; // [esp+3Ch] [ebp-2Ch] BYREF

  v2 = *(_QWORD *)(a2 + 120);
  v3 = *(float *)(a2 + 112);
  ray_from.z = *(float *)(a2 + 128);
  v4 = *(int *)((char *)&dword_10F00 + a2);
  *(_QWORD *)&ray_from.x = v2;
  *(_QWORD *)&ray_dir.x = *(_QWORD *)(a2 + 104);
  ray_dir.z = v3;
  v5 = *(vostok::resources::unmanaged_resource **)(v4 + 4);
  v6 = 0;
  if ( v5 )
  {
    v6 = v5;
    _InterlockedExchangeAdd(&v5->m_reference_count, 1u);
  }
  (*(void (__stdcall **)(vostok::physics::closest_ray_result *, vostok::math::float3 *, vostok::math::float3 *, _DWORD, int, int))(**(_DWORD **)(*(int *)((char *)&dword_10F00 + a2) + 176) + 60))(
    &result,
    &ray_from,
    &ray_dir,
    1000.0,
    16,
    8);
  if ( result.object )
    *(float *)(*(_DWORD *)(*(int *)((char *)&dword_10F04 + a2) + 116) + 60) = sqrtf(
                                                                                (float)((float)((float)(result.hit_point_world.z - ray_from.z)
                                                                                              * (float)(result.hit_point_world.z - ray_from.z))
                                                                                      + (float)((float)(result.hit_point_world.y - ray_from.y)
                                                                                              * (float)(result.hit_point_world.y - ray_from.y)))
                                                                              + (float)((float)(result.hit_point_world.x
                                                                                              - ray_from.x)
                                                                                      * (float)(result.hit_point_world.x
                                                                                              - ray_from.x)));
  if ( v6 )
  {
    if ( !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
  }
}
