void __userpurge vostok::physics::bullet_physics_world::bullet_physics_world(
        vostok::physics::bullet_physics_world *this@<ecx>,
        int a2@<eax>,
        vostok::physics::engine *allocator,
        vostok::physics::engine *engine)
{
  float v4; // xmm0_4
  __int64 v5; // [esp+0h] [ebp-Ch]

  *(_DWORD *)a2 = &vostok::physics::bullet_physics_world::`vftable';
  *(_QWORD *)(a2 + 4) = 0;
  *(_QWORD *)(a2 + 12) = 0;
  v4 = infinity_7;
  *(_BYTE *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_BYTE *)(a2 + 24) = (_BYTE)allocator;
  *(_DWORD *)(a2 + 12) = a2 + 4;
  *(_DWORD *)(a2 + 16) = a2 + 4;
  *(_DWORD *)(a2 + 60) = allocator;
  *(_DWORD *)(a2 + 28) = &vostok::memory::g_mt_allocator;
  *(float *)&v5 = v4;
  *((float *)&v5 + 1) = v4;
  *(_QWORD *)(a2 + 64) = v5;
  *(float *)(a2 + 72) = v4;
  *(float *)&v5 = -v4;
  *((float *)&v5 + 1) = -v4;
  *(_QWORD *)(a2 + 76) = v5;
  *(float *)(a2 + 84) = -v4;
}
