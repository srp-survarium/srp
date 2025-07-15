boost::asio::mutable_buffer *__usercall boost::asio::operator+@<eax>(
        const boost::asio::mutable_buffer *b@<edx>,
        boost::asio::mutable_buffer *result@<eax>,
        unsigned int start)
{
  unsigned int size; // ecx

  size = b->size_;
  if ( start <= size )
  {
    result->data_ = (char *)b->data_ + start;
    result->size_ = size - start;
  }
  else
  {
    result->data_ = 0;
    result->size_ = 0;
  }
  return result;
}
