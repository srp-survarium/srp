void __thiscall survarium::player::insert_alive(survarium::player *this, survarium::player *thisa)
{
  vostok::math::float4x4 *v2; // ecx
  bool v3; // zf
  int v4; // eax
  vostok::math::float3 *angles; // eax
  vostok::math::float4x4 *rotation_y; // eax
  const btTransform *v7; // eax
  const btTransform *v8; // eax
  survarium::damage_model **v9; // eax
  const vostok::math::float4x4 *v10; // xmm0_4
  vostok::math::float3 *v11; // [esp+4h] [ebp-70h]
  vostok::math::axis_rotation_order v12; // [esp+8h] [ebp-6Ch]
  int v13; // [esp+1Ch] [ebp-58h]
  vostok::physics::bt_character_controller *physics_controller; // [esp+1Ch] [ebp-58h]
  survarium::player_input v15; // [esp+20h] [ebp-54h] BYREF
  _QWORD v16[8]; // [esp+34h] [ebp-40h] BYREF

  byte_10F37[(_DWORD)thisa] = 1;
  survarium::player_input::player_input(&v15);
  v3 = *(int *)((char *)&dword_10EF4 + (_DWORD)thisa) == 0;
  thisa->m_input.angular_velocity = *(vostok::math::float2 *)v4;
  thisa->m_input.angular_acceleration = *(vostok::math::float2 *)(v4 + 8);
  *(int *)((char *)&dword_10EE0 + (_DWORD)thisa) = *(_DWORD *)(v4 + 16);
  if ( !v3 )
  {
    angles = vostok::math::float4x4::get_angles(v2, v11, v12);
    rotation_y = vostok::math::create_rotation_y(v16, COERCE_VOSTOK_MATH_FLOAT4X4_(angles->y));
    survarium::game_camera::set_position_direction(
      (const vostok::math::float3 *)&thisa->m_current.transform.lines[3],
      (const vostok::math::float3 *)&rotation_y->lines[2],
      (survarium::game_camera *)(*(int *)((char *)&dword_10EF4 + (_DWORD)thisa) + 4));
  }
  if ( !byte_10F80[(_DWORD)thisa] )
  {
    (*(void (__thiscall **)(_DWORD, vostok::math::float4x4 *))(**(_DWORD **)(*(int *)((char *)&dword_10EF0
                                                                                    + (_DWORD)thisa)
                                                                           + 36)
                                                             + 24))(
      *(_DWORD *)(*(int *)((char *)&dword_10EF0 + (_DWORD)thisa) + 36),
      &thisa->m_current.transform);
    (*(void (__thiscall **)(_DWORD, _DWORD, int, int))(**(_DWORD **)(*(int *)((char *)&dword_10F00 + (_DWORD)thisa) + 176)
                                                     + 40))(
      *(_DWORD *)(*(int *)((char *)&dword_10F00 + (_DWORD)thisa) + 176),
      *(_DWORD *)(*(int *)((char *)&dword_10EF0 + (_DWORD)thisa) + 36),
      104,
      17);
  }
  v13 = *(int *)((char *)&dword_10DC8 + (_DWORD)thisa);
  vostok::physics::bullet_character_controller::insert(
    *(vostok::physics::bullet_character_controller **)v13,
    *(btDynamicsWorld **)(*(_DWORD *)(v13 + 4) + 52));
  v7 = vostok::physics::from_vostok((const vostok::math::float4x4 *)&byte_10D44[(_DWORD)thisa]);
  vostok::physics::bullet_character_controller::set_transform(
    *(vostok::physics::bullet_character_controller **)v13,
    v7,
    (btMatrix3x3 *)v13);
  if ( byte_10F36[(_DWORD)thisa] )
  {
    physics_controller = thisa->m_current.physics_controller;
    vostok::physics::bullet_character_controller::insert(
      physics_controller->m_bt_controller,
      physics_controller->m_bt_physics_world->m_dynamicsWorld);
    v8 = vostok::physics::from_vostok((const vostok::math::float4x4 *)&byte_10D44[(_DWORD)thisa]);
    vostok::physics::bullet_character_controller::set_transform(
      physics_controller->m_bt_controller,
      v8,
      (btMatrix3x3 *)physics_controller);
  }
  v9 = (survarium::damage_model **)thisa->damage_model(thisa);
  survarium::damage_model::reset(*v9);
  survarium::player_stamina::reset((survarium::player_stamina *)((char *)&unk_10E30 + (_DWORD)thisa));
  v10 = clear_value;
  *(int *)((char *)&dword_10F1C + (_DWORD)thisa) = (int)clear_value;
  *(int *)((char *)&dword_10F18 + (_DWORD)thisa) = (int)v10;
  for ( *(int *)((char *)&dword_10F20 + (_DWORD)thisa) = (int)v10;
        *(int *)((char *)&dword_10E28 + (_DWORD)thisa) != *(int *)((char *)&dword_10E2C + (_DWORD)thisa);
        *(int *)((char *)&dword_10E2C + (_DWORD)thisa) = (unsigned int)(*(int *)((char *)&dword_10E2C + (_DWORD)thisa)
                                                                      + 1)
                                                       % *(int *)((char *)&dword_10E24 + (_DWORD)thisa) )
  {
    ;
  }
  thisa->m_is_alive = 1;
}
