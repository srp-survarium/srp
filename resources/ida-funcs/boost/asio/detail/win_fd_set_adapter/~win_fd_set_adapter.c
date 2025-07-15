void __thiscall boost::asio::detail::win_fd_set_adapter::~win_fd_set_adapter(
        boost::asio::detail::win_fd_set_adapter *this)
{
  operator delete(this->fd_set_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
