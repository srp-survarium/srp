void __thiscall vostok::sound::composite_sound::serialize(
        vostok::sound::composite_sound *this,
        vostok::memory::writer *w)
{
  unsigned __int64 m_old_address; // [esp+10h] [ebp-10h] BYREF
  const stlp_std::pair<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>,stlp_std::pair<unsigned int,unsigned int> > *end; // [esp+18h] [ebp-8h]
  const stlp_std::pair<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>,stlp_std::pair<unsigned int,unsigned int> > *begin; // [esp+1Ch] [ebp-4h]

  this->m_old_address = (unsigned __int64)this->get_sound_propagator_emitter(this);
  m_old_address = this->m_old_address;
  w->write(w, &m_old_address, 8u);
  begin = this->m_collection.m_begin;
  end = this->m_collection.m_end;
  while ( begin != end )
  {
    begin->first.m_object->serialize(begin->first.m_object, w);
    ++begin;
  }
}
