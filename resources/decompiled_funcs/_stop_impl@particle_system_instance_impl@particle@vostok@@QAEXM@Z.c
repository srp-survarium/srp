void __thiscall vostok::particle::particle_system_instance_impl::stop_impl(
        vostok::particle::particle_system_instance_impl *this,
        float time)
{
  vostok::threading::interlocked_exchange_pointer(&this->m_is_playing, 0);
  this->m_no_more_create = 1;
}
