vostok::render::stage_shadow_mask *__userpurge vostok::render::stage_shadow_mask::`scalar deleting destructor'@<eax>(
        vostok::render::stage_shadow_mask *this@<ecx>,
        vostok::render::hw_buffer_pool *esi0@<esi>,
        char a2)
{
  vostok::render::sphere_geometry *v4; // ecx

  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_far_plane_mask_effect);
  `vector destructor iterator'(
    (char *)this->m_sun_shadow_apply_effect,
    4u,
    8,
    (void (__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_shadow_mask_effect);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(&this->m_obb_geometry);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &this->m_obb_index_buffer,
    esi0);
  vostok::render::sphere_geometry::~sphere_geometry(v4, (int)&this->m_sphere_geometry);
  this->__vftable = (vostok::render::stage_shadow_mask_vtbl *)&vostok::render::stage::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
