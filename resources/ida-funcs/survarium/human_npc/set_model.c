void __usercall survarium::human_npc::set_model(survarium::human_npc *this@<ecx>, int a2@<esi>)
{
  survarium::human_npc_vtbl *v2; // ecx
  survarium::human_npc_vtbl *v3; // eax
  vostok::resources::unmanaged_resource *v4; // edx
  int v5; // eax

  v2 = this->vostok::ai::npc::__vftable;
  v3 = 0;
  if ( v2 )
  {
    v3 = v2;
    _InterlockedExchangeAdd((volatile signed __int32 *)&v2[1].attack_melee, 1u);
  }
  v4 = *(vostok::resources::unmanaged_resource **)(a2 + 348);
  *(_DWORD *)(a2 + 348) = v3;
  if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
  if ( a2 )
    v5 = a2 + 36;
  else
    v5 = 0;
  *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 348) + 276) + 36) + 8) = v5;
  survarium::damage_model::subscribe_on_affect(
    *(survarium::damage_model **)(*(_DWORD *)(a2 + 348) + 272),
    affects_type_death,
    (survarium::affect_subscriber *const)(a2 + 664));
}
