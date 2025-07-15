void __thiscall survarium::booby_trap_set_core::~booby_trap_set_core(survarium::booby_trap_set_core *this)
{
  survarium::booby_trap_set_core::apply_damage *m_begin; // ecx
  vostok::memory::doug_lea_allocator *v2; // eax
  survarium::game_camera *v3; // ecx
  vostok::memory::doug_lea_allocator *v4; // eax
  survarium::booby_trap_set_core::apply_damage *j; // [esp+14h] [ebp-2Ch]
  char **p_m_traps_buffer; // [esp+18h] [ebp-28h]
  survarium::booby_trap_set_core::apply_damage *i; // [esp+30h] [ebp-10h]
  const void *damage_parms_buffer; // [esp+3Ch] [ebp-4h] BYREF

  this->__vftable = (survarium::booby_trap_set_core_vtbl *)&survarium::booby_trap_set_core::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  damage_parms_buffer = this->m_damage_parameters.m_begin;
  for ( i = this->m_damage_parameters.m_begin; i != this->m_damage_parameters.m_end; ++i )
    ;
  m_begin = this->m_damage_parameters.m_begin;
  this->m_damage_parameters.m_end = m_begin;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_begin);
  ___free_helper_Vdoug_lea_allocator_memory_vostok____CBX_memory_vostok__YAXAAVdoug_lea_allocator_01_AAPBX_Z(
    v2,
    (void **)&damage_parms_buffer);
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>>::clear(&this->m_traps);
  p_m_traps_buffer = (char **)&this->m_traps_buffer;
  survarium::weapon_user_dead_state::finalize(v3);
  if ( this->m_traps_buffer )
  {
    vostok::memory::doug_lea_allocator::free_impl(v4, *p_m_traps_buffer);
    *p_m_traps_buffer = 0;
  }
  for ( j = this->m_damage_parameters.m_begin; j != this->m_damage_parameters.m_end; ++j )
    ;
  this->m_damage_parameters.m_end = this->m_damage_parameters.m_begin;
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>>::clear(&this->m_traps);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_action_behaviuor);
  survarium::interactive_object::~interactive_object(this);
}
