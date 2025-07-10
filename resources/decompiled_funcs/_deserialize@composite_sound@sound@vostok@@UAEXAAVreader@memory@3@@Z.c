void __thiscall vostok::sound::composite_sound::deserialize(
        vostok::sound::composite_sound *this,
        vostok::memory::reader_wrapper<vostok::memory::reader> *r)
{
  int v2; // edx
  stlp_std::pair<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>,stlp_std::pair<unsigned int,unsigned int> > *end; // [esp+18h] [ebp-8h]
  stlp_std::pair<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>,stlp_std::pair<unsigned int,unsigned int> > *begin; // [esp+1Ch] [ebp-4h]

  LODWORD(this->m_old_address) = vostok::memory::reader_wrapper<vostok::memory::reader>::r<unsigned __int64>(r);
  HIDWORD(this->m_old_address) = v2;
  begin = this->m_collection.m_begin;
  end = this->m_collection.m_end;
  while ( begin != end )
  {
    begin->first.m_object->deserialize(begin->first.m_object, (vostok::memory::reader *)r);
    ++begin;
  }
}
