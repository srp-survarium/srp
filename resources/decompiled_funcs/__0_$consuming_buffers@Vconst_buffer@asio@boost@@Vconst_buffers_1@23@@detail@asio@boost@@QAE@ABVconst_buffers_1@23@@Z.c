void __thiscall boost::asio::detail::consuming_buffers<boost::asio::const_buffer,boost::asio::const_buffers_1>::consuming_buffers<boost::asio::const_buffer,boost::asio::const_buffers_1>(
        boost::asio::detail::consuming_buffers<boost::asio::const_buffer,boost::asio::const_buffers_1> *this,
        const boost::asio::const_buffers_1 *buffers)
{
  unsigned int size; // edx
  unsigned int v3; // edx

  size = buffers->size_;
  this->buffers_.data_ = buffers->data_;
  this->buffers_.size_ = size;
  this->at_end_ = 0;
  this->first_.data_ = 0;
  this->first_.size_ = 0;
  this->begin_remainder_ = &this->buffers_;
  this->max_size_ = -1;
  if ( !this->at_end_ )
  {
    v3 = this->buffers_.size_;
    this->first_.data_ = this->buffers_.data_;
    this->first_.size_ = v3;
    ++this->begin_remainder_;
  }
}
