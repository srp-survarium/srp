void __usercall survarium::human_npc::set_animation_space_graph(survarium::human_npc *this@<ecx>, int a2@<eax>)
{
  survarium::human_npc_vtbl *v2; // ecx
  survarium::human_npc_vtbl *v4; // eax
  vostok::resources::unmanaged_resource *v5; // edx

  v2 = this->vostok::ai::npc::__vftable;
  v4 = 0;
  if ( v2 )
  {
    v4 = v2;
    _InterlockedExchangeAdd((volatile signed __int32 *)&v2[1].attack_melee, 1u);
  }
  v5 = *(vostok::resources::unmanaged_resource **)(a2 + 712);
  *(_DWORD *)(a2 + 712) = v4;
  if ( v5 )
  {
    if ( !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
  }
}
