void __userpurge vostok::sound::composite_sound::composite_sound(
        vostok::sound::composite_sound *this@<ecx>,
        unsigned int max_count@<eax>,
        stlp_std::pair<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>,vostok::sound::composite_sound_params> *buffer,
        unsigned int last_time)
{
  vostok::sound::sound_emitter::sound_emitter(this, this);
  this->m_master_layer_index = -1;
  this->vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::sound::composite_sound_vtbl *)&vostok::sound::composite_sound::`vftable'{for `vostok::sound::sound_emitter'};
  this->vostok::sound::sound_propagator_emitter::__vftable = (vostok::sound::sound_propagator_emitter_vtbl *)&vostok::sound::composite_sound::`vftable'{for `vostok::sound::sound_propagator_emitter'};
  this->m_collection.m_begin = buffer;
  this->m_collection.m_end = buffer;
  this->m_collection.m_max_end = &buffer[max_count];
  this->m_random_number.m_seed = last_time;
}
