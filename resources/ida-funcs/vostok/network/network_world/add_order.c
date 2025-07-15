void __thiscall vostok::network::network_world::add_order(
        vostok::network::network_world *this,
        vostok::network::response *order)
{
  vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>::push_back(
    (vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4> *)&this->m_channel.orders,
    order);
}
