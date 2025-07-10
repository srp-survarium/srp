boost::asio::buffers_iterator<boost::asio::const_buffers_1,char> *__cdecl boost::asio::buffers_iterator<boost::asio::const_buffers_1,char>::begin(
        boost::asio::buffers_iterator<boost::asio::const_buffers_1,char> *result,
        const boost::asio::const_buffers_1 *buffers)
{
  unsigned int size; // eax
  boost::asio::buffers_iterator<boost::asio::const_buffers_1,char> new_iter; // [esp+Ch] [ebp-1Ch] BYREF

  boost::asio::buffers_iterator<boost::asio::const_buffers_1,char>::buffers_iterator<boost::asio::const_buffers_1,char>(&new_iter);
  new_iter.begin_ = buffers;
  new_iter.current_ = buffers;
  new_iter.end_ = buffers + 1;
  while ( new_iter.current_ != new_iter.end_ )
  {
    size = new_iter.current_->size_;
    new_iter.current_buffer_.data_ = new_iter.current_->data_;
    new_iter.current_buffer_.size_ = size;
    if ( size )
      break;
    ++new_iter.current_;
  }
  qmemcpy(result, &new_iter, sizeof(boost::asio::buffers_iterator<boost::asio::const_buffers_1,char>));
  return result;
}
