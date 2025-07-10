void __thiscall boost::asio::ip::resolver_service<boost::asio::ip::udp>::resolver_service<boost::asio::ip::udp>(
        boost::asio::ip::resolver_service<boost::asio::ip::udp> *this,
        boost::asio::io_service *io_service)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->key_);
  this->__vftable = (boost::asio::ip::resolver_service<boost::asio::ip::udp>_vtbl *)&boost::asio::io_service::service::`vftable';
  this->key_.type_info_ = 0;
  this->key_.id_ = 0;
  this->owner_ = io_service;
  this->next_ = 0;
  this->__vftable = (boost::asio::ip::resolver_service<boost::asio::ip::udp>_vtbl *)&boost::asio::detail::service_base<boost::asio::ip::resolver_service<boost::asio::ip::udp>>::`vftable';
  this->__vftable = (boost::asio::ip::resolver_service<boost::asio::ip::udp>_vtbl *)&boost::asio::ip::resolver_service<boost::asio::ip::udp>::`vftable';
  boost::asio::detail::resolver_service_base::resolver_service_base(&this->service_impl_, io_service);
}
