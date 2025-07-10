void __thiscall vostok::physics::bt_character_controller::initialize(
        vostok::physics::bt_character_controller *this,
        vostok::physics::bt_character_controller *thisa)
{
  btPairCachingGhostObject *v2; // ecx
  btPairCachingGhostObject *v3; // edi
  vostok::physics::bullet_character_controller *v4; // esi
  vostok::physics::bullet_character_controller *v5; // eax
  __int16 v6; // [esp+0h] [ebp-20h]
  __int16 v7; // [esp+4h] [ebp-1Ch]
  vostok::math::float2 crouch_shape_dim; // [esp+10h] [ebp-10h] BYREF
  vostok::math::float2 stand_shape_dim; // [esp+18h] [ebp-8h] BYREF

  if ( thisa->m_bt_physics_world->m_allocator->call_malloc(thisa->m_bt_physics_world->m_allocator, 320u) )
    v3 = btPairCachingGhostObject::btPairCachingGhostObject(v2);
  else
    v3 = 0;
  v3->m_collisionFlags = 16;
  v3->m_friction = 100.0;
  v4 = (vostok::physics::bullet_character_controller *)thisa->m_bt_physics_world->m_allocator->call_malloc(
                                                         thisa->m_bt_physics_world->m_allocator,
                                                         272u);
  if ( v4 )
  {
    crouch_shape_dim = (vostok::math::float2)0x3F8CCCCD3F666666LL;
    stand_shape_dim = (vostok::math::float2)0x3FE666663F666666LL;
    vostok::physics::bullet_character_controller::bullet_character_controller(
      v4,
      &stand_shape_dim,
      &crouch_shape_dim,
      v3,
      v6,
      v7);
    thisa->m_bt_controller = v5;
  }
  else
  {
    thisa->m_bt_controller = 0;
  }
}
