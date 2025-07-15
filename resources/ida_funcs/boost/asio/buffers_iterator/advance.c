void __thiscall boost::asio::buffers_iterator<boost::asio::const_buffers_1,char>::advance(
        boost::asio::buffers_iterator<boost::asio::const_buffers_1,char> *this,
        int n)
{
  const boost::asio::const_buffer *current; // edx
  unsigned int size; // ecx
  const void *buffer; // [esp+14h] [ebp-18h]
  unsigned int buffer_4; // [esp+18h] [ebp-14h]
  const boost::asio::const_buffer *iter; // [esp+20h] [ebp-Ch]
  unsigned int abs_n; // [esp+24h] [ebp-8h]
  int current_buffer_balance; // [esp+28h] [ebp-4h]

  if ( n <= 0 )
  {
    if ( n < 0 )
    {
      abs_n = -n;
      while ( 1 )
      {
LABEL_9:
        if ( this->current_buffer_position_ >= abs_n )
        {
          this->position_ -= abs_n;
          this->current_buffer_position_ -= abs_n;
          return;
        }
        abs_n -= this->current_buffer_position_;
        this->position_ -= this->current_buffer_position_;
        if ( this->current_ == this->begin_ )
          break;
        iter = this->current_;
        while ( iter != this->begin_ )
        {
          --iter;
          buffer = iter->data_;
          buffer_4 = iter->size_;
          if ( buffer_4 )
          {
            this->current_ = iter;
            this->current_buffer_.data_ = buffer;
            this->current_buffer_.size_ = buffer_4;
            this->current_buffer_position_ = buffer_4;
            goto LABEL_9;
          }
        }
      }
      this->current_buffer_position_ = 0;
    }
  }
  else
  {
    while ( 1 )
    {
      current_buffer_balance = this->current_buffer_.size_ - this->current_buffer_position_;
      if ( current_buffer_balance > n )
      {
        this->position_ += n;
        this->current_buffer_position_ += n;
        return;
      }
      n -= current_buffer_balance;
      this->position_ += current_buffer_balance;
      if ( ++this->current_ == this->end_ )
        break;
      current = this->current_;
      size = current->size_;
      this->current_buffer_.data_ = current->data_;
      this->current_buffer_.size_ = size;
      this->current_buffer_position_ = 0;
    }
    this->current_buffer_.data_ = 0;
    this->current_buffer_.size_ = 0;
    this->current_buffer_position_ = 0;
  }
}
