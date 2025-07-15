boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *__usercall boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>::operator=@<eax>(
        boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *this@<esi>,
        const boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *__that@<edi>)
{
  boost::detail::sp_counted_base *pi; // eax
  stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp> > > *px; // ecx
  boost::detail::sp_counted_base *v4; // ecx
  boost::detail::sp_counted_base *v6; // [esp+4h] [ebp-4h] BYREF

  pi = __that->values_.pn.pi_;
  px = __that->values_.px;
  if ( pi )
    _InterlockedExchangeAdd(&pi->use_count_, 1u);
  this->values_.px = px;
  v4 = this->values_.pn.pi_;
  this->values_.pn.pi_ = pi;
  v6 = v4;
  boost::detail::shared_count::~shared_count((boost::detail::shared_count *)v4, (volatile signed __int32 **)&v6);
  this->index_ = __that->index_;
  return this;
}


boost::detail::shared_count **__usercall boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>::operator++@<eax>(
        boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *this@<ecx>,
        boost::detail::shared_count **a2@<esi>)
{
  boost::detail::shared_count *v2; // ecx
  boost::detail::shared_count *v4; // [esp+Ch] [ebp-4h] BYREF

  a2[2] = (boost::detail::shared_count *)((char *)a2[2] + 1);
  v2 = *a2;
  if ( a2[2] == (boost::detail::shared_count *)(((char *)(*a2)[1].pi_ - (char *)(*a2)->pi_) / 76) )
  {
    *a2 = 0;
    v4 = a2[1];
    a2[1] = 0;
    boost::detail::shared_count::~shared_count(v2, (volatile signed __int32 **)&v4);
    a2[2] = 0;
  }
  return a2;
}
