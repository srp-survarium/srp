void __thiscall survarium::client_player_state::update_transform(
        survarium::client_player_state *this,
        survarium::client_player_state *thisa)
{
  vostok::physics::bullet_character_controller *physics_controller; // ecx
  btTransform *transform; // eax
  btMatrix3x3 *v4; // ecx
  vostok::math::float4x4 v5; // [esp+10h] [ebp-80h] BYREF
  btTransform v6; // [esp+50h] [ebp-40h] BYREF

  physics_controller = (vostok::physics::bullet_character_controller *)thisa->physics_controller;
  if ( BYTE1(physics_controller->__vftable[21].debugDraw) )
  {
    transform = vostok::physics::bullet_character_controller::get_transform(
                  physics_controller,
                  &v6,
                  (int)physics_controller->__vftable);
    vostok::physics::from_bullet(transform, v4, &v5);
    qmemcpy((void *)&thisa->transform, &v5, sizeof(thisa->transform));
  }
  qmemcpy((void *)&thisa->previous_transform, &thisa->transform, sizeof(thisa->previous_transform));
}
