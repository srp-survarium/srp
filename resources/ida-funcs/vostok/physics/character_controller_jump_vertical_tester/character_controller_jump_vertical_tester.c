void __thiscall vostok::physics::character_controller_jump_vertical_tester::character_controller_jump_vertical_tester(
        vostok::physics::character_controller_jump_vertical_tester *this,
        unsigned int up_vector,
        btCollisionObject *object,
        btCapsuleShape *shape)
{
  btVector3 *v4; // ebx
  _STLP_atomic_freelist::item *v5; // eax
  _STLP_atomic_freelist::item *v6; // ecx
  btCapsuleShape *v7; // eax

  v4 = (btVector3 *)up_vector;
  *(_DWORD *)(up_vector + 16) = 0;
  up_vector = 2560;
  v5 = stlp_std::__node_alloc::allocate(&up_vector);
  v4->mVec128.m128_i32[0] = (int)v5;
  v4->mVec128.m128_i32[3] = (int)v5;
  v4->mVec128.m128_i32[2] = (int)v5;
  v6 = v5 + 640;
  v7 = shape;
  v4->mVec128.m128_i32[1] = (int)v6;
  v4[2] = (btVector3)vostok::physics::bullet_character_controller::ms_up_vector.mVec128;
  v4[3].mVec128.m128_i32[2] = 0;
  v4[3].mVec128.m128_i32[0] = (int)v7;
  v4[3].mVec128.m128_i32[1] = (int)object;
}
