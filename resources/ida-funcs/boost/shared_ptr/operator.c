boost::shared_ptr<boost::asio::detail::win_mutex> *__usercall boost::shared_ptr<boost::asio::detail::win_mutex>::operator=@<eax>(
        boost::shared_ptr<boost::asio::detail::win_mutex> *this@<esi>,
        const boost::shared_ptr<boost::asio::detail::win_mutex> *r@<eax>)
{
  boost::asio::detail::win_mutex *px; // ecx
  boost::detail::sp_counted_base *pi; // eax
  boost::detail::sp_counted_base *v4; // ecx
  boost::detail::sp_counted_base *v6; // [esp+4h] [ebp-4h] BYREF

  px = r->px;
  pi = r->pn.pi_;
  if ( pi )
    _InterlockedExchangeAdd(&pi->use_count_, 1u);
  this->px = px;
  v4 = this->pn.pi_;
  this->pn.pi_ = pi;
  v6 = v4;
  boost::detail::shared_count::~shared_count((boost::detail::shared_count *)v4, (volatile signed __int32 **)&v6);
  return this;
}
