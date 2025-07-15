bool __usercall boost::asio::detail::operator!=@<al>(
        const boost::asio::detail::consuming_buffers_iterator<boost::asio::const_buffer,boost::asio::const_buffer const *> *a@<ecx>,
        const boost::asio::detail::consuming_buffers_iterator<boost::asio::const_buffer,boost::asio::const_buffer const *> *b@<eax>)
{
  char v2; // al

  if ( !a->at_end_ )
  {
    if ( b->at_end_
      || a->first_.data_ != b->first_.data_
      || a->first_.size_ != b->first_.size_
      || a->begin_remainder_ != b->begin_remainder_
      || a->end_remainder_ != b->end_remainder_ )
    {
      goto LABEL_3;
    }
LABEL_10:
    v2 = 1;
    return v2 == 0;
  }
  if ( b->at_end_ )
    goto LABEL_10;
LABEL_3:
  v2 = 0;
  return v2 == 0;
}
