vostok::render::stage_gbuffer *__thiscall vostok::render::stage_gbuffer::`vector deleting destructor'(
        vostok::render::stage_gbuffer *this,
        char a2)
{
  vostok::render::res_state *m_object; // eax

  this->__vftable = (vostok::render::stage_gbuffer_vtbl *)&vostok::render::stage_gbuffer::`vftable';
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_fill_depth_effect);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_copy_depth_rt);
  m_object = this->m_state.m_object;
  if ( m_object )
    --m_object->m_reference_count;
  this->__vftable = (vostok::render::stage_gbuffer_vtbl *)&vostok::render::stage::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
