boost::shared_ptr<boost::asio::detail::win_mutex> *__thiscall boost::shared_ptr<boost::asio::detail::win_mutex>::operator=(
        boost::shared_ptr<boost::asio::detail::win_mutex> *this,
        const boost::shared_ptr<boost::asio::detail::win_mutex> *r)
{
  boost::detail::sp_counted_base *pi; // [esp+10h] [ebp-18h]
  boost::shared_ptr<boost::asio::detail::win_mutex> v5; // [esp+20h] [ebp-8h]

  v5 = *r;
  if ( r->pn.pi_ )
    _InterlockedExchangeAdd(&v5.pn.pi_->use_count_, 1u);
  this->px = v5.px;
  pi = this->pn.pi_;
  this->pn.pi_ = v5.pn.pi_;
  if ( pi )
    boost::detail::sp_counted_base::release(pi);
  return this;
}
