void __usercall survarium::base_game_scene::init_physics(survarium::base_game_scene *this@<ecx>, int a2@<edi>)
{
  vostok::memory::base_allocator *v2; // esi
  vostok::physics::bullet_physics_world *v3; // ecx
  int v4; // eax
  vostok::physics::engine *v5; // [esp+0h] [ebp-4h]

  if ( a2 )
    v2 = (vostok::memory::base_allocator *)(a2 + 16);
  else
    v2 = 0;
  if ( vostok::memory::g_mt_allocator.call_malloc(&vostok::memory::g_mt_allocator, 96) )
    vostok::physics::bullet_physics_world::bullet_physics_world(v3, v2, v5);
  else
    v4 = 0;
  *(_DWORD *)(a2 + 176) = v4;
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(v4);
}
