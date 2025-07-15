bool __thiscall boost::asio::detail::consuming_buffers_iterator<boost::asio::const_buffer,boost::asio::const_buffer const *>::equal(
        boost::asio::detail::consuming_buffers_iterator<boost::asio::const_buffer,boost::asio::const_buffer const *> *this,
        const boost::asio::detail::consuming_buffers_iterator<boost::asio::const_buffer,boost::asio::const_buffer const *> *other)
{
  if ( this->at_end_ && other->at_end_ )
    return 1;
  return !this->at_end_
      && !other->at_end_
      && this->first_.data_ == other->first_.data_
      && this->first_.size_ == other->first_.size_
      && this->begin_remainder_ == other->begin_remainder_
      && this->end_remainder_ == other->end_remainder_;
}
