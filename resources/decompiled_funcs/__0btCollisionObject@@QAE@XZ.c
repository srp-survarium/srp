btCollisionObject *__usercall btCollisionObject::btCollisionObject@<eax>(
        btCollisionObject *this@<ecx>,
        btCollisionObject *result@<eax>)
{
  const vostok::math::float4x4 *v2; // xmm1_4

  v2 = clear_value;
  result->__vftable = (btCollisionObject_vtbl *)&btCollisionObject::`vftable';
  result->m_anisotropicFriction.mVec128.m128_i32[0] = (int)v2;
  result->m_anisotropicFriction.mVec128.m128_i32[1] = (int)v2;
  result->m_anisotropicFriction.mVec128.m128_i32[2] = (int)v2;
  result->m_anisotropicFriction.mVec128.m128_i32[3] = 0;
  result->m_contactProcessingThreshold = 9.9999998e17;
  result->m_islandTag1 = -1;
  result->m_companionId = -1;
  result->m_deactivationTime = 0.0;
  result->m_friction = FLOAT_0_5;
  result->m_restitution = 0.0;
  LODWORD(result->m_hitFraction) = v2;
  result->m_ccdSweptSphereRadius = 0.0;
  result->m_ccdMotionThreshold = 0.0;
  result->m_hasAnisotropicFriction = 0;
  result->m_broadphaseHandle = 0;
  result->m_collisionShape = 0;
  result->m_extensionPointer = 0;
  result->m_rootCollisionShape = 0;
  result->m_userObjectPointer = 0;
  result->m_checkCollideWith = 0;
  result->m_collisionFlags = 1;
  result->m_activationState1 = 1;
  result->m_internalType = 1;
  result->m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[0] = (int)v2;
  result->m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[1] = 0;
  result->m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[2] = 0;
  result->m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[3] = 0;
  result->m_worldTransform.m_basis.m_el[1].mVec128.m128_i32[0] = 0;
  result->m_worldTransform.m_basis.m_el[1].mVec128.m128_i32[1] = (int)v2;
  result->m_worldTransform.m_basis.m_el[1].mVec128.m128_i32[2] = 0;
  result->m_worldTransform.m_basis.m_el[1].mVec128.m128_i32[3] = 0;
  result->m_worldTransform.m_basis.m_el[2].mVec128.m128_i32[0] = 0;
  result->m_worldTransform.m_basis.m_el[2].mVec128.m128_i32[1] = 0;
  result->m_worldTransform.m_basis.m_el[2].mVec128.m128_i32[2] = (int)v2;
  result->m_worldTransform.m_basis.m_el[2].mVec128.m128_i32[3] = 0;
  result->m_worldTransform.m_origin.mVec128.m128_i32[0] = 0;
  result->m_worldTransform.m_origin.mVec128.m128_i32[1] = 0;
  result->m_worldTransform.m_origin.mVec128.m128_i32[2] = 0;
  result->m_worldTransform.m_origin.mVec128.m128_i32[3] = 0;
  return result;
}
