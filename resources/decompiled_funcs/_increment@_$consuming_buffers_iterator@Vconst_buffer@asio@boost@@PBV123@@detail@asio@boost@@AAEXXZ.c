void __thiscall boost::asio::detail::consuming_buffers_iterator<boost::asio::const_buffer,boost::asio::const_buffer const *>::increment(
        boost::asio::detail::consuming_buffers_iterator<boost::asio::const_buffer,boost::asio::const_buffer const *> *this)
{
  const boost::asio::const_buffer *begin_remainder; // [esp+8h] [ebp-2Ch]
  unsigned int size; // [esp+Ch] [ebp-28h]

  if ( !this->at_end_ )
  {
    if ( this->begin_remainder_ == this->end_remainder_ || this->first_.size_ + this->offset_ >= this->max_size_ )
    {
      this->at_end_ = 1;
    }
    else
    {
      this->offset_ += this->first_.size_;
      begin_remainder = this->begin_remainder_;
      this->begin_remainder_ = begin_remainder + 1;
      if ( begin_remainder->size_ >= this->max_size_ - this->offset_ )
        size = this->max_size_ - this->offset_;
      else
        size = begin_remainder->size_;
      this->first_.data_ = begin_remainder->data_;
      this->first_.size_ = size;
    }
  }
}
