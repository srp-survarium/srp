void __thiscall vostok::sound::composite_sound::composite_sound(
        vostok::sound::composite_sound *this,
        stlp_std::pair<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>,stlp_std::pair<unsigned int,unsigned int> > *buffer,
        unsigned int max_count,
        unsigned int last_time)
{
  vostok::sound::sound_emitter::sound_emitter(this);
  this->vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::sound::composite_sound_vtbl *)&vostok::sound::composite_sound::`vftable'{for `vostok::sound::sound_emitter'};
  this->vostok::sound::sound_propagator_emitter::__vftable = (vostok::sound::sound_propagator_emitter_vtbl *)&vostok::sound::composite_sound::`vftable'{for `vostok::sound::sound_propagator_emitter'};
  this->m_collection.m_begin = buffer;
  this->m_collection.m_end = buffer;
  this->m_random_number.m_seed = last_time;
  this->m_old_address = (int)vostok::sound::composite_sound::get_sound_propagator_emitter(this);
}
