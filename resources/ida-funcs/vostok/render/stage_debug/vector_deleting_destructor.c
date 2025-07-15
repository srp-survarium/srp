vostok::render::stage_debug *__thiscall vostok::render::stage_debug::`vector deleting destructor'(
        vostok::render::stage_debug *this,
        char a2)
{
  vostok::render::box_geometry *p_m_box_geometry; // esi
  vostok::render::sphere_geometry *v4; // ecx

  p_m_box_geometry = &this->m_box_geometry;
  this->__vftable = (vostok::render::stage_debug_vtbl *)&vostok::render::stage_debug::`vftable';
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &this->m_box_geometry.m_index_buffer,
    (vostok::render::hw_buffer_pool *)&this->m_box_geometry);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &p_m_box_geometry->m_vertex_buffer,
    (vostok::render::hw_buffer_pool *)p_m_box_geometry);
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(&p_m_box_geometry->m_vertext_declaration);
  vostok::render::sphere_geometry::~sphere_geometry(v4, (int)&this->m_sphere_geometry);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_debug_environment_probe_preview_effect);
  this->__vftable = (vostok::render::stage_debug_vtbl *)&vostok::render::stage::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
