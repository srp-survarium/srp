vostok::animation::event_channel *__usercall vostok::animation::animation_event_channels::channel@<eax>(
        vostok::animation::animation_event_channels *this@<ecx>,
        unsigned int id@<eax>)
{
  return (vostok::animation::event_channel *)((char *)this + 44 * id + this->m_internal_memory_position);
}
