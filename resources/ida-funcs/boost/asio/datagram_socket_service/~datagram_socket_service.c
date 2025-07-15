void __thiscall boost::asio::datagram_socket_service<boost::asio::ip::udp>::~datagram_socket_service<boost::asio::ip::udp>(
        boost::asio::datagram_socket_service<boost::asio::ip::udp> *this)
{
  boost::asio::detail::win_mutex *lpCriticalSection; // [esp+4h] [ebp-4h]

  lpCriticalSection = &this->service_impl_.mutex_;
  DeleteCriticalSection(&this->service_impl_.mutex_.crit_section_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)lpCriticalSection);
  this->__vftable = (boost::asio::datagram_socket_service<boost::asio::ip::udp>_vtbl *)&boost::asio::io_service::service::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->key_);
}
