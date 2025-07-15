boost::asio::buffers_iterator<boost::asio::const_buffers_1,char> *__cdecl boost::asio::buffers_iterator<boost::asio::const_buffers_1,char>::end(
        boost::asio::buffers_iterator<boost::asio::const_buffers_1,char> *result,
        const boost::asio::const_buffers_1 *buffers)
{
  boost::asio::buffers_iterator<boost::asio::const_buffers_1,char> new_iter; // [esp+14h] [ebp-1Ch] BYREF

  boost::asio::buffers_iterator<boost::asio::const_buffers_1,char>::buffers_iterator<boost::asio::const_buffers_1,char>(&new_iter);
  new_iter.begin_ = buffers;
  new_iter.current_ = buffers;
  new_iter.end_ = buffers + 1;
  while ( new_iter.current_ != new_iter.end_ )
  {
    new_iter.position_ += new_iter.current_->size_;
    ++new_iter.current_;
  }
  qmemcpy(result, &new_iter, sizeof(boost::asio::buffers_iterator<boost::asio::const_buffers_1,char>));
  return result;
}
