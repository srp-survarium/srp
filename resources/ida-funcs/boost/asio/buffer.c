boost::asio::mutable_buffers_1 *__usercall boost::asio::buffer@<eax>(
        const boost::asio::mutable_buffer *b@<ecx>,
        boost::asio::mutable_buffers_1 *result@<eax>,
        unsigned int max_size_in_bytes)
{
  unsigned int size; // edx
  void *data; // ecx

  size = b->size_;
  data = b->data_;
  if ( size >= max_size_in_bytes )
    size = max_size_in_bytes;
  result->data_ = data;
  result->size_ = size;
  return result;
}
