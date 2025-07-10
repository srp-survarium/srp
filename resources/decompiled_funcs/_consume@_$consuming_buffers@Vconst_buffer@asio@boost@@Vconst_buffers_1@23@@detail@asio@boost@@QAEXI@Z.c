void __thiscall boost::asio::detail::consuming_buffers<boost::asio::const_buffer,boost::asio::const_buffers_1>::consume(
        boost::asio::detail::consuming_buffers<boost::asio::const_buffer,boost::asio::const_buffers_1> *this,
        unsigned int size)
{
  const boost::asio::const_buffer *begin_remainder; // eax
  unsigned int v3; // edx
  const boost::asio::const_buffer *v4; // eax
  unsigned int v5; // edx
  boost::asio::const_buffer v6; // [esp+2Ch] [ebp-8h]

  while ( size && !this->at_end_ )
  {
    if ( this->first_.size_ > size )
    {
      if ( size <= this->first_.size_ )
      {
        v6.data_ = (char *)this->first_.data_ + size;
        v6.size_ = this->first_.size_ - size;
      }
      else
      {
        v6 = 0;
      }
      this->first_ = v6;
      size = 0;
    }
    else
    {
      size -= this->first_.size_;
      if ( (bool *)this->begin_remainder_ == &this->at_end_ )
      {
        this->at_end_ = 1;
      }
      else
      {
        begin_remainder = this->begin_remainder_;
        v3 = begin_remainder->size_;
        this->first_.data_ = begin_remainder->data_;
        this->first_.size_ = v3;
        ++this->begin_remainder_;
      }
    }
  }
  while ( !this->at_end_ && !this->first_.size_ )
  {
    if ( (bool *)this->begin_remainder_ == &this->at_end_ )
    {
      this->at_end_ = 1;
    }
    else
    {
      v4 = this->begin_remainder_;
      v5 = v4->size_;
      this->first_.data_ = v4->data_;
      this->first_.size_ = v5;
      ++this->begin_remainder_;
    }
  }
}
