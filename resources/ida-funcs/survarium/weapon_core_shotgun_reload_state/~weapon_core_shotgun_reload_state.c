void __usercall survarium::weapon_core_shotgun_reload_state::~weapon_core_shotgun_reload_state(
        survarium::weapon_core_shotgun_reload_state *this@<ecx>,
        int a2@<eax>)
{
  bool v3; // zf
  vostok::resources::unmanaged_resource *v4; // ebx
  vostok::ai::fsm *v5; // ecx
  vostok::ai::fsm *v6; // [esp-4h] [ebp-14h]
  const char *v7; // [esp+0h] [ebp-10h]
  const char *v8; // [esp+4h] [ebp-Ch]
  unsigned int v9; // [esp+8h] [ebp-8h]
  vostok::ai::fsm_state *pointer; // [esp+Ch] [ebp-4h] BYREF

  v3 = *(_BYTE *)(a2 + 308) == 0;
  v4 = (vostok::resources::unmanaged_resource *)(a2 + 24);
  *(_DWORD *)a2 = &survarium::weapon_core_shotgun_reload_state::`vftable'{for `vostok::ai::fsm_state'};
  *(_DWORD *)(a2 + 24) = &survarium::weapon_core_shotgun_reload_state::`vftable'{for `vostok::resources::unmanaged_resource'};
  if ( !v3 )
  {
    vostok::ai::fsm::clear_transitions((vostok::ai::fsm *)this, *(_DWORD *)(a2 + 304));
    while ( 1 )
    {
      pointer = vostok::ai::fsm::pop_state(v5, *(_DWORD **)(a2 + 304));
      if ( !pointer )
        break;
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        survarium::g_allocator,
        &pointer,
        v7,
        v8,
        v9);
      v5 = v6;
    }
  }
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::fsm>(
    survarium::g_allocator,
    (vostok::ai::fsm **)(a2 + 304));
  vostok::resources::unmanaged_resource::~unmanaged_resource(v4);
}
