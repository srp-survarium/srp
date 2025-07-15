void __usercall boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>::basic_resolver_iterator<boost::asio::ip::tcp>(
        boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *this@<eax>,
        const boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *__that@<edx>)
{
  boost::detail::sp_counted_base *pi; // ecx

  this->values_.px = __that->values_.px;
  pi = __that->values_.pn.pi_;
  this->values_.pn.pi_ = pi;
  if ( pi )
    _InterlockedExchangeAdd(&pi->use_count_, 1u);
  this->index_ = __that->index_;
}
