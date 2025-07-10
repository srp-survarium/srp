void __thiscall vostok::sound::single_sound::deserialize(
        vostok::sound::single_sound *this,
        vostok::memory::reader_wrapper<vostok::memory::reader> *r)
{
  int v2; // edx

  LODWORD(this->m_old_address) = vostok::memory::reader_wrapper<vostok::memory::reader>::r<unsigned __int64>(r);
  HIDWORD(this->m_old_address) = v2;
}
