char __thiscall boost::asio::detail::win_fd_set_adapter::set(
        boost::asio::detail::win_fd_set_adapter *this,
        unsigned int descriptor)
{
  unsigned int j; // [esp+8h] [ebp-10h]
  unsigned int new_capacity; // [esp+Ch] [ebp-Ch]
  boost::asio::detail::win_fd_set_adapter::win_fd_set *new_fd_set; // [esp+10h] [ebp-8h]
  unsigned int i; // [esp+14h] [ebp-4h]

  for ( i = 0; i < this->fd_set_->fd_count; ++i )
  {
    if ( this->fd_set_->fd_array[i] == descriptor )
      return 1;
  }
  if ( this->fd_set_->fd_count == this->capacity_ )
  {
    new_capacity = this->capacity_ + (this->capacity_ >> 1);
    new_fd_set = (boost::asio::detail::win_fd_set_adapter::win_fd_set *)operator new(4 * new_capacity + 4);
    new_fd_set->fd_count = this->fd_set_->fd_count;
    for ( j = 0; j < this->fd_set_->fd_count; ++j )
      new_fd_set->fd_array[j] = this->fd_set_->fd_array[j];
    operator delete(this->fd_set_);
    this->fd_set_ = new_fd_set;
    this->capacity_ = new_capacity;
  }
  this->fd_set_->fd_array[this->fd_set_->fd_count++] = descriptor;
  return 1;
}
