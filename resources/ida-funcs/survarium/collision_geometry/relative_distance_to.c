float __userpurge survarium::collision_geometry::relative_distance_to@<xmm0>(
        survarium::collision_geometry *this@<ecx>,
        const vostok::math::float3 *point,
        const vostok::math::float3 *a3)
{
  const vostok::math::float3 *v3; // ebx
  float x; // eax
  long double v5; // rdi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  vostok::math::float4x4 *v10; // esi
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  int v15; // [esp+8h] [ebp-13Ch]
  vostok::math::float4x4 v16; // [esp+1Ch] [ebp-128h] BYREF
  vostok::math::float4x4 v17; // [esp+5Ch] [ebp-E8h] BYREF
  vostok::math::float4x4 v18; // [esp+9Ch] [ebp-A8h] BYREF
  vostok::math::float4x4 v19; // [esp+DCh] [ebp-68h] BYREF
  int v20; // [esp+11Ch] [ebp-28h]
  float v21; // [esp+120h] [ebp-24h]
  vostok::math::float3 v22; // [esp+124h] [ebp-20h] BYREF
  float v23; // [esp+130h] [ebp-14h]
  float v24; // [esp+134h] [ebp-10h]
  int v25; // [esp+138h] [ebp-Ch]
  int i; // [esp+13Ch] [ebp-8h]
  int v27; // [esp+140h] [ebp-4h]

  v3 = point;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&point,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(LODWORD(point[1].z) + 16));
  x = point[22].x;
  if ( *(_DWORD *)(LODWORD(x) + 4) == 31 )
    v27 = *(_DWORD *)(LODWORD(x) + 16);
  else
    v27 = 1;
  (*(void (__thiscall **)(const vostok::math::float3 *, vostok::math::float4x4 *))(LODWORD(v3->x) + 24))(v3, &v18);
  LODWORD(v5) = 0;
  v24 = s_bm_current_air_resistance;
  v25 = 0;
  if ( v27 )
  {
    for ( i = 0; ; LODWORD(v5) = i )
    {
      HIDWORD(v5) = LODWORD(point[22].x);
      v6 = *(_DWORD *)(HIDWORD(v5) + 4) == 31
         ? *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(HIDWORD(v5) + 24) + LODWORD(v5) + 64) + 4)
         : *(_DWORD *)(HIDWORD(v5) + 4);
      if ( v6 )
      {
        v7 = v6 - 8;
        if ( v7 )
        {
          v15 = v7 == 2 ? 3 : 2;
          v8 = v15;
        }
        else
        {
          v8 = 0;
        }
      }
      else
      {
        v8 = 1;
      }
      v9 = v8;
      vostok::physics::dimensions_from_bullet_shape((int)&v22);
      if ( *(_DWORD *)(HIDWORD(v5) + 4) == 31 )
      {
        HIDWORD(v5) = LODWORD(v5) + *(_DWORD *)(HIDWORD(v5) + 24);
        vostok::physics::from_bullet(v5, &v17);
        vostok::math::mul4x3(&v18, &v17, &v16);
        v10 = &v16;
      }
      else
      {
        v10 = &v18;
      }
      qmemcpy(&v19, v10, sizeof(v19));
      v11 = fsqrt(
              (float)((float)((float)(v19.c.x - a3->x) * (float)(v19.c.x - a3->x))
                    + (float)((float)(v19.c.y - a3->y) * (float)(v19.c.y - a3->y)))
            + (float)((float)(v19.c.z - a3->z) * (float)(v19.c.z - a3->z)));
      v21 = v11;
      v20 = LODWORD(v11) & 0x7FFFFFFF;
      v23 = v11;
      if ( COERCE_FLOAT(LODWORD(v11) & 0x7FFFFFFF) < 0.001 )
        break;
      if ( v9 )
      {
        if ( v9 == 1 )
        {
          v12 = COERCE_FLOAT(survarium::distance_from_box_center_to_point_on_shape(a3, &v19, &v22));
        }
        else if ( v9 == 2 )
        {
          v12 = survarium::distance_from_cylinder_center_to_point_on_shape(&v19, a3, v22.x, v22.y);
        }
        else
        {
          v12 = survarium::distance_from_capsule_center_to_point_on_shape(&v19, a3, v22.x, v22.y);
        }
        v11 = v23;
      }
      else
      {
        v12 = v22.x;
      }
      v13 = v11 / v12;
      if ( s_bm_current_air_resistance <= v13 )
        v13 = s_bm_current_air_resistance;
      if ( v13 <= v24 )
        v24 = v13;
      ++v25;
      i += 80;
      if ( v25 == v27 )
        goto LABEL_37;
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&point);
    return 0.0;
  }
  else
  {
LABEL_37:
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&point);
    return v24;
  }
}
