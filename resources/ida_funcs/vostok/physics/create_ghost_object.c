vostok::physics::bt_ghost_object *__cdecl vostok::physics::create_ghost_object(
        vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> shape,
        const vostok::math::float4x4 *transform)
{
  btPairCachingGhostObject *v2; // ecx
  btPairCachingGhostObject *v3; // ebx
  const btTransform *v4; // eax
  vostok::physics::bt_collision_shape *v5; // eax
  _DWORD *v6; // eax
  vostok::resources::unmanaged_intrusive_base *v7; // ecx
  int v8; // eax
  int v9; // esi
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> v11; // [esp-8h] [ebp-58h] BYREF
  btPairCachingGhostObject *v12; // [esp-4h] [ebp-54h]

  if ( vostok::physics::g_ph_allocator->call_malloc(vostok::physics::g_ph_allocator, 320) )
    v3 = btPairCachingGhostObject::btPairCachingGhostObject(v2);
  else
    v3 = 0;
  v4 = vostok::physics::from_vostok(transform);
  btCollisionObject::setWorldTransform(v3, v4);
  v5 = vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator->(&shape);
  v3->setCollisionShape(v3, v5->m_bt_shape);
  v6 = vostok::physics::g_ph_allocator->call_malloc(vostok::physics::g_ph_allocator, 20);
  if ( v6 )
  {
    v12 = v3;
    v7 = (vostok::resources::unmanaged_intrusive_base *)&v11;
    v11.m_object = 0;
    if ( shape.m_object )
    {
      v11.m_object = shape.m_object;
      v7 = &shape.m_object->vostok::resources::unmanaged_intrusive_base;
      _InterlockedExchangeAdd(&shape.m_object->m_reference_count, 1u);
    }
    vostok::physics::bt_ghost_object::bt_ghost_object((vostok::physics::bt_ghost_object *)v7, v6, v11, v12);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  if ( shape.m_object && !_InterlockedExchangeAdd(&shape.m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &shape.m_object->vostok::resources::unmanaged_intrusive_base,
      shape.m_object);
  return (vostok::physics::bt_ghost_object *)v9;
}
