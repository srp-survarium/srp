vostok::physics::bt_collision_shape *__fastcall vostok::physics::create_primitive_shape(
        const vostok::math::float3 *dim,
        vostok::collision::primitive_type type,
        const vostok::math::float3 *local_scale)
{
  btCollisionShape *v4; // eax
  btCollisionShape *v5; // edi
  btCollisionShape_vtbl *v6; // eax
  vostok::physics::bt_collision_shape *v7; // eax
  int v8; // eax
  int v9; // edi
  vostok::memory::base_allocator *v10; // esi
  char *v11; // eax
  _WORD *v12; // eax
  vostok::resources::unmanaged_resource *v14; // [esp-4h] [ebp-24h]
  __int64 v15; // [esp+10h] [ebp-10h] BYREF
  float z; // [esp+18h] [ebp-8h]
  int v17; // [esp+1Ch] [ebp-4h]

  vostok::physics::create_bt_primitive(type, dim, vostok::physics::g_allocator);
  v15 = *(_QWORD *)&local_scale->x;
  v5 = v4;
  v6 = v4->__vftable;
  z = local_scale->z;
  v17 = 0;
  v6->setLocalScaling(v5, (const btVector3 *)&v15);
  v7 = (vostok::physics::bt_collision_shape *)vostok::memory::new_helper<vostok::physics::bt_collision_shape>::call<vostok::memory::base_allocator>(
                                                vostok::physics::g_allocator,
                                                "vostok::physics::create_primitive_shape",
                                                (const char *const)0xE0);
  if ( v7 )
  {
    vostok::physics::bt_collision_shape::bt_collision_shape(v7, v5, v14);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  v10 = vostok::physics::g_allocator;
  v11 = type_info::raw_name(&unsigned short `RTTI Type Descriptor');
  v12 = v10->call_malloc(v10, 2u, v11, "vostok::physics::create_primitive_shape", ".\\collision_shapes.cpp", 227u);
  *(_DWORD *)(v9 + 272) = v12;
  *v12 = 0;
  return (vostok::physics::bt_collision_shape *)v9;
}
