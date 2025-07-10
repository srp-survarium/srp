void __thiscall boost::asio::buffers_iterator<boost::asio::const_buffers_1,char>::increment(
        boost::asio::buffers_iterator<boost::asio::const_buffers_1,char> *this)
{
  const boost::asio::const_buffer *current; // eax
  unsigned int size; // edx

  ++this->position_;
  if ( ++this->current_buffer_position_ == this->current_buffer_.size_ )
  {
    ++this->current_;
    this->current_buffer_position_ = 0;
    while ( this->current_ != this->end_ )
    {
      current = this->current_;
      size = current->size_;
      this->current_buffer_.data_ = current->data_;
      this->current_buffer_.size_ = size;
      if ( this->current_buffer_.size_ )
        break;
      ++this->current_;
    }
  }
}
