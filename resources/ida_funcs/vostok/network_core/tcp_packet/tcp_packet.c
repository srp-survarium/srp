void __thiscall vostok::network_core::tcp_packet::tcp_packet(
        vostok::network_core::tcp_packet *this,
        vostok::memory::base_allocator *allocator)
{
  this->m_buffer = 0;
  this->m_buffer_size = 0;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_allocator);
  this->m_allocator = allocator;
  this->m_allocated_size = 0;
}
