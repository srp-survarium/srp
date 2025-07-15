void __thiscall vostok::sound::sound_receiver::on_register_receiver_order_created(
        vostok::sound::sound_receiver *this,
        vostok::sound::atomic_half3 *position)
{
  this->m_position = position;
}
