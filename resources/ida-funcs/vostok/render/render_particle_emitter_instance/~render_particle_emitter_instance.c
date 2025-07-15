void __thiscall vostok::render::render_particle_emitter_instance::~render_particle_emitter_instance(
        vostok::render::render_particle_emitter_instance *this)
{
  volatile int m_initialized; // eax
  vostok::render::material_effects *v3; // ecx

  m_initialized = this->m_vertices.m_initialized;
  this->__vftable = (vostok::render::render_particle_emitter_instance_vtbl *)&vostok::render::render_particle_emitter_instance::`vftable';
  if ( m_initialized )
  {
    vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      &this->m_vertices.m_variable->m_buffer,
      (vostok::render::hw_buffer_pool *)this);
    this->m_vertices.m_initialized = 0;
  }
  if ( this->m_indices.m_initialized )
  {
    vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      &this->m_indices.m_variable->m_buffer,
      (vostok::render::hw_buffer_pool *)this);
    this->m_indices.m_initialized = 0;
  }
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(&this->m_particle_beamtrail_geometry);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(&this->m_subuv_particle_sprite_geometry);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(&this->m_particle_sprite_geometry);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_material_effects_ptr);
  vostok::render::material_effects::~material_effects(v3, (int)&this->m_material_effects);
}
