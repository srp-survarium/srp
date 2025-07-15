void __thiscall vostok::network::network_world::tick(vostok::network::network_world *this, bool single_threaded)
{
  vostok::network::network_world::process_orders(this);
  if ( single_threaded )
    boost::asio::io_service::run_one(this->m_io_service);
  else
    boost::asio::io_service::poll(this->m_io_service);
}
