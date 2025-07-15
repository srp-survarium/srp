void __thiscall vostok::sound::single_sound::~single_sound(vostok::sound::single_sound *this)
{
  this->vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::sound::single_sound_vtbl *)&vostok::sound::single_sound::`vftable'{for `vostok::sound::sound_emitter'};
  this->vostok::sound::sound_propagator_emitter::__vftable = (vostok::sound::sound_propagator_emitter_vtbl *)&vostok::sound::single_sound::`vftable'{for `vostok::sound::sound_propagator_emitter'};
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_sound_options);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_encoded_sound);
  this->vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::sound::single_sound_vtbl *)&vostok::sound::sound_emitter::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
