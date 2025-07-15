void __userpurge vostok::physics::bullet_character_controller::bullet_character_controller(
        vostok::physics::bullet_character_controller *this@<ecx>,
        unsigned int stand_shape_dim,
        unsigned int crouch_shape_dim,
        vostok::physics::character_controller_can_stand_tester *collisionFilterGroup,
        __int16 collisionFilterMask,
        vostok::memory::base_allocator *allocator)
{
  unsigned int v6; // ebx
  _DWORD *v7; // edi
  float *v8; // eax
  double v9; // st7
  float *v10; // eax
  btPairCachingGhostObject *v11; // ecx
  btConvexInternalShape *v12; // ecx
  _STLP_atomic_freelist::item *v13; // eax
  _STLP_atomic_freelist::item *v14; // eax
  _STLP_atomic_freelist::item *v15; // eax
  unsigned int v16; // ecx
  _STLP_atomic_freelist::item *v17; // eax
  vostok::physics::character_controller_jump_vertical_tester *v18; // ecx
  float v19; // xmm0_4
  vostok::memory::base_allocator *v20; // [esp+0h] [ebp-10h]

  v6 = stand_shape_dim;
  v20 = vostok::physics::g_allocator;
  v7 = (_DWORD *)(stand_shape_dim + 4);
  *(_DWORD *)stand_shape_dim = &btActionInterface::`vftable';
  vostok::physics::base_physics_object::base_physics_object((vostok::physics::base_physics_object *)this, v7, v20);
  *(_DWORD *)(v6 + 20) = 0;
  v8 = (float *)crouch_shape_dim;
  *(_DWORD *)v6 = &vostok::physics::bullet_character_controller::`vftable'{for `btActionInterface'};
  *v7 = &vostok::physics::bullet_character_controller::`vftable'{for `vostok::physics::base_physics_object'};
  *(_DWORD *)(v6 + 32) = 0;
  *(_DWORD *)(v6 + 36) = 0;
  *(_DWORD *)(v6 + 40) = 0;
  *(_DWORD *)(v6 + 44) = 0;
  *(_DWORD *)(v6 + 48) = 0;
  *(_DWORD *)(v6 + 52) = 0;
  *(_DWORD *)(v6 + 56) = 0;
  *(_DWORD *)(v6 + 60) = 0;
  *(_DWORD *)(v6 + 64) = 0;
  *(_DWORD *)(v6 + 68) = 0;
  *(_DWORD *)(v6 + 72) = 0;
  *(_DWORD *)(v6 + 76) = 0;
  *(float *)(v6 + 80) = *v8;
  v9 = v8[1];
  v10 = (float *)collisionFilterGroup;
  *(float *)(v6 + 84) = v9;
  *(float *)(v6 + 88) = *v10;
  *(float *)(v6 + 92) = v10[1];
  btPairCachingGhostObject::btPairCachingGhostObject(v11, (btPairCachingGhostObject *)(v6 + 96));
  btCapsuleShape::btCapsuleShape((btCapsuleShape *)(v6 + 416), v12, s_bm_current_air_resistance, 1.0);
  *(_BYTE *)(v6 + 496) = 0;
  *(_BYTE *)(v6 + 497) = 0;
  *(_BYTE *)(v6 + 498) = 1;
  *(_BYTE *)(v6 + 499) = 0;
  *(_BYTE *)(v6 + 500) = 0;
  *(_DWORD *)(v6 + 528) = 0;
  stand_shape_dim = 2560;
  v13 = stlp_std::__node_alloc::allocate(&stand_shape_dim);
  *(_DWORD *)(v6 + 512) = v13;
  *(_DWORD *)(v6 + 524) = v13;
  *(_DWORD *)(v6 + 520) = v13;
  *(_DWORD *)(v6 + 516) = v13 + 640;
  *(btVector3 *)(v6 + 544) = (btVector3)vostok::physics::bullet_character_controller::ms_up_vector.mVec128;
  *(_DWORD *)(v6 + 568) = 0;
  *(_DWORD *)(v6 + 564) = v6 + 96;
  *(_DWORD *)(v6 + 560) = v6 + 416;
  vostok::physics::character_controller_move_step_tester::character_controller_move_step_tester(
    (vostok::physics::character_controller_move_step_tester *)(v6 + 416),
    v6 + 576,
    (btCollisionObject *)(v6 + 96),
    (btCapsuleShape *)(v6 + 416));
  *(_DWORD *)(v6 + 800) = 0;
  stand_shape_dim = 3072;
  v14 = stlp_std::__node_alloc::allocate(&stand_shape_dim);
  *(_DWORD *)(v6 + 784) = v14;
  *(_DWORD *)(v6 + 796) = v14;
  *(_DWORD *)(v6 + 792) = v14;
  *(_DWORD *)(v6 + 788) = v14 + 768;
  *(btVector3 *)(v6 + 816) = (btVector3)vostok::physics::bullet_character_controller::ms_up_vector.mVec128;
  *(_DWORD *)(v6 + 840) = 0;
  *(_DWORD *)(v6 + 832) = v6 + 416;
  *(_DWORD *)(v6 + 836) = v6 + 96;
  *(_DWORD *)(v6 + 864) = 0;
  stand_shape_dim = 1536;
  v15 = stlp_std::__node_alloc::allocate(&stand_shape_dim);
  *(_DWORD *)(v6 + 848) = v15;
  *(_DWORD *)(v6 + 860) = v15;
  *(_DWORD *)(v6 + 856) = v15;
  *(_DWORD *)(v6 + 852) = v15 + 384;
  v16 = crouch_shape_dim;
  *(btVector3 *)(v6 + 880) = (btVector3)vostok::physics::bullet_character_controller::ms_up_vector.mVec128;
  *(_DWORD *)(v6 + 904) = 0;
  *(_DWORD *)(v6 + 896) = v6 + 416;
  *(_DWORD *)(v6 + 900) = v6 + 96;
  vostok::physics::character_controller_can_stand_tester::character_controller_can_stand_tester(
    collisionFilterGroup,
    v6 + 912,
    (btCollisionObject *)&vostok::physics::bullet_character_controller::ms_up_vector,
    (btCapsuleShape *)(v6 + 96),
    COERCE_FLOAT(v6 + 416),
    COERCE_INT(*(float *)(v16 + 4) - *(float *)&collisionFilterGroup->m_cache.m_buffer.m_end));
  *(_DWORD *)(v6 + 992) = 0;
  crouch_shape_dim = 2560;
  v17 = stlp_std::__node_alloc::allocate(&crouch_shape_dim);
  *(_DWORD *)(v6 + 1008) = 0;
  *(_DWORD *)(v6 + 976) = v17;
  *(_DWORD *)(v6 + 988) = v17;
  *(_DWORD *)(v6 + 984) = v17;
  *(_DWORD *)(v6 + 980) = v17 + 640;
  *(_DWORD *)(v6 + 1000) = v6 + 416;
  *(_DWORD *)(v6 + 1004) = v6 + 96;
  vostok::physics::character_controller_jump_vertical_tester::character_controller_jump_vertical_tester(
    (vostok::physics::character_controller_jump_vertical_tester *)&v17[640],
    v6 + 1024,
    (btCollisionObject *)(v6 + 96),
    (btCapsuleShape *)(v6 + 416));
  vostok::physics::character_controller_jump_vertical_tester::character_controller_jump_vertical_tester(
    v18,
    v6 + 1088,
    (btCollisionObject *)(v6 + 96),
    (btCapsuleShape *)(v6 + 416));
  *(_WORD *)(v6 + 1152) = 2084;
  *(float *)(v6 + 1156) = satisfaction_equality_tolerance;
  *(_WORD *)(v6 + 1154) = 3;
  *(float *)(v6 + 1160) = FLOAT_9_8000002;
  *(_BYTE *)(v6 + 1164) = 0;
  *(btVector3 *)(v6 + 1168) = (btVector3)vostok::physics::bullet_character_controller::ms_up_vector.mVec128;
  *(_DWORD *)(v6 + 1184) = 0;
  *(_DWORD *)(v6 + 1192) = 0;
  *(_DWORD *)(v6 + 1232) = 0;
  *(_DWORD *)(v6 + 1236) = 0;
  *(_DWORD *)(v6 + 1240) = 0;
  *(_DWORD *)(v6 + 1244) = 0;
  v19 = s_spot_max_distance;
  *(_DWORD *)(v6 + 344) = v6 + 4;
  *(_BYTE *)(v6 + 1248) = -1;
  *(_DWORD *)(v6 + 312) = 16;
  *(float *)(v6 + 332) = v19;
}
