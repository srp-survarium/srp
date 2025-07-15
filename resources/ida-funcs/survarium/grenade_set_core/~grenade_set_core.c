void __thiscall survarium::grenade_set_core::~grenade_set_core(survarium::grenade_set_core *this)
{
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base> > *p_m_grenades; // edi
  vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base> *i; // esi
  const char *v4; // [esp+0h] [ebp-10h]
  const char *v5; // [esp+4h] [ebp-Ch]
  unsigned int v6; // [esp+8h] [ebp-8h]

  p_m_grenades = &this->m_grenades;
  this->__vftable = (survarium::grenade_set_core_vtbl *)&survarium::grenade_set_core::`vftable';
  for ( i = this->m_grenades.m_begin; i != p_m_grenades->m_end; ++i )
    vostok::intrusive_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(i);
  p_m_grenades->m_end = p_m_grenades->m_begin;
  if ( this->m_grenades_buffer )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      (char *)this->m_grenades_buffer,
      v4,
      v5,
      v6);
    this->m_grenades_buffer = 0;
  }
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base>>::~buffer_vector<vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base>>(
    (vostok::buffer_vector<vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base> > *)this,
    &p_m_grenades->m_begin);
  vostok::resources::unmanaged_resource::~unmanaged_resource(&this->survarium::inventory_item);
}
