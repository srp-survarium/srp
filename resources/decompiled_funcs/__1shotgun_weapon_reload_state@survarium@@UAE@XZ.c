void __usercall survarium::shotgun_weapon_reload_state::~shotgun_weapon_reload_state(
        survarium::shotgun_weapon_reload_state *this@<ecx>,
        survarium::weapon_core_shotgun_reload_state *a2@<esi>)
{
  unsigned int m_size; // eax
  vostok::resources::unmanaged_intrusive_base *v3; // eax
  vostok::resources::unmanaged_resource *v4; // ecx
  vostok::ai::fsm_state *next; // eax
  vostok::resources::unmanaged_intrusive_base *v6; // eax
  vostok::resources::unmanaged_resource *v7; // ecx
  survarium::weapon_core_shotgun_reload_state_vtbl *v8; // eax
  survarium::weapon_core_shotgun_reload_state_vtbl *v9; // eax

  m_size = a2[1].transitions.m_size;
  if ( m_size && !_InterlockedExchangeAdd((volatile signed __int32 *)(m_size + 232), 0xFFFFFFFF) )
  {
    v3 = (vostok::resources::unmanaged_intrusive_base *)a2[1].transitions.m_size;
    if ( v3 )
      v4 = (vostok::resources::unmanaged_resource *)&v3[3];
    else
      v4 = 0;
    vostok::resources::unmanaged_intrusive_base::destroy(v3 + 29, v4);
  }
  next = a2[1].next;
  if ( next && !_InterlockedExchangeAdd((volatile signed __int32 *)&next[9].transitions.m_first, 0xFFFFFFFF) )
  {
    v6 = (vostok::resources::unmanaged_intrusive_base *)a2[1].next;
    if ( v6 )
      v7 = (vostok::resources::unmanaged_resource *)&v6[3];
    else
      v7 = 0;
    vostok::resources::unmanaged_intrusive_base::destroy(v6 + 29, v7);
  }
  v8 = a2[1].survarium::weapon_core_base_state::vostok::ai::fsm_state::__vftable;
  if ( v8 && !_InterlockedExchangeAdd((volatile signed __int32 *)&v8[7].execute, 0xFFFFFFFF) )
  {
    v9 = a2[1].survarium::weapon_core_base_state::vostok::ai::fsm_state::__vftable;
    if ( v9 )
    {
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)&v9[7].execute,
        (vostok::resources::unmanaged_resource *)&v9->deserialize);
      survarium::weapon_core_shotgun_reload_state::~weapon_core_shotgun_reload_state(a2);
      return;
    }
    vostok::resources::unmanaged_intrusive_base::destroy((vostok::resources::unmanaged_intrusive_base *)0xE8, 0);
  }
  survarium::weapon_core_shotgun_reload_state::~weapon_core_shotgun_reload_state(a2);
}
