void __thiscall vostok::render::render_particle_emitter_instance::~render_particle_emitter_instance(
        vostok::render::render_particle_emitter_instance *this)
{
  vostok::render::render_particle_emitter_instance *v1; // esi
  volatile int m_initialized; // eax
  vostok::render::render_particle_emitter_instance_vtbl *v3; // eax
  bool v4; // zf
  vostok::render::render_particle_emitter_instance_vtbl *v5; // eax
  vostok::render::res_geometry *m_object; // eax
  vostok::render::res_geometry *v7; // eax
  vostok::render::res_geometry *v8; // eax
  vostok::render::material_effects_instance *v9; // eax

  v1 = this;
  m_initialized = this->m_vertices.m_initialized;
  this->__vftable = (vostok::render::render_particle_emitter_instance_vtbl *)&vostok::render::render_particle_emitter_instance::`vftable';
  if ( m_initialized )
  {
    this = (vostok::render::render_particle_emitter_instance *)this->m_vertices.m_variable;
    v3 = this->__vftable;
    if ( this->__vftable )
    {
      v4 = v3->change_material-- == (void (__thiscall *)(struct vostok::render::render_particle_emitter_instance *, const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *))1;
      if ( v4 )
        vostok::render::resource_manager::release(
          (vostok::render::res_state *)this->__vftable,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
    }
    v1->m_vertices.m_initialized = 0;
  }
  if ( v1->m_indices.m_initialized )
  {
    this = (vostok::render::render_particle_emitter_instance *)v1->m_indices.m_variable;
    v5 = this->__vftable;
    if ( this->__vftable )
    {
      v4 = v5->change_material-- == (void (__thiscall *)(struct vostok::render::render_particle_emitter_instance *, const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *))1;
      if ( v4 )
        vostok::render::resource_manager::release(
          (vostok::render::res_state *)this->__vftable,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
    }
    v1->m_indices.m_initialized = 0;
  }
  m_object = v1->m_particle_beamtrail_geometry.m_object;
  if ( m_object )
  {
    v4 = m_object->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v1->m_particle_beamtrail_geometry.m_object);
  }
  v7 = v1->m_subuv_particle_sprite_geometry.m_object;
  if ( v7 )
  {
    v4 = v7->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v1->m_subuv_particle_sprite_geometry.m_object);
  }
  v8 = v1->m_particle_sprite_geometry.m_object;
  if ( v8 )
  {
    v4 = v8->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v1->m_particle_sprite_geometry.m_object);
  }
  v9 = v1->m_material_effects_ptr.m_object;
  if ( v9 )
  {
    this = (vostok::render::render_particle_emitter_instance *)_InterlockedExchangeAdd(
                                                                 &v9->m_reference_count,
                                                                 0xFFFFFFFF);
    if ( !this )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &v1->m_material_effects_ptr.m_object->vostok::resources::unmanaged_intrusive_base,
        v1->m_material_effects_ptr.m_object);
  }
  vostok::render::material_effects::~material_effects(
    (vostok::render::material_effects *)this,
    (int)&v1->m_material_effects);
}
