boost::asio::detail::consuming_buffers_iterator<boost::asio::const_buffer,boost::asio::const_buffer const *> *__thiscall boost::asio::detail::consuming_buffers<boost::asio::const_buffer,boost::asio::const_buffers_1>::begin(
        boost::asio::detail::consuming_buffers<boost::asio::const_buffer,boost::asio::const_buffers_1> *this,
        boost::asio::detail::consuming_buffers_iterator<boost::asio::const_buffer,boost::asio::const_buffer const *> *result)
{
  bool at_end; // [esp+3h] [ebp-35h]
  unsigned int max_size; // [esp+8h] [ebp-30h]
  const boost::asio::const_buffer *begin_remainder; // [esp+Ch] [ebp-2Ch]
  unsigned int size; // [esp+18h] [ebp-20h]

  max_size = this->max_size_;
  begin_remainder = this->begin_remainder_;
  if ( max_size )
    at_end = this->at_end_;
  else
    at_end = 1;
  result->at_end_ = at_end;
  if ( this->first_.size_ >= max_size )
    size = max_size;
  else
    size = this->first_.size_;
  result->first_.data_ = this->first_.data_;
  result->first_.size_ = size;
  result->begin_remainder_ = begin_remainder;
  result->end_remainder_ = (const boost::asio::const_buffer *)&this->at_end_;
  result->offset_ = 0;
  result->max_size_ = max_size;
  return result;
}
