boost::asio::ip::resolver_service<boost::asio::ip::udp> *__thiscall boost::asio::ip::resolver_service<boost::asio::ip::tcp>::`vector deleting destructor'(
        boost::asio::ip::resolver_service<boost::asio::ip::udp> *this,
        char a2)
{
  boost::asio::detail::resolver_service_base::~resolver_service_base(&this->service_impl_);
  this->__vftable = (boost::asio::ip::resolver_service<boost::asio::ip::udp>_vtbl *)&boost::asio::io_service::service::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->key_);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
