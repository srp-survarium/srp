void __thiscall vostok::sound::single_sound::serialize(vostok::sound::single_sound *this, vostok::memory::writer *w)
{
  unsigned __int64 m_old_address; // [esp+4h] [ebp-8h] BYREF

  this->m_old_address = (unsigned __int64)this->get_sound_propagator_emitter(this);
  m_old_address = this->m_old_address;
  w->write(w, &m_old_address, 8u);
}
