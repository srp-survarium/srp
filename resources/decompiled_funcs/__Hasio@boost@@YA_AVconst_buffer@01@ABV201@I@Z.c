boost::asio::const_buffer *__cdecl boost::asio::operator+(
        boost::asio::const_buffer *result,
        const boost::asio::const_buffer *b,
        unsigned int start)
{
  unsigned int size; // [esp+0h] [ebp-14h]

  if ( start <= b->size_ )
  {
    size = b->size_;
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
