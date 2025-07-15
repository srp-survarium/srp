void __thiscall vostok::physics::character_controller_move_step_tester::character_controller_move_step_tester(
        vostok::physics::character_controller_move_step_tester *this,
        unsigned int up_vector,
        btCollisionObject *object,
        btCapsuleShape *shape)
{
  unsigned int v4; // ebx
  _STLP_atomic_freelist::item *v5; // eax
  btSphereShape *v6; // ecx
  btCapsuleShape *v7; // eax
  float radius; // [esp+0h] [ebp-10h]

  v4 = up_vector;
  *(_DWORD *)(up_vector + 16) = 0;
  up_vector = 3072;
  v5 = stlp_std::__node_alloc::allocate(&up_vector);
  *(_DWORD *)v4 = v5;
  *(_DWORD *)(v4 + 12) = v5;
  *(_DWORD *)(v4 + 8) = v5;
  *(_DWORD *)(v4 + 4) = v5 + 768;
  btCylinderShape::btCylinderShape((btCylinderShape *)(v4 + 32));
  radius = ((double (__thiscall *)(unsigned int))*(_DWORD *)(*(_DWORD *)(v4 + 32) + 84))(v4 + 32);
  btSphereShape::btSphereShape(v6, radius);
  v7 = shape;
  *(btVector3 *)(v4 + 176) = (btVector3)vostok::physics::bullet_character_controller::ms_up_vector.mVec128;
  *(_DWORD *)(v4 + 200) = 0;
  *(_DWORD *)(v4 + 192) = v7;
  *(_DWORD *)(v4 + 196) = object;
}
