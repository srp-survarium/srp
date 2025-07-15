bool __thiscall boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>::equal(
        boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *this,
        const boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *other)
{
  if ( !this->values_.px && !other->values_.px )
    return 1;
  if ( this->values_.px == other->values_.px )
    return this->index_ == other->index_;
  return 0;
}
