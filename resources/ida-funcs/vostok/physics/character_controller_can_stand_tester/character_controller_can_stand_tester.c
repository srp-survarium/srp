void __thiscall vostok::physics::character_controller_can_stand_tester::character_controller_can_stand_tester(
        vostok::physics::character_controller_can_stand_tester *this,
        unsigned int up_vector,
        btCollisionObject *object,
        btCapsuleShape *shape,
        float stand_crouch_difference,
        int a6)
{
  float *v6; // ebx
  _STLP_atomic_freelist::item *v7; // eax
  btCollisionObject *v8; // esi
  int v9; // xmm0_4
  _STLP_atomic_freelist::item *v10; // ecx
  float v11; // eax

  v6 = (float *)up_vector;
  *(_DWORD *)(up_vector + 16) = 0;
  up_vector = 1536;
  v7 = stlp_std::__node_alloc::allocate(&up_vector);
  v8 = object;
  v9 = a6;
  *(_DWORD *)v6 = v7;
  *((_DWORD *)v6 + 3) = v7;
  *((_DWORD *)v6 + 2) = v7;
  v10 = v7 + 384;
  v11 = stand_crouch_difference;
  *((_DWORD *)v6 + 1) = v10;
  v6[8] = *(float *)&v8->__vftable;
  v8 = (btCollisionObject *)((char *)v8 + 4);
  v6[9] = *(float *)&v8->__vftable;
  v8 = (btCollisionObject *)((char *)v8 + 4);
  v6[10] = *(float *)&v8->__vftable;
  v6[11] = *((float *)&v8->__vftable + 1);
  v6[14] = 0.0;
  v6[12] = v11;
  *((_DWORD *)v6 + 13) = shape;
  *((_DWORD *)v6 + 15) = v9;
}
