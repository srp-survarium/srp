void __thiscall vostok::sound::sound_collection::serialize(
        vostok::sound::sound_collection *this,
        vostok::memory::writer *w)
{
  unsigned int m_previously_played_sound_index; // [esp+10h] [ebp-14h] BYREF
  unsigned int m_cyclic_repeating_from_index; // [esp+14h] [ebp-10h] BYREF
  unsigned int m_seed; // [esp+18h] [ebp-Ch] BYREF
  const vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *end; // [esp+1Ch] [ebp-8h]
  const vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *begin; // [esp+20h] [ebp-4h]

  w->write(w, &this->m_type, 4u);
  m_seed = this->m_random_number.m_seed;
  w->write(w, &m_seed, 4u);
  m_cyclic_repeating_from_index = this->m_cyclic_repeating_from_index;
  w->write(w, &m_cyclic_repeating_from_index, 4u);
  m_previously_played_sound_index = this->m_previously_played_sound_index;
  w->write(w, &m_previously_played_sound_index, 4u);
  w->write(w, &this->m_can_repeat_successively, 1u);
  begin = this->m_sounds.m_begin;
  end = this->m_sounds.m_end;
  while ( begin != end )
  {
    begin->m_object->serialize(begin->m_object, w);
    ++begin;
  }
}
