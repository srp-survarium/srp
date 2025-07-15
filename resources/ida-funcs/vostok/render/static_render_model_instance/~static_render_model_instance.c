void __thiscall vostok::render::static_render_model_instance::~static_render_model_instance(
        vostok::render::static_render_model_instance *this)
{
  const char *v1; // esi
  char **m_sectors_holder; // ebx
  vostok::render::render_model_instance_impl *v4; // ecx
  const char *v5; // [esp+0h] [ebp-10h]
  const char *v6; // [esp+4h] [ebp-Ch]
  unsigned int v7; // [esp+8h] [ebp-8h]

  v1 = (const char *)vostok::render::g_allocator;
  this->__vftable = (vostok::render::static_render_model_instance_vtbl *)&vostok::render::static_render_model_instance::`vftable';
  m_sectors_holder = (char **)this->m_sectors_holder;
  if ( m_sectors_holder )
  {
    if ( *m_sectors_holder )
    {
      vostok::memory::doug_lea_allocator::free_impl(
        (vostok::memory::doug_lea_allocator *)this,
        (int)v1,
        *m_sectors_holder,
        v5,
        v6,
        v7);
      *m_sectors_holder = 0;
    }
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)v1,
      (char *)m_sectors_holder,
      v5,
      v6,
      v7);
    this->m_sectors_holder = 0;
  }
  vostok::memory::delete_array_helper<vostok::memory::doug_lea_allocator,vostok::render::render_surface_instance>(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&this->m_surface_instances,
    (unsigned int)m_sectors_holder,
    (const char *)this,
    v1,
    vostok::render::g_allocator);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_original);
  vostok::render::render_model_instance_impl::~render_model_instance_impl(v4, this);
}
