void __thiscall boost::asio::buffers_iterator<boost::asio::const_buffers_1,char>::buffers_iterator<boost::asio::const_buffers_1,char>(
        boost::asio::buffers_iterator<boost::asio::const_buffers_1,char> *this)
{
  this->current_buffer_.data_ = 0;
  this->current_buffer_.size_ = 0;
  this->current_buffer_position_ = 0;
  this->begin_ = 0;
  this->current_ = 0;
  this->end_ = 0;
  this->position_ = 0;
}
