void __userpurge vostok::sound::sound_collection::sound_collection(
        vostok::sound::sound_collection *this@<ecx>,
        unsigned int max_count@<eax>,
        vostok::sound::collection_playback_types type,
        bool can_repeat_successively,
        unsigned __int16 cyclic_repeating_index,
        stlp_std::pair<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>,vostok::sound::sound_collection_params> *buffer,
        unsigned int random_seed)
{
  vostok::sound::sound_emitter::sound_emitter(this, this);
  this->vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::sound::sound_collection_vtbl *)&vostok::sound::sound_collection::`vftable'{for `vostok::sound::sound_emitter'};
  this->vostok::sound::sound_propagator_emitter::__vftable = (vostok::sound::sound_propagator_emitter_vtbl *)&vostok::sound::sound_collection::`vftable'{for `vostok::sound::sound_propagator_emitter'};
  this->m_sounds.m_begin = buffer;
  this->m_sounds.m_end = buffer;
  this->m_sounds.m_max_end = &buffer[max_count];
  this->m_type = type;
  this->m_random_number.m_seed = random_seed;
  this->m_current_sound_index = -1;
  this->m_cyclic_repeating_from_index = cyclic_repeating_index;
  this->m_can_repeat_successively = can_repeat_successively;
}
