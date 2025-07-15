vostok::render::stage_forward *__thiscall vostok::render::stage_forward::`scalar deleting destructor'(
        vostok::render::stage_forward *this,
        char a2)
{
  this->__vftable = (vostok::render::stage_forward_vtbl *)&vostok::render::stage_forward::`vftable';
  `vector destructor iterator'(
    (char *)this->m_gbuffer_depth_effect,
    4u,
    15,
    (void (__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_opaque_geometry_mask_effect);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_debug_tracer_effect);
  this->__vftable = (vostok::render::stage_forward_vtbl *)&vostok::render::stage::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
