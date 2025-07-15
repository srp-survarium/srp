void __thiscall vostok::sound::world_user::add_order(
        vostok::sound::world_user *this,
        vostok::sound::sound_order *order)
{
  vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>::push_back(
    &this->m_channel.orders.m_forward_queue,
    order);
}
