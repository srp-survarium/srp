vostok::render::stage_atmosphere *__userpurge vostok::render::stage_atmosphere::`vector deleting destructor'@<eax>(
        vostok::render::stage_atmosphere *this@<ecx>,
        vostok::render::hw_buffer_pool *esi0@<esi>,
        char a2)
{
  vostok::render::sphere_geometry *v4; // ecx

  this->__vftable = (vostok::render::stage_atmosphere_vtbl *)&vostok::render::stage_atmosphere::`vftable';
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(&this->m_screen_vertex_geometry);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &this->m_screen_vertex_ib,
    esi0);
  `vector destructor iterator'(
    (char *)this->m_atmospheric_scattering_effect,
    4u,
    2,
    (void (__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  vostok::render::sphere_geometry::~sphere_geometry(v4, (int)&this->m_clouds_geometry);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &this->m_sky_dome_geometry.m_index_buffer,
    (vostok::render::hw_buffer_pool *)&this->m_sky_dome_geometry);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &this->m_sky_dome_geometry.m_vertex_buffer,
    (vostok::render::hw_buffer_pool *)&this->m_sky_dome_geometry);
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(&this->m_sky_dome_geometry.m_vertext_declaration);
  this->__vftable = (vostok::render::stage_atmosphere_vtbl *)&vostok::render::stage::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
