void __thiscall boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>::basic_resolver_iterator<boost::asio::ip::tcp>(
        boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *this,
        const boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *__that)
{
  this->values_.px = __that->values_.px;
  this->values_.pn.pi_ = __that->values_.pn.pi_;
  if ( this->values_.pn.pi_ )
    _InterlockedExchangeAdd(&this->values_.pn.pi_->use_count_, 1u);
  this->index_ = __that->index_;
}
