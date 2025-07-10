void __thiscall boost::asio::datagram_socket_service<boost::asio::ip::udp>::datagram_socket_service<boost::asio::ip::udp>(
        boost::asio::datagram_socket_service<boost::asio::ip::udp> *this,
        boost::asio::io_service *io_service)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->key_);
  this->__vftable = (boost::asio::datagram_socket_service<boost::asio::ip::udp>_vtbl *)&boost::asio::io_service::service::`vftable';
  this->key_.type_info_ = 0;
  this->key_.id_ = 0;
  this->owner_ = io_service;
  this->next_ = 0;
  this->__vftable = (boost::asio::datagram_socket_service<boost::asio::ip::udp>_vtbl *)&boost::asio::detail::service_base<boost::asio::datagram_socket_service<boost::asio::ip::udp>>::`vftable';
  this->__vftable = (boost::asio::datagram_socket_service<boost::asio::ip::udp>_vtbl *)&boost::asio::datagram_socket_service<boost::asio::ip::udp>::`vftable';
  this->service_impl_.io_service_ = io_service;
  this->service_impl_.iocp_service_ = io_service->impl_;
  this->service_impl_.reactor_ = 0;
  boost::asio::detail::win_mutex::win_mutex(&this->service_impl_.mutex_);
  this->service_impl_.impl_list_ = 0;
}
