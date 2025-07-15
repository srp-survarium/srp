void __usercall survarium::object_wire::~object_wire(survarium::object_wire *this@<ecx>, const char *a2@<esi>)
{
  vostok::math::float3 **p_m_points; // edi
  char *m_points; // eax
  const char *v5; // [esp+0h] [ebp-8h]
  unsigned int v6; // [esp+4h] [ebp-4h]

  p_m_points = &this->m_points;
  this->__vftable = (survarium::object_wire_vtbl *)&survarium::object_wire::`vftable';
  m_points = (char *)this->m_points;
  if ( m_points )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      m_points,
      a2,
      v5,
      v6);
    *p_m_points = 0;
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_visual);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
