vostok::physics::bt_collision_shape *__usercall vostok::physics::create_primitive_shape@<eax>(
        vostok::collision::primitive_type type@<edx>,
        const vostok::math::float3 *dim@<ecx>,
        float a3@<xmm4>,
        const vostok::math::float3 *local_scale)
{
  int v4; // eax
  int v5; // edi
  void (__thiscall *v6)(int, float *); // edx
  vostok::resources::unmanaged_resource *v7; // eax
  _DWORD *v8; // esi
  _WORD *v9; // eax
  float x; // [esp+10h] [ebp-10h] BYREF
  __int64 v12; // [esp+14h] [ebp-Ch]
  int v13; // [esp+1Ch] [ebp-4h]

  vostok::physics::create_bt_primitive(type, dim, a3);
  x = local_scale->x;
  v5 = v4;
  v6 = *(void (__thiscall **)(int, float *))(*(_DWORD *)v4 + 20);
  v12 = *(_QWORD *)&local_scale->elements[1];
  v13 = 0;
  v6(v4, &x);
  v7 = (vostok::resources::unmanaged_resource *)vostok::physics::g_ph_allocator->call_malloc(
                                                  vostok::physics::g_ph_allocator,
                                                  280);
  v8 = &v7->__vftable;
  if ( v7 )
  {
    vostok::resources::unmanaged_resource::unmanaged_resource(v7, 1u);
    *v8 = &vostok::physics::bt_collision_shape::`vftable';
    v8[66] = v5;
    v8[67] = 0;
    v8[68] = 0;
    *(_DWORD *)(v5 + 8) = v8;
  }
  else
  {
    v8 = 0;
  }
  v9 = vostok::physics::g_ph_allocator->call_malloc(vostok::physics::g_ph_allocator, 2);
  v8[68] = v9;
  *v9 = 0;
  return (vostok::physics::bt_collision_shape *)v8;
}
