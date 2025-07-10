void __thiscall boost::asio::detail::socket_holder::~socket_holder(boost::asio::detail::socket_holder *this)
{
  unsigned __int8 state; // [esp+BFh] [ebp-9h] BYREF
  boost::system::error_code ec; // [esp+C0h] [ebp-8h] BYREF

  if ( this->socket_ != -1 )
  {
    ec.m_val = 0;
    ec.m_cat = boost::system::system_category();
    state = 0;
    boost::asio::detail::socket_ops::close(this->socket_, &state, 1, &ec);
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
