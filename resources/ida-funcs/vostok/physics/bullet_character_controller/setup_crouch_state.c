void __thiscall vostok::physics::bullet_character_controller::setup_crouch_state(
        vostok::physics::bullet_character_controller *this,
        int crouch,
        char a3)
{
  const btCapsuleShape *v3; // esi
  int v4; // edi
  btQuaternion q; // [esp+10h] [ebp-60h] BYREF
  _DWORD v6[4]; // [esp+20h] [ebp-50h] BYREF
  btMatrix3x3 v7; // [esp+30h] [ebp-40h] BYREF
  int v8; // [esp+60h] [ebp-10h]
  int v9; // [esp+64h] [ebp-Ch]
  int v10; // [esp+68h] [ebp-8h]
  int v11; // [esp+6Ch] [ebp-4h]

  v3 = (const btCapsuleShape *)(crouch + 416);
  v4 = crouch + 160;
  *(_BYTE *)(crouch + 499) = a3;
  vostok::physics::capsule_center_to_bottom_position(
    (const btVector3 *)(crouch + 160),
    (const btCapsuleShape *)(crouch + 416),
    (int)&q);
  if ( a3 )
  {
    vostok::physics::bullet_character_controller::setup_shape_dim(
      (const vostok::math::float2 *)(crouch + 88),
      crouch,
      v4,
      (int)v3,
      (vostok::physics::bullet_character_controller *)crouch);
    *(_BYTE *)(crouch + 498) = 0;
  }
  else
  {
    vostok::physics::bullet_character_controller::setup_shape_dim(
      (const vostok::math::float2 *)(crouch + 80),
      crouch,
      v4,
      (int)v3,
      (vostok::physics::bullet_character_controller *)crouch);
    *(_BYTE *)(crouch + 498) = 1;
  }
  vostok::physics::capsule_bottom_to_center_position((const btVector3 *)&q, v3, (int)v6);
  btMatrix3x3::getRotation((btMatrix3x3 *)(crouch + 112), &q);
  btMatrix3x3::setRotation(&q, &v7);
  v8 = v6[0];
  v9 = v6[1];
  v10 = v6[2];
  v11 = v6[3];
  btCollisionObject::setWorldTransform((btCollisionObject *)&v7, (btVector3 *)(crouch + 96));
}
