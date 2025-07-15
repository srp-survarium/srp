vostok::physics::bt_dynamic_rigid_body *__usercall vostok::physics::create_dynamic_rigid_body@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        float a4@<xmm4>,
        const vostok::physics::bt_rigid_body_construction_info *construction_info,
        vostok::physics::bt_collision_shape *shape)
{
  double m_mass; // st7
  btCollisionShape *m_bt_shape; // ecx
  float m_linearDamping; // xmm0_4
  bool m_additionalDamping; // al
  float m_additionalAngularDampingFactor; // xmm0_4
  btRigidBody *v11; // eax
  btRigidBody *v12; // eax
  float m_inverseMass; // xmm1_4
  float v14; // xmm2_4
  vostok::memory::base_allocator *v15; // esi
  char *v16; // eax
  vostok::physics::base_physics_object *v17; // ecx
  _DWORD *v18; // edi
  float v20; // [esp+8h] [ebp-D8h]
  struct btMotionState *v21; // [esp+1Ch] [ebp-C4h]
  struct btCollisionShape *v22; // [esp+20h] [ebp-C0h]
  const struct btVector3 *v23; // [esp+24h] [ebp-BCh]
  btRigidBody *v24; // [esp+28h] [ebp-B8h]
  vostok::math::float3 m_linear_factor; // [esp+2Ch] [ebp-B4h] BYREF
  int v26; // [esp+38h] [ebp-A8h]
  btRigidBody::btRigidBodyConstructionInfo v27; // [esp+3Ch] [ebp-A4h] BYREF
  float m_additionalLinearDampingThresholdSqr; // [esp+DCh] [ebp-4h]
  float m_additionalAngularDampingThresholdSqr; // [esp+E0h] [ebp+0h]
  float retaddr; // [esp+E4h] [ebp+4h]

  m_mass = construction_info->m_mass;
  m_bt_shape = shape->m_bt_shape;
  *(_QWORD *)&m_linear_factor.elements[1] = 0;
  v26 = 0;
  v27.m_mass = 0.0;
  v20 = m_mass;
  ((void (__stdcall *)(_DWORD, float *, int, int, int))m_bt_shape->calculateLocalInertia)(
    LODWORD(v20),
    &m_linear_factor.y,
    a2,
    a3,
    a1);
  btRigidBody::btRigidBodyConstructionInfo::btRigidBodyConstructionInfo(
    &v27,
    (int)shape->m_bt_shape,
    LODWORD(construction_info->m_mass),
    &v27.m_startWorldTransform,
    v21,
    v22,
    v23);
  m_linearDamping = construction_info->m_linearDamping;
  v27.m_linearDamping = v27.m_mass;
  LODWORD(v27.m_angularDamping) = v27.m_motionState;
  LODWORD(v27.m_friction) = (&v27.m_motionState)[1];
  m_additionalDamping = construction_info->m_additionalDamping;
  LODWORD(v27.m_restitution) = (&v27.m_motionState)[2];
  v27.m_linearSleepingThreshold = m_linearDamping;
  v27.m_angularSleepingThreshold = construction_info->m_angularDamping;
  *(float *)&v27.m_additionalDamping = construction_info->m_friction;
  v27.m_additionalDampingFactor = construction_info->m_restitution;
  v27.m_additionalLinearDampingThresholdSqr = construction_info->m_linearSleepingThreshold;
  v27.m_additionalAngularDampingThresholdSqr = construction_info->m_angularSleepingThreshold;
  *((_DWORD *)&v27.m_additionalAngularDampingFactor + 1) = LODWORD(construction_info->m_additionalDampingFactor);
  m_additionalLinearDampingThresholdSqr = construction_info->m_additionalLinearDampingThresholdSqr;
  m_additionalAngularDampingThresholdSqr = construction_info->m_additionalAngularDampingThresholdSqr;
  m_additionalAngularDampingFactor = construction_info->m_additionalAngularDampingFactor;
  LOBYTE(v27.m_additionalAngularDampingFactor) = m_additionalDamping;
  retaddr = m_additionalAngularDampingFactor;
  v11 = (btRigidBody *)btAlignedAllocInternal(0x290u);
  if ( v11 )
  {
    v12 = btRigidBody::btRigidBody(
            (btRigidBody *)&v27.m_startWorldTransform,
            v11,
            a4,
            (const btRigidBody::btRigidBodyConstructionInfo *)&v27.m_startWorldTransform);
    v24 = v12;
  }
  else
  {
    v24 = 0;
    v12 = 0;
  }
  m_linear_factor = construction_info->m_linear_factor;
  v26 = 0;
  *(vostok::math::float3 *)v12->m_linearFactor.mVec128.m128_f32 = m_linear_factor;
  v12->m_linearFactor.mVec128.m128_i32[3] = v26;
  m_inverseMass = v12->m_inverseMass;
  m_linear_factor.x = v12->m_linearFactor.mVec128.m128_f32[0] * m_inverseMass;
  m_linear_factor.y = v12->m_linearFactor.mVec128.m128_f32[1] * m_inverseMass;
  v14 = v12->m_linearFactor.mVec128.m128_f32[2];
  v26 = 0;
  m_linear_factor.z = v14 * m_inverseMass;
  *(vostok::math::float3 *)v12->m_invMass.mVec128.m128_f32 = m_linear_factor;
  v12->m_invMass.mVec128.m128_i32[3] = v26;
  m_linear_factor = construction_info->m_angular_factor;
  v26 = 0;
  *(vostok::math::float3 *)v12->m_angularFactor.mVec128.m128_f32 = m_linear_factor;
  v12->m_angularFactor.mVec128.m128_i32[3] = v26;
  if ( construction_info->m_disable_deactivation )
    btCollisionObject::setActivationState((btCollisionObject *)&v12->m_linearFactor, (int)v12, 4);
  v15 = vostok::physics::g_allocator;
  v16 = type_info::raw_name(&vostok::physics::bt_dynamic_rigid_body `RTTI Type Descriptor');
  v18 = v15->call_malloc(v15, 24u, v16, "vostok::physics::create_dynamic_rigid_body", ".\\dynamic_rigid_body.cpp", 122u);
  if ( !v18 )
    return 0;
  vostok::physics::base_physics_object::base_physics_object(v17, v18, vostok::physics::g_allocator);
  v18[4] = shape;
  v18[5] = v24;
  *v18 = &vostok::physics::bt_dynamic_rigid_body::`vftable';
  v24->m_userObjectPointer = v18;
  return (vostok::physics::bt_dynamic_rigid_body *)v18;
}
