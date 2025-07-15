void __userpurge vostok::physics::old_bullet_character_controller::old_bullet_character_controller(
        vostok::physics::old_bullet_character_controller *this@<ecx>,
        int a2@<esi>,
        const vostok::math::float2 *stand_shape_dim,
        btPairCachingGhostObject *crouch_shape_dim,
        __int16 collisionFilterGroup,
        __int16 collisionFilterMask,
        vostok::memory::base_allocator *allocator)
{
  float v7; // xmm0_4
  btConvexInternalShape *v8; // ecx
  float v9; // eax
  float v10; // xmm0_4
  vostok::buffer_vector<vostok::physics::old_bullet_character_controller::sweep_test_cache_item *> *v11; // ecx
  unsigned int v12; // edx
  int v13; // eax
  vostok::memory::base_allocator *v14; // [esp+0h] [ebp-10h]

  v14 = vostok::physics::g_allocator;
  *(_DWORD *)a2 = &btActionInterface::`vftable';
  vostok::physics::base_physics_object::base_physics_object(
    (vostok::physics::base_physics_object *)this,
    (_DWORD *)(a2 + 4),
    v14);
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)a2 = &vostok::physics::old_bullet_character_controller::`vftable'{for `btActionInterface'};
  *(_DWORD *)(a2 + 4) = &vostok::physics::old_bullet_character_controller::`vftable'{for `vostok::physics::base_physics_object'};
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 44) = 0;
  *(_DWORD *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 52) = 0;
  *(_DWORD *)(a2 + 56) = 0;
  *(_DWORD *)(a2 + 60) = 0;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 68) = 0;
  *(_DWORD *)(a2 + 72) = 0;
  *(_DWORD *)(a2 + 76) = 0;
  *(_DWORD *)(a2 + 80) = 0;
  *(_DWORD *)(a2 + 84) = 0;
  *(_DWORD *)(a2 + 88) = 0;
  *(_DWORD *)(a2 + 92) = 0;
  *(_DWORD *)(a2 + 96) = 0;
  *(_DWORD *)(a2 + 112) = 0;
  *(_DWORD *)(a2 + 116) = 0;
  *(_DWORD *)(a2 + 120) = 0;
  *(_DWORD *)(a2 + 124) = 0;
  v7 = SNaN;
  *(float *)(a2 + 128) = SNaN;
  *(float *)(a2 + 132) = v7;
  *(vostok::math::float2 *)(a2 + 136) = *stand_shape_dim;
  *(float *)(a2 + 144) = *(float *)&crouch_shape_dim->__vftable;
  *(float *)(a2 + 148) = *((float *)&crouch_shape_dim->__vftable + 1);
  btPairCachingGhostObject::btPairCachingGhostObject(crouch_shape_dim, (btPairCachingGhostObject *)(a2 + 160));
  btCapsuleShape::btCapsuleShape((btCapsuleShape *)(a2 + 480), v8, s_bm_current_air_resistance, 1.0);
  *(float *)(a2 + 568) = FLOAT_9_8000002;
  *(_WORD *)(a2 + 562) = 2084;
  *(_BYTE *)(a2 + 560) = 0;
  *(_BYTE *)(a2 + 572) = 0;
  *(_BYTE *)(a2 + 573) = 0;
  *(_BYTE *)(a2 + 574) = 0;
  *(_DWORD *)(a2 + 576) = 0;
  *(_WORD *)(a2 + 564) = 3;
  *(_DWORD *)(a2 + 584) = 0;
  *(_DWORD *)(a2 + 624) = 0;
  *(_DWORD *)(a2 + 628) = 0;
  *(_DWORD *)(a2 + 632) = 0;
  *(_DWORD *)(a2 + 636) = 0;
  *(_BYTE *)(a2 + 640) = -1;
  *(_DWORD *)(a2 + 4752) = a2 + 4764;
  *(_DWORD *)(a2 + 4756) = a2 + 4764;
  *(_DWORD *)(a2 + 4760) = a2 + 4892;
  vostok::physics::character_controller_can_stand_tester::character_controller_can_stand_tester(
    (vostok::physics::character_controller_can_stand_tester *)crouch_shape_dim,
    a2 + 4896,
    (btCollisionObject *)&vostok::physics::old_bullet_character_controller::m_up_vector,
    (btCapsuleShape *)(a2 + 160),
    v9,
    COERCE_INT(stand_shape_dim->y - *((float *)&crouch_shape_dim->__vftable + 1)));
  v10 = s_spot_max_distance;
  *(_DWORD *)(a2 + 376) = 16;
  *(float *)(a2 + 396) = v10;
  *(_DWORD *)(a2 + 408) = a2 + 4;
  vostok::buffer_vector<vostok::physics::old_bullet_character_controller::sweep_test_cache_item *>::resize(
    v11,
    (int *)(a2 + 4752));
  v12 = 0;
  v13 = a2 + 656;
  do
  {
    *(_BYTE *)(v13 + 117) = 0;
    *(_DWORD *)(v12 + *(_DWORD *)(a2 + 4752)) = v13;
    v12 += 4;
    v13 += 128;
  }
  while ( v12 < 0x80 );
  *(_DWORD *)(a2 + 4968) = 0;
  *(_DWORD *)(a2 + 4960) = 0;
  *(_DWORD *)(a2 + 4964) = 0;
}
