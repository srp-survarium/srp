void __thiscall vostok::particle::particle_system_instance_impl::~particle_system_instance_impl(
        vostok::particle::particle_system_instance_impl *this)
{
  this->__vftable = (vostok::particle::particle_system_instance_impl_vtbl *)&vostok::particle::particle_system_instance_impl::`vftable';
  vostok::particle::particle_system_instance_impl::remove_emitter_instances(this);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&this->m_scene);
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_next);
  vostok::particle::particle_system_instance::~particle_system_instance(this);
}
