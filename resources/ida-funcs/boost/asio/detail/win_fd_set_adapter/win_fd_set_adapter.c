void __thiscall boost::asio::detail::win_fd_set_adapter::win_fd_set_adapter(
        boost::asio::detail::win_fd_set_adapter *this)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  this->capacity_ = 1024;
  this->max_descriptor_ = -1;
  this->fd_set_ = (boost::asio::detail::win_fd_set_adapter::win_fd_set *)operator new(4 * this->capacity_ + 4);
  this->fd_set_->fd_count = 0;
}
