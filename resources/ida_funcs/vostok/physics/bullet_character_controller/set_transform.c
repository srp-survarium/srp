void __usercall vostok::physics::bullet_character_controller::set_transform(
        vostok::physics::bullet_character_controller *this@<edi>,
        const btTransform *transform@<eax>,
        btMatrix3x3 *a3@<ecx>)
{
  btPairCachingGhostObject *m_ghost_object; // ecx
  __m128i v4; // [esp+10h] [ebp-60h] BYREF
  btQuaternion q; // [esp+20h] [ebp-50h] BYREF
  btTransform worldTrans; // [esp+30h] [ebp-40h] BYREF

  *(float *)v4.m128i_i32 = transform->m_origin.mVec128.m128_f32[0] + this->m_shape_offset.mVec128.m128_f32[0];
  *(float *)&v4.m128i_i32[1] = transform->m_origin.mVec128.m128_f32[1] + this->m_shape_offset.mVec128.m128_f32[1];
  v4.m128i_i64[1] = COERCE_UNSIGNED_INT(transform->m_origin.mVec128.m128_f32[2] + this->m_shape_offset.mVec128.m128_f32[2]);
  btMatrix3x3::getRotation(a3, (float *)transform, &q);
  btMatrix3x3::setRotation((btMatrix3x3 *)&q, (int)&worldTrans);
  m_ghost_object = this->m_ghost_object;
  worldTrans.m_origin = (btVector3)_mm_load_si128(&v4);
  btCollisionObject::setWorldTransform(m_ghost_object, &worldTrans);
  btCollisionObject::setInterpolationWorldTransform(this->m_ghost_object, &this->m_ghost_object->m_worldTransform);
}
