boost::asio::detail::service_base<boost::asio::ip::resolver_service<boost::asio::ip::udp> > *__thiscall boost::asio::detail::service_base<boost::asio::detail::select_reactor>::`vector deleting destructor'(
        boost::asio::detail::service_base<boost::asio::ip::resolver_service<boost::asio::ip::udp> > *this,
        char a2)
{
  this->__vftable = (boost::asio::detail::service_base<boost::asio::ip::resolver_service<boost::asio::ip::udp> >_vtbl *)&boost::asio::io_service::service::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->key_);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
