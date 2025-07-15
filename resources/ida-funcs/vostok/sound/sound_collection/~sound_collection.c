void __thiscall vostok::sound::sound_collection::~sound_collection(vostok::sound::sound_collection *this)
{
  vostok::buffer_vector<stlp_std::pair<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>,vostok::sound::sound_collection_params> > *p_m_sounds; // esi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *i; // ebx

  p_m_sounds = &this->m_sounds;
  this->vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::sound::sound_collection_vtbl *)&vostok::sound::sound_collection::`vftable'{for `vostok::sound::sound_emitter'};
  this->vostok::sound::sound_propagator_emitter::__vftable = (vostok::sound::sound_propagator_emitter_vtbl *)&vostok::sound::sound_collection::`vftable'{for `vostok::sound::sound_propagator_emitter'};
  for ( i = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->m_sounds.m_begin;
        i != (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_sounds->m_end;
        i += 4 )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(i);
  }
  p_m_sounds->m_end = p_m_sounds->m_begin;
  this->vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::sound::sound_collection_vtbl *)&vostok::sound::sound_emitter::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
