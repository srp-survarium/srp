jump_vertical_test_callback *__thiscall jump_vertical_test_callback::jump_vertical_test_callback(
        jump_vertical_test_callback *this,
        jump_vertical_test_callback *self,
        btCollisionObject *up_vector,
        const btVector3 *center,
        const float capsule_radius,
        float a6)
{
  btVector3 v7; // [esp+4h] [ebp-20h] BYREF
  btVector3 v8; // [esp+14h] [ebp-10h] BYREF

  v7.mVec128.m128_f32[0] = QNaN_153;
  v7.mVec128.m128_f32[1] = QNaN_153;
  v7.mVec128.m128_u64[1] = LODWORD(QNaN_153);
  v8.mVec128.m128_f32[0] = QNaN_153;
  v8.mVec128.m128_f32[1] = QNaN_153;
  v8.mVec128.m128_u64[1] = LODWORD(QNaN_153);
  btCollisionWorld::ClosestConvexResultCallback::ClosestConvexResultCallback(self, &v8, &v7);
  self->__vftable = (jump_vertical_test_callback_vtbl *)&jump_vertical_test_callback::`vftable';
  self->m_up_vector = (const btVector3)center->mVec128;
  self->m_center = *(const btVector3 *)capsule_radius;
  self->m_self = up_vector;
  self->m_collisionFilterGroup = 4;
  self->m_collisionFilterMask = 2;
  self->m_capsule_radius2 = a6 * a6;
  return self;
}
