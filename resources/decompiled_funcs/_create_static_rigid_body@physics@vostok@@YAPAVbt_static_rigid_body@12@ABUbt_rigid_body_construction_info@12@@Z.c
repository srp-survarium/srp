vostok::physics::bt_static_rigid_body *__usercall vostok::physics::create_static_rigid_body@<eax>(
        const vostok::physics::bt_rigid_body_construction_info *construction_info@<eax>,
        btRigidBody *a2@<ebx>,
        int a3@<edi>,
        vostok::physics::bt_collision_shape *a4@<esi>)
{
  vostok::physics::bt_collision_shape *m_object; // eax
  vostok::physics::bt_collision_shape *v6; // eax
  vostok::physics::bt_collision_shape *v7; // eax
  bool m_additionalDamping; // cl
  float m_additionalLinearDampingThresholdSqr; // xmm0_4
  void *(__thiscall *call_malloc)(vostok::memory::base_allocator *, unsigned int); // eax
  btCollisionObject *v11; // ecx
  btRigidBody *v12; // esi
  _DWORD *v13; // eax
  vostok::physics::bt_static_rigid_body *v14; // ecx
  int v15; // eax
  int v16; // esi
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> v19; // [esp+200h] [ebp-CCh] BYREF
  btRigidBody *v20; // [esp+204h] [ebp-C8h]
  vostok::intrusive_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v21; // [esp+214h] [ebp-B8h] BYREF
  int v22; // [esp+218h] [ebp-B4h]
  btRigidBody::btRigidBodyConstructionInfo resource; // [esp+21Ch] [ebp-B0h] BYREF
  float v24; // [esp+2BCh] [ebp-10h]
  float m_additionalAngularDampingThresholdSqr; // [esp+2C0h] [ebp-Ch]
  float m_additionalAngularDampingFactor; // [esp+2C4h] [ebp-8h]

  v20 = a2;
  v19.m_object = a4;
  m_object = construction_info->m_collisionShape.m_object;
  memset(&resource, 0, 16);
  v21.m_object = 0;
  if ( m_object )
  {
    v21.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v22 = LODWORD(construction_info->m_mass) & 0x7FFFFFFF;
  if ( *(float *)&v22 < 0.0000099999997 )
  {
    memset(&resource, 0, 16);
  }
  else
  {
    v6 = vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator->(&v21);
    ((void (__stdcall *)(float, btRigidBody::btRigidBodyConstructionInfo *))v6->m_bt_shape->calculateLocalInertia)(
      construction_info->m_mass,
      &resource);
  }
  v7 = vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator->(&v21);
  btRigidBody::btRigidBodyConstructionInfo::btRigidBodyConstructionInfo(
    &resource,
    (int)&resource.m_startWorldTransform,
    (int)v7->m_bt_shape,
    LODWORD(construction_info->m_mass));
  m_additionalDamping = construction_info->m_additionalDamping;
  *(__m128i *)&resource.m_linearDamping = _mm_load_si128((const __m128i *)&resource);
  resource.m_linearSleepingThreshold = construction_info->m_linearDamping;
  resource.m_angularSleepingThreshold = construction_info->m_angularDamping;
  *(float *)&resource.m_additionalDamping = construction_info->m_friction;
  resource.m_additionalDampingFactor = construction_info->m_restitution;
  resource.m_additionalLinearDampingThresholdSqr = construction_info->m_linearSleepingThreshold;
  resource.m_additionalAngularDampingThresholdSqr = construction_info->m_angularSleepingThreshold;
  *((_DWORD *)&resource.m_additionalAngularDampingFactor + 1) = LODWORD(construction_info->m_additionalDampingFactor);
  m_additionalLinearDampingThresholdSqr = construction_info->m_additionalLinearDampingThresholdSqr;
  LOBYTE(resource.m_additionalAngularDampingFactor) = m_additionalDamping;
  call_malloc = vostok::physics::g_ph_allocator->call_malloc;
  v24 = m_additionalLinearDampingThresholdSqr;
  m_additionalAngularDampingThresholdSqr = construction_info->m_additionalAngularDampingThresholdSqr;
  m_additionalAngularDampingFactor = construction_info->m_additionalAngularDampingFactor;
  v12 = (btRigidBody *)((int (__thiscall *)(vostok::memory::base_allocator *, int, int, vostok::physics::bt_collision_shape *, btRigidBody *))call_malloc)(
                         vostok::physics::g_ph_allocator,
                         704,
                         a3,
                         v19.m_object,
                         v20);
  if ( v12 )
  {
    btCollisionObject::btCollisionObject(v11);
    v12->__vftable = (btRigidBody_vtbl *)&btRigidBody::`vftable';
    v12->m_constraintRefs.m_ownsMemory = 1;
    v12->m_constraintRefs.m_data = 0;
    v12->m_constraintRefs.m_size = 0;
    v12->m_constraintRefs.m_capacity = 0;
    btRigidBody::setupRigidBody(
      v12,
      (btRigidBody::btRigidBodyConstructionInfo *)&resource.m_startWorldTransform.m_basis.m_el[0].m_floats[3]);
  }
  else
  {
    v12 = 0;
  }
  v13 = vostok::physics::g_ph_allocator->call_malloc(vostok::physics::g_ph_allocator, 20);
  if ( v13 )
  {
    v20 = v12;
    v14 = (vostok::physics::bt_static_rigid_body *)&v19;
    v19.m_object = 0;
    if ( resource.m_motionState )
    {
      v19.m_object = (vostok::physics::bt_collision_shape *)resource.m_motionState;
      v14 = (vostok::physics::bt_static_rigid_body *)&resource.m_motionState[52];
      _InterlockedExchangeAdd((volatile signed __int32 *)&resource.m_motionState[52], 1u);
    }
    vostok::physics::bt_static_rigid_body::bt_static_rigid_body(v14, v13, v19, v20);
    v16 = v15;
  }
  else
  {
    v16 = 0;
  }
  if ( resource.m_motionState
    && !_InterlockedExchangeAdd((volatile signed __int32 *)&resource.m_motionState[52], 0xFFFFFFFF) )
  {
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)&resource.m_motionState[52],
      (vostok::resources::unmanaged_resource *)resource.m_motionState);
  }
  return (vostok::physics::bt_static_rigid_body *)v16;
}
