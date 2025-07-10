void __thiscall vostok::particle::particle_emitter_instance::~particle_emitter_instance(
        vostok::particle::particle_emitter_instance *this)
{
  vostok::threading::mutex *v1; // ecx

  this->__vftable = (vostok::particle::particle_emitter_instance_vtbl *)&vostok::particle::particle_emitter_instance::`vftable';
  vostok::particle::particle_emitter_instance::remove_particles(this, 0xFFFFFFFF);
  if ( this->m_render_instance )
    this->m_engine->destroy(this->m_engine, &this->m_render_instance);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&this->m_particle_system_instance_ptr);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&this->m_material);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&this->m_scene);
  vostok::threading::mutex::~mutex(v1, (_RTL_CRITICAL_SECTION *)&this->m_particle_list.vostok::threading::mutex);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_transform);
}
