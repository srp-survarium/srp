void __thiscall vostok::physics::old_bullet_character_controller::set_transform(
        vostok::physics::old_bullet_character_controller *this,
        const btTransform *transform)
{
  btCollisionWorld *v2; // esi
  float v3; // [esp+8h] [ebp-60h]
  float v4; // [esp+Ch] [ebp-5Ch]
  float v5; // [esp+10h] [ebp-58h]
  btQuaternion q; // [esp+18h] [ebp-50h] BYREF
  btMatrix3x3 v7; // [esp+28h] [ebp-40h] BYREF
  float v8; // [esp+58h] [ebp-10h]
  float v9; // [esp+5Ch] [ebp-Ch]
  float v10; // [esp+60h] [ebp-8h]
  int v11; // [esp+64h] [ebp-4h]

  v3 = transform[1].m_origin.mVec128.m128_f32[0] + this->m_air_control_vector.mVec128.m128_f32[0];
  v4 = this->m_air_control_vector.mVec128.m128_f32[1] + transform[1].m_origin.mVec128.m128_f32[1];
  v5 = this->m_air_control_vector.mVec128.m128_f32[2] + transform[1].m_origin.mVec128.m128_f32[2];
  btMatrix3x3::getRotation((btMatrix3x3 *)this, &q);
  btMatrix3x3::setRotation(&q, &v7);
  v8 = v3;
  v9 = v4;
  v10 = v5;
  v11 = 0;
  btCollisionObject::setWorldTransform((btCollisionObject *)&v7, &transform[2].m_basis.m_el[2]);
  btCollisionObject::setInterpolationWorldTransform(
    (btCollisionObject *)&transform[2].m_origin,
    &transform[2].m_basis.m_el[2]);
  v2 = (btCollisionWorld *)transform->m_basis.m_el[1].mVec128.m128_i32[1];
  if ( v2 )
    btCollisionWorld::updateSingleAabb(v2, (btCollisionObject *)&transform[2].m_basis.m_el[2]);
}
