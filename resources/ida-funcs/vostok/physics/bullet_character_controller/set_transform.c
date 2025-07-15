void __thiscall vostok::physics::bullet_character_controller::set_transform(
        vostok::physics::bullet_character_controller *this,
        const btTransform *transform,
        btMatrix3x3 *a3)
{
  btCollisionWorld *v3; // esi
  btQuaternion q; // [esp+10h] [ebp-60h] BYREF
  _DWORD v5[4]; // [esp+20h] [ebp-50h] BYREF
  btMatrix3x3 v6; // [esp+30h] [ebp-40h] BYREF
  int v7; // [esp+60h] [ebp-10h]
  int v8; // [esp+64h] [ebp-Ch]
  int v9; // [esp+68h] [ebp-8h]
  int v10; // [esp+6Ch] [ebp-4h]

  vostok::physics::capsule_bottom_to_center_position(
    a3[1].m_el,
    (const btCapsuleShape *)&transform[6].m_basis.m_el[2],
    (int)v5);
  btMatrix3x3::getRotation(a3, &q);
  btMatrix3x3::setRotation(&q, &v6);
  v7 = v5[0];
  v8 = v5[1];
  v9 = v5[2];
  v10 = v5[3];
  btCollisionObject::setWorldTransform((btCollisionObject *)&v6, &transform[1].m_basis.m_el[2]);
  v3 = (btCollisionWorld *)transform->m_basis.m_el[1].mVec128.m128_i32[1];
  if ( v3 )
    btCollisionWorld::updateSingleAabb(v3, (btCollisionObject *)&transform[1].m_basis.m_el[2]);
}
