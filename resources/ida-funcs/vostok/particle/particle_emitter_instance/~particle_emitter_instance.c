void __thiscall vostok::particle::particle_emitter_instance::~particle_emitter_instance(
        vostok::particle::particle_emitter_instance *this)
{
  this->__vftable = (vostok::particle::particle_emitter_instance_vtbl *)&vostok::particle::particle_emitter_instance::`vftable';
  vostok::particle::particle_emitter_instance::remove_particles(this, (int)this, 0xFFFFFFFF);
  if ( this->m_render_instance )
    this->m_engine->destroy(this->m_engine, &this->m_render_instance);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_particle_system_instance_ptr);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_material);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_scene);
  DeleteCriticalSection((LPCRITICAL_SECTION)&this->m_particle_list.vostok::threading::mutex);
}
