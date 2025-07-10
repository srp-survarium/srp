void __thiscall vostok::sound::sound_collection::sound_collection(
        vostok::sound::sound_collection *this,
        vostok::sound::collection_playback_types type,
        bool can_repeat_successively,
        unsigned __int16 cyclic_repeating_index,
        vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *buffer,
        unsigned int max_count,
        unsigned int last_time)
{
  vostok::sound::sound_emitter::sound_emitter(this);
  this->__vftable = (vostok::sound::sound_collection_vtbl *)&vostok::sound::sound_collection::`vftable';
  this->m_sounds.m_begin = buffer;
  this->m_sounds.m_end = buffer;
  this->m_type = type;
  this->m_random_number.m_seed = last_time;
  this->m_cyclic_repeating_from_index = cyclic_repeating_index;
  this->m_previously_played_sound_index = -1;
  this->m_can_repeat_successively = can_repeat_successively;
}
