void __usercall survarium::grenade_core::grenade_core(survarium::grenade_core *this@<ecx>, int a2@<esi>)
{
  unsigned int v2; // eax

  *(_DWORD *)a2 = &survarium::tickable_object::`vftable';
  *(_DWORD *)(a2 + 12) = &survarium::serializable_object::`vftable';
  *(_DWORD *)(a2 + 24) = &vostok::collision::game_object::`vftable';
  vostok::resources::unmanaged_resource::unmanaged_resource(
    (vostok::resources::unmanaged_resource *)this,
    (_DWORD *)(a2 + 32),
    fs_iterator_class);
  *(_DWORD *)(a2 + 296) = -1;
  *(_DWORD *)(a2 + 304) = 0;
  *(_WORD *)(a2 + 444) = -1;
  v2 = g_grenade_id++;
  *(_DWORD *)(a2 + 32) = &survarium::grenade_core::`vftable'{for `vostok::resources::unmanaged_resource'};
  *(_DWORD *)(a2 + 452) = v2;
  *(_DWORD *)a2 = &survarium::grenade_core::`vftable'{for `survarium::tickable_object'};
  *(_DWORD *)(a2 + 12) = &survarium::grenade_core::`vftable'{for `survarium::serializable_object'};
  *(_DWORD *)(a2 + 24) = &survarium::grenade_core::`vftable'{for `vostok::collision::game_object'};
  *(_BYTE *)(a2 + 300) = 0;
}
