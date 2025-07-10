void __usercall survarium::player::set_use_physics_controller_for_current(
        survarium::player *this@<ecx>,
        char value@<al>)
{
  btTransform *transform; // eax
  vostok::physics::bt_character_controller *physics_controller; // ebx
  const btTransform *v5; // eax
  btMatrix3x3 *v6; // ecx
  vostok::math::float4x4 m; // [esp+10h] [ebp-C0h] BYREF
  btTransform v8; // [esp+50h] [ebp-80h] BYREF

  if ( byte_10F36[(_DWORD)this] != value )
  {
    byte_10F36[(_DWORD)this] = value;
    if ( value )
    {
      transform = vostok::physics::bullet_character_controller::get_transform(
                    *(vostok::physics::bullet_character_controller **)((char *)&dword_10DC8 + (_DWORD)this),
                    &v8,
                    **(_DWORD **)((char *)&dword_10DC8 + (_DWORD)this));
      vostok::physics::from_bullet(transform);
      physics_controller = this->m_current.physics_controller;
      vostok::physics::bullet_character_controller::insert(
        physics_controller->m_bt_controller,
        physics_controller->m_bt_physics_world->m_dynamicsWorld);
      v5 = vostok::physics::from_vostok(&m);
      vostok::physics::bullet_character_controller::set_transform(physics_controller->m_bt_controller, v5, v6);
    }
    else
    {
      vostok::physics::bullet_character_controller::remove(
        (vostok::physics::bullet_character_controller *)this->m_current.physics_controller,
        this->m_current.physics_controller->m_bt_controller);
    }
  }
}
