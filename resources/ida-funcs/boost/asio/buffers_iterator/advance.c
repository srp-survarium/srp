void __usercall boost::asio::buffers_iterator<boost::asio::const_buffers_1,char>::advance(
        boost::asio::buffers_iterator<boost::asio::const_buffers_1,char> *this@<eax>,
        int n@<edx>)
{
  signed int v2; // ecx
  const boost::asio::const_buffer *end; // esi
  const boost::asio::const_buffer *v4; // ecx
  const void *v5; // edi
  unsigned int v6; // ecx
  unsigned int v7; // edx
  const boost::asio::const_buffer *begin; // edi
  unsigned int current_buffer_position; // ecx
  const boost::asio::const_buffer *current; // ecx
  unsigned int size; // esi
  const void *data; // ebx

  if ( n <= 0 )
  {
    if ( n < 0 )
    {
      v7 = -n;
      if ( this->current_buffer_position_ >= v7 )
      {
LABEL_17:
        this->position_ -= v7;
        this->current_buffer_position_ -= v7;
      }
      else
      {
        begin = this->begin_;
        while ( 1 )
        {
          current_buffer_position = this->current_buffer_position_;
          this->position_ -= current_buffer_position;
          v7 -= current_buffer_position;
          current = this->current_;
          if ( current == begin )
            break;
          while ( 1 )
          {
            --current;
            size = current->size_;
            if ( size )
              break;
            if ( current == begin )
              goto LABEL_16;
          }
          data = current->data_;
          this->current_ = current;
          this->current_buffer_.data_ = data;
          this->current_buffer_.size_ = size;
          this->current_buffer_position_ = size;
LABEL_16:
          if ( this->current_buffer_position_ >= v7 )
            goto LABEL_17;
        }
        this->current_buffer_position_ = 0;
      }
    }
  }
  else
  {
    v2 = this->current_buffer_.size_ - this->current_buffer_position_;
    if ( v2 > n )
    {
LABEL_6:
      this->position_ += n;
      this->current_buffer_position_ += n;
    }
    else
    {
      end = this->end_;
      while ( 1 )
      {
        this->position_ += v2;
        ++this->current_;
        n -= v2;
        v4 = this->current_;
        if ( v4 == end )
          break;
        v5 = v4->data_;
        v6 = v4->size_;
        this->current_buffer_position_ = 0;
        this->current_buffer_.data_ = v5;
        this->current_buffer_.size_ = v6;
        v2 = v6 - this->current_buffer_position_;
        if ( v2 > n )
          goto LABEL_6;
      }
      this->current_buffer_position_ = 0;
      this->current_buffer_.data_ = 0;
      this->current_buffer_.size_ = 0;
    }
  }
}
