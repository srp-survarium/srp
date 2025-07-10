void __thiscall boost::asio::detail::buffer_sequence_adapter<boost::asio::const_buffer,boost::asio::mutable_buffers_1>::buffer_sequence_adapter<boost::asio::const_buffer,boost::asio::mutable_buffers_1>(
        boost::asio::detail::buffer_sequence_adapter<boost::asio::const_buffer,boost::asio::mutable_buffers_1> *this,
        const boost::asio::mutable_buffers_1 *buffer_sequence)
{
  unsigned int size; // [esp+18h] [ebp-4h]

  size = buffer_sequence->size_;
  this->buffer_.buf = (char *)buffer_sequence->data_;
  this->buffer_.len = size;
  this->total_buffer_size_ = buffer_sequence->size_;
}
