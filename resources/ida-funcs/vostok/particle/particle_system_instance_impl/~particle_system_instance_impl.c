void __thiscall vostok::particle::particle_system_instance_impl::~particle_system_instance_impl(
        vostok::particle::particle_system_instance_impl *this)
{
  vostok::particle::particle_system_instance *v2; // ecx

  this->__vftable = (vostok::particle::particle_system_instance_impl_vtbl *)&vostok::particle::particle_system_instance_impl::`vftable';
  vostok::particle::particle_system_instance_impl::remove_emitter_instances(this, (int)this);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_skeleton_model);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_damage_model);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_scene);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_next);
  vostok::particle::particle_system_instance::~particle_system_instance(v2, (int)this);
}
