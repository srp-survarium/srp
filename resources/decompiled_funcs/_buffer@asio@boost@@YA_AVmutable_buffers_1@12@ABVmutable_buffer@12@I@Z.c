boost::asio::mutable_buffers_1 *__cdecl boost::asio::buffer(
        boost::asio::mutable_buffers_1 *result,
        const boost::asio::mutable_buffer *b,
        unsigned int max_size_in_bytes)
{
  unsigned int size; // [esp+0h] [ebp-18h]

  if ( b->size_ >= max_size_in_bytes )
    size = max_size_in_bytes;
  else
    size = b->size_;
  result->data_ = b->data_;
  result->size_ = size;
  return result;
}
