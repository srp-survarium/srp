void __thiscall boost::asio::detail::scoped_lock<boost::asio::detail::win_mutex>::lock(
        boost::asio::detail::scoped_lock<boost::asio::detail::win_mutex> *this)
{
  if ( !this->locked_ )
  {
    EnterCriticalSection(&this->mutex_->crit_section_);
    this->locked_ = 1;
  }
}
