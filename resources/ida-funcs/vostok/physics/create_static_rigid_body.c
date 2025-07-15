vostok::physics::bt_static_rigid_body *__usercall vostok::physics::create_static_rigid_body@<eax>(
        const struct btVector3 *a1@<ebx>,
        struct btMotionState *a2@<edi>,
        struct btCollisionShape *a3@<esi>,
        float a4@<xmm4>,
        const vostok::physics::bt_rigid_body_construction_info *construction_info)
{
  float m_linearDamping; // xmm0_4
  bool m_additionalDamping; // al
  float m_additionalAngularDampingFactor; // xmm0_4
  btRigidBody *v8; // eax
  btRigidBody *v9; // edi
  vostok::memory::base_allocator *v10; // esi
  char *v11; // eax
  vostok::particle::particle_system_instance_impl *v12; // ecx
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> v13; // ebx
  vostok::physics::bt_static_rigid_body *v14; // ecx
  int v15; // eax
  int v16; // esi
  int v18; // [esp+8h] [ebp-C0h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v19; // [esp+Ch] [ebp-BCh] BYREF
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *v20; // [esp+10h] [ebp-B8h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v21; // [esp+14h] [ebp-B4h] BYREF
  btRigidBody::btRigidBodyConstructionInfo v22; // [esp+18h] [ebp-B0h] BYREF
  float m_additionalLinearDampingThresholdSqr; // [esp+B8h] [ebp-10h]
  float m_additionalAngularDampingThresholdSqr; // [esp+BCh] [ebp-Ch]
  float v25; // [esp+C0h] [ebp-8h]

  memset(&v22, 0, 16);
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v21,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&construction_info->m_collisionShape);
  btRigidBody::btRigidBodyConstructionInfo::btRigidBodyConstructionInfo(
    &v22,
    (int)v21.m_object->m_lods[0].m_template.m_object,
    0,
    &v22.m_startWorldTransform,
    a2,
    a3,
    a1);
  m_linearDamping = construction_info->m_linearDamping;
  v22.m_linearDamping = v22.m_mass;
  LODWORD(v22.m_angularDamping) = v22.m_motionState;
  LODWORD(v22.m_friction) = (&v22.m_motionState)[1];
  m_additionalDamping = construction_info->m_additionalDamping;
  LODWORD(v22.m_restitution) = (&v22.m_motionState)[2];
  v22.m_linearSleepingThreshold = m_linearDamping;
  v22.m_angularSleepingThreshold = construction_info->m_angularDamping;
  *(float *)&v22.m_additionalDamping = construction_info->m_friction;
  v22.m_additionalDampingFactor = construction_info->m_restitution;
  v22.m_additionalLinearDampingThresholdSqr = construction_info->m_linearSleepingThreshold;
  v22.m_additionalAngularDampingThresholdSqr = construction_info->m_angularSleepingThreshold;
  *((_DWORD *)&v22.m_additionalAngularDampingFactor + 1) = LODWORD(construction_info->m_additionalDampingFactor);
  m_additionalLinearDampingThresholdSqr = construction_info->m_additionalLinearDampingThresholdSqr;
  m_additionalAngularDampingThresholdSqr = construction_info->m_additionalAngularDampingThresholdSqr;
  m_additionalAngularDampingFactor = construction_info->m_additionalAngularDampingFactor;
  LOBYTE(v22.m_additionalAngularDampingFactor) = m_additionalDamping;
  v25 = m_additionalAngularDampingFactor;
  v8 = (btRigidBody *)btAlignedAllocInternal(0x290u);
  if ( v8 )
    v9 = btRigidBody::btRigidBody(
           (btRigidBody *)&v22.m_startWorldTransform,
           v8,
           a4,
           (const btRigidBody::btRigidBodyConstructionInfo *)&v22.m_startWorldTransform);
  else
    v9 = 0;
  v10 = vostok::physics::g_allocator;
  v11 = type_info::raw_name(&vostok::physics::bt_static_rigid_body `RTTI Type Descriptor');
  v13.m_object = (vostok::physics::bt_collision_shape *)((int (__thiscall *)(vostok::memory::base_allocator *, int, char *, const char *, const char *, int, int, vostok::particle::particle_system_instance_impl *, vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *))v10->call_malloc)(
                                                          v10,
                                                          24,
                                                          v11,
                                                          "vostok::physics::create_static_rigid_body",
                                                          ".\\static_rigid_body.cpp",
                                                          90,
                                                          v18,
                                                          v19.m_object,
                                                          v20);
  if ( v13.m_object )
  {
    v20 = (vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)v9;
    v19.m_object = v12;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v19,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&(&v22.m_motionState)[1]);
    vostok::physics::bt_static_rigid_body::bt_static_rigid_body(v14, v13, (btRigidBody *)v19.m_object, v20);
    v16 = v15;
  }
  else
  {
    v16 = 0;
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&(&v22.m_motionState)[1]);
  return (vostok::physics::bt_static_rigid_body *)v16;
}
