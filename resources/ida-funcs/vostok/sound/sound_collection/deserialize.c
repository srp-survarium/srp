void __thiscall vostok::sound::sound_collection::deserialize(
        vostok::sound::sound_collection *this,
        vostok::memory::reader_wrapper<vostok::memory::reader> *r)
{
  vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *end; // [esp+2Ch] [ebp-8h]
  vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *begin; // [esp+30h] [ebp-4h]

  vostok::memory::copy(&this->m_type, 4u, *(const void **)&r[4], 4u);
  *(_DWORD *)&r[4] += 4;
  this->m_random_number.m_seed = vostok::memory::reader_wrapper<vostok::memory::reader>::r<unsigned int>(r);
  this->m_cyclic_repeating_from_index = vostok::memory::reader_wrapper<vostok::memory::reader>::r<unsigned int>(r);
  this->m_previously_played_sound_index = vostok::memory::reader_wrapper<vostok::memory::reader>::r<unsigned int>(r);
  vostok::memory::copy(&this->m_can_repeat_successively, 1u, *(const void **)&r[4], 1u);
  ++*(_DWORD *)&r[4];
  begin = this->m_sounds.m_begin;
  end = this->m_sounds.m_end;
  while ( begin != end )
  {
    begin->m_object->deserialize(begin->m_object, (vostok::memory::reader *)r);
    ++begin;
  }
}
