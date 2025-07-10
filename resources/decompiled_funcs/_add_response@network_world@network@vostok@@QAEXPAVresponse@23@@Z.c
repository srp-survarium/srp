void __thiscall vostok::network::network_world::add_response(
        vostok::network::network_world *this,
        vostok::network::response *response)
{
  vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>::push_back(
    &this->m_channel.responses.m_forward_queue,
    response);
}
