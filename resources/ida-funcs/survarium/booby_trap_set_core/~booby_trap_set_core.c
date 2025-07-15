void __thiscall survarium::booby_trap_set_core::~booby_trap_set_core(survarium::booby_trap_set_core *this)
{
  survarium::booby_trap_set_core::apply_damage *m_begin; // eax
  vostok::memory::doug_lea_allocator *v3; // ecx
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *i; // esi
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> > *v5; // ecx
  const char *v6; // [esp+0h] [ebp-10h]
  const char *v7; // [esp+4h] [ebp-Ch]
  unsigned int v8; // [esp+8h] [ebp-8h]

  m_begin = this->m_damage_parameters.m_begin;
  v3 = (vostok::memory::doug_lea_allocator *)m_begin;
  this->__vftable = (survarium::booby_trap_set_core_vtbl *)&survarium::booby_trap_set_core::`vftable';
  this->m_damage_parameters.m_end = m_begin;
  if ( m_begin )
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)m_begin,
      (int)survarium::g_allocator,
      m_begin->body_part,
      v6,
      v7,
      v8);
  for ( i = this->m_traps.m_begin; i != this->m_traps.m_end; ++i )
    vostok::intrusive_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(i);
  this->m_traps.m_end = this->m_traps.m_begin;
  if ( this->m_traps_buffer )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      v3,
      (int)survarium::g_allocator,
      (char *)this->m_traps_buffer,
      v6,
      v7,
      v8);
    this->m_traps_buffer = 0;
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_material_manager);
  this->m_damage_parameters.m_end = this->m_damage_parameters.m_begin;
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>>::~buffer_vector<vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>>(
    v5,
    &this->m_traps.m_begin);
  vostok::resources::unmanaged_resource::~unmanaged_resource(&this->survarium::inventory_item);
}
