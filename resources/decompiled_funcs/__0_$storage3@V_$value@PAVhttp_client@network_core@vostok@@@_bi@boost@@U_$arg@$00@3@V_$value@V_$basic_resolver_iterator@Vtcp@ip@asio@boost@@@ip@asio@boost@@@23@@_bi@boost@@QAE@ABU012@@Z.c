void __thiscall boost::_bi::storage3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::_bi::value<boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>>>::storage3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::_bi::value<boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>>>(
        boost::_bi::storage3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::_bi::value<boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> > > *this,
        const boost::_bi::storage3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::_bi::value<boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> > > *__that)
{
  this->a1_.t_ = __that->a1_.t_;
  this->a3_.t_.values_.px = __that->a3_.t_.values_.px;
  this->a3_.t_.values_.pn.pi_ = __that->a3_.t_.values_.pn.pi_;
  if ( this->a3_.t_.values_.pn.pi_ )
    _InterlockedExchangeAdd(&this->a3_.t_.values_.pn.pi_->use_count_, 1u);
  this->a3_.t_.index_ = __that->a3_.t_.index_;
}
