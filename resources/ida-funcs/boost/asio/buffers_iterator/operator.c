boost::asio::buffers_iterator<boost::asio::const_buffers_1,char> *__usercall boost::asio::buffers_iterator<boost::asio::const_buffers_1,char>::operator++@<eax>(
        boost::asio::buffers_iterator<boost::asio::const_buffers_1,char> *this@<ecx>,
        boost::asio::buffers_iterator<boost::asio::const_buffers_1,char> *result@<eax>)
{
  const boost::asio::const_buffer *v2; // ecx
  unsigned int size; // edx

  ++result->position_;
  if ( ++result->current_buffer_position_ == result->current_buffer_.size_ )
  {
    v2 = ++result->current_;
    for ( result->current_buffer_position_ = 0; v2 != result->end_; result->current_ = v2 )
    {
      result->current_buffer_.data_ = v2->data_;
      size = v2->size_;
      result->current_buffer_.size_ = size;
      if ( size )
        break;
      ++v2;
    }
  }
  return result;
}
